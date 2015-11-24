//-----------------------------------------------------------
// DrawSetting.h
// �ݒ��ʂ̕`��
// ����� 2015.03.25
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"

class DrawSetting {
public:
private:
    GameData *game_data;        // �Q�[���f�[�^
    GameState *game_state;      // �Q�[���̏��
    SaveData *save_data;        // �Z�[�u�f�[�^
    SettingState *setting_state; // �ݒ���

    int handl_back;             // �w�i
public:
    DrawSetting(GameData*, GameState*); // �R���X�g���N�^
    ~DrawSetting();             // �f�X�g���N�^
    void init();                // ������
    void update();              // �X�V
    void loadImage();           // �摜�ǂݍ���
    void draw();                // �`��
};