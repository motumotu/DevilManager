//-----------------------------------------------------------
// DrawTitle.cpp
// タイトル画面の描画
// 制作日 2015.03.15
// 制作者 motumotu
//-----------------------------------------------------------
#include "DrawTitle.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
DrawTitle::DrawTitle(GameData *data, GameState *state)
{
    game_data = data;
    game_state = state;
    title_state = state->getSceneState()->getTitleState();
    title_data = data->getTitleData();
    color_white = GetColor(255, 255, 255);
    init();               // 初期処理
    loadImage();          // 画像読み込み
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
DrawTitle::~DrawTitle()
{
    
}

//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void DrawTitle::init()
{
    
}

//-----------------------------------------------------------
// 更新
//-----------------------------------------------------------
void DrawTitle::update()
{
    
}

//-----------------------------------------------------------
// 画像読み込み
//-----------------------------------------------------------
void DrawTitle::loadImage()
{
    handl_circle_logo = LoadGraph("image/title/circle_logo.png");
    handl_game_logo = LoadGraph("image/title/game_logo.png");
    LoadDivGraph("image/title/button.png", 10, 5, 2, 200, 40, handl_button);
    handl_back = LoadGraph("image/title/back.png");
}

//-----------------------------------------------------------
// 描画
//-----------------------------------------------------------
void DrawTitle::draw()
{
    // 背景
    DrawBox(0, 0,
        SystemData::getWindowWidth(),
        SystemData::getWindowHeight(),
        color_white, TRUE);

    // サークルロゴ
    if (title_state->getNowState() == TitleState::STATE_CIRCLE_LOGO) {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, title_state->getAlpha());
        DrawGraph(200, 100, handl_circle_logo, TRUE);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);  // 戻す
    }
    // タイトル
    if (title_state->getNowState() == TitleState::STATE_TITLE) {
        DrawGraph(0, 0, handl_back, TRUE);
        DrawGraph(
            SystemData::getWindowWidth() / 2 - 650 / 2,
            50, handl_game_logo, TRUE);
        drawButton();
    }
}

//-----------------------------------------------------------
// ボタン描画
//-----------------------------------------------------------
void DrawTitle::drawButton()
{
    int image = 0;
    int obj = title_state->getNowMouseOnObj();
    //---- はじめから
    image = 0 + ((obj == TitleState::MOUSEON_NEWGAME) ? 5 : 0);
    DrawGraph(
        title_data->getPosButtonNewgameX(),
        title_data->getPosButtonNewgameY(),
        handl_button[image], TRUE);
    //---- つづきから
    image = 1 + ((obj == TitleState::MOUSEON_CONTINUE) ? 5 : 0);
    DrawGraph(
        title_data->getPosButtonContinueX(),
        title_data->getPosButtonContinueY(),
        handl_button[image], TRUE);
    //----- システム設定
    image = 2 + ((obj == TitleState::MOUSEON_SETTING) ? 5 : 0);
    DrawGraph(
        title_data->getPosButtonSettingX(),
        title_data->getPosButtonSettingY(),
        handl_button[image], TRUE);
    //----- 公式サイト
    image = 3 + ((obj == TitleState::MOUSEON_SITE) ? 5 : 0);
    DrawGraph(
        title_data->getPosButtonSiteX(),
        title_data->getPosButtonSiteY(),
        handl_button[image], TRUE);
    //---- 終了
    image = 4 + ((obj == TitleState::MOUSEON_END) ? 5 : 0);
    DrawGraph(
        title_data->getPosButtonEndX(),
        title_data->getPosButtonEndY(),
        handl_button[image], TRUE);
}
//===========================================================
// getter
//===========================================================