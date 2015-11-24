//-----------------------------------------------------------
// DrawHome.h
// ホーム画面の描画
// 制作日 2015.03.16
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"

class DrawHome {
private:
    GameData *game_data;            // ゲームデータ
    GameState *game_state;          // シーンマネージャー
    HomeState *home_state;          // ホームの状態
    InputState *input_state;        // 入力状態
    int handl_back;                 // 背景
    int handl_button[18];           // ボタン
public:
    DrawHome(GameData*, GameState*); // コンストラクタ
    ~DrawHome();             // デストラクタ
    void init();             // 初期化
    void update();           // 更新
    void loadImage();        // 画像データ読み込み
    void draw();             // 全体描画
};