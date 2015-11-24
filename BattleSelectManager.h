//-----------------------------------------------------------
// BattleSelectManager.h
// �ΐ�I����ʂ̐���
// ����� 2015.03.17
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"

class BattleSelectManager {
private:
    GameData *game_data;         // �Q�[���f�[�^
    GameState *game_state;       // �Q�[���̏��
    InputState *input_state;     // ���͏��
    BattleSelectState *battle_select_state; // �ΐ�I����ʂ̏��
    bool scroll_flag;            // �X�N���[�����邩
public:
    BattleSelectManager(GameData*, GameState*); // �R���X�g���N�^
    ~BattleSelectManager();      // �f�X�g���N�^
    void init();                 // ������
    void update();               // �X�V

    void leftClickFirst();       // ���N���b�N�ŏ�
    void leftClickNow();         // ���N���b�N��
    void leftClickEnd();         // ���N���b�N�I����
};