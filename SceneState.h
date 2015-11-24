//-----------------------------------------------------------
// SceneState.h
// 各シーンの状態
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "TitleState.h"
#include "HomeState.h"
#include "BattleState.h"
#include "BattleResultState.h"
#include "StorySelectState.h"
#include "StoryState.h"
#include "DeckListState.h"
#include "DeckEditState.h"
#include "BattleSelectState.h"
#include "SettingState.h"

class SceneState {
public:
    static const int SCENE_TITLE = 0;         // タイトル
    static const int SCENE_HOME = 1;          // ホーム
    static const int SCENE_BATTLE = 2;        // 対戦
    static const int SCENE_BATTLE_RESULT = 3; // 対戦結果
    static const int SCENE_STORY_SELECT = 4;  // ストーリー選択
    static const int SCENE_BATTLE_SELECT = 5; // 対戦選択
    static const int SCENE_STORY = 6;         // ストーリー画面
    static const int SCENE_DECKLIST = 7;      // デッキ画面
    static const int SCENE_DECKEDIT = 8;      // デッキ編集画面
    static const int SCENE_SETTING = 9;       // 設定画面
private:
    GameData *game_data;                    // ゲームデータ
    SaveData *save_data;                    // セーブデータ
    TitleState *title_state;                // タイトル画面
    HomeState *home_state;                  // ホーム画面
    BattleState *battle_state;              // 対戦画面
    BattleResultState *battle_result_state; // 対戦結果画面
    StorySelectState * story_select_state;  // ストーリー選択画面
    StoryState *story_state;                // ストーリー画面
    DeckListState *deck_list_state;         // デッキ一覧画面
    DeckEditState *deck_edit_state;         // デッキ編集画面
    BattleSelectState *battle_select_state; // 対戦選択画面
    SettingState *setting_state;            // 設定画面

    int now_scene;             // 現在シーン
    int change_scene;          // 変化後のシーン
    int is_fade_out_now;       // フェードアウト中か
    int is_fade_in_now;        // フェードイン中か
    int fade_val;              // フェード量取得
public:
    SceneState(GameData*);     // コンストラクタ
    ~SceneState();             // デストラクタ
    void init();               // 初期化
    void update();             // 更新
    void changeScene(int);     // シーン変更
    void change();             // チェンジ

    TitleState *getTitleState();               // タイトル画面状態取得
    HomeState *getHomeState();                 // ホーム画面状態取得
    BattleState *getBattleState();             // 対戦画面状態取得
    BattleResultState *getBattleResultState(); // 対戦結果画面状態取得
    StorySelectState *getStorySelectState();   // ストーリー選択画面状態
    StoryState *getStoryState();               // ストーリー画面状態取得
    DeckListState *getDeckListState();         // デッキ一覧画面状態取得
    DeckEditState *getDeckEditState();         // デッキ一覧画面状態取得
    BattleSelectState *getBattleSelectState(); // 対戦選択画面状態取得
    SettingState *getSettingState();           // 設定画面の取得
    int getNowScene();                         // 現在のシーン取得
    int getIsFadeOutNow();                     // フェード中か
    int getIsFadeInNow();                      // フェード中か
    int getFadeVal();                          // フェード量取得
};