//-----------------------------------------------------------
// GameManager.h
// ゲーム制御部
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "DrawManager.h"
#include "FPSManager.h"
#include "SceneManager.h"
#include "GameData.h"
#include "GameState.h"

class GameManager {
private:
    DrawManager *draw_manager;   // 描画制御
    // 音声制御
    FPSManager *fps_manager;     // FPS制御
    SceneManager *scene_manager; // 各シーンの制御

    GameData *game_data;         // ゲームデータ
    GameState *game_state;       // ゲーム状態

public:
    GameManager(GameData*, GameState*); // コンストラクタ
    ~GameManager();              // デストラクタ
    void init();                 // 初期化
    void update();               // 更新

    DrawManager *getDrawManager();
    FPSManager *getFPSManager();
    SceneManager *getSceneManager();
};