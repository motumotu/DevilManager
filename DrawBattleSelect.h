//-----------------------------------------------------------
// DrawBattleSelect.h
// デッキ一覧画面の描画
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "DxLib.h"
#include "GameData.h"
#include "GameState.h"

class DrawBattleSelect {
private:
    GameData *game_data;            // ゲームデータ
    GameState *game_state;          // シーンマネージャー
    BattleSelectState *battle_select_state; // ホームの状態
    InputState *input_state;        // 入力状態
    ImageData *image_data;          // 画像データ
    SaveData *save_data;            // セーブデータ

    int handl_back;                 // 背景
    int handl_back_1;               // 背景の上にかぶせるやつ
    int handl_back_2;               // 背景の上にかぶせるやつ
    int handl_button_back[2];       // 戻るボタン
    int handl_button_battle[2];     // 対戦ボタン
    int handl_select;               // 選択マス
    int handl_select_now;           // 現在選択中か
    int handl_chara[10];            // キャライラスト
    int handl_lank;                 // ランク
    int handl_select_left[2];       // 左選択
    int handl_select_right[2];      // 右選択
    int handl_bar;
    int font;                       // フォント
    int color_black;                // 色_黒
public:
    DrawBattleSelect(GameData*, GameState*); // コンストラクタ
    ~DrawBattleSelect();             // デストラクタ
    void init();             // 初期化
    void update();           // 更新
    void loadImage();        // 画像データ読み込み
    void draw();             // 全体描画
    void drawAllOpponent();  // 対戦相手描画
    void drawOpponent(int, int);// 対戦相手描画
    void drawEnemyDeck();    // デッキ描画
    void drawBattleData();   // 対戦データ描画
    void drawMyDeck();       // 自分のデッキ描画
    void drawDeckSelect();   // デッキ選択描画
    void drawBar();          // スクロールバー描画
    void drawButton();       // ボタン描画
};