//-----------------------------------------------------------
// BattleResultState.h
// �ΐ팋�ʉ�ʂ̏��
// ����� 2015.03.15
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"

class BattleResultState {
private:
public:
    BattleResultState(GameData*); // �R���X�g���N�^
    ~BattleResultState();         // �f�X�g���N�^
    void init();                  // ������
    void update();                // �X�V
};