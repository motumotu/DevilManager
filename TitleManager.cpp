//-----------------------------------------------------------
// TitleManager.cpp
// タイトル画面の制御
// 制作日 2015.03.15
// 制作者 motumotu
//-----------------------------------------------------------
#include "TitleManager.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
TitleManager::TitleManager(GameData* _game_data, GameState *_game_state)
{
    game_data = _game_data;
    game_state = _game_state;
    input_state = game_state->getInputState();
    title_state = game_state->getSceneState()->getTitleState();
    init();     // 初期処理
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
TitleManager::~TitleManager()
{

}

//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void TitleManager::init()
{

}

//-----------------------------------------------------------
// 更新
//-----------------------------------------------------------
void TitleManager::update()
{
    // マウス座標更新
    title_state->updateMousePos(
        input_state->getPointX(),
        input_state->getPointY());

    // 左クリックされた瞬間
    if (input_state->getClick(MOUSE_INPUT_LEFT) == 1) {
        if (title_state->getNowState() == TitleState::STATE_TITLE) {
            switch (title_state->getNowMouseOnObj()) {
            case TitleState::MOUSEON_NEWGAME: clickFirst(); break;
            case TitleState::MOUSEON_CONTINUE: clickContinue(); break;
            case TitleState::MOUSEON_SETTING: clickSetting(); break;
            case TitleState::MOUSEON_SITE: clickSite(); break;
            case TitleState::MOUSEON_END: clickEnd(); break;
            }
        }
    }
}

//-----------------------------------------------------------
// 「はじめから」ボタンクリック
//-----------------------------------------------------------
void TitleManager::clickFirst()
{
    game_state->getSceneState()->changeScene(SceneState::SCENE_HOME);
}

//-----------------------------------------------------------
// 「つづきから」ボタンクリック
//-----------------------------------------------------------
void TitleManager::clickContinue()
{
    game_state->getSceneState()->changeScene(SceneState::SCENE_HOME);
}
//-----------------------------------------------------------
// 「システム設定」ボタンクリック
//-----------------------------------------------------------
void TitleManager::clickSetting()
{
    game_state->getSceneState()->changeScene(SceneState::SCENE_SETTING);
}

//-----------------------------------------------------------
// 「公式サイト」ボタンクリック
//-----------------------------------------------------------
void TitleManager::clickSite()
{
    ShellExecute(
        NULL,
        TEXT("open"),
        TEXT("http://yahoo.co.jp"),
        NULL,
        TEXT(""),
        SW_SHOW);
}

//-----------------------------------------------------------
// 「ゲーム終了」ボタンクリック
//-----------------------------------------------------------
void TitleManager::clickEnd()
{
    game_state->gameEnd();
}

//===========================================================
// getter
//===========================================================