//-----------------------------------------------------------
// DrawHome.cpp
// ホーム画面の描画
// 制作日 2015.03.16
// 制作者 motumotu
//-----------------------------------------------------------
#include "DrawHome.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
DrawHome::DrawHome(GameData *data, GameState *state)
{
    game_data = data;
    game_state = state;
    home_state = state->getSceneState()->getHomeState();
    input_state = state->getInputState();
    loadImage();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
DrawHome::~DrawHome()
{
}

//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void DrawHome::init()
{
}

//-----------------------------------------------------------
// 更新
//-----------------------------------------------------------
void DrawHome::update()
{
}

//-----------------------------------------------------------
// 画像読み込み
//-----------------------------------------------------------
void DrawHome::loadImage()
{
    handl_back = LoadGraph("image/home/back.png");
    LoadDivGraph("image/home/button.png", 18, 6, 3, 280, 100, handl_button);
}

//-----------------------------------------------------------
// 描画
//-----------------------------------------------------------
void DrawHome::draw()
{
     DrawGraph(0, 0, handl_back, TRUE);
     //---- ボタン
     DrawGraph(HomeData::STORY_X, HomeData::STORY_Y, handl_button[home_state->getImageButtonStory()], TRUE);
     DrawGraph(HomeData::BATTLE_X, HomeData::BATTLE_Y, handl_button[home_state->getImageButtonBattle()], TRUE);
     DrawGraph(HomeData::DECK_X, HomeData::DECK_Y, handl_button[home_state->getImageButtonDeck()], TRUE);
     DrawGraph(HomeData::SHOP_X, HomeData::SHOP_Y, handl_button[home_state->getImageButtonShop()], TRUE);
     DrawGraph(HomeData::SAVE_X, HomeData::SAVE_Y, handl_button[home_state->getImageButtonSave()], TRUE);
     DrawGraph(HomeData::SETTING_X, HomeData::SETTING_Y, handl_button[home_state->getImageButtonSetting()], TRUE);
}

//===========================================================
// getter
//===========================================================
