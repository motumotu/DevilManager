//-----------------------------------------------------------
// BattleState.cpp
// 対戦画面の状態
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#include "BattleState.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
BattleState::BattleState(GameData* _game_data)
{
    game_data = _game_data;
    map_state = new BattleMapState(game_data);
    card_state = new BattleCardState();
    init();     // 初期処理
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
BattleState::~BattleState()
{
    delete(card_state);
    delete(map_state);
}

//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void BattleState::init()
{
    now_turn = TURN_CURD_SELECT;    // カード選択ターン
    now_battle_select_mode = BATTLE_SELECT_NORMAL;
    select_unit_com = -1;
    player_pos_x = -1;         // プレイヤーの座標x
    player_pos_y = -1;         // プレイヤーの座標y
    shift_pos_x = 0;           // ずらす座標x
    shift_pos_y = 0;           // ずらす座標y
    time_cnt = TURN_TIME;      // バトル残り時間
    my_mp = INIT_MP;           // 自分魔力
    en_mp = INIT_MP;           // 敵魔力
    mouse_on_unit = NULL;      // カーソルが乗ってるユニット
    winner = -1;               // 勝利者
}

//-----------------------------------------------------------
// 対戦情報初期化
//-----------------------------------------------------------
void BattleState::battleInit()
{
    now_turn = TURN_CURD_SELECT;    // カード選択ターン
    now_battle_select_mode = BATTLE_SELECT_NORMAL; // 選択モード
    select_unit_com = -1;      // 選択中のコマンド
    player_pos_x = -1;         // プレイヤーの座標x
    player_pos_y = -1;         // プレイヤーの座標y
    shift_pos_x = 0;           // ずらす座標x
    shift_pos_y = 0;           // ずらす座標y
    time_cnt = TURN_TIME;      // バトル残り時間
    my_mp = INIT_MP;           // 自分魔力
    en_mp = INIT_MP;           // 敵魔力
    while (!select_unit.empty()) select_unit.pop();
    mouse_on_unit = NULL;      // カーソルが乗ってるユニット
    winner = -1;               // 勝利者

    map_state->battleInit();   // マップ情報初期化
    card_state->battleInit();  // カード情報初期化
}

//-----------------------------------------------------------
// 対戦設定
//-----------------------------------------------------------
void BattleState::battleSetting()
{
    setInitShiftPos();
    map_state->battleSetting();
    card_state->battleSetting();
}

//-----------------------------------------------------------
// 更新
//-----------------------------------------------------------
void BattleState::update()
{
    card_state->update();

    //---- 対戦ターン
    if (now_turn == TURN_BATTLE) {
        map_state->update();
        if (--time_cnt <= 0) {
            changeCardSelectTurn();
        }
        checkEnd();    // 終了判定
    }
    //---- カード選択ターン
    else if (now_turn == TURN_CURD_SELECT) {

    }
    //---- カード使用ターン
    else if (now_turn == TURN_CURD_USE) {

    }
}

//-----------------------------------------------------------
// カード使用ターンに移行
//-----------------------------------------------------------
void BattleState::changeCardSelectTurn()
{
    card_state->drawCardMy();    // カードを引く
    card_state->drawCardMy();    // カードを引く
    card_state->drawCardEn();    // カードを引く
    card_state->drawCardEn();    // カードを引く
    my_mp += ONETURN_MP;         // 魔力プラス
    en_mp += ONETURN_MP;         // 魔力プラス
    now_turn = TURN_CURD_SELECT; // ターン変更
    time_cnt = 0;                // 時間
    deselectUnit();              // ユニット選択解除
    left_click_now = 0;          // クリック中か
    click_first_pos_x = 0;       // クリック初期位置x
    click_first_pos_y = 0;       // クリック初期位置y
    click_now_pos_x = 0;         // クリック終了位置x
    click_now_pos_y = 0;         // クリック終了位置y
    select_unit_com = -1;
}

//-----------------------------------------------------------
// マウス座標更新
//-----------------------------------------------------------
void BattleState::updateMousePos(int x, int y)
{
    int px = changeMousePosX(x);
    int py = changeMousePosY(y);
    player_pos_x = -1;
    player_pos_y = -1;
    if (getMapData()->outCheck(px, py)) return;
    if (getMapData()->map_data[py][px] == MapData::MAP_FLOOR) {
        player_pos_x = px;
        player_pos_y = py;
    }
}

//-----------------------------------------------------------
// 座標変更
//-----------------------------------------------------------
void BattleState::moveShiftPos(int dire, int movement)
{
    int dx[] = { 0, -1, 0, 1 };
    int dy[] = { 1, 0, -1, 0 };
    shift_pos_x += dx[dire] * movement;
    shift_pos_y += dy[dire] * movement;
}

//-----------------------------------------------------------
// 指定座標にずらす
//-----------------------------------------------------------
void BattleState::setShiftPos(int x, int y)
{
    shift_pos_x = SystemData::getWindowWidth() / 2;
    shift_pos_y = SystemData::getWindowHeight() / 2;
    shift_pos_x -= x * MapData::MAP_IMAGE_SIZE;
    shift_pos_y -= y * MapData::MAP_IMAGE_SIZE;
    shift_pos_x -= MapData::MAP_IMAGE_SIZE / 2;
    shift_pos_y -= MapData::MAP_IMAGE_SIZE / 2;
}
void BattleState::setInitShiftPos()
{
    setShiftPos(
        getMapData()->player_base_x,
        getMapData()->player_base_y);
}

//-----------------------------------------------------------
// マウス座標をマップ座標に変換
//-----------------------------------------------------------
int BattleState::changeMousePosX(int x) {
    return (x - shift_pos_x) / MapData::MAP_IMAGE_SIZE;
}
int BattleState::changeMousePosY(int y) {
    return (y - shift_pos_y) / MapData::MAP_IMAGE_SIZE;
}

//-----------------------------------------------------------
// マップデータ設定
//-----------------------------------------------------------
void BattleState::setMapData(MapData* data)
{
    map_state->setMapData(data);
}

//-----------------------------------------------------------
// カード選択
//-----------------------------------------------------------
void BattleState::selectCard(int n)
{
    card_state->selectHandCardMy(n);
    now_turn = TURN_CURD_USE;
}

//-----------------------------------------------------------
// キャンセルボタン選択
//-----------------------------------------------------------
void BattleState::selectCancelButton()
{
    puts("キャンセルしました");
}

//-----------------------------------------------------------
// 終了ボタン選択
//-----------------------------------------------------------
void BattleState::selectEndButton()
{
    now_turn = TURN_BATTLE;  // 対戦モードに移行
    now_battle_select_mode = BATTLE_SELECT_NORMAL;  // 通常選択モード
    time_cnt = TURN_TIME;    // 時間設定
}

//-----------------------------------------------------------
// ユニット設置
//-----------------------------------------------------------
void BattleState::putUnit()
{
    now_turn = TURN_CURD_SELECT;
}

//-----------------------------------------------------------
// 魔力使用
// 使用：true、不使用：false
//-----------------------------------------------------------
bool BattleState::useMyMp(int mp)
{
    if (mp > my_mp) {
        return false;
    }
    my_mp -= mp;
    return true;
}
bool BattleState::useEnMp(int mp)
{
    if (mp > en_mp) {
        return false;
    }
    en_mp -= mp;
    return true;
}

//-----------------------------------------------------------
// 最初の左クリック
//-----------------------------------------------------------
void BattleState::firstLeftClick(int x, int y)
{
    BattleAllUnitState *unit = getMapState()->getUnitState();

    //---- 通常選択モード時
    if (now_battle_select_mode == BATTLE_SELECT_NORMAL) {
        click_first_pos_x = x - shift_pos_x;
        click_first_pos_y = y - shift_pos_y;
        click_now_pos_x = x - shift_pos_x;
        click_now_pos_y = y - shift_pos_y;
        left_click_now = 1;
        updateSelectUnit();
    }
    //---- エリア選択モード時
    else if (now_battle_select_mode == BATTLE_SELECT_AREA) {
        // エリア取得
        int px = changeMousePosX(x);
        int py = changeMousePosY(y);
        if (getMapData()->isFloor(px, py)) {
            commandSelectUnit(select_unit_com, px, py);
            deselectUnit();
        }
    }
    //---- 自軍ユニット選択モード
    else if (now_battle_select_mode == BATTLE_SELECT_MYUNIT) {
        for (int i = 0; i < unit->getMyUnitNum(); i++) {
            BattleUnitState *state = unit->getMyUnit();
            if (x > state->getPixelX() + shift_pos_x && x < state->getPixelX() + state->getImageSizeX() + shift_pos_x &&
                y > state->getPixelY() + shift_pos_y && y < state->getPixelY() + state->getImageSizeY() + shift_pos_y) {
                commandSelectUnit(select_unit_com, state);
                deselectUnit();
            }
        }
    }
    //---- 敵軍ユニット選択モード
    else if (now_battle_select_mode == BATTLE_SELECT_ENUNIT) {
        for (int i = 0; i < unit->getEnUnitNum(); i++) {
            BattleUnitState *state = unit->getEnUnit();
            if (x > state->getPixelX() + shift_pos_x && x < state->getPixelX() + state->getImageSizeX() + shift_pos_x&&
                y > state->getPixelY() + shift_pos_y && y < state->getPixelY() + state->getImageSizeY() + shift_pos_y) {
                commandSelectUnit(select_unit_com, state);
                deselectUnit();
            }
        }
    }
}

//-----------------------------------------------------------
// 左クリック中
//-----------------------------------------------------------
void BattleState::nowLeftClick(int x, int y)
{
    if (left_click_now) {
        click_now_pos_x = x - shift_pos_x;
        click_now_pos_y = y - shift_pos_y;
        updateSelectUnit();
    }
}

//-----------------------------------------------------------
// 左クリックの最後
//-----------------------------------------------------------
void BattleState::endLeftClick(int x, int y)
{
    if (left_click_now) {
        updateSelectUnit();
    }
    left_click_now = 0;
    click_first_pos_x = -10000;
    click_first_pos_y = -10000;
    click_now_pos_x = -10000;
    click_now_pos_y = -10000;
}

//-----------------------------------------------------------
// 選択ユニット更新
//-----------------------------------------------------------
void BattleState::updateSelectUnit()
{
    deselectUnit();
    BattleAllUnitState *unit = getMapState()->getUnitState();
    for (int i = 0; i < unit->getMyUnitNum(); i++) {
        BattleUnitState *state = unit->getMyUnit();
        int ax1 = click_first_pos_x;
        int ay1 = click_first_pos_y;
        int ax2 = click_now_pos_x;
        int ay2 = click_now_pos_y;
        if (ay1 > ay2) std::swap(ay1, ay2);
        if (ax1 > ax2) std::swap(ax1, ax2);
        int bx1 = state->getPixelX();
        int by1 = state->getPixelY();
        int bx2 = state->getPixelX() + state->getImageSizeX();
        int by2 = state->getPixelY() + state->getImageSizeY();
        if (Algo::crossTwoSquare(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2)) {
            select_unit.push(state);
        }
    }
}

//-----------------------------------------------------------
// ユニット選択解除
//-----------------------------------------------------------
void BattleState::deselectUnit()
{
    while (!select_unit.empty()) select_unit.pop();
}

//-----------------------------------------------------------
// 選択中のユニットに対し命令
//-----------------------------------------------------------
void BattleState::commandSelectUnit(int com)
{
    for (int i = 0; i < (int)select_unit.size(); i++) {
        BattleUnitState *unit = select_unit.front();
        unit->setNowCommand(com);
        select_unit.pop();
        select_unit.push(unit);
    }
    changeSelectMode(BATTLE_SELECT_NORMAL);  // 通常選択モードに直す
    select_unit_com = -1;
}
void BattleState::commandSelectUnit(int com, int x, int y)
{
    for (int i = 0; i < (int)select_unit.size(); i++) {
        BattleUnitState *unit = select_unit.front();
        unit->setMovePos(x, y);
        unit->setNowCommand(com);
        select_unit.pop();
        select_unit.push(unit);
    }
    changeSelectMode(BATTLE_SELECT_NORMAL);  // 通常選択モードに直す
    select_unit_com = -1;
}
void BattleState::commandSelectUnit(int com, BattleUnitState* u)
{
    for (int i = 0; i < (int)select_unit.size(); i++) {
        BattleUnitState *unit = select_unit.front();
        if (com == BattleUnitState::COM_SPE_ATTACK)
            unit->setAttackUnit(u);
        if (com == BattleUnitState::COM_SPE_DEFENSE)
            unit->setDefenseUnit(u);
        unit->setNowCommand(com);
        select_unit.pop();
        select_unit.push(unit);
    }
    changeSelectMode(BATTLE_SELECT_NORMAL);  // 通常選択モードに直す
    select_unit_com = -1;
}

//-----------------------------------------------------------
// 選択モード変更
//-----------------------------------------------------------
void BattleState::changeSelectMode(int mode)
{
    now_battle_select_mode = mode;
}

//-----------------------------------------------------------
// ユニットに対する命令セット
//-----------------------------------------------------------
void BattleState::setSelectUnitCom(int com)
{
    if (select_unit.size() == 0) return;
    select_unit_com = com;
    // 指定移動
    if (com == BattleUnitState::COM_SPE_MOVE) {
        changeSelectMode(BattleState::BATTLE_SELECT_AREA);
    }
    // 指定攻撃
    else if (com == BattleUnitState::COM_SPE_ATTACK) {
        changeSelectMode(BattleState::BATTLE_SELECT_ENUNIT);
    }
    // 指定防御
    else if (com == BattleUnitState::COM_SPE_DEFENSE) {
        changeSelectMode(BattleState::BATTLE_SELECT_MYUNIT);
    }
    // 待機・自由・攻撃・防御
    else {
        commandSelectUnit(select_unit_com);
        deselectUnit();
    }
}

//-----------------------------------------------------------
// ユニットを置けるか
//-----------------------------------------------------------
bool BattleState::isPutUnitMy(CardData* card, int x, int y)
{
    if (card->mp > my_mp) return false;
    for (int py = y; py < y + card->size_y; py++) {
        for (int px = x; px < x + card->size_x; px++) {
            if (map_state->isUnit(px, py)) return false;
            if (!map_state->getMapData()->isFloor(px, py)) return false;
            if (map_state->getAreaState()->getAreaWho(px, py) != BattleAreaState::AREA_MY) return false;
        }
    }
    return true;
}

//-----------------------------------------------------------
// ユニットに対する命令セット
//-----------------------------------------------------------
bool BattleState::isPutUnitEn(CardData* card, int x, int y)
{
    if (card->mp > en_mp) return false;
    for (int py = y; py < y + card->size_y; py++) {
        for (int px = x; px < x + card->size_x; px++) {
            if (map_state->isUnit(px, py)) return false;
            if (!map_state->getMapData()->isFloor(px, py)) return false;
            if (map_state->getAreaState()->getAreaWho(px, py) != BattleAreaState::AREA_ENE) return false;
        }
    }
    return true;
}

//-----------------------------------------------------------
// 自軍ユニット生成
//-----------------------------------------------------------
void BattleState::createUnitMy(CardData* card, int x, int y)
{
    useMyMp(card->mp);                    // 魔力使用
    map_state->createMyUnit(card, x, y);  // マップに設置
}

//-----------------------------------------------------------
// 敵軍ユニット生成
//-----------------------------------------------------------
void BattleState::createUnitEn(CardData* card, int x, int y)
{
    useEnMp(card->mp);                    // 魔力使用
    map_state->createEnUnit(card, x, y);  // マップに設置
}

//-----------------------------------------------------------
// マウスが乗ってるユニット更新
//-----------------------------------------------------------
void BattleState::updateMouseOnUnit(int x, int y)
{
    mouse_on_unit = NULL;
    BattleAllUnitState *unit = getMapState()->getUnitState();

    //---- 自軍
    for (int i = 0; i < unit->getMyUnitNum(); i++) {
        BattleUnitState *state = unit->getMyUnit();
        if (x >= state->getX() && x <= state->getX() + state->getImageSizeX() &&
            y >= state->getY() && y <= state->getY() + state->getImageSizeY()) {
            mouse_on_unit = state;
        }
    }
    //---- 敵軍
    for (int i = 0; i < unit->getEnUnitNum(); i++) {
        BattleUnitState *state = unit->getEnUnit();
        if (x >= state->getX() && x <= state->getX() + state->getImageSizeX() &&
            y >= state->getY() && y <= state->getY() + state->getImageSizeY()) {
            mouse_on_unit = state;
        }
    }
}

//-----------------------------------------------------------
// 終了判定
//-----------------------------------------------------------
void BattleState::checkEnd()
{
    BattleAllUnitState *unit = map_state->getUnitState();
    int px = getMapData()->player_base_x;
    int py = getMapData()->player_base_y;
    int ex = getMapData()->enemy_base_x;
    int ey = getMapData()->enemy_base_y;

    // プレイヤー勝利
    if (unit->getUnit(ex, ey) == NULL) {
        now_turn = TURN_END;
        winner = PLAYER;
    }
    // プレイヤー敗北
    if (unit->getUnit(px, py) == NULL) {
        now_turn = TURN_END;
        winner = ENEMY;
    }
}

//===========================================================
// getter
//===========================================================
BattleMapState *BattleState::getMapState() { return map_state; }
BattleCardState *BattleState::getCardState() { return card_state; }
MapData *BattleState::getMapData() { return map_state->getMapData(); }
int BattleState::getSelectUnitNum() { return (int)select_unit.size(); }
BattleUnitState* BattleState::getSelectUnit() {
    BattleUnitState* unit = select_unit.front();
    select_unit.pop();
    select_unit.push(unit);
    return unit;
}
int BattleState::getPlayerPosX() { return player_pos_x; }
int BattleState::getPlayerPosY() { return player_pos_y; }
int BattleState::getShiftPosX() { return shift_pos_x; }
int BattleState::getShiftPosY() { return shift_pos_y; }
int BattleState::getNowTurn() { return now_turn; }
int BattleState::getNowTimeCnt() { return time_cnt; }
int BattleState::getMyMp() { return my_mp; }
int BattleState::getEnMp() { return en_mp; }
bool BattleState::isLeftClickNow() { return (left_click_now) ? true : false; }
int BattleState::getClickFirstPosX() { return click_first_pos_x; }
int BattleState::getClickFirstPosY() { return click_first_pos_y; }
int BattleState::getClickNowPosX() { return click_now_pos_x; }
int BattleState::getClickNowPosY() { return click_now_pos_y; }
int BattleState::getNowSelectMode() { return now_battle_select_mode; }
int BattleState::getSelectUnitCom() { return select_unit_com; }
int BattleState::getWinner() { return winner; }