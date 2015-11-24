//-----------------------------------------------------------
// DeckListManager.h
// �f�b�L�ꗗ��ʂ̐���
// ����� 2015.03.17
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "DxLib.h"
#include "GameData.h"
#include "GameState.h"

class DeckListManager {
private:
    GameData *game_data;         // �Q�[���f�[�^
    GameState *game_state;       // �Q�[���̏��
    InputState *input_state;     // ���͏��
    DeckListState *deck_list_state; // 
public:
    DeckListManager(GameData*, GameState*); // �R���X�g���N�^
    ~DeckListManager();          // �f�X�g���N�^
    void init();                 // ������
    void update();               // �X�V
    void leftClickFirst();       // ���N���b�N���ꂽ�u��
    void leftClickNow();         // ���N���b�N����Ă���� 
    void leftClickEnd();         // ���N���b�N�I����
    void mouseWheel();           // �}�E�X�z�C�[��
};