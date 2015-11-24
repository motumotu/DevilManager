//-----------------------------------------------------------
// BattleEnemyManager.cpp
// 対戦相手の制御（敵AI）
// 制作日 2015.03.12
// 制作者 motumotu
//-----------------------------------------------------------
#include "BattleEnemyManager.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
BattleEnemyManager::BattleEnemyManager(GameData* data, GameState* state)
{
    game_data = data;
    game_state = state;
    battle_state = game_state->getSceneState()->getBattleState();
    map_state = battle_state->getMapState();
    card_state = battle_state->getCardState();
    unit_state = map_state->getUnitState();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
BattleEnemyManager::~BattleEnemyManager()
{

}

//-----------------------------------------------------------
// カード使用
//-----------------------------------------------------------
void BattleEnemyManager::useCard()
{
    int p = 0;
    MapData *map = battle_state->getMapData();

    while (1) {
        bool f = false;
        int n = card_state->getEnHand(p);
        CardData *card = game_data->getAllCardData()->getCardData(n);
        for (int y = 0; y < map->map_size_height; y++) {
            for (int x = 0; x < map->map_size_width; x++) {
                if (battle_state->isPutUnitEn(card, x, y)) {
                    f = true;
                    card_state->useHandCardEn(p);
                    battle_state->createUnitEn(card, x, y);
                    break;
                }
            }
            if (f) break;
        }
        if (!f) {
            p++;
        }
        if (card_state->getEnHandNum() <= p) break;
    }
}

//-----------------------------------------------------------
// コマンド更新
//-----------------------------------------------------------
void BattleEnemyManager::updateCommand()
{
    if (battle_state->getNowTurn() != BattleState::TURN_BATTLE) return;
    for (int i = 0; i < unit_state->getEnUnitNum(); i++) {
        BattleUnitState *unit = unit_state->getEnUnit();

    }
}