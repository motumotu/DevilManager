//-----------------------------------------------------------
// BattleManager.h
// �ΐ��ʂ̐���
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"
#include "BattleEnemyManager.h"
#include "Define.h"

class BattleManager {
private:
    GameData *game_data;         // �Q�[���f�[�^
    GameState *game_state;       // �ΐ���
    BattleEnemyManager* enemy_manager;
    
    BattleState *battle_state;
    BattleMapState *map_state;
    BattleCardState *card_state;
    InputState *input_state;
public:
    BattleManager(GameData*, GameState*); // �R���X�g���N�^
    ~BattleManager();               // �f�X�g���N�^
    void init();                    // ������
    void update();                  // �X�V
    void clickProcess();            // �N���b�N����
    void rightClickProcess();       // �E�N���b�N����
    void leftClickProcess();        // ���N���b�N����

    void createMyUnit(int);         // ���R���j�b�g����
    void createMyUnit(int,int,int); // ���R���j�b�g����
    void createEnUnit(int,int,int); // �G�R���j�b�g����
};