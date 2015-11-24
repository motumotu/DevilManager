//-----------------------------------------------------------
// HomeManager.h
// ホーム画面の制御
// 制作日 2015.03.16
// 制作者 motumotu
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
    HomeManager(GameData*, GameState*); // コンストラクタ
    ~HomeManager();           // デストラクタ
    void init();              // 初期化
    void update();            // 更新
    void clickFirst();        // クリック最初
    void clickEnd();          // クリック終了
};