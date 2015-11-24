//-----------------------------------------------------------
// InputState.cpp
// キー・マウスの入力情報管理
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#include "InputState.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
InputState::InputState()
{
    key_state = new InputKeyState();
    mouse_state = new InputMouseState();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
InputState::~InputState()
{
    delete(mouse_state);
    delete(key_state);
}

//-----------------------------------------------------------
// 初期処理
//-----------------------------------------------------------
void InputState::init()
{

}

//-----------------------------------------------------------
// 更新処理
//-----------------------------------------------------------
void InputState::update()
{
    key_state->update();
    mouse_state->update();
}

//===========================================================
// getter
//===========================================================
int InputState::getKeyState(int n) { return key_state->getKeyState(n); }
int InputState::getMouseWheel() { return mouse_state->getMouseWheel(); }
int InputState::getPointX() { return mouse_state->getPointX(); }
int InputState::getPointY() { return mouse_state->getPointY(); }
int InputState::getClick(int n) { return mouse_state->getClick(n); }
int InputState::getPreClick(int n) { return mouse_state->getPreClick(n); }
bool InputState::isRereaseClick(int n) { return mouse_state->isRereaseClick(n); }