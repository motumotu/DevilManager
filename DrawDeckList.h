//-----------------------------------------------------------
// DrawDeckList.h
// デッキ一覧画面の描画
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "DxLib.h"
#include "GameData.h"
#include "GameState.h"

class DrawDeckList {
private:
    GameData *game_data;            // ゲームデータ
    GameState *game_state;          // シーンマネージャー
    DeckListState *deck_list_state; // デッキ一覧画面の状態
    DeckListData *deck_list_data;   // デッキ一覧画面のデータ
    InputState *input_state;        // 入力状態
    SaveData *save_data;            // セーブデータ
    ImageData *image_data;          // 画像データ
    int handl_back;                 // 背景
    int handl_back1;
    int handl_back2;
    int handl_bar;
    int handl_bar_up;
    int handl_bar_down;
    int handl_button_back[2];       // もどるボタン
    int handl_button_edit[2];       // デッキ編集
    int handl_button_delete[2];     // デッキ削除
    int handl_button_deck[2];       // デッキ一覧ボタン
    int font;
    int color_black;
public:
    DrawDeckList(GameData*, GameState*); // コンストラクタ
    ~DrawDeckList();         // デストラクタ
    void init();             // 初期化
    void update();           // 更新
    void loadImage();        // 画像データ読み込み
    void draw();             // 全体描画
    void drawBar();          // バー描画
    void drawButton();       // ボタン系描画
    void drawDeckCard();     // デッキカード描画
    void drawDeckList();     // デッキリスト描画
    void drawDeckName();     // デッキ名描画
};