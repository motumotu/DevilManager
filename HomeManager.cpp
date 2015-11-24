//-----------------------------------------------------------
// HomeManager.cpp
// ホーム画面の制御
// 制作日 2015.03.16
// 制作者 motumotu
//-----------------------------------------------------------
#include "HomeManager.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
HomeManager::HomeManager(GameData *data, GameState *state)
{
    game_state = state;
    game_data = data;
    home_state = state->getSceneState()->getHomeState();
    input_state = state->getInputState();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
HomeManager::~HomeManager()
{

}

//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void HomeManager::init()
{
}

//-----------------------------------------------------------
// 更新
//-----------------------------------------------------------
void HomeManager::update()
{
    //---- マウス位置
    home_state->updateMousePos(
        input_state->getPointX(),
        input_state->getPointY());

    //---- クリック処理
    // 左クリックされた瞬間
    if (input_state->getClick(MOUSE_INPUT_LEFT) == 1) {
        clickFirst();
    }
    // クリックが離された瞬間
    if (input_state->getClick(MOUSE_INPUT_LEFT) == 0 && home_state->isClickNow()) {
        clickEnd();
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
// クリック最初
//-----------------------------------------------------------
void HomeManager::clickFirst()
{
    home_state->clickFirst(
        input_state->getPointX(),
        input_state->getPointY());
}

//-----------------------------------------------------------
// クリック最後
//-----------------------------------------------------------
void HomeManager::clickEnd()
{
    int obj = home_state->clickEnd(
        input_state->getPointX(),
        input_state->getPointY());

    // ストーリーボタン
    if (obj == HomeState::CLICK_BUTTON_STORY) {
        game_state->getSceneState()->changeScene(SceneState::SCENE_STORY_SELECT);
    }
    // 対戦ボタン
    if (obj == HomeState::CLICK_BUTTON_BATTLE) {
        game_state->getSceneState()->changeScene(SceneState::SCENE_BATTLE_SELECT);
    }
    // デッキ編成ボタン
    if (obj == HomeState::CLICK_BUTTON_DECK) {
        game_state->getSceneState()->changeScene(SceneState::SCENE_DECKLIST);
    }
    // ショップボタン
    if (obj == HomeState::CLICK_BUTTON_SHOP) {

    }
    // セーブボタン
    if (obj == HomeState::CLICK_BUTTON_SAVE) {

    }
    // 設定ボタン
    if (obj == HomeState::CLICK_BUTTON_SETTING) {
        game_state->getSceneState()->changeScene(SceneState::SCENE_SETTING);
    }
}


//===========================================================
// getter
//===========================================================

