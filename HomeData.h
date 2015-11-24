//-----------------------------------------------------------
// HomeData.h
// ホーム画面のデータ
// 制作日 2015.03.16
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once

class HomeData {
public:
    static const int BUTTON_SIZE_X = 280;
    static const int BUTTON_SIZE_Y = 100;
    static const int STORY_X = 100;
    static const int STORY_Y = 100;
    static const int BATTLE_X = 450;
    static const int BATTLE_Y = 100;
    static const int DECK_X = 100;
    static const int DECK_Y = 250;
    static const int SHOP_X = 450;
    static const int SHOP_Y = 250;
    static const int SAVE_X = 100;
    static const int SAVE_Y = 400;
    static const int SETTING_X = 450;
    static const int SETTING_Y = 400;
    HomeData();                        // コンストラクタ
    ~HomeData();                       // デストラクタ
};