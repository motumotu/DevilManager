//-----------------------------------------------------------
// DeckListState.h
// デッキ一覧画面の状態
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"

class DeckListState {
public:
    static const int NONE = 0;
    static const int BUTTON_BACK = 1;
    static const int BUTTON_EDIT = 2;
    static const int BUTTON_DELETE = 3;
    static const int INPUT_BOX = 4;
private:
    GameData *game_data;       // ゲームデータ
    SaveData *save_data;       // セーブデータ
    int mouse_x;               // マウスの座標x
    int mouse_y;               // マウスの座標y
    int select_deck_num;       // 選択中のデッキ
    int shift_pos_y;           // ずらす座標
    int input_handl;           // 入力ハンドル
    int input_active;          // 入力がアクティブか
    int bar_pos;               // バーの位置
    bool is_bar_click_now;     // バーをクリック中か
public:
    DeckListState(GameData*);  // コンストラクタ
    ~DeckListState();          // デストラクタ
    void init();               // 初期化
    void update();             // 更新
    void updateMousePos(int, int); // マウスの座標更新
    void selectDeckList(int);      // デッキ選択
    void slideBarUp();             // スライドバーを上に
    void slideBarUp(int);          // スライドバーを上に
    void slideBarDown();           // スライドバーを下に
    void slideBarDown(int);        // スライドバーを下に
    void slideBarAdjustment();     // スライドバー調整
    void clickBar();               // バーをクリック
    void leftClickEnd();           // マウスクリック終了

    int getMousePosObject();       // マウスの位置にあるオブジェクト取得
    bool isPosButtonBack(int, int);
    bool isPosButtonEdit(int, int);
    bool isPosButtonDelete(int, int);
    bool isPosInputBox(int, int);       // 入力ボックス
    int isPosDeckList(int, int);        // デッキリストか
    bool isPosBarUp(int, int);          // 上スクロール
    bool isPosBarDown(int, int);        // 下スクロール
    bool isPosBar(int, int);            // スクロールバー
    bool isPosBarArea(int, int);        // スクロールバーエリア
    int getSelectDeckNum();         // 選択中のデッキ取得
    int getShiftPosY();             // ずらす座標取得
    void offInputActive();
    void onInputActive();
    int getInputActive();
    int getInputHandl();
    int getBarPos();                 // スクロールバーの座標取得
};