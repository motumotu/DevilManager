//-----------------------------------------------------------
// SceneState.cpp
// 各シーンの状態
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#include "SceneState.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
SceneState::SceneState(GameData* _game_data)
{
    game_data = _game_data;
    save_data = game_data->getSaveData();
    title_state = new TitleState(game_data);
    home_state = new HomeState(game_data);
    battle_state = new BattleState(game_data);
    battle_result_state = new BattleResultState(game_data);
    story_select_state = new StorySelectState(game_data);
    story_state = new StoryState(game_data);
    deck_list_state = new DeckListState(game_data);
    deck_edit_state = new DeckEditState(game_data);
    battle_select_state = new BattleSelectState(game_data);
    setting_state = new SettingState(game_data);
    init();     // 初期処理
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
SceneState::~SceneState()
{
    delete(setting_state);
    delete(battle_select_state);
    delete(deck_edit_state);
    delete(deck_list_state);
    delete(story_state);
    delete(story_select_state);
    delete(battle_result_state);
    delete(battle_state);
    delete(home_state);
    delete(title_state);
}

//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void SceneState::init()
{
    now_scene = SCENE_TITLE;
    is_fade_out_now = 0;
    is_fade_in_now = 0;
}

//-----------------------------------------------------------
// 更新
//-----------------------------------------------------------
void SceneState::update()
{
    //---- フェードイン中
    if (is_fade_in_now) {
        fade_val -= 20;
        if (fade_val <= 0) {
            fade_val = 0;
            is_fade_in_now = 0;
        }
        return;
    }
    //---- フェードアウト中
    if (is_fade_out_now) {
        fade_val += 20;
        if (fade_val >= 255) {
            change();
        }
        return;
    }
    //---- タイトル画面
    if (now_scene == SCENE_TITLE) {
        title_state->update();
    }
    //---- ホーム画面
    else if (now_scene == SCENE_HOME) {
        home_state->update();
    }
    //---- 対戦画面
    else if (now_scene == SCENE_BATTLE) {
        battle_state->update();
    }
    //---- 対戦結果画面
    else if (now_scene == SCENE_BATTLE_RESULT) {
        battle_result_state->update();
    }
    //---- ストーリー選択画面
    else if (now_scene == SCENE_STORY_SELECT) {
        story_select_state->update();
    }
    //---- ストーリー画面
    else if (now_scene == SCENE_STORY) {
        story_state->update();
    }
    //---- デッキ一覧画面
    else if (now_scene == SCENE_DECKLIST) {
        deck_list_state->update();
    }
    //---- デッキ編集画面
    else if (now_scene == SCENE_DECKEDIT) {
        deck_edit_state->update();
    }
    //---- 対戦選択画面
    else if (now_scene == SCENE_BATTLE_SELECT) {
        battle_select_state->update();
    }
    //---- 設定画面
    else if (now_scene == SCENE_SETTING) {
        setting_state->update();
    }
}

//-----------------------------------------------------------
// シーン変更
//-----------------------------------------------------------
void SceneState::changeScene(int scene)
{
    // 対戦選択画面 → 対戦画面
    if (now_scene == SCENE_BATTLE_SELECT && scene == SCENE_BATTLE) {
        int n = battle_select_state->getSelectNum();
        battle_state->battleInit();
        // 自軍デッキセット
        DeckData *deck = save_data->getDeckData(battle_select_state->getMyDeckNum());
        battle_state->getCardState()->setMyDeck(deck);
        // 相手デッキセット
        deck = game_data->getAllBattleData()->getBattleData(n)->getDeckData();
        battle_state->getCardState()->setEnDeck(deck);
        // マップデータセット
        int map_num = game_data->getAllBattleData()->getBattleData(n)->getMapNum();
        MapData *map = game_data->getAllMapData()->getMapData(map_num);
        battle_state->setMapData(map);
        // 設定
        battle_state->battleSetting();
    }
    // ストーリー → 対戦画面
    if (now_scene == SCENE_STORY && scene == SCENE_BATTLE) {
        battle_state->battleInit();
        // 自軍デッキセット
        DeckData *deck = save_data->getDeckData(story_select_state->getDeckNum());
        battle_state->getCardState()->setMyDeck(deck);
        // 敵軍デッキセット
        int n = story_select_state->getStoryNum();
        deck = game_data->getAllStoryEnemyData()->getStoryEnemyData(n)->getDeckData();
        battle_state->getCardState()->setEnDeck(deck);
        // マップデータセット
        int map_num = game_data->getAllStoryEnemyData()->getStoryEnemyData(n)->getMapNum();
        MapData *map = game_data->getAllMapData()->getMapData(map_num);
        battle_state->setMapData(map);
        // 設定
        battle_state->battleSetting();
    }
    // → 設定画面
    if (scene == SCENE_SETTING) {
        setting_state->setPreScene(now_scene);
    }
    change_scene = scene;
    is_fade_out_now = 1;
    fade_val = 0;
}

//-----------------------------------------------------------
// チェンジ
//-----------------------------------------------------------
void SceneState::change()
{
    now_scene = change_scene;
    is_fade_in_now = 1;
    is_fade_out_now = 0;
    fade_val = 255;
}

//===========================================================
// getter
//===========================================================
TitleState *SceneState::getTitleState() { return title_state; }
HomeState *SceneState::getHomeState() { return home_state; }
BattleState *SceneState::getBattleState() { return battle_state; }
BattleResultState *SceneState::getBattleResultState() { return battle_result_state; }
StorySelectState *SceneState::getStorySelectState() { return story_select_state; }
StoryState *SceneState::getStoryState() { return story_state; }
DeckListState *SceneState::getDeckListState() { return deck_list_state; }
DeckEditState *SceneState::getDeckEditState() { return deck_edit_state; }
BattleSelectState *SceneState::getBattleSelectState() { return battle_select_state; }
SettingState *SceneState::getSettingState() { return setting_state; }
int SceneState::getNowScene() { return now_scene; }
int SceneState::getIsFadeOutNow() { return is_fade_out_now; }
int SceneState::getIsFadeInNow() { return is_fade_in_now; }
int SceneState::getFadeVal() { return fade_val; }