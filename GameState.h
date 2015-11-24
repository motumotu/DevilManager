//-----------------------------------------------------------
// GameState.h
// ゲームの状態
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "InputState.h"
#include "SceneState.h"

class GameState {
private:
    GameData *game_data;
    InputState *input_state;   // 入力状態
    // システム状態
    // プレイヤー状態
    SceneState *scene_state;   // 各シーン状態

    bool is_game_end;          // ゲーム終了か
public:
    GameState(GameData*);      // コンストラクタ
    ~GameState();              // デストラクタ
    void init();               // 初期化
    void update();             // 更新
    void gameEnd();            // ゲーム終了
    SceneState *getSceneState(); // シーン状態取得
    InputState *getInputState(); 
    bool isGameEnd();
};