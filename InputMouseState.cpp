//-----------------------------------------------------------
// InputMouseState.h
// マウスの入力状態
// 制作日 2014.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#include "InputMouseState.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
InputMouseState::InputMouseState()
{
    init();   // 初期処理
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
InputMouseState::~InputMouseState()
{

}

//-----------------------------------------------------------
// 初期処理
//-----------------------------------------------------------
void InputMouseState::init()
{
    point_x = 0;
    point_y = 0;
    wheel = GetMouseWheelRotVol();
    for (int i = 0; i < CLICK_MAX; i++) {
        click[i] = 0;
    }
}

//-----------------------------------------------------------
// 更新処理
//-----------------------------------------------------------
void InputMouseState::update()
{
    // マウスホイール
    wheel = GetMouseWheelRotVol();

    // マウスの座標
    if (GetMousePoint(&point_x, &point_y) == -1) {
        return;
    }
    // 前フレームのクリック状態
    for (int i = 0; i < CLICK_MAX; i++) {
        pre_click[i] = click[i];
    }
    // マウスのクリック状態
    int MouseInput = GetMouseInput();
    for (int i = 0; i < CLICK_MAX; i++) {
        click[i] = (MouseInput & 1 << i) ? click[i] + 1 : 0;
    }
}

//===========================================================
// getter
//===========================================================
int InputMouseState::getMouseWheel() { return wheel; }
int InputMouseState::getPointX() { return point_x; }
int InputMouseState::getPointY() { return point_y; }
int InputMouseState::getClick(int n) {
    if (n-1 < 0 || n-1 >= CLICK_MAX) {
        puts("範囲外参照 InputMouseState::getClick(int)");
        return 0;
    }
    return click[n-1];
}
int InputMouseState::getPreClick(int n) {
    if (n - 1 < 0 || n - 1 >= CLICK_MAX) {
        puts("範囲外参照 InputMouseState::getPreClick(int)");
        return 0;
    }
    return pre_click[n - 1];
}
bool InputMouseState::isRereaseClick(int n) {
    return (click[n - 1] == 0 && pre_click[n - 1] >= 1);
}