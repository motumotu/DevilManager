//-----------------------------------------------------------
// BattleEnemyManager.h
// 対戦相手の制御（敵AI）
// 制作日 2015.03.12
// 制作者 motumotu
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
    BattleEnemyManager(GameData*, GameState*); // コンストラクタ
    ~BattleEnemyManager();     // デストラクタ
    void useCard();            // カード使用
    void updateCommand();      // コマンド更新
};