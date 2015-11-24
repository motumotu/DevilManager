//-----------------------------------------------------------
// StorySelectState.h
// ストーリー選択画面の状態
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"

class StorySelectState {
public:
    static const int NONE = 0;
    static const int BUTTON_BACK = 1;
    static const int BUTTON_DECISION = 2;
    static const int DECK_SELECT_LEFT = 3;
    static const int DECK_SELECT_RIGHT = 4;
    static const int STORY_AREA = 5;
    static const int DECK_AREA = 6;
private:
    GameData *game_data;   // ゲームデータ
    SaveData *save_data;   // セーブデータ
    int mouse_x;           // マウス座標x
    int mouse_y;           // マウス座標y
    int deck_num;          // デッキ番号
    int story_num;         // ストーリー番号
    int chapter_num;       // チャプター番号
public:
    StorySelectState(GameData*);    // コンストラクタ
    ~StorySelectState();            // デストラクタ
    void init();                    // 初期化
    void update();                  // 更新
    void updateMousePos(int, int);  // マウス座標更新
    void deckSelectLeft();          // デッキ選択を左に
    void deckSekectRight();         // デッキ選択を右に
    void selectStory(int);          // ストーリーを選択
    
    int getMousePosObject();             // マウス座標の物体取得
    int getPosObject(int, int);          // その座標にある物体取得
    bool isPosButtonBack(int,int);       // 戻るボタンか
    bool isPosButtonDecision(int, int);  // 決定ボタンか
    bool isPosDeckSelectLeft(int, int);  // デッキ選択ボタン左
    bool isPosDeckSelectRight(int, int); // デッキ選択ボタン右
    bool isPosStoryArea(int, int);       // ストーリーエリアか
    bool isPosDeckArea(int, int);        // デッキエリアか
    int getMousePosStory();              // マウスの位置にあるストーリー数取得
    //---- getter
    int getDeckNum();      // デッキ番号取得
    int getStoryNum();     // ストーリー番号取得
    int getChapterNum();   // チャプター番号取得
    int getNowChapterStoryNum(); // 現在チャプターのストーリー数取得
};