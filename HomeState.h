//-----------------------------------------------------------
// HomeState.h
// ホーム画面の状態
// 制作日 2015.03.16
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"

class HomeState {
public:
    static const int CLICK_NONE = 0;             // 何もクリックされてない
    static const int CLICK_BUTTON_STORY = 1;
    static const int CLICK_BUTTON_BATTLE = 2;
    static const int CLICK_BUTTON_DECK = 3;
    static const int CLICK_BUTTON_SHOP = 4;
    static const int CLICK_BUTTON_SAVE = 5;
    static const int CLICK_BUTTON_SETTING = 6;
private:
    GameData *game_data;         // ゲームデータ
    int click_now;               // クリック中か
    int click_pos_x;             // クリックされた場所
    int click_pos_y;             // クリックされた場所
    int mouse_x;
    int mouse_y;
public:
    HomeState(GameData*);        // コンストラクタ
    ~HomeState();                // デストラクタ
    void init();                 // 初期化
    void update();               // 更新
    void updateMousePos(int, int);  // マウス位置更新
    void clickPosUpdate(int, int);  // クリック座標取得      
    void clickFirst(int, int);      // 最初のクリック
    int clickEnd(int, int);         // クリックされたものを返す
    // クリックの場所か
    bool isPosButtonStory();
    bool isPosButtonStory(int, int);
    bool isPosButtonBattle();
    bool isPosButtonBattle(int, int);
    bool isPosButtonDeck();
    bool isPosButtonDeck(int, int);
    bool isPosButtonShop();
    bool isPosButtonShop(int, int);
    bool isPosButtonSave();
    bool isPosButtonSave(int, int);
    bool isPosButtonSetting();
    bool isPosButtonSetting(int, int);
    // 画像状態取得
    int getImageButtonStory();
    int getImageButtonBattle();
    int getImageButtonDeck();
    int getImageButtonShop();
    int getImageButtonSave();
    int getImageButtonSetting();
    bool isClickNow();           // クリック中か
};