//-----------------------------------------------------------
// BattleEnemyManager.h
// �ΐ푊��̐���i�GAI�j
// ����� 2015.03.12
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"
#include "Define.h"

class BattleEnemyManager {
private:
    GameData *game_data;
    GameState *game_state;
    BattleState *battle_state;
    BattleMapState *map_state;
    BattleCardState *card_state;
    BattleAllUnitState *unit_state;
public:
    BattleEnemyManager(GameData*, GameState*); // �R���X�g���N�^
    ~BattleEnemyManager();     // �f�X�g���N�^
    void useCard();            // �J�[�h�g�p
    void updateCommand();      // �R�}���h�X�V
};