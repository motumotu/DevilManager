//-----------------------------------------------------------
// DrawStory.h
// ストーリー画面の描画
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"

class DrawStory {
public:
private:
    GameData *game_data;      // ゲームデータ
    GameState *game_state;    // ゲーム状態
    StoryState *story_state;  // ストーリー状態
    int handl_back;           // 背景
    int handl_window;         // ウインドウ
    int handl_button[8];      // ボタン
    int handl_button_close[2];// 閉じるボタン
    int handl_back_log;       // バックログ
    int handl_button_back[2]; // 戻るボタン
    int handl_bar_area;       // スクロールバーエリア
    int handl_bar;            // スクロールバー
    int font;                 // フォント
    int color_white;          // 色_黒
public:
    DrawStory(GameData*, GameState*); // コンストラクタ
    ~DrawStory();             // デストラクタ
    void init();              // 初期化
    void update();            // 更新
    void draw();              // 描画
    void loadImage();         // 画像読み込み
    void drawButton();        // ボタン描画
    void drawText();          // テキスト描画
    void drawLogText(int, int, StoryTextData*);  // テキスト描画
    void drawBackLog();       // バックログ描画
};