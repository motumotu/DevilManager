//-----------------------------------------------------------
// DrawBattleSelect.cpp
// デッキ一覧画面の描画
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#include "DrawBattleSelect.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
DrawBattleSelect::DrawBattleSelect(GameData *data, GameState *state)
{
    game_data = data;
    game_state = state;
    battle_select_state = state->getSceneState()->getBattleSelectState();
    input_state = state->getInputState();
    image_data = data->getImageData();
    save_data = data->getSaveData();

    font = CreateFontToHandle("PixelMplus12", 12, 1, DX_FONTTYPE_NORMAL);
    color_black = GetColor(0, 0, 0);
    loadImage();
    init();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
DrawBattleSelect::~DrawBattleSelect()
{
    DeleteFontToHandle(font);
}

//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void DrawBattleSelect::init()
{
}

//-----------------------------------------------------------
// 更新
//-----------------------------------------------------------
void DrawBattleSelect::update()
{
}

//-----------------------------------------------------------
// 画像読み込み
//-----------------------------------------------------------
void DrawBattleSelect::loadImage()
{
    handl_back = LoadGraph("image/battle_select/back.png");
    handl_back_1 = LoadGraph("image/battle_select/back_1.png");
    handl_back_2 = LoadGraph("image/battle_select/back_2.png");
    LoadDivGraph("image/battle_select/button_back.png", 2, 1, 2,
        BattleSelectData::BUTTON_BACK_SIZE_X, BattleSelectData::BUTTON_BACK_SIZE_Y, handl_button_back);
    LoadDivGraph("image/battle_select/button_battle.png", 2, 1, 2,
        BattleSelectData::BUTTON_BATTLE_SIZE_X, BattleSelectData::BUTTON_BATTLE_SIZE_Y, handl_button_battle);
    handl_select = LoadGraph("image/battle_select/select.png");
    handl_select_now = LoadGraph("image/battle_select/select_now.png");
    handl_chara[1] = LoadGraph("image/battle_select/chara1.png");
    handl_lank = LoadGraph("image/battle_select/lank.png");
    LoadDivGraph("image/battle_select/select_left.png", 2, 1, 2,
        BattleSelectData::DECK_SELECT_SIZE_X, BattleSelectData::DECK_SELECT_SIZE_Y, handl_select_left);
    LoadDivGraph("image/battle_select/select_right.png", 2, 1, 2,
        BattleSelectData::DECK_SELECT_SIZE_X, BattleSelectData::DECK_SELECT_SIZE_Y, handl_select_right);
    handl_bar = LoadGraph("image/battle_select/bar.png");
}

//-----------------------------------------------------------
// 描画
//-----------------------------------------------------------
void DrawBattleSelect::draw()
{
    DrawGraph(0, 0, handl_back, TRUE);
    drawAllOpponent();   // 対戦相手描画
    //---- 選択中の相手情報描画
    drawOpponent(battle_select_state->getSelectNum(), 1); // 対戦キャラ描画
    drawEnemyDeck();    // デッキ描画
    drawBattleData();   // 対戦データ描画
    //---- 自分情報描画
    drawMyDeck();       // デッキ描画
    drawDeckSelect();   // デッキ選択→描画
    //
    DrawGraph(0, 0, handl_back_1, TRUE);
    DrawGraph(0, 545, handl_back_2, TRUE);
    // ボタン描画
    drawButton();
    // スクロールバー描画
    drawBar();
}

//-----------------------------------------------------------
// 対戦相手描画
//-----------------------------------------------------------
void DrawBattleSelect::drawAllOpponent()
{
    for (int n = 1; n <= game_data->getAllBattleData()->getBattleDataNum(); n++) {
        drawOpponent(n, 0);
    }
}
void DrawBattleSelect::drawOpponent(int n, int flag)
{
    BattleData *battle_data = game_data->getAllBattleData()->getBattleData(n);
    int x = BattleSelectData::SELECT_AREA_POS_X + 5;
    int y = BattleSelectData::SELECT_AREA_POS_Y + 5 + (n - 1) * (BattleSelectData::SELECT_SIZE_Y + 5);
    y -= battle_select_state->getShiftPosY();
    if (flag) {
        x = BattleSelectData::ENEMY_INFO_POS_X;
        y = BattleSelectData::ENEMY_INFO_POS_Y;
    }
    int level = battle_data->getRank();
    DrawGraph(x, y, handl_select, TRUE);             // ベース
    DrawGraph(x + 4, y + 3, handl_chara[1], TRUE);   // キャラ画像
    // 敵ランク
    for (int i = 0; i < level; i++) {
        DrawGraph(x + 260 - i * 12, y + 47, handl_lank, TRUE);
    }
    DrawFormatStringToHandle(x + 83, y + 15, color_black, font, "%s",
        battle_data->getName().c_str());
    // 選択中か
    if (flag == 0 && n == battle_select_state->getSelectNum()) {
        DrawGraph(x, y, handl_select_now, TRUE);
    }
}

//-----------------------------------------------------------
// デッキ描画
//-----------------------------------------------------------
void DrawBattleSelect::drawEnemyDeck()
{
    int x = BattleSelectData::ENEMY_INFO_POS_X;
    int y = BattleSelectData::ENEMY_INFO_POS_Y + BattleSelectData::SELECT_SIZE_Y + 10;
    int n = battle_select_state->getSelectNum();
    BattleData *battle_data = game_data->getAllBattleData()->getBattleData(n);
    int card = battle_data->getDeckData()->getCard(0);

    DrawGraph(x, y + 5, image_data->getCardMini(card), TRUE);  // カード描画
    DrawFormatStringToHandle(x + 48, y + 17, color_black, font, "%s", // デッキ名
        battle_data->getDeckData()->getDeckName().c_str());
}

//-----------------------------------------------------------
// 対戦データ描画
//-----------------------------------------------------------
void DrawBattleSelect::drawBattleData()
{
    int x = BattleSelectData::ENEMY_INFO_POS_X;
    int y = BattleSelectData::ENEMY_INFO_POS_Y + BattleSelectData::SELECT_SIZE_Y + 10;
    DrawFormatStringToHandle(x, y + 70, color_black, font, "最高スコア %d",
        0);
    DrawFormatStringToHandle(x, y + 90, color_black, font, "勝利回数  %d",
        0);
}

//-----------------------------------------------------------
// 自分のデッキ描画
//-----------------------------------------------------------
void DrawBattleSelect::drawMyDeck()
{
    int x = BattleSelectData::MY_INFO_POS_X;
    int y = BattleSelectData::MY_INFO_POS_Y + 10;
    DeckData *deck = save_data->getDeckData(battle_select_state->getMyDeckNum());
    int card = deck->getCard(0);

    DrawGraph(x, y + 5, image_data->getCardMini(card), TRUE);  // カード描画
    DrawFormatStringToHandle(x + 48, y + 17, color_black, font, "%s", // デッキ名
        deck->getDeckName().c_str());
}

//-----------------------------------------------------------
// デッキ選択の描画
//-----------------------------------------------------------
void DrawBattleSelect::drawDeckSelect()
{
    int mx = input_state->getPointX();
    int my = input_state->getPointY();
    // 左
    int image = (battle_select_state->isPosDeckSelectLeft(mx, my)) ? 1 : 0;
    DrawGraph(
        BattleSelectData::DECK_SELECT_LEFT_POS_X,
        BattleSelectData::DECK_SELECT_LEFT_POS_Y,
        handl_select_left[image], TRUE);
    // 右
    image = (battle_select_state->isPosDeckSelectRight(mx, my)) ? 1 : 0;
    DrawGraph(
        BattleSelectData::DECK_SELECT_RIGHT_POS_X,
        BattleSelectData::DECK_SELECT_RIGHT_POS_Y,
        handl_select_right[image], TRUE);
}

//-----------------------------------------------------------
// スクロールバー描画
//-----------------------------------------------------------
void DrawBattleSelect::drawBar()
{
    int x = BattleSelectData::BAR_POS_X;
    int y = battle_select_state->getBarPos();
    DrawGraph(x, y, handl_bar, TRUE);
}

//-----------------------------------------------------------
// ボタン描画
//-----------------------------------------------------------
void DrawBattleSelect::drawButton()
{
    int mx = input_state->getPointX();
    int my = input_state->getPointY();

    DrawGraph(
        BattleSelectData::BUTTON_BACK_POS_X,
        BattleSelectData::BUTTON_BACK_POS_Y,
        handl_button_back[((battle_select_state->isPosButtonBack(mx, my)) ? 1 : 0)],
        TRUE);
    DrawGraph(
        BattleSelectData::BUTTON_BATTLE_POS_X,
        BattleSelectData::BUTTON_BATTLE_POS_Y,
        handl_button_battle[((battle_select_state->isPosButtonBattle(mx, my)) ? 1 : 0)],
        TRUE);
}

//===========================================================
// getter
//===========================================================
