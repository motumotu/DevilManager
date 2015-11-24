//-----------------------------------------------------------
// BattleResultManager.h
// 対戦結果画面の制御
// 制作日 2015.03.15
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"

class BattleResultManager {
private:
    GameData *game_data;         // ゲームデータ
    GameState *game_state;       // ゲームの状態
    InputState *input_state;     // 入力状態
public:
    BattleResultManager(GameData*, GameState*); // コンストラクタ
    ~BattleResultManager();      // デストラクタ
    void init();                 // 初期化
    void update();               // 更新
};