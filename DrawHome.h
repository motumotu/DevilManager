//-----------------------------------------------------------
// DrawHome.h
// �z�[����ʂ̕`��
// ����� 2015.03.16
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"

class DrawHome {
private:
    GameData *game_data;            // �Q�[���f�[�^
    GameState *game_state;          // �V�[���}�l�[�W���[
    HomeState *home_state;          // �z�[���̏��
    InputState *input_state;        // ���͏��
    int handl_back;                 // �w�i
    int handl_button[18];           // �{�^��
public:
    DrawHome(GameData*, GameState*); // �R���X�g���N�^
    ~DrawHome();             // �f�X�g���N�^
    void init();             // ������
    void update();           // �X�V
    void loadImage();        // �摜�f�[�^�ǂݍ���
    void draw();             // �S�̕`��
};