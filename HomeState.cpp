//-----------------------------------------------------------
// HomeState.cpp
// ホーム画面の状態
// 制作日 2015.03.16
// 制作者 motumotu
//-----------------------------------------------------------
#include "HomeState.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
HomeState::HomeState(GameData *data)
{
    game_data = data;
    init();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
HomeState::~HomeState()
{
}

//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void HomeState::init()
{
    click_now = 0;
    click_pos_x = 0;
    click_pos_y = 0;
}

//-----------------------------------------------------------
// 更新
//-----------------------------------------------------------
void HomeState::update()
{
}

//-----------------------------------------------------------
// マウス位置更新
//-----------------------------------------------------------
void HomeState::updateMousePos(int x, int y)
{
    mouse_x = x;
    mouse_y = y;
}
//-----------------------------------------------------------
// クリックのはじめ
//-----------------------------------------------------------
void HomeState::clickFirst(int x, int y)
{
    click_pos_x = x;
    click_pos_y = y;
    click_now = 1;
}

//-----------------------------------------------------------
// クリックの終わり
//-----------------------------------------------------------
int HomeState::clickEnd(int x, int y)
{
    click_now = 0;

    // ストーリーボタン
    if (isPosButtonStory(x, y) && isPosButtonStory(click_pos_x, click_pos_y)) {
        return CLICK_BUTTON_STORY;
    }
    // 対戦ボタン
    if (isPosButtonBattle(x, y) && isPosButtonBattle(click_pos_x, click_pos_y)) {
        return CLICK_BUTTON_BATTLE;
    }
    // デッキ編成ボタン
    if (isPosButtonDeck(x, y) && isPosButtonDeck(click_pos_x, click_pos_y)) {
        return CLICK_BUTTON_DECK;
    }
    // ショップボタン
    if (isPosButtonShop(x, y) && isPosButtonShop(click_pos_x, click_pos_y)) {
        return CLICK_BUTTON_SHOP;
    }
    // セーブボタン
    if (isPosButtonSave(x, y) && isPosButtonSave(click_pos_x, click_pos_y)) {
        return CLICK_BUTTON_SAVE;
    }
    // 設定ボタン
    if (isPosButtonSetting(x, y) && isPosButtonSetting(click_pos_x, click_pos_y)) {
        return CLICK_BUTTON_SETTING;
    }
    // 何もなし
    return CLICK_NONE;
}


//-----------------------------------------------------------
// クリック位置
//-----------------------------------------------------------
bool HomeState::isPosButtonStory() { return isPosButtonStory(mouse_x, mouse_y); }
bool HomeState::isPosButtonStory(int mx, int my) {
    if (mx >= HomeData::STORY_X && mx <= HomeData::STORY_X + HomeData::BUTTON_SIZE_X &&
        my >= HomeData::STORY_Y && my <= HomeData::STORY_Y + HomeData::BUTTON_SIZE_Y) return true;
    return false;
}
bool HomeState::isPosButtonBattle() { return isPosButtonBattle(mouse_x, mouse_y); }
bool HomeState::isPosButtonBattle(int mx, int my) {
    if (mx >= HomeData::BATTLE_X && mx <= HomeData::BATTLE_X + HomeData::BUTTON_SIZE_X &&
        my >= HomeData::BATTLE_Y && my <= HomeData::BATTLE_Y + HomeData::BUTTON_SIZE_Y) return true;
    return false;
}
bool HomeState::isPosButtonDeck() { return isPosButtonDeck(mouse_x, mouse_y); }
bool HomeState::isPosButtonDeck(int mx, int my) {
    if (mx >= HomeData::DECK_X && mx <= HomeData::DECK_X + HomeData::BUTTON_SIZE_X &&
        my >= HomeData::DECK_Y && my <= HomeData::DECK_Y + HomeData::BUTTON_SIZE_Y) return true;
    return false;
}
bool HomeState::isPosButtonShop() { return isPosButtonShop(mouse_x, mouse_y); }
bool HomeState::isPosButtonShop(int mx, int my) {
    if (mx >= HomeData::SHOP_X && mx <= HomeData::SHOP_X + HomeData::BUTTON_SIZE_X &&
        my >= HomeData::SHOP_Y && my <= HomeData::SHOP_Y + HomeData::BUTTON_SIZE_Y) return true;
    return false;
}
bool HomeState::isPosButtonSave() { return isPosButtonSave(mouse_x, mouse_y); }
bool HomeState::isPosButtonSave(int mx, int my) {
    if (mx >= HomeData::SAVE_X && mx <= HomeData::SAVE_X + HomeData::BUTTON_SIZE_X &&
        my >= HomeData::SAVE_Y && my <= HomeData::SAVE_Y + HomeData::BUTTON_SIZE_Y) return true;
    return false;
}
bool HomeState::isPosButtonSetting() { return isPosButtonSetting(mouse_x, mouse_y); }
bool HomeState::isPosButtonSetting(int mx, int my) {
    if (mx >= HomeData::SETTING_X && mx <= HomeData::SETTING_X + HomeData::BUTTON_SIZE_X &&
        my >= HomeData::SETTING_Y && my <= HomeData::SETTING_Y + HomeData::BUTTON_SIZE_Y) return true;
    return false;
}

//-----------------------------------------------------------
// 画像取得
//-----------------------------------------------------------
int HomeState::getImageButtonStory() {
    if (isClickNow() && isPosButtonStory() &&
        isPosButtonStory(click_pos_x, click_pos_y)) return 6;
    if (isPosButtonStory()) return 12;
    return 0;
}
int HomeState::getImageButtonBattle() {
    if (isClickNow() && isPosButtonBattle() &&
        isPosButtonBattle(click_pos_x, click_pos_y)) return 7;
    if (isPosButtonBattle()) return 13;
    return 1;
}
int HomeState::getImageButtonDeck() {
    if (isClickNow() && isPosButtonDeck() && 
        isPosButtonDeck(click_pos_x, click_pos_y)) return 8;
    if (isPosButtonDeck()) return 14;
    return 2;
}
int HomeState::getImageButtonShop() {
    if (isClickNow() && isPosButtonShop() &&
        isPosButtonShop(click_pos_x, click_pos_y)) return 9;
    if (isPosButtonShop()) return 15;
    return 3;
}
int HomeState::getImageButtonSave() {
    if (isClickNow() && isPosButtonSave() &&
        isPosButtonSave(click_pos_x, click_pos_y)) return 10;
    if (isPosButtonSave()) return 16;
    return 4;
}
int HomeState::getImageButtonSetting() {
    if (isClickNow() && isPosButtonSetting() &&
        isPosButtonSetting(click_pos_x, click_pos_y)) return 11;
    if (isPosButtonSetting()) return 17;
    return 5;
}

//===========================================================
// getter
//===========================================================
bool HomeState::isClickNow() { return (click_now) ? true : false; }