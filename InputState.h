//-----------------------------------------------------------
// InputState.h
// 入力状態
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "InputKeyState.h"
#include "InputMouseState.h"

class InputState {
public:
    //static const int

private:
    InputKeyState *key_state;     // キー入力情報
    InputMouseState *mouse_state; // マウス入力情報

public:
    InputState();      // コンストラクタ
    ~InputState();     // デストラクタ
    void init();       // 初期処理
    void update();     // 更新処理

    // getter
    int getKeyState(int);  // キーの入力状態取得
    int getMouseWheel();   // マウスホイール回転量取得
    int getPointX();       // 座標xを取得
    int getPointY();       // 座標yを取得
    int getClick(int);     // クリック情報取得
    int getPreClick(int);  // 前フレームクリック情報
    bool isRereaseClick(int); // クリックが離されたか
};