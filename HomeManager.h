//-----------------------------------------------------------
// HomeManager.h
// �z�[����ʂ̐���
// ����� 2015.03.16
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"

class HomeManager {
private:
    GameData *game_data;
    GameState *game_state;
    InputState *input_state;
    HomeState *home_state;
public:
    HomeManager(GameData*, GameState*); // �R���X�g���N�^
    ~HomeManager();           // �f�X�g���N�^
    void init();              // ������
    void update();            // �X�V
    void clickFirst();        // �N���b�N�ŏ�
    void clickEnd();          // �N���b�N�I��
};