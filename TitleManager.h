//-----------------------------------------------------------
// TitleManager.h
// タイトル画面の制御
// 制作日 2015.03.15
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"

class TitleManager {
private:
    GameData *game_data;
    GameState *game_state;
    InputState *input_state;
    TitleState *title_state;
public:
    TitleManager(GameData*, GameState*); // コンストラクタ
    ~TitleManager();           // デストラクタ
    void init();               // 初期化
    void update();             // 更新
    void clickFirst();         // 最初から
    void clickContinue();      // 続きから
    void clickSetting();       // システム設定
    void clickSite();          // 公式サイト
    void clickEnd();           // ゲーム終了
};