//-----------------------------------------------------------
// DrawDamage.h
// �_���[�W�̕`��
// ����� 2015.03.04
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "DxLib.h"
#include "GameData.h"
#include "BattleState.h"

class DrawDamage {
private:
    GameData* game_data;
    BattleState* battle_state;
    int color_white;    // ��
    int color_red;      // ��
    int font;           // �t�H���g
public:
    DrawDamage(GameData*, BattleState*);// �R���X�g���N�^
    ~DrawDamage();      // �f�X�g���N�^
    void init();        // ��������
    void update();      // �X�V
    void draw();        // �`��
    void loadImage();   // �摜�ǂݍ���
};