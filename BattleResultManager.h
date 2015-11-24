//-----------------------------------------------------------
// BattleResultManager.h
// �ΐ팋�ʉ�ʂ̐���
// ����� 2015.03.15
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"

class BattleResultManager {
private:
    GameData *game_data;         // �Q�[���f�[�^
    GameState *game_state;       // �Q�[���̏��
    InputState *input_state;     // ���͏��
public:
    BattleResultManager(GameData*, GameState*); // �R���X�g���N�^
    ~BattleResultManager();      // �f�X�g���N�^
    void init();                 // ������
    void update();               // �X�V
};