//-----------------------------------------------------------
// InputMouseState.h
// マウスの入力状態
// 制作日 2014.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "DxLib.h"

class InputMouseState {
public:
    static const int CLICK_MAX = 8;

private:
    int point_x;           // マウスの座標x
    int point_y;           // マウスの座標y
    int click[CLICK_MAX];  // クリック情報
    int pre_click[CLICK_MAX]; // 前フレームのクリック情報
    int wheel;             // マウス回転量

public:
    InputMouseState();     // コンストラクタ
    ~InputMouseState();    // デストラクタ
    void init();           // 初期処理
    void update();         // 更新処理
    // getter
    int getMouseWheel();   // マウスホイール回転量取得
    int getPointX();       // 座標xを取得
    int getPointY();       // 座標yを取得
    int getClick(int);     // クリック情報取得
    int getPreClick(int);  // 前フレームクリック情報取得
    bool isRereaseClick(int); // 指定クリックが離されたか
};