//-----------------------------------------------------------
// StoryState.h
// ストーリーの状態
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"

class StoryState {
public:
    static const int NONE = 0;
    static const int BUTTON_AUTO = 1;
    static const int BUTTON_SKIP = 2;
    static const int BUTTON_LOG = 3;
    static const int BUTTON_CONFIG = 4;
    static const int BUTTON_CLOSE = 5;
    static const int BUTTON_BACK = 6;
    static const int BAR_AREA = 7;
private:
    GameData *game_data;       // ゲームデータ
    int mouse_x;               // マウス座標x
    int mouse_y;               // マウス座標y
    int now_text_num;          // 現在のテキスト番号
    int now_text_len;          // 現在のテキスト長
    int cnt_frame;             // 経過フレーム
    bool is_draw_end;          // 描画終了してるか
    bool is_close;             // ウインドウを閉じているか
    bool is_auto;              // オートか
    bool is_next_text;         // 次の文に行くか
    bool is_back_log;          // バックログ表示中
    int backlog_pos;           // バックログの場所
    int bar_pos;               // バーの位置
public:
    StoryState(GameData*);     // コンストラクタ
    ~StoryState();             // デストラクタ
    void init();               // 初期化
    void update();             // 更新
    void updateMousePos(int, int); // マウス座標

    //---- テキスト関連
    std::string getNowName();  // 現在の名前取得
    std::string getNowText1(); // 現在のテキスト１取得
    std::string getNowText2(); // 現在のテキスト２取得
    std::string getNowText3(); // 現在のテキスト３取得
    int isJapaneseCharacter(unsigned char); // 日本語か
    void changeNextText();           // 次のテキスト
    void fullText();                 // 全文表示
    //----- オブジェクト関連
    int getMousePosObject(); // マウスの座標の物体取得
    bool isPosButtonAuto(int, int);
    bool isPosButtonSkip(int, int);
    bool isPosButtonLog(int, int);
    bool isPosButtonConfig(int, int);
    bool isPosButtonClose(int, int);
    bool isPosButtonBack(int, int);
    bool isPosBarArea(int, int);
    //---- バックログ
    int getBarPosY();           // バーの位置取得
    void AdjustingBar();        // バーの位置調整
    void changeBarMousePos();   // バーの位置変更
    void backlogUp();           // バックログを上に
    void backlogDown();         // バックログを下に

    //---- setter
    void setNowTextNum(int);   // 現在テキスト番号設定
    void setIsClose(bool);     // ウインドウを閉じてるか
    void setIsAuto(bool);      // オートかを設定
    void setIsBackLog(bool);   // バックログ表示中
    //---- getter
    int getNowTextNum();       // 現在テキスト番号取得
    StoryTextData *getNowStoryTextData();
    std::string getNowText();  // 現在のテキスト取得
    bool isDrawEnd();          // 描画終了してるか
    bool isClose();            // ウィンドウを閉じとんのか
    bool isAuto();             // オートか
    bool isNextText();         // 次のテキスト行くか
    bool isBackLog();          // バックログ表示中
    int getBacklogPos();       // バックログ場所
};