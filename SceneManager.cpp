//-----------------------------------------------------------
// SceneManager.cpp
// 各シーンの制御
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#include "SceneManager.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
SceneManager::SceneManager(GameData *data, GameState *state)
{
    game_data = data;
    game_state = state;
    title_manager = new TitleManager(data, state);
    home_manager = new HomeManager(data, state);
    battle_manager = new BattleManager(data, state);
    battle_result_manager = new BattleResultManager(data, state);
    story_select_manager = new StorySelectManager(data, state);
    story_manager = new StoryManager(data, state);
    deck_list_manager = new DeckListManager(data, state);
    deck_edit_manager = new DeckEditManager(data, state);
    battle_select_manager = new BattleSelectManager(data, state);
    setting_manager = new SettingManager(data, state);
    init();       // 初期処理
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
SceneManager::~SceneManager()
{
    delete(setting_manager);
    delete(battle_select_manager);
    delete(deck_edit_manager);
    delete(deck_list_manager);
    delete(story_manager);
    delete(story_select_manager);
    delete(battle_result_manager);
    delete(battle_manager);
    delete(home_manager);
    delete(title_manager);
}

//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void SceneManager::init()
{
}

//-----------------------------------------------------------
// 更新
//-----------------------------------------------------------
void SceneManager::update()
{
    //---- フェード中
    if (game_state->getSceneState()->getIsFadeInNow() ||
        game_state->getSceneState()->getIsFadeOutNow()) {
        return;
    }

    int scene = game_state->getSceneState()->getNowScene();
    //---- タイトル画面
    if (scene == SceneState::SCENE_TITLE) {
        title_manager->update();
    }
    //---- ホーム画面
    else if (scene == SceneState::SCENE_HOME) {
        home_manager->update();
    }
    //---- 対戦画面
    else if (scene == SceneState::SCENE_BATTLE) {
        battle_manager->update();
    }
    //---- 対戦結果画面
    else if (scene == SceneState::SCENE_BATTLE_RESULT) {
        battle_result_manager->update();
    }
    //---- ストーリー選択画面
    else if (scene == SceneState::SCENE_STORY_SELECT) {
        story_select_manager->update();
    }
    //---- ストーリー画面
    else if (scene == SceneState::SCENE_STORY) {
        story_manager->update();
    }
    //---- デッキ一覧画面
    else if (scene == SceneState::SCENE_DECKLIST) {
        deck_list_manager->update();
    }
    //---- デッキ編集画面
    else if (scene == SceneState::SCENE_DECKEDIT) {
        deck_edit_manager->update();
    }
    //---- 対戦選択画面
    else if (scene == SceneState::SCENE_BATTLE_SELECT) {
        battle_select_manager->update();
    }
    //---- 設定画面
    else if (scene == SceneState::SCENE_SETTING) {
        setting_manager->update();
    }
}

//===========================================================
// getter
//===========================================================

