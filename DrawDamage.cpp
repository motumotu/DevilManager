//-----------------------------------------------------------
// DrawDamage.cpp
// �_���[�W�̕`��
// ����� 2015.03.04
// ����� motumotu
//-----------------------------------------------------------
#include "DrawDamage.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
DrawDamage::DrawDamage(GameData* data, BattleState* state)
{
    game_data = data;
    battle_state = state;
    init();
    loadImage();          // �摜�ǂݍ���
    color_white = GetColor(255, 255, 255);
    color_red = GetColor(207, 0, 0);
    font = CreateFontToHandle("PixelMplus12", 12, -1, DX_FONTTYPE_ANTIALIASING_EDGE);
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
DrawDamage::~DrawDamage()
{

}

//-----------------------------------------------------------
// ��������
//-----------------------------------------------------------
void DrawDamage::init()
{
}

//-----------------------------------------------------------
// �X�V����
//-----------------------------------------------------------
void DrawDamage::update()
{

}

//-----------------------------------------------------------
// �摜�ǂݍ���
//-----------------------------------------------------------
void DrawDamage::loadImage()
{
}

//-----------------------------------------------------------
// �`��
//-----------------------------------------------------------
void DrawDamage::draw()
{
    BattleMapState* map_state = battle_state->getMapState();
    for (int i = 0; i < map_state->getDamageStateNum(); i++) {
        BattleDamageState* damage = map_state->getDamageState();
        int px = damage->getX() + battle_state->getShiftPosX();
        px -= damage->getDamageDigits() * 5;
        int py = damage->getY() + battle_state->getShiftPosY() - 10;
        int color = (damage->getWhich()) ? color_white : color_red;
        DrawFormatStringToHandle(px, py - damage->getCntFrame() / 2,
            color, font, "%d", damage->getDamage());
    }
}