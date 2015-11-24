//-----------------------------------------------------------
// BattleDamageState.cpp
// ダメージの状態
// 制作日 2015.03.04
// 制作者 motumotu
//-----------------------------------------------------------
#include "BattleDamageState.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
BattleDamageState::BattleDamageState(int dame, int _x, int _y, int _which)
{
    damage = dame;
    x = _x;
    y = _y;
    cnt_frame = 0;
    which = _which;
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
BattleDamageState::~BattleDamageState()
{
}

//-----------------------------------------------------------
// 更新
//-----------------------------------------------------------
void BattleDamageState::update()
{
    cnt_frame++;
}

//-----------------------------------------------------------
// 消えるべきか
//-----------------------------------------------------------
bool BattleDamageState::isDelete()
{
    return (cnt_frame >= DISPLAY_TIME) ? true : false;
}

//===========================================================
// getter
//===========================================================
int BattleDamageState::getDamage() { return damage; }
int BattleDamageState::getCntFrame() { return cnt_frame; }
int BattleDamageState::getX() { return x; }
int BattleDamageState::getY() { return y; }
int BattleDamageState::getWhich() { return which; }
int BattleDamageState::getDamageDigits() { return (int)log10(damage) + 1; }