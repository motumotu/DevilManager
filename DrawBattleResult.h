//-----------------------------------------------------------
// DrawBattleResult.h
// �ΐ팋�ʉ�ʕ`��
// ����� 2015.03.15
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"

class DrawBattleResult {
private:
    GameData *game_data;         // �Q�[���f�[�^
    GameState *game_state;       // �Q�[���̏��
    int handl;
public:
    DrawBattleResult(GameData*, GameState*); // �R���X�g���N�^
    ~DrawBattleResult();         // �f�X�g���N�^
    void init();                 // ������
    void update();               // �X�V
    void loadImage();           // �摜�ǂݍ���
    void draw();                 // �`��
};