//-----------------------------------------------------------
// InputKeyState.h
// キーボードの入力情報管理
// 制作日 2014.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "DxLib.h"

class InputKeyState {
public:
    static const int KEY_MAX = 256;

private:
    int key[KEY_MAX];     // キー入力状態

public:
    InputKeyState();       // コンストラクタ
    ~InputKeyState();      // デストラクタ
    void init();           // 初期処理
    void update();         // 更新処理

    int getKeyState(int);  // キーの入力状態取得
};