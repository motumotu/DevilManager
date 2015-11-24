//-----------------------------------------------------------
// StoryManager.h
// ストーリーの制御
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"
class StoryManager {
public:
private:
    GameData *game_data;
    GameState *game_state;
    InputState *input_state;
    StoryState *story_state;
    int wheel;
public:
    StoryManager(GameData*, GameState*);     // コンストラクタ
    ~StoryManager();            // デストラクタ
    void init();               // 初期化
    void update();             // 更新
    void leftClickFirst();       // 左クリックされた瞬間
    void leftClickNow();         // 左クリックされている間 
    void leftClickEnd();         // 左クリック終了時
    void mouseWheel();          // マウスホイール
    void nextText();            // 次のテキストへ
};