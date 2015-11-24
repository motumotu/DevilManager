//-----------------------------------------------------------
// DeckEditState.h
// デッキ編集画面の状態
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"

class DeckEditState {
public:
    static const int NONE = 0;        // 何もなし
    static const int BUTTON_BACK = 1; // 戻るボタン
    static const int DECK_AREA = 2;   // デッキエリア
    static const int CARD_AREA = 3;   // カードエリア
private:
    GameData *game_data;         // ゲームデータ
    SaveData *save_data;         // セーブデータ
    int shift_pos_y;             // シフト座標
    int bar_pos;                 // スライドバーの位置
    int select_deck_num;         // 選択されてるデッキ番号
    int select_now_card;         // 選択中のカード
    int mouse_x;                 // マウス座標
    int mouse_y;                 // マウス座標
public:
    DeckEditState(GameData*);    // コンストラクタ
    ~DeckEditState();            // デストラクタ
    void init();                 // 初期化
    void update();               // 更新
    void updateMousePos(int, int); // マウス座標更新
    void slideBarUp();           // 上にスライド
    void slideBarUp(int);        // 上にスライド
    void slideBarDown();         // 下にスライド
    void slideBarDown(int);      // 下にスライド
    void slideBarAdjustment();   // スライドバーの調整
    void selectDeckAreaCard(int);// デッキエリアのn番目を選択
    void selectCardAreaCard(int);// カードエリアのn番目を選択
    void mouseRelease();         // マウスが離された
    void addDeckAreaCard(int);   // デッキエリアのn番目に選択中のカードを追加
    void addCardAreaCard(int);   // カードエリアのn番目に選択中のカードを追加
    bool isDeckMax();            // デッキが最大か

    int getPosObject(int, int);     // その位置の物体
    int getMousePosObject();        // マウス座標の物体取得
    int getPosCard(int, int);       // その座標のカード取得
    int getMousePosCard();          // マウスの座標位置のカード取得
    int getPosDeckAreaNum(int, int);// その座標がデッキエリアの何番目か取得
    int getPosCardAreaNum(int, int);// その座標がカードエリアの何番目か取得
    bool isPosButtonBack(int, int); // 戻るボタンの位置か
    bool isPosDeckArea(int, int);   // デッキエリアか
    bool isPosCardArea(int, int);   // カードエリアか
    int getShiftPosY();             // シフト
    int getBarPosY();               // バーの位置
    void setSelectDeckNum(int);     // 選択デッキをセット
    int getSelectNowCard();         
};