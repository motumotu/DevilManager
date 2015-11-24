//-----------------------------------------------------------
// BattleSelectState.h
// 対戦選択画面の状態
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"

class BattleSelectState {
public:
    static const int NONE = 0;               // 何もない場所
    static const int BUTTON_BACK = 1;        // 戻るボタン
    static const int BUTTON_BATTLE = 2;      // 対戦ボタン
    static const int DECK_SELECT_LEFT = 3;   // デッキを左に
    static const int DECK_SELECT_RIGHT = 4;  // デッキを右に
    static const int BAR_AREA = 5;           // スクロールバーエリア
    static const int BAR = 6;                // スクロールバー
    static const int SELECT_AREA = 7;        // 選択エリア
private:
    GameData *game_data;          // ゲームデータ
    SaveData *save_data;          // セーブデータ
    int select_num;               // 選択番号
    int my_deck_num;              // 自分のデッキ番号
    int shift_pos_y;              // ずらす座標の量
public:
    BattleSelectState(GameData*); // コンストラクタ
    ~BattleSelectState();         // デストラクタ
    void init();                  // 初期化
    void update();                // 更新
    void upSelectNum();           // 選択番号を上に
    void downSelectNum();         // 選択番号を下に
    void leftMyDeck();            // 左にデッキ移動
    void rightMyDeck();           // 右にデッキ移動
    void scrollBattleSelect(int);  // スクロール
    void adjustmentBar(int, int);  // バーの位置調整
    void selectBattleNum(int);    // 対戦相手選択

    int getPosObject(int, int);        // その座標のオブジェクト取得
    bool isPosButtonBack(int, int);    // 戻るボタンか
    bool isPosButtonBattle(int, int);  // 対戦ボタンか
    bool isPosDeckSelectLeft(int, int);   // デッキ選択左
    bool isPosDeckSelectRight(int, int);  // デッキ選択右
    bool isPosBarArea(int, int);       // スクロールバーエリアか
    bool isPosBar(int, int);           // スクロールバー
    bool isPosSelectArea(int, int);    // 選択エリアか
    int getPosBattleNum(int, int);     // その場所の対戦相手番号取得
    //---- getter
    int getSelectNum();           // 選択番号描画
    int getMyDeckNum();           // 自分のデッキ番号
    int getShiftPosY();           // ずらす座標量取得
    int getMaxShiftPosY();        // 最大スクロール量取得
    double getShiftRate();        // スクロールしている割合取得
    int getBarPos();              // バーの位置取得
};