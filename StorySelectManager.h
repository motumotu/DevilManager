//-----------------------------------------------------------
// StorySelectManager.h
// ストーリー選択画面の制御
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"

class StorySelectManager {
public:
private:
    GameData *game_data;
    GameState *game_state;
    InputState *input_state;
    StorySelectState *story_select_state;
public:
    StorySelectManager(GameData*, GameState*);// コンストラクタ
    ~StorySelectManager();       // デストラクタ
    void init();                 // 初期化
    void update();               // 更新
    void leftClickFirst();       // 左クリックされた瞬間
    void leftClickNow();         // 左クリックされている間 
    void leftClickEnd();         // 左クリック終了時
};