//-----------------------------------------------------------
// SettingState.cpp
// セッティング画面の状態
// 制作日 2015.03.25
// 制作者 motumotu
//-----------------------------------------------------------
#include "SettingState.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
SettingState::SettingState(GameData* data)
{
    game_data = data;
    init();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
SettingState::~SettingState()
{

}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
void SettingState::init()
{

}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
void SettingState::update()
{

}

//-----------------------------------------------------------
// setter
//-----------------------------------------------------------
void SettingState::setPreScene(int n) { pre_scene = n; }
//-----------------------------------------------------------
// getter
//-----------------------------------------------------------
int SettingState::getPreScene() { return pre_scene; }