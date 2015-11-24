//-----------------------------------------------------------
// SettingManager.cpp
// 設定画面管理
// 制作日 2015.03.25
// 制作者 motumotu
//-----------------------------------------------------------
#include "SettingManager.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
SettingManager::SettingManager(GameData *data, GameState *state)
{
    game_data = data;
    game_state = state;
    input_state = state->getInputState();
    setting_state = state->getSceneState()->getSettingState();

}
//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
SettingManager::~SettingManager()
{

}

//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void SettingManager::init()
{


}
//-----------------------------------------------------------
// 更新処理
//-----------------------------------------------------------
void SettingManager::update()
{
    //---- マウス座標
    //---- クリック処理
    // 左クリックされた瞬間
    if (input_state->getClick(MOUSE_INPUT_LEFT) == 1) {
        leftClickFirst();
    }
    // 左クリックが押されている間
    if (input_state->getClick(MOUSE_INPUT_LEFT) > 1) {
        leftClickNow();
    }
    // クリックが離された瞬間
    if (input_state->isRereaseClick(MOUSE_INPUT_LEFT)) {
        leftClickEnd();
    }
}

//-----------------------------------------------------------
// 左クリックの最初
//-----------------------------------------------------------
void SettingManager::leftClickFirst()
{
    int pre_scene = setting_state->getPreScene();
    game_state->getSceneState()->changeScene(pre_scene);
}

//-----------------------------------------------------------
// 左クリック中
//-----------------------------------------------------------
void SettingManager::leftClickNow()
{

}

//-----------------------------------------------------------
// 左クリックの最後
//-----------------------------------------------------------
void SettingManager::leftClickEnd()
{

}