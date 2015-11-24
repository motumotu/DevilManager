//-----------------------------------------------------------
// SettingManager.h
// �ݒ��ʊǗ�
// ����� 2015.03.25
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "DxLib.h"
#include "GameData.h"
#include "GameState.h"

class SettingManager {
private:
    GameData *game_data;         // �Q�[���f�[�^
    GameState *game_state;       // �Q�[���̏��
    InputState *input_state;     // ���͏��
    SettingState *setting_state; // �ݒ���
public:
    SettingManager(GameData*, GameState*); // �R���X�g���N�^
    ~SettingManager();          // �f�X�g���N�^
    void init();                 // ������
    void update();               // �X�V
    void leftClickFirst();       // ���N���b�N���ꂽ�u��
    void leftClickNow();         // ���N���b�N����Ă���� 
    void leftClickEnd();         // ���N���b�N�I����
};