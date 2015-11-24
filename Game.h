//-----------------------------------------------------------
// Game.h
// �Q�[�����S��
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameManager.h"
#include "GameState.h"
#include <ctime>

class Game {
private:
    GameData *game_data;         // �Q�[���̃f�[�^
    GameState *game_state;       // �Q�[���̏��
    GameManager *game_manager;   // �Q�[���̐���
public:
    Game();                      // �R���X�g���N�^
    ~Game();                     // �f�X�g���N�^
    void init();                 // ������
    int update();               // �X�V
    int mainLoop();             // ���C�����[�v
};