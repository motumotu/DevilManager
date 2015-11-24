//-----------------------------------------------------------
// DrawTitle.h
// タイトル画面の描画
// 制作日 2015.03.15
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"

class DrawTitle {
private:
    GameData *game_data;      // ゲームデータ
    GameState *game_state;    // ゲーム状態
    TitleState *title_state;  // タイトル画面の状態
    TitleData *title_data;    // タイトル画面のデータ
    int handl_circle_logo;    // サークルロゴ
    int handl_game_logo;      // ゲームロゴ
    int handl_button[10];     // ボタン
    int handl_back;           // 背景
    int color_white;          // 色_白
public:
    DrawTitle(GameData*, GameState*);     // コンストラクタ
    ~DrawTitle();             // デストラクタ
    void init();              // 初期化
    void loadImage();         // 画像読み込み
    void update();            // 更新
    void draw();              // 描画
    void drawButton();        // ボタン描画
};