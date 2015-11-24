//-----------------------------------------------------------
// BattleDamageState.cpp
// �_���[�W�̏��
// ����� 2015.03.04
// ����� motumotu
//-----------------------------------------------------------
#include "BattleDamageState.h"

//-----------------------------------------------------------
// �R���X�g���N�^
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
// �f�X�g���N�^
//-----------------------------------------------------------
BattleDamageState::~BattleDamageState()
{
}

//-----------------------------------------------------------
// �X�V
//-----------------------------------------------------------
void BattleDamageState::update()
{
    cnt_frame++;
}

//-----------------------------------------------------------
// ������ׂ���
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