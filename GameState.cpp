//-----------------------------------------------------------
// GameState.cpp
// ゲームの状態
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#include "GameState.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
GameState::GameState(GameData* _game_data)
{
    game_data = _game_data;
    input_state = new InputState();
    scene_state = new SceneState(game_data);
    init();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
GameState::~GameState()
{
    delete(scene_state);
    delete(input_state);
}

//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void GameState::init()
{
    is_game_end = false;
}

//-----------------------------------------------------------
// 更新
//-----------------------------------------------------------
void GameState::update()
{
    input_state->update();
    scene_state->update();
}

//-----------------------------------------------------------
// ゲーム終了
//-----------------------------------------------------------
void GameState::gameEnd() { is_game_end = true; }

//===========================================================
// getter
//===========================================================
SceneState *GameState::getSceneState() { return scene_state; }
InputState *GameState::getInputState() { return input_state; }
bool GameState::isGameEnd() { return is_game_end; }