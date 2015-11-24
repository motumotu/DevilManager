//-----------------------------------------------------------
// BattleSelectState.h
// 対戦選択画面の状態
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#include "BattleSelectState.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
BattleSelectState::BattleSelectState(GameData* data)
{
    game_data = data;
    save_data = data->getSaveData();
    init();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
BattleSelectState::~BattleSelectState()
{

}

//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void BattleSelectState::init()
{
    select_num = 1;
    my_deck_num = 1;
    shift_pos_y = 0;
}

//-----------------------------------------------------------
// 更新
//-----------------------------------------------------------
void BattleSelectState::update()
{

}

//-----------------------------------------------------------
// 選択番号操作
//-----------------------------------------------------------
void BattleSelectState::upSelectNum()
{
    select_num--;
    if (select_num == 0) {
        select_num = game_data->getAllBattleData()->getBattleDataNum();
        shift_pos_y = getMaxShiftPosY();
    }
}
void BattleSelectState::downSelectNum()
{
    select_num++;
    if (select_num > game_data->getAllBattleData()->getBattleDataNum()) {
        select_num = 1;
        shift_pos_y = 0;
    }
}

//-----------------------------------------------------------
// 自分デッキ操作
//-----------------------------------------------------------
void BattleSelectState::leftMyDeck()
{
    my_deck_num--;
    if (my_deck_num < 1) my_deck_num = save_data->getDeckNum();
}

void BattleSelectState::rightMyDeck()
{
    my_deck_num++;
    if (my_deck_num > save_data->getDeckNum()) my_deck_num = 1;
}

//-----------------------------------------------------------
// スクロール
//-----------------------------------------------------------
void BattleSelectState::scrollBattleSelect(int val)
{
    shift_pos_y -= val * 20;
    if (shift_pos_y < 0) shift_pos_y = 0;
    int max_shift = getMaxShiftPosY();
    if (max_shift > 0 && shift_pos_y > max_shift) shift_pos_y = max_shift;

}

//-----------------------------------------------------------
// バーの位置調整
//-----------------------------------------------------------
void BattleSelectState::adjustmentBar(int mx, int my)
{
    int x = BattleSelectData::BAR_POS_X;
    int y = BattleSelectData::BAR_POS_Y;
    int sx = BattleSelectData::BAR_AREA_SIZE_X;
    int sy = BattleSelectData::BAR_AREA_SIZE_Y;
    // 上
    if (my <= y + BattleSelectData::BAR_SIZE_Y / 2) {
        shift_pos_y = 0;
    }
    // 下
    else if (my >= y + sy - BattleSelectData::BAR_SIZE_Y / 2) {
        shift_pos_y = getMaxShiftPosY();
    }
    // その他
    else {
        my -= y + BattleSelectData::BAR_SIZE_Y / 2;
        shift_pos_y = (int)getMaxShiftPosY() * (my / (sy - (double)BattleSelectData::BAR_SIZE_Y));
    }
}

//-----------------------------------------------------------
// 対戦相手選択
//-----------------------------------------------------------
void BattleSelectState::selectBattleNum(int n)
{
    select_num = n;
}

//-----------------------------------------------------------
// その座標のオブジェクト取得
//-----------------------------------------------------------
int BattleSelectState::getPosObject(int x, int y)
{
    if (isPosButtonBack(x, y)) return BUTTON_BACK;
    if (isPosButtonBattle(x, y)) return BUTTON_BATTLE;
    if (isPosDeckSelectLeft(x, y)) return DECK_SELECT_LEFT;
    if (isPosDeckSelectRight(x, y)) return DECK_SELECT_RIGHT;
    if (isPosBar(x, y)) return BAR;
    if (isPosBarArea(x, y)) return BAR_AREA;
    if (isPosSelectArea(x, y)) return SELECT_AREA;
    return NONE;
}

//-----------------------------------------------------------
// 座標か
//-----------------------------------------------------------
bool BattleSelectState::isPosButtonBack(int x, int y) {
    int px = BattleSelectData::BUTTON_BACK_POS_X;
    int py = BattleSelectData::BUTTON_BACK_POS_Y;
    int sx = BattleSelectData::BUTTON_BACK_SIZE_X;
    int sy = BattleSelectData::BUTTON_BACK_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}
bool BattleSelectState::isPosButtonBattle(int x, int y) {
    int px = BattleSelectData::BUTTON_BATTLE_POS_X;
    int py = BattleSelectData::BUTTON_BATTLE_POS_Y;
    int sx = BattleSelectData::BUTTON_BATTLE_SIZE_X;
    int sy = BattleSelectData::BUTTON_BATTLE_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}
bool BattleSelectState::isPosDeckSelectLeft(int x, int y) {
    int px = BattleSelectData::DECK_SELECT_LEFT_POS_X;
    int py = BattleSelectData::DECK_SELECT_LEFT_POS_Y;
    int sx = BattleSelectData::DECK_SELECT_SIZE_X;
    int sy = BattleSelectData::DECK_SELECT_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}
bool BattleSelectState::isPosDeckSelectRight(int x, int y) {
    int px = BattleSelectData::DECK_SELECT_RIGHT_POS_X;
    int py = BattleSelectData::DECK_SELECT_RIGHT_POS_Y;
    int sx = BattleSelectData::DECK_SELECT_SIZE_X;
    int sy = BattleSelectData::DECK_SELECT_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}
bool BattleSelectState::isPosBarArea(int x, int y) {
    int px = BattleSelectData::BAR_POS_X;
    int py = BattleSelectData::BAR_POS_Y;
    int sx = BattleSelectData::BAR_AREA_SIZE_X;
    int sy = BattleSelectData::BAR_AREA_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}
bool BattleSelectState::isPosBar(int x, int y) {
    int px = BattleSelectData::BAR_POS_X;
    int py = getBarPos();
    int sx = BattleSelectData::BAR_SIZE_X;
    int sy = BattleSelectData::BAR_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}
bool BattleSelectState::isPosSelectArea(int x, int y) {
    int px = BattleSelectData::SELECT_AREA_POS_X;
    int py = BattleSelectData::SELECT_AREA_POS_Y;
    int sx = BattleSelectData::SELECT_AREA_SIZE_X;
    int sy = BattleSelectData::SELECT_AREA_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}
//-----------------------------------------------------------
// その場所の対戦相手番号取得
//-----------------------------------------------------------
int BattleSelectState::getPosBattleNum(int x, int y) {
    for (int n = 1; n <= game_data->getAllBattleData()->getBattleDataNum(); n++) {
        int x1 = BattleSelectData::SELECT_AREA_POS_X + 5;   // 左上
        int y1 = BattleSelectData::SELECT_AREA_POS_Y + 5 +  // 左上
            (n - 1) * (BattleSelectData::SELECT_SIZE_Y + 5) - shift_pos_y;
        int x2 = x1 + BattleSelectData::SELECT_SIZE_X;      // 右下
        int y2 = y1 + BattleSelectData::SELECT_SIZE_Y;      // 右下
        if (x >= x1 && x <= x2 && y >= y1 && y <= y2) return n;
    }
    return 0;
}

//===========================================================
// getter
//===========================================================
int BattleSelectState::getSelectNum() { return select_num; }
int BattleSelectState::getMyDeckNum() { return my_deck_num; }
int BattleSelectState::getShiftPosY() { return shift_pos_y; }
int BattleSelectState::getMaxShiftPosY() {
    return (BattleSelectData::SELECT_SIZE_Y + 5) *
        game_data->getAllBattleData()->getBattleDataNum() -
        BattleSelectData::SELECT_AREA_SIZE_Y + 5;
}
double BattleSelectState::getShiftRate() {
    return (double)shift_pos_y / getMaxShiftPosY();
}
int BattleSelectState::getBarPos() {
    return (int)(BattleSelectData::BAR_POS_Y + getShiftRate() *
        (BattleSelectData::BAR_AREA_SIZE_Y - BattleSelectData::BAR_SIZE_Y));
}