//-----------------------------------------------------------
// TitleData.h
// タイトル画面のデータ
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "SystemData.h"

class TitleData {
public:
    static const int BUTTON_SIZE_X = 200;   // ボタンの大きさx
    static const int BUTTON_SIZE_Y = 40;    // ボタンの大きさy
private:
public:
    TitleData();                  // コンストラクタ
    ~TitleData();                 // デストラクタ
    int getPosButtonNewgameX();   // ボタン「はじめから」の位置x
    int getPosButtonNewgameY();   // ボタン「はじめから」の位置y
    int getPosButtonContinueX();  // ボタン「つづきから」の位置x
    int getPosButtonContinueY();  // ボタン「つづきから」の位置y
    int getPosButtonSettingX();   // ボタン「システム設定」の位置x
    int getPosButtonSettingY();   // ボタン「システム設定」の位置y
    int getPosButtonSiteX();      // ボタン「公式サイト」の位置x
    int getPosButtonSiteY();      // ボタン「公式サイト」の位置y
    int getPosButtonEndX();       // ボタン「ゲーム終了」の位置x
    int getPosButtonEndY();       // ボタン「ゲーム終了」の位置y
};