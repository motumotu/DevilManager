//-----------------------------------------------------------
// DrawManager.h
// 描画制御
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"
#include "DrawTitle.h"
#include "DrawHome.h"
#include "DrawBattle.h"
#include "DrawBattleResult.h"
#include "DrawStorySelect.h"
#include "DrawStory.h"
#include "DrawDeckList.h"
#include "DrawDeckEdit.h"
#include "DrawBattleSelect.h"
#include "DrawSetting.h"

class DrawManager {
private:
    DrawTitle *draw_title;                // タイトル画面
    DrawHome *draw_home;                  // ホーム画面
    DrawBattle *draw_battle;              // 対戦画面
    DrawBattleResult *draw_battle_result; // 対戦結果画面
    DrawStorySelect *draw_story_select;   // ストーリー選択画面の描画
    DrawStory *draw_story;                // ストーリー画面の描画
    DrawDeckList *draw_deck_list;         // デッキ一覧画面
    DrawDeckEdit *draw_deck_edit;         // デッキ一覧画面
    DrawBattleSelect *draw_battle_select; // 対戦選択画面
    DrawSetting *draw_setting;            // 設定画面の描画
    //----------
    GameData *game_data;                  // ゲームデータ
    GameState *game_state;                // ゲームの状態
    SceneState *scene_state;              // シーンの状態
    int color_black;
public:
    DrawManager(GameData*, GameState*);   // コンストラクタ
    ~DrawManager();                       // デストラクタ
    void init();                          // 初期化
    void update();                        // 更新
    void draw();                          // 描画
};