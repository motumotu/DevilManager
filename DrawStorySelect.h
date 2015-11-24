//-----------------------------------------------------------
// DrawStorySelect.h
// ストーリー選択画面の描画
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"

class DrawStorySelect {
public:
private:
    GameData *game_data;        // ゲームデータ
    GameState *game_state;      // ゲームの状態
    StorySelectState *story_select_state;
    SaveData *save_data;

    int handl_back;                 // 背景画像
    int handl_button_back[2];       // 戻るボタン
    int handl_button_decision[2];   // 決定ボタン
    int handl_deck_select_left[2];  // 左選択ボタン
    int handl_deck_select_right[2]; // 右選択ボタン
    int handl_story[10][9];         // ストーリー
    int handl_story_select;         // 選択中ストーリー
    int handl_rank;                 // ランク
    int handl_mouseon;

    int color_black;                // 色黒
    int font;                       // フォント
public:
    DrawStorySelect(GameData*, GameState*); // コンストラクタ
    ~DrawStorySelect();         // デストラクタ
    void init();                // 初期化
    void update();              // 更新
    void loadImage();           // 画像読み込み
    void draw();                // 描画
    void drawMyDeck();          // 自分デッキ描画
    void drawStory();           // ストーリー描画
    void drawStoryInfo();       // ストーリー情報描画
    void drawDeckCard();        // デッキのカード描画
};