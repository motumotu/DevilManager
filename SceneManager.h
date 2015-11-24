//-----------------------------------------------------------
// SceneManager.h
// 各シーンの制御
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"
#include "TitleManager.h"
#include "HomeManager.h"
#include "BattleManager.h"
#include "BattleResultManager.h"
#include "StorySelectManager.h"
#include "StoryManager.h"
#include "DeckListManager.h"
#include "DeckEditManager.h"
#include "BattleSelectManager.h"
#include "SettingManager.h"

class SceneManager {
public:

private:
    TitleManager *title_manager;                // タイトル画面
    HomeManager *home_manager;                  // ホーム画面
    BattleManager *battle_manager;              // 対戦画面
    BattleResultManager *battle_result_manager; // 対戦結果画面
    StorySelectManager *story_select_manager;   // ストーリー選択画面
    StoryManager *story_manager;                // ストーリー画面
    DeckListManager *deck_list_manager;         // デッキ一覧画面
    DeckEditManager *deck_edit_manager;         // デッキ編集画面
    BattleSelectManager *battle_select_manager; // 対戦選択画面
    SettingManager *setting_manager;            // 設定画面

    GameData *game_data;            // ゲームデータ
    GameState *game_state;          // シーンマネージャー
public:
    SceneManager(GameData*,GameState*); // コンストラクタ
    ~SceneManager();             // デストラクタ
    void init();                 // 初期化
    void update();               // 更新
};