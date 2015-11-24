//-----------------------------------------------------------
// SettingState.h
// �Z�b�e�B���O��ʂ̏��
// ����� 2015.03.25
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"

class SettingState {
public:
private:
    GameData *game_data;       // �Q�[���f�[�^
    int pre_scene;             // �O�V�[��
public:
    SettingState(GameData*);   // �R���X�g���N�^
    ~SettingState();           // �f�X�g���N�^
    void init();               // ������
    void update();             // �X�V
    void setPreScene(int);     // �O�V�[���ݒ�
    int getPreScene();         // �O�V�[���擾
};