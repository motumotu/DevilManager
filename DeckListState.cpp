//-----------------------------------------------------------
// DeckListState.h
// デッキ一覧画面の状態
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#include "DeckListState.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
DeckListState::DeckListState(GameData* data)
{
    game_data = data;
    save_data = data->getSaveData();
    
    SetKeyInputStringColor(
        GetColor(0, 0, 0),       // 入力文字列の色
        GetColor(0, 0, 0),       // ＩＭＥ非使用時のカーソルの色
        GetColor(255, 255, 255), // ＩＭＥ使用時の入力文字列の周りの色
        GetColor(255, 255, 255), // ＩＭＥ使用時のカーソルの色
        GetColor(0, 0, 0),       // ＩＭＥ使用時の変換文字列の下線
        GetColor(255, 255, 255), // ＩＭＥ使用時の選択対象の変換候補文字列の色
        GetColor(0, 0, 0),       // ＩＭＥ使用時の入力モード文字列の色(『全角ひらがな』等)
        GetColor(255, 0, 0),     // 入力文字列の縁の色
        GetColor(0, 255, 0),     // ＩＭＥ使用時の選択対象の変換候補文字列の縁の色
        GetColor(255, 0, 0),     // ＩＭＥ使用時の入力モード文字列の縁の色
        GetColor(255, 0, 0),     // ＩＭＥ使用時の変換候補ウインドウの縁の色
        GetColor(255, 0, 0),     // ＩＭＥ使用時の変換候補ウインドウの下地の色
        GetColor(51, 153, 255),  // 入力文字列の選択部分( SHIFTキーを押しながら左右キーで選択 )の周りの色
        GetColor(255, 255, 255), // 入力文字列の選択部分( SHIFTキーを押しながら左右キーで選択 )の色
        GetColor(51, 153, 5)     // 入力文字列の選択部分( SHIFTキーを押しながら左右キーで選択 )の縁の色
        //GetColor(255, 0, 0),   // ＩＭＥ使用時の入力文字列の色
        //GetColor(255, 0, 0));  // ＩＭＥ使用時の入力文字列の縁の色
        );
    init();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
DeckListState::~DeckListState()
{
    DeleteKeyInput(input_handl);
}

//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void DeckListState::init()
{
    select_deck_num = 1;
    shift_pos_y = 0;
    input_active = 0;
    SetKeyInputString(
        save_data->getDeckData(1)->getDeckName().c_str(),
        input_handl);
    bar_pos = DeckListData::BAR_POS_Y;
}

//-----------------------------------------------------------
// デッキ選択
//-----------------------------------------------------------
void DeckListState::selectDeckList(int n)
{
    select_deck_num = n;
    SetKeyInputString(save_data->getDeckData(n)->getDeckName().c_str(), input_handl);
}

//-----------------------------------------------------------
// 更新
//-----------------------------------------------------------
void DeckListState::update()
{
    // 入力ボックス
    if (CheckKeyInput(input_handl) && input_active == 1) {
        offInputActive();
    }
    // スライドバー
    if (is_bar_click_now) {
        slideBarAdjustment();
    }
}

//-----------------------------------------------------------
// マウス座標更新
//-----------------------------------------------------------
void DeckListState::updateMousePos(int x, int y)
{
    mouse_x = x;
    mouse_y = y;
}

//-----------------------------------------------------------
// スライドバー操作
//-----------------------------------------------------------
void DeckListState::slideBarUp() { slideBarUp(3); }
void DeckListState::slideBarUp(int val)
{
    if (save_data->getDeckNum() <= 7) return;
    shift_pos_y -= val;
    double rate = (double)shift_pos_y / ((save_data->getDeckNum() - 7) * DeckListData::BUTTON_DECK_SIZE_Y);
    bar_pos = (int)(DeckListData::BAR_POS_Y + DeckListData::BAR_AREA_SIZE * rate);
    if (shift_pos_y < 0) {
        shift_pos_y = 0;
        bar_pos = DeckListData::BAR_POS_Y;
    }
}
void DeckListState::slideBarDown() { slideBarDown(3); }
void DeckListState::slideBarDown(int val)
{
    if (save_data->getDeckNum() <= 7) return;
    shift_pos_y += val;
    double rate = (double)shift_pos_y / ((save_data->getDeckNum() - 7) * DeckListData::BUTTON_DECK_SIZE_Y);
    bar_pos = (int)(DeckListData::BAR_POS_Y + DeckListData::BAR_AREA_SIZE * rate);
    if (shift_pos_y >= (save_data->getDeckNum() - 7) * DeckListData::BUTTON_DECK_SIZE_Y) {
        shift_pos_y = (save_data->getDeckNum() - 7) * DeckListData::BUTTON_DECK_SIZE_Y;
        bar_pos = DeckListData::BAR_POS_Y + DeckListData::BAR_AREA_SIZE;
    }
}
void DeckListState::slideBarAdjustment()
{
    if (save_data->getDeckNum() <= 7) return;
    int up_y = DeckListData::BAR_POS_Y + DeckListData::BAR_SIZE_Y / 2;
    int down_y = up_y + DeckListData::BAR_AREA_SIZE;
    double rate = (double)(mouse_y - up_y) / DeckListData::BAR_AREA_SIZE;
    if (rate < 0) rate = 0;
    if (rate > 1) rate = 1;
    shift_pos_y = (int)((save_data->getDeckNum() - 7) * DeckListData::BUTTON_DECK_SIZE_Y * rate);
    bar_pos = (int)(DeckListData::BAR_POS_Y + DeckListData::BAR_AREA_SIZE * rate);
}

//-----------------------------------------------------------
// バーをクリック
//-----------------------------------------------------------
void DeckListState::clickBar()
{
    is_bar_click_now = true;
}

//-----------------------------------------------------------
// 左クリック終了
//-----------------------------------------------------------
void DeckListState::leftClickEnd()
{
    is_bar_click_now = false;
}

//-----------------------------------------------------------
// マウス座標にある物体取得
//-----------------------------------------------------------
int DeckListState::getMousePosObject()
{
    if (isPosButtonBack(mouse_x, mouse_y)) return BUTTON_BACK;
    if (isPosButtonEdit(mouse_x, mouse_y)) return BUTTON_EDIT;
    if (isPosButtonDelete(mouse_x, mouse_y)) return BUTTON_DELETE;
    if (isPosInputBox(mouse_x, mouse_y)) return INPUT_BOX;
    return NONE;
}

//-----------------------------------------------------------
// その位置がボタンか
//-----------------------------------------------------------
bool DeckListState::isPosButtonBack(int x, int y) {
    int px = DeckListData::BUTTON_BACK_POS_X;
    int py = DeckListData::BUTTON_BACK_POS_Y;
    int sx = DeckListData::BUTTON_BACK_SIZE_X;
    int sy = DeckListData::BUTTON_BACK_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}
bool DeckListState::isPosButtonEdit(int x, int y) {
    int px = DeckListData::BUTTON_EDIT_POS_X;
    int py = DeckListData::BUTTON_EDIT_POS_Y;
    int sx = DeckListData::BUTTON_EDIT_SIZE_X;
    int sy = DeckListData::BUTTON_EDIT_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}
bool DeckListState::isPosButtonDelete(int x, int y) {
    int px = DeckListData::BUTTON_DELETE_POS_X;
    int py = DeckListData::BUTTON_DELETE_POS_Y;
    int sx = DeckListData::BUTTON_DELETE_SIZE_X;
    int sy = DeckListData::BUTTON_DELETE_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}
bool DeckListState::isPosInputBox(int x, int y) {
    int px = DeckListData::INPUT_BOX_POS_X;
    int py = DeckListData::INPUT_BOX_POS_Y;
    int sx = DeckListData::INPUT_BOX_SIZE_X;
    int sy = DeckListData::INPUT_BOX_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}
int DeckListState::isPosDeckList(int x, int y) {
    if (x < 26 || x > 279 || y < 70 || y > 564) return 0;
    int px = DeckListData::BUTTON_DECK_POS_X;
    int py = DeckListData::BUTTON_DECK_POS_Y - shift_pos_y;
    int sx = DeckListData::BUTTON_DECK_SIZE_X;
    int sy = DeckListData::BUTTON_DECK_SIZE_Y;
    for (int i = 0; i < game_data->getSaveData()->getDeckNum(); i++) {
        if (x >= px && x <= px + sx && y >= py + i * sy && y <= py + i * sy + sy) {
            return i + 1;
        }
    }
    return 0;
}
bool DeckListState::isPosBarUp(int x, int y) {
    int px = DeckListData::BAR_UP_POS_X;
    int py = DeckListData::BAR_UP_POS_Y;
    int sx = DeckListData::BAR_UP_SIZE_X;
    int sy = DeckListData::BAR_UP_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}
bool DeckListState::isPosBarDown(int x, int y) {
    int px = DeckListData::BAR_DOWN_POS_X;
    int py = DeckListData::BAR_DOWN_POS_Y;
    int sx = DeckListData::BAR_DOWN_SIZE_X;
    int sy = DeckListData::BAR_DOWN_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}
bool DeckListState::isPosBar(int x, int y) {
    int px = DeckListData::BAR_POS_X;
    int py = bar_pos;
    int sx = DeckListData::BAR_SIZE_X;
    int sy = DeckListData::BAR_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}
bool DeckListState::isPosBarArea(int x, int y) {
    int px = DeckListData::BAR_POS_X;
    int py = DeckListData::BAR_UP_POS_Y + DeckListData::BAR_UP_SIZE_Y;
    int sx = DeckListData::BAR_SIZE_X;
    int sy = DeckListData::BAR_AREA_SIZE + DeckListData::BAR_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}

//-----------------------------------------------------------
// 入力がアクティブ操作
//-----------------------------------------------------------
void DeckListState::offInputActive() {
    if (input_active == 0) return;
    char name[256];
    GetKeyInputString(name, input_handl);
    save_data->getDeckData(select_deck_num)->setDeckName(name);
    DeleteKeyInput(input_handl);
    input_active = 0; 
}
void DeckListState::onInputActive() {
    input_handl = MakeKeyInput(24, TRUE, FALSE, FALSE);
    SetKeyInputString(save_data->getDeckData(select_deck_num)->getDeckName().c_str(), input_handl);
    input_active = 1;
}

//===========================================================
// getter
//===========================================================
int DeckListState::getSelectDeckNum() { return select_deck_num; }
int DeckListState::getShiftPosY() { return shift_pos_y; }
int DeckListState::getInputActive() { return input_active; }
int DeckListState::getInputHandl() { return input_handl; }
int DeckListState::getBarPos() { return bar_pos; }