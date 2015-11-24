//-----------------------------------------------------------
// DrawDeckEdit.h
// デッキ編集画面の描画
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "DxLib.h"
#include "GameData.h"
#include "GameState.h"

class DrawDeckEdit {
private:
    GameData *game_data;            // ゲームデータ
    GameState *game_state;          // シーンマネージャー
    DeckEditState *deck_edit_state; // ホームの状態
    InputState *input_state;        // 入力状態
    SaveData *save_data;            // セーブデータ
    int handl_back;                 // 背景
    int handl_back1;                // 背景1
    int handl_back2;                // 背景2
    int handl_button_back[2];       // もどるボタン
    int handl_bar;
    int font_10;
    int font_12;
    int color_black;
public:
    DrawDeckEdit(GameData*, GameState*); // コンストラクタ
    ~DrawDeckEdit();             // デストラクタ
    void init();             // 初期化
    void update();           // 更新
    void loadImage();        // 画像データ読み込み
    void draw();             // 全体描画
    void drawDeckArea();     // デッキのカード描画
    void drawCardIntro(CardData*); // カード説明描画
    void drawCardList();     // カードリスト描画
    void drawBar();          // バーの描画
    void drawSelectNowCard();// 選択中のカード描画
};