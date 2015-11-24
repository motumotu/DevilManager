//-----------------------------------------------------------
// DeckEditState.h
// デッキ編集画面の状態
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#include "DeckEditState.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
DeckEditState::DeckEditState(GameData* data)
{
    game_data = data;
    save_data = data->getSaveData();
    init();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
DeckEditState::~DeckEditState()
{

}

//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void DeckEditState::init()
{
    shift_pos_y = 0;
    bar_pos = DeckEditData::BAR_AREA_POS_Y;
    select_now_card = 0;

}

//-----------------------------------------------------------
// 更新
//-----------------------------------------------------------
void DeckEditState::update()
{

}

//-----------------------------------------------------------
// マウス座標更新
//-----------------------------------------------------------
void DeckEditState::updateMousePos(int x, int y)
{
    mouse_x = x;
    mouse_y = y;
}


//-----------------------------------------------------------
// スライドバー操作
//-----------------------------------------------------------
void DeckEditState::slideBarUp() { slideBarUp(3); }
void DeckEditState::slideBarUp(int val)
{
    //if (save_data->getHaveCardNum() <= 50) return;

    shift_pos_y -= val;
    int max_shift = (int)(ceil((save_data->getHaveCardNum() - 50) / 5.0) * DeckEditData::CARD_SIZE_Y);
    double rate = (double)shift_pos_y / max_shift;
    bar_pos = (int)(DeckEditData::BAR_AREA_POS_Y + (DeckEditData::BAR_AREA_SIZE_Y - DeckEditData::BAR_SIZE_Y) * rate);
    if (shift_pos_y < 0) {
        shift_pos_y = 0;
        bar_pos = DeckEditData::BAR_AREA_POS_Y;
    }
}
void DeckEditState::slideBarDown() { slideBarDown(3); }
void DeckEditState::slideBarDown(int val)
{
    if (save_data->getHaveCardNum() > 50) {
        shift_pos_y += val;
    }
    int max_shift = (int)(ceil((save_data->getHaveCardNum() - 50) / 5.0) * DeckEditData::CARD_SIZE_Y);
    if (save_data->getHaveCardNum() <= 50) max_shift = 0;
    double rate = (double)shift_pos_y / max_shift;
    bar_pos = (int)(DeckEditData::BAR_AREA_POS_Y + (DeckEditData::BAR_AREA_SIZE_Y - DeckEditData::BAR_SIZE_Y) * rate);
    if (shift_pos_y >= max_shift) {
        shift_pos_y = max_shift;
        bar_pos = DeckEditData::BAR_AREA_POS_Y + DeckEditData::BAR_AREA_SIZE_Y - DeckEditData::BAR_SIZE_Y;
    }
}
void DeckEditState::slideBarAdjustment()
{
    /*
    if (save_data->getDeckNum() <= 7) return;
    int up_y = DeckListData::BAR_POS_Y + DeckListData::BAR_SIZE_Y / 2;
    int down_y = up_y + DeckListData::BAR_AREA_SIZE;
    double rate = (double)(mouse_y - up_y) / DeckListData::BAR_AREA_SIZE;
    if (rate < 0) rate = 0;
    if (rate > 1) rate = 1;
    shift_pos_y = (int)((save_data->getDeckNum() - 7) * DeckListData::BUTTON_DECK_SIZE_Y * rate);
    bar_pos = (int)(DeckListData::BAR_POS_Y + DeckListData::BAR_AREA_SIZE * rate);
    */
}

//-----------------------------------------------------------
// エリアのn番目を選択
//-----------------------------------------------------------
void DeckEditState::selectDeckAreaCard(int n)
{
    // カードがない
    if (n >= save_data->getDeckData(select_deck_num)->getCardNum()) {
        select_now_card = 0;
        return;
    }
    select_now_card = save_data->getDeckData(select_deck_num)->getCard(n);
    save_data->getDeckData(select_deck_num)->deletePosCard(n);  // カード消去
}
void DeckEditState::selectCardAreaCard(int n)
{
    if (n >= save_data->getHaveCardNum()) {
        select_now_card = 0;
        return;
    }
    select_now_card = save_data->getHaveCardData()->getCard(n);
    save_data->getHaveCardData()->deletePosCard(n);            // カード消去
}

//-----------------------------------------------------------
// マウスが離された
//-----------------------------------------------------------
void DeckEditState::mouseRelease()
{
    select_now_card = 0;
}

//-----------------------------------------------------------
// n番目にカード追加
//-----------------------------------------------------------
void DeckEditState::addDeckAreaCard(int n)
{
    if (select_now_card == 0) return;
    // 指定場所に挿入
    if (n >= 0 && n < save_data->getDeckData(select_deck_num)->getCardNum()) {
        save_data->getDeckData(select_deck_num)->addPosCard(n, select_now_card);
    }
    // 最後に挿入
    else {
        save_data->getDeckData(select_deck_num)->addCard(select_now_card);
    }
    select_now_card = 0;
}
void DeckEditState::addCardAreaCard(int n)
{
    if (select_now_card == 0) return;
    // 指定場所に挿入
    if (n >= 0 && n < save_data->getHaveCardNum()) {
        save_data->getHaveCardData()->addPosCard(n, select_now_card);
    }
    // 最後に挿入
    else {
        save_data->getHaveCardData()->addCard(select_now_card);
    }
    select_now_card = 0;
}

//-----------------------------------------------------------
// デッキが最大か
//-----------------------------------------------------------
bool DeckEditState::isDeckMax()
{
    if (save_data->getDeckData(select_deck_num)->getCardNum() >= DeckData::DECK_CARD_MAX) {
        return true;
    }
    return false;
}

//-----------------------------------------------------------
// オブジェクト取得
//-----------------------------------------------------------
int DeckEditState::getPosObject(int x, int y)
{
    if (isPosButtonBack(x, y)) return BUTTON_BACK;
    if (isPosDeckArea(x, y)) return DECK_AREA;
    if (isPosCardArea(x, y)) return CARD_AREA;
    return NONE;
}
int DeckEditState::getMousePosObject() {
    return getPosObject(mouse_x, mouse_y);
}


//-----------------------------------------------------------
// 座標のカード取得
//-----------------------------------------------------------
int DeckEditState::getPosCard(int x, int y)
{
    //---- デッキエリア
    if (isPosDeckArea(x, y)) {
        int n = getPosDeckAreaNum(x, y);
        if (n >= save_data->getDeckData(select_deck_num)->getCardNum()) return 0;
        return save_data->getDeckData(select_deck_num)->getCard(n);
    }
    //---- 手持ちカード
    if (isPosCardArea(x, y)) {
        int n = getPosCardAreaNum(x, y);
        if (n >= save_data->getHaveCardNum()) return 0;
        return save_data->getHaveCardData()->getCard(n);
    }
    return 0;
}
int DeckEditState::getMousePosCard() {
    return getPosCard(mouse_x, mouse_y);
}
//-----------------------------------------------------------
// 何番目か取得
//-----------------------------------------------------------
int DeckEditState::getPosDeckAreaNum(int x, int y) {
    int px = (x - DeckEditData::DECK_AREA_POS_X) / DeckEditData::CARD_SIZE_X;
    int py = (y - DeckEditData::DECK_AREA_POS_Y) / DeckEditData::CARD_SIZE_Y;
    return py * DeckEditData::DECK_AREA_CARD_NUM_X + px;
}
int DeckEditState::getPosCardAreaNum(int x, int y) {
    int px = (x - DeckEditData::CARD_AREA_POS_X) / DeckEditData::CARD_SIZE_X;
    int py = (y - DeckEditData::CARD_AREA_POS_Y + shift_pos_y) / DeckEditData::CARD_SIZE_Y;
    return py * DeckEditData::CARD_AREA_CARD_NUM_X + px;
}
//-----------------------------------------------------------
// 位置確認系
//-----------------------------------------------------------
bool DeckEditState::isPosButtonBack(int x, int y) {
    int px = DeckEditData::BUTTON_BACK_POS_X;
    int py = DeckEditData::BUTTON_BACK_POS_Y;
    int sx = DeckEditData::BUTTON_BACK_SIZE_X;
    int sy = DeckEditData::BUTTON_BACK_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}
bool DeckEditState::isPosDeckArea(int x, int y) {
    int px = DeckEditData::DECK_AREA_POS_X;
    int py = DeckEditData::DECK_AREA_POS_Y;
    int sx = DeckEditData::DECK_AREA_SIZE_X;
    int sy = DeckEditData::DECK_AREA_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}
bool DeckEditState::isPosCardArea(int x, int y) {
    int px = DeckEditData::CARD_AREA_POS_X;
    int py = DeckEditData::CARD_AREA_POS_Y;
    int sx = DeckEditData::CARD_AREA_SIZE_X;
    int sy = DeckEditData::CARD_AREA_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}
//===========================================================
// getter・setter
//===========================================================
int DeckEditState::getShiftPosY() { return shift_pos_y; }
int DeckEditState::getBarPosY() { return bar_pos; }
void DeckEditState::setSelectDeckNum(int n) { select_deck_num = n; }
int DeckEditState::getSelectNowCard() { return select_now_card; }