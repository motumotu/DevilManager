//-----------------------------------------------------------
// DeckEditManager.h
// �f�b�L�ҏW��ʂ̐���
// ����� 2015.03.17
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"

class DeckEditManager {
private:
    GameData *game_data;            // �Q�[���f�[�^
    GameState *game_state;          // �Q�[���̏��
    DeckEditState *deck_edit_state; // �f�b�L�ҏW��ʂ̏��
    InputState *input_state;        // ���͏��
    SaveData *save_data;            // �Z�[�u�f�[�^
public:
    DeckEditManager(GameData*, GameState*); // �R���X�g���N�^
    ~DeckEditManager();          // �f�X�g���N�^
    void init();                 // ������
    void update();               // �X�V
    void leftClickFirst();       // ���N���b�N�����ꂽ�u��
    void leftClickNow();         // ���N���b�N��
    void leftClickEnd();         // ���N���b�N�̏I���
    void mouseWheel();           // �}�E�X�z�C�[��
};