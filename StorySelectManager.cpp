//-----------------------------------------------------------
// StorySelectManager.h
// ストーリー選択画面の制御
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#include "StorySelectManager.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
StorySelectManager::StorySelectManager(GameData* data, GameState* state)
{
    game_data = data;
    game_state = state;
    input_state = state->getInputState();
    story_select_state = state->getSceneState()->getStorySelectState();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
StorySelectManager::~StorySelectManager()
{

}
//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void StorySelectManager::init()
{

}

//-----------------------------------------------------------
// 更新処理
//-----------------------------------------------------------
void StorySelectManager::update()
{
    //---- マウス座標
    story_select_state->updateMousePos(
        input_state->getPointX(),
        input_state->getPointY());

    //---- マウス入力処理
    // 左クリックされた瞬間
    if (input_state->getClick(MOUSE_INPUT_LEFT) == 1) {
        leftClickFirst();
    }
    //---- キー入力処理
    // 上
    if (input_state->getKeyState(KEY_INPUT_W) >= 1) {

    }
    // 右
    if (input_state->getKeyState(KEY_INPUT_D) >= 1) {
    }
    // 下
    if (input_state->getKeyState(KEY_INPUT_S) >= 1) {

    }
    // 左
    if (input_state->getKeyState(KEY_INPUT_A) >= 1) {
    }
}

//-----------------------------------------------------------
// 左クリックされた瞬間
//-----------------------------------------------------------
void StorySelectManager::leftClickFirst()
{
    int obj = story_select_state->getPosObject(
        input_state->getPointX(),
        input_state->getPointY());

    //---- 戻るボタン
    if (obj == StorySelectState::BUTTON_BACK) {
        game_state->getSceneState()->changeScene(SceneState::SCENE_HOME);
    }
    //---- 決定ボタン
    if (obj == StorySelectState::BUTTON_DECISION) {
        game_state->getSceneState()->changeScene(SceneState::SCENE_STORY);
    }
    //---- デッキ選択ボタン左
    if (obj == StorySelectState::DECK_SELECT_LEFT) {
        story_select_state->deckSelectLeft();
    }
    //---- デッキ選択ボタン右
    if (obj == StorySelectState::DECK_SELECT_RIGHT) {
        story_select_state->deckSekectRight();
    }
    //---- ストーリーエリア
    if (obj == StorySelectState::STORY_AREA) {
        int n = story_select_state->getMousePosStory();
        if (n != 0) story_select_state->selectStory(n);
    }
}

//-----------------------------------------------------------
// 左クリックされている間 
//-----------------------------------------------------------
void StorySelectManager::leftClickNow()
{

}
//-----------------------------------------------------------
// 左クリック終了時
//-----------------------------------------------------------
void StorySelectManager::leftClickEnd()
{

}