//-----------------------------------------------------------
// BattleResultManager.cpp
// 対戦結果画面の制御
// 制作日 2015.03.15
// 制作者 motumotu
//-----------------------------------------------------------
#include "BattleResultManager.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
BattleResultManager::BattleResultManager(GameData* data, GameState* state)
{
    game_data = data;
    game_state = state;
    input_state = state->getInputState();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
BattleResultManager::~BattleResultManager()
{

}

//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void BattleResultManager::init()
{

}

//-----------------------------------------------------------
// 更新
//-----------------------------------------------------------
void BattleResultManager::update()
{
    // 左クリックされた瞬間
    if (input_state->getClick(MOUSE_INPUT_LEFT) == 1) {
        game_state->getSceneState()->changeScene(SceneState::SCENE_HOME);
    }
}