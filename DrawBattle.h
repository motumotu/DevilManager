//-----------------------------------------------------------
// DrawBattle.h
// 対戦画面描画
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "DxLib.h"
#include "GameData.h"
#include "GameState.h"
#include "DrawDamage.h"

class DrawBattle {
public:

private:
    GameData* game_data;
    InputState* input_state;
    BattleState* battle_state;
    BattleCardState *card_state;
    DrawDamage* draw_damage;
    ImageData *image_data;
    //---- 画像ハンドル
    int handl_base;
    int handl_map[100];         // マップ画像
    int hand_com_button[14];    // 命令ボタン
    int handl_area_my;          // 自軍エリア
    int handl_area_ene;         // 敵軍エリア
    int handl_area_select;      // エリア選択
    int handl_area_select2;     // エリア選択
    int handl_area_grid;        // エリアグリッド
    int handl_ui_card_back;     // カード背景
    int handl_ui_mp_back;       // mp背景
    int handl_ui_button_cancel; // キャンセルボタン
    int handl_ui_button_end;    // 終了ボタン
    int handl_ui_card_intro;    // カード説明
    int handl_res_win;          // 勝利
    int handl_res_lose;         // 敗北

    int color_white;            // 色_白
    int color_black;            // 色_黒
    int color_blue;             // 色_青
    int color_red;              // 色_赤
    int color_gray;             // 色_グレー
    int color_green;            // 色_緑
    int color_orange;           // 色_オレンジ

    int font_10;
    int font_12;

public:
    DrawBattle(GameData*,GameState*); // コンストラクタ
    ~DrawBattle();              // デストラクタ
    void init();                // 初期化
    void update();              // 更新
    void loadImage();           // 画像読み込み
    void draw();                // 描画
    void drawMap();             // マップ描画
    void drawUnit();            // ユニット描画
    void drawArea();            // エリア描画
    void drawAreaGrid();        // エリアグリッド描画
    void drawAreaMp();          // エリア魔力描画
    void drawSelectUnit();      // 選択中のユニット描画
    void drawUnitArea(BattleUnitState*); // ユニットの領域を描画
    void drawUnitArea(BattleUnitState*,int); // ユニットの領域を描画
    void drawUnitArea(BattleUnitState*, int, int); // ユニットの領域を描画
    void drawSelectMode();      // 選択モード中の描画
    void drawSelectArea(int, int);// 選択エリア描画
    void drawClickSelectArea(); // クリック中の選択エリア
    void drawUI();              // UI描画
    void drawHpBar(BattleUnitState*);// ユニットHPゲージ表示
    void drawHandCard();        // 手札描画
    void drawTimeBar();         // タイムゲージ表示
    void drawCardIntro(CardData*); // カード説明描画
    void drawResult();          // 結果描画
};