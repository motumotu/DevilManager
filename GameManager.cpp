//-----------------------------------------------------------
// GameManager.cpp
// ゲーム制御部
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#include "GameManager.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
GameManager::GameManager(GameData* data, GameState* state)
{
    game_data = data;
    game_state = state;
    fps_manager = new FPSManager();
    draw_manager = new DrawManager(data, state);
    scene_manager = new SceneManager(data, state);
    init();     // 初期処理
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
GameManager::~GameManager()
{
    delete(scene_manager);
    delete(draw_manager);
    delete(fps_manager);
}

//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void GameManager::init()
{
    fps_manager->init();
}

//-----------------------------------------------------------
// 更新
//-----------------------------------------------------------
void GameManager::update()
{
    scene_manager->update();
}

//===========================================================
// getter
//===========================================================
DrawManager *GameManager::getDrawManager() { return draw_manager; }
FPSManager *GameManager::getFPSManager() { return fps_manager; }
SceneManager *GameManager::getSceneManager() { return scene_manager; }