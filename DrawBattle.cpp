//-----------------------------------------------------------
// DrawBattle.cpp
// 描画制御
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#include "DrawBattle.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
DrawBattle::DrawBattle(GameData* data, GameState* state)
{
    game_data = data;
    input_state = state->getInputState();
    battle_state = state->getSceneState()->getBattleState();
    card_state = battle_state->getCardState();
    draw_damage = new DrawDamage(data, battle_state);
    image_data = data->getImageData();
    init();               // 初期処理
    loadImage();          // 画像読み込み

    // フォント作成
    font_10 = CreateFontToHandle("PixelMplus10", 10, 1, DX_FONTTYPE_NORMAL);
    font_12 = CreateFontToHandle("PixelMplus12", 12, -1, DX_FONTTYPE_NORMAL);
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
DrawBattle::~DrawBattle()
{
    delete(draw_damage);
    DeleteFontToHandle(font_10);
    DeleteFontToHandle(font_12);
}

//-----------------------------------------------------------
// 初期処理
//-----------------------------------------------------------
void DrawBattle::init()
{
    color_white = GetColor(255, 255, 255);
    color_black = GetColor(0, 0, 0);
    color_blue = GetColor(0, 125, 255);
    color_red = GetColor(255, 40, 40);
    color_gray = GetColor(60, 60, 60);
    color_green = GetColor(101, 243, 117);
    color_orange = GetColor(255, 158, 36);
    //ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE); // エッジ・アンチエイリアス
    //SetFontSize(15);                               // サイズを変更
}

//-----------------------------------------------------------
// 更新処理
//-----------------------------------------------------------
void DrawBattle::update()
{

}

//-----------------------------------------------------------
// 画像読み込み
//-----------------------------------------------------------
void DrawBattle::loadImage()
{
    std::stringstream ss;

    // ユニット画像
    handl_base = LoadGraph("image/unit/unit_0.png");

    // マップ画像
    handl_map[0] = LoadGraph("image/battle/tile.png");
    handl_map[1] = LoadGraph("image/battle/wall.png");

    // UI部
    LoadDivGraph("image/battle/com_button.png", 14, 7, 2, 60, 60, hand_com_button);
    handl_area_my = LoadGraph("image/battle/area_my.png");
    handl_area_ene = LoadGraph("image/battle/area_ene.png");
    handl_area_select = LoadGraph("image/battle/area_select.png");
    handl_area_select2 = LoadGraph("image/battle/area_select2.png");
    handl_area_grid = LoadGraph("image/battle/area_grid.png");
    handl_ui_card_back = LoadGraph("image/battle/card_back.png");
    handl_ui_mp_back = LoadGraph("image/battle/mp_back.png");
    handl_ui_button_cancel = LoadGraph("image/battle/button_cancel.png");
    handl_ui_button_end = LoadGraph("image/battle/button_end.png");
    handl_ui_card_intro = LoadGraph("image/battle/card_intro.png");
    handl_res_win = LoadGraph("image/battle/result_win.png");
    handl_res_lose = LoadGraph("image/battle/result_lose.png");
}

//-----------------------------------------------------------
// 描画
//-----------------------------------------------------------
void DrawBattle::draw()
{
    drawMap();             // マップ描画
    drawArea();            // エリア描画
    drawAreaGrid();        // エリアグリッド描画
    drawUnit();            // ユニット描画
    //drawAreaMp();        // エリア魔力描画
    drawSelectUnit();      // 選択中のユニット描画
    drawSelectMode();      // 選択モード中の描画
    draw_damage->draw();   // ダメージ描画
    drawClickSelectArea(); // クリック中の選択エリア
    drawUI();              // UI描画
    drawResult();          // 結果描画
}

//-----------------------------------------------------------
// マップ描画
//-----------------------------------------------------------
void DrawBattle::drawMap()
{
    MapData *map_data = battle_state->getMapData();
    int shift_pos_x = battle_state->getShiftPosX();
    int shift_pos_y = battle_state->getShiftPosY();

    for (int y = 0; y < map_data->map_size_height; y++) {
        for (int x = 0; x < map_data->map_size_width; x++) {
            int image = handl_map[1];
            if (map_data->map_data[y][x] == MapData::MAP_FLOOR) {
                image = handl_map[0];
            }
            int px = MapData::MAP_IMAGE_SIZE * x + shift_pos_x;
            int py = MapData::MAP_IMAGE_SIZE * y + shift_pos_y;

            DrawGraph(px, py, image, TRUE);
        }
    }
}

//-----------------------------------------------------------
// ユニット描画
//-----------------------------------------------------------
void DrawBattle::drawUnit()
{
    BattleMapState *map = battle_state->getMapState();
    BattleAllUnitState *unit = map->getUnitState();
    int px, py;
    int shift_pos_x = battle_state->getShiftPosX();
    int shift_pos_y = battle_state->getShiftPosY();

    //---- 自軍ユニット描画
    for (int i = 0; i < unit->getMyUnitNum(); i++) {
        BattleUnitState *state = unit->getMyUnit();
        px = state->getPixelX() + shift_pos_x;
        py = state->getPixelY() + shift_pos_y;
        int image = image_data->getMonster(state->getId(), state->getImage());
        if (state->getName() == "拠点") image = handl_base;
        DrawGraph(px, py, image, TRUE);
        drawHpBar(state);
    }
    //---- 敵軍ユニット描画
    for (int i = 0; i < unit->getEnUnitNum(); i++) {
        BattleUnitState *state = unit->getEnUnit();
        px = state->getPixelX() + shift_pos_x;
        py = state->getPixelY() + shift_pos_y;
        int image = image_data->getMonster(state->getId(), state->getImage());
        if (state->getName() == "拠点") image = handl_base;
        DrawGraph(px, py, image, TRUE);
        drawHpBar(state);
    }
}

//-----------------------------------------------------------
// エリア描画
//-----------------------------------------------------------
void DrawBattle::drawArea()
{
    BattleMapState *map_state = battle_state->getMapState();
    BattleAreaState *area_state = map_state->getAreaState();
    MapData *map_data = battle_state->getMapData();
    int shift_pos_x = battle_state->getShiftPosX();
    int shift_pos_y = battle_state->getShiftPosY();

    for (int y = 0; y < map_data->map_size_height; y++) {
        for (int x = 0; x < map_data->map_size_width; x++) {
            int px = x * MapData::MAP_IMAGE_SIZE + shift_pos_x;
            int py = y * MapData::MAP_IMAGE_SIZE + shift_pos_y;
            if (area_state->getAreaWho(x, y) == BattleAreaState::AREA_MY)
                DrawGraph(px, py, handl_area_my, TRUE);
            if (area_state->getAreaWho(x, y) == BattleAreaState::AREA_ENE)
                DrawGraph(px, py, handl_area_ene, TRUE);
        }
    }
}

//-----------------------------------------------------------
// エリアグリッド描画
//-----------------------------------------------------------
void DrawBattle::drawAreaGrid()
{
    if (battle_state->getNowSelectMode() == BattleState::BATTLE_SELECT_AREA ||
        battle_state->getNowTurn() == BattleState::TURN_CURD_USE) {
        MapData *map_data = battle_state->getMapData();
        int shift_pos_x = battle_state->getShiftPosX();
        int shift_pos_y = battle_state->getShiftPosY();

        for (int y = 0; y < map_data->map_size_height; y++) {
            for (int x = 0; x < map_data->map_size_width; x++) {
                int px = x * MapData::MAP_IMAGE_SIZE + shift_pos_x;
                int py = y * MapData::MAP_IMAGE_SIZE + shift_pos_y;
                DrawGraph(px, py, handl_area_grid, TRUE);
            }
        }
    }
}

//-----------------------------------------------------------
// エリア魔力描画
//-----------------------------------------------------------
void DrawBattle::drawAreaMp()
{
    int x = input_state->getPointX();
    int y = input_state->getPointY();
    int px = battle_state->changeMousePosX(x);
    int py = battle_state->changeMousePosY(y);
    if (battle_state->getMapData()->isFloor(px, py)) {
        int mx = px * MapData::MAP_IMAGE_SIZE + battle_state->getShiftPosX() + 10;
        int my = py * MapData::MAP_IMAGE_SIZE + battle_state->getShiftPosY() + 30;
        // 自軍魔力
        DrawFormatStringToHandle(mx, my, color_blue, font_12, "%d",
            battle_state->getMapState()->getAreaState()->getAreaMpMy(px, py));
        // 敵軍魔力
        DrawFormatStringToHandle(mx + 25, my, color_red, font_12, "%d",
            battle_state->getMapState()->getAreaState()->getAreaMpEn(px, py));
    }
}

//-----------------------------------------------------------
// 選択中のユニット描画
//-----------------------------------------------------------
void DrawBattle::drawSelectUnit()
{
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 120);
    for (int i = 0; i < battle_state->getSelectUnitNum(); i++) {
        BattleUnitState* unit = battle_state->getSelectUnit();
        drawUnitArea(unit);
    }
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
//-----------------------------------------------------------
// ユニットのエリア描画
//-----------------------------------------------------------
void DrawBattle::drawUnitArea(BattleUnitState* unit)
{
    drawUnitArea(unit, color_orange, TRUE);
}
void DrawBattle::drawUnitArea(BattleUnitState* unit, int color)
{
    drawUnitArea(unit, color, TRUE);
}
void DrawBattle::drawUnitArea(BattleUnitState* unit, int color, int flag)
{
    DrawBox(
        unit->getPixelX() + battle_state->getShiftPosX(),
        unit->getPixelY() + battle_state->getShiftPosY(),
        unit->getPixelX() + unit->getImageSizeX() + battle_state->getShiftPosX(),
        unit->getPixelY() + unit->getImageSizeY() + battle_state->getShiftPosY(),
        color, flag);
    // 中心線
    if (flag == FALSE) {
        // 横線
        DrawLine(
            unit->getPixelX() + battle_state->getShiftPosX(),
            unit->getPixelY() + battle_state->getShiftPosY() + unit->getImageSizeY() / 2,
            unit->getPixelX() + unit->getImageSizeX() + battle_state->getShiftPosX() - 1,
            unit->getPixelY() + battle_state->getShiftPosY() + unit->getImageSizeY() / 2,
            color, 1);
        // 縦線
        DrawLine(
            unit->getPixelX() + battle_state->getShiftPosX() + unit->getImageSizeX() / 2,
            unit->getPixelY() + battle_state->getShiftPosY(),
            unit->getPixelX() + battle_state->getShiftPosX() + unit->getImageSizeX() / 2,
            unit->getPixelY() + unit->getImageSizeY() + battle_state->getShiftPosY() - 1,
            color, 1);
    }
}
//-----------------------------------------------------------
// 選択中モード中の描画
//-----------------------------------------------------------
void DrawBattle::drawSelectMode()
{
    int mode = battle_state->getNowSelectMode();
    int mx = input_state->getPointX();
    int my = input_state->getPointY();
    int shift_pos_x = battle_state->getShiftPosX();
    int shift_pos_y = battle_state->getShiftPosY();
    BattleMapState *map = battle_state->getMapState();
    BattleAllUnitState *unit = map->getUnitState();

    //---- 領域選択モード
    if (mode == BattleState::BATTLE_SELECT_AREA) {
        int px = battle_state->changeMousePosX(mx);
        int py = battle_state->changeMousePosY(my);
        if (!battle_state->getMapData()->isFloor(px, py)) return;
        DrawGraph(
            MapData::MAP_IMAGE_SIZE * px + shift_pos_x,
            MapData::MAP_IMAGE_SIZE * py + shift_pos_y,
            handl_area_select, TRUE);
    }
    //---- 自軍選択モード
    if (mode == BattleState::BATTLE_SELECT_MYUNIT) {
        BattleUnitState *s = NULL;
        for (int i = 0; i < unit->getMyUnitNum(); i++) {
            BattleUnitState *state = unit->getMyUnit();
            int x = state->getPixelX() + shift_pos_x;
            int y = state->getPixelY() + shift_pos_y;
            if (mx > x && mx < x + state->getImageSizeX() && my > y && my < y + state->getImageSizeY()) {
                s = state;
            }
        }
        if (s != NULL) drawUnitArea(s, color_blue, FALSE);
    }
    //---- 敵軍選択モード
    if (mode == BattleState::BATTLE_SELECT_ENUNIT) {
        BattleUnitState *s = NULL;
        for (int i = 0; i < unit->getEnUnitNum(); i++) {
            BattleUnitState *state = unit->getEnUnit();
            int x = state->getPixelX() + shift_pos_x;
            int y = state->getPixelY() + shift_pos_y;
            if (mx > x && mx < x + state->getImageSizeX() && my > y && my < y + state->getImageSizeY()) {
                s = state;
            }
        }
        if (s != NULL) drawUnitArea(s, color_red, FALSE);
    }
}

//-----------------------------------------------------------
// 選択エリア描画
//-----------------------------------------------------------
void DrawBattle::drawSelectArea(int x, int y)
{
    if (!battle_state->getMapData()->isFloor(x, y)) return;
    CardData *card = game_data->getAllCardData()->getCardData(card_state->getSelectCard());
    if (battle_state->isPutUnitMy(card, x, y)) {
        for (int i = y; i < y + card->size_y; i++) {
            for (int j = x; j < x + card->size_x; j++) {
                int px = j * MapData::MAP_IMAGE_SIZE + battle_state->getShiftPosX();
                int py = i * MapData::MAP_IMAGE_SIZE + battle_state->getShiftPosY();
                if (battle_state->getMapData()->isFloor(j, i))
                DrawGraph(px, py, handl_area_select, TRUE);
            }
        }
    }
    else {
        for (int i = y; i < y + card->size_y; i++) {
            for (int j = x; j < x + card->size_x; j++) {
                int px = j * MapData::MAP_IMAGE_SIZE + battle_state->getShiftPosX();
                int py = i * MapData::MAP_IMAGE_SIZE + battle_state->getShiftPosY();
                if (battle_state->getMapData()->isFloor(j, i))
                    DrawGraph(px, py, handl_area_select2, TRUE);
            }
        }
    }
}

//-----------------------------------------------------------
// クリック中の選択エリア描画
//-----------------------------------------------------------
void DrawBattle::drawClickSelectArea()
{
    if (!battle_state->isLeftClickNow()) return;
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
    DrawBox(
        battle_state->getClickFirstPosX() + battle_state->getShiftPosX(),
        battle_state->getClickFirstPosY() + battle_state->getShiftPosY(),
        battle_state->getClickNowPosX() + battle_state->getShiftPosX(),
        battle_state->getClickNowPosY() + battle_state->getShiftPosY(),
        color_blue, TRUE);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    DrawBox(
        battle_state->getClickFirstPosX() + battle_state->getShiftPosX(),
        battle_state->getClickFirstPosY() + battle_state->getShiftPosY(),
        battle_state->getClickNowPosX() + battle_state->getShiftPosX(),
        battle_state->getClickNowPosY() + battle_state->getShiftPosY(),
        color_blue, FALSE);
}

//-----------------------------------------------------------
// UI描画
//-----------------------------------------------------------
void DrawBattle::drawUI()
{
    //---- UI描画
    int mx = input_state->getPointX();
    int my = input_state->getPointY();
    int px = battle_state->changeMousePosX(mx);
    int py = battle_state->changeMousePosY(my);
    int y = (battle_state->getNowTurn() == BattleState::TURN_BATTLE) ? 30 : 0;
    DrawGraph(0, SystemData::getWindowHeight() - 120 + y, handl_ui_card_back, TRUE);
    DrawGraph(675, SystemData::getWindowHeight() - 118 + y, handl_ui_mp_back, TRUE);
    DrawFormatString(730, 484 + y, color_white, "%d", battle_state->getMyMp()); // MP表示
    drawTimeBar();       // タイムゲージ描画

    //---- 対戦ターン
    if (battle_state->getNowTurn() == BattleState::TURN_BATTLE) {
        // 命令ボタン
        int com = battle_state->getSelectUnitCom();
        for (int i = 0; i < 7; i++) {
            int t = (battle_state->getSelectUnitNum() && !battle_state->isLeftClickNow()) ? 0 : 7;
            if (com >= BattleUnitState::COM_SPE_MOVE) t = 7;
            if (i == BattleUnitState::COM_SPE_MOVE && com == BattleUnitState::COM_SPE_MOVE) t = 0;
            if (i == BattleUnitState::COM_SPE_ATTACK && com == BattleUnitState::COM_SPE_ATTACK) t = 0;
            if (i == BattleUnitState::COM_SPE_DEFENSE && com == BattleUnitState::COM_SPE_DEFENSE) t = 0;
            DrawGraph(i * 70 + 21, 535, hand_com_button[i + t], TRUE);
        }
    }
    //---- カード選択ターン
    if (battle_state->getNowTurn() == BattleState::TURN_CURD_SELECT) {
        drawHandCard();      // 手札描画
        for (int i = 0; i < card_state->getMyHandNum(); i++) {  // カード説明
            if (mx < 21 + i * 70 || mx > 21 + i * 70 + 60 || my < 510 || my > 595) continue;
            drawCardIntro(game_data->getAllCardData()->getCardData(card_state->getMyHand(i)));
        }
        DrawGraph(BattleState::BUTTON_CANCEL_TOP_X, BattleState::BUTTON_CANCEL_TOP_Y, handl_ui_button_cancel, TRUE);
        DrawGraph(BattleState::BUTTON_END_TOP_X, BattleState::BUTTON_END_TOP_Y, handl_ui_button_end, TRUE);
    }
    //---- カード使用ターン
    if (battle_state->getNowTurn() == BattleState::TURN_CURD_USE) {
        drawSelectArea(px, py);   // 選択エリア描画
        int card = card_state->getSelectCard();   // 選択ユニット取得
        CardData *c_data = game_data->getAllCardData()->getCardData(card);
        DrawGraph(mx - c_data->image_size_x / 2, my - c_data->image_size_y / 2, image_data->getMonster(card, 8), TRUE);   // 選択ユニット描画
        DrawGraph(BattleState::BUTTON_CANCEL_TOP_X, BattleState::BUTTON_CANCEL_TOP_Y, handl_ui_button_cancel, TRUE);
    }
}

//-----------------------------------------------------------
// HPゲージ描画
//-----------------------------------------------------------
void DrawBattle::drawHpBar(BattleUnitState* unit)
{
    // 値算出
    int shift_pos_x = battle_state->getShiftPosX();
    int shift_pos_y = battle_state->getShiftPosY();
    int px = unit->getPixelX() + shift_pos_x;
    int py = unit->getPixelY() + shift_pos_y;
    int hp = (int)((double)unit->getHp() / unit->getMaxHp() * (unit->getImageSizeX() - 10));

    // ゲージ描画
    int x1 = px + 5;
    int y1 = py + unit->getImageSizeY() - 10;
    int x2 = x1 + (unit->getImageSizeX() - 10);
    int y2 = y1 + 5;
    DrawBox(x1, y1, x2, y2, color_gray, TRUE);
    DrawBox(x1, y1, x1 + hp, y2, (unit->getWhich()) ? color_red : color_blue, TRUE);
    DrawBox(x1, y1, x2, y2, color_black, FALSE);
}

//-----------------------------------------------------------
// 手札描画
//-----------------------------------------------------------
void DrawBattle::drawHandCard()
{
    if (battle_state->getNowTurn() == BattleState::TURN_CURD_SELECT) {
        BattleCardState *card = battle_state->getCardState();
        for (int i = 0; i < card->getMyHandNum(); i++) {
            DrawGraph(i * 70 + 21, 510, image_data->getCard(card->getMyHand(i)), TRUE);
        }
    }
}

//-----------------------------------------------------------
// タイムゲージ描画
//-----------------------------------------------------------
void DrawBattle::drawTimeBar()
{
    int gauge_size = 640;
    int x = 21;
    int y = SystemData::getWindowHeight() - 113;
    y += (battle_state->getNowTurn() == BattleState::TURN_BATTLE) ? 30 : 0;
    double rate = (double)battle_state->getNowTimeCnt() / BattleState::TURN_TIME;
    int gauge = x + (int)(gauge_size * rate);

    DrawBox(x, y, x + gauge_size, y + 10, color_gray, TRUE);
    DrawBox(x, y, gauge, y + 10, color_green, TRUE);
    DrawBox(x, y, x + gauge_size, y + 10, color_black, FALSE);
}

//-----------------------------------------------------------
// カード説明描画
//-----------------------------------------------------------
void DrawBattle::drawCardIntro(CardData* card)
{
    int x = 0;   // カード説明画像の位置
    int y = 0;   // カード説明画像の位置
    
    // カード説明画像
    DrawGraph(x, y, handl_ui_card_intro, TRUE);
    // イラスト
    DrawGraph(x + 43 - card->image_size_x / 2, y + 60 - card->image_size_y / 2, image_data->getMonster(card->id, 8), TRUE);
    // 名前
    DrawFormatStringToHandle(x + 92, y + 28, color_black, font_12, "%s", card->name.c_str(), font_12);
    // 種類
    // 属性
    //---- 魔力
    int t = (card->mp / 10 <= 0) ? 0 : -3;
    DrawFormatStringToHandle(x + 202 + t, y + 73, color_black, font_12, "%d", card->mp);
    // 攻撃力
    DrawFormatStringToHandle(x + 58, y + 136, color_black, font_12, "%d", card->pow);
    // 守備力
    DrawFormatStringToHandle(x + 172, y + 136, color_black, font_12, "%d", card->def);
    // 移動速度
    DrawFormatStringToHandle(x + 58, y + 165, color_black, font_12, "%d", card->move_speed);
    // 攻撃速度
    DrawFormatStringToHandle(x + 172, y + 165, color_black, font_12, "%d", card->attack_speed);
    // 索敵範囲
    DrawFormatStringToHandle(x + 58, y + 194, color_black, font_12, "%d", card->search_range);
    // 体力
    DrawFormatStringToHandle(x + 172, y + 194, color_black, font_12, "%d", card->hp);
    //---- 属性
    DrawFormatStringToHandle(x + 40, y + 247, color_black, font_12, "%d", card->fire);
    DrawFormatStringToHandle(x + 117, y + 247, color_black, font_12, "%d", card->water);
    DrawFormatStringToHandle(x + 194, y + 247, color_black, font_12, "%d", card->ice);
    DrawFormatStringToHandle(x + 40, y + 266, color_black, font_12, "%d", card->elect);
    DrawFormatStringToHandle(x + 117, y + 266, color_black, font_12, "%d", card->dark);
    DrawFormatStringToHandle(x + 194, y + 266, color_black, font_12, "%d", card->light);
    DrawFormatStringToHandle(x + 40, y + 285, color_black, font_12, "%d", card->earth);
    DrawFormatStringToHandle(x + 117, y + 285, color_black, font_12, "%d", card->poison);
    DrawFormatStringToHandle(x + 194, y + 285, color_black, font_12, "%d", card->wind);
    //---- スキル
    for (int i = 0; i < (int)card->skil.size(); i++) {
        int n = card->skil[i];
        DrawFormatStringToHandle(x + 28, y + 338 + i * 38, color_black, font_10,
            "%s", game_data->getSkillData()->getSkillText1(n).c_str());
        DrawFormatStringToHandle(x + 28, y + 351 + i * 38, color_black, font_10,
            "%s", game_data->getSkillData()->getSkillText2(n).c_str());
    }
}

//-----------------------------------------------------------
// 対戦結果描画
//-----------------------------------------------------------
void DrawBattle::drawResult()
{
    if (battle_state->getNowTurn() != BattleState::TURN_END) return;
    //---- プレイヤー勝利
    if (battle_state->getWinner() == BattleState::PLAYER) {
        DrawGraph(0, 0, handl_res_win, TRUE);
    }
    //---- プレイヤー敗北
    if (battle_state->getWinner() == BattleState::ENEMY) {
        DrawGraph(0, 0, handl_res_lose, TRUE);
    }

}
//===========================================================
// getter
//===========================================================

