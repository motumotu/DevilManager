//-----------------------------------------------------------
// BattleManager.h
// 対戦画面の制御
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"
#include "BattleEnemyManager.h"
#include "Define.h"

class BattleManager {
private:
    GameData *game_data;         // ゲームデータ
    GameState *game_state;       // 対戦状態
    BattleEnemyManager* enemy_manager;
    
    BattleState *battle_state;
    BattleMapState *map_state;
    BattleCardState *card_state;
    InputState *input_state;
public:
    BattleManager(GameData*, GameState*); // コンストラクタ
    ~BattleManager();               // デストラクタ
    void init();                    // 初期化
    void update();                  // 更新
    void clickProcess();            // クリック処理
    void rightClickProcess();       // 右クリック処理
    void leftClickProcess();        // 左クリック処理

    void createMyUnit(int);         // 自軍ユニット生成
    void createMyUnit(int,int,int); // 自軍ユニット生成
    void createEnUnit(int,int,int); // 敵軍ユニット生成
};