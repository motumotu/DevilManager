//-----------------------------------------------------------
// BattleSelectManager.cpp
// 対戦選択画面の制御
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#include "BattleSelectManager.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
BattleSelectManager::BattleSelectManager(GameData* data, GameState* state)
{
    game_data = data;
    game_state = state;
    input_state = state->getInputState();
    battle_select_state = state->getSceneState()->getBattleSelectState();
    init();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
BattleSelectManager::~BattleSelectManager()
{

}

//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void BattleSelectManager::init()
{
    scroll_flag = false;
}

//-----------------------------------------------------------
// 更新
//-----------------------------------------------------------
void BattleSelectManager::update()
{
    //---- マウスホイール
    int wheel = input_state->getMouseWheel();
    battle_select_state->scrollBattleSelect(wheel);

    //---- クリック処理
    // 左クリックされた瞬間
    if (input_state->getClick(MOUSE_INPUT_LEFT) == 1) {
        leftClickFirst();
    }
    // 左クリック中
    if (input_state->getClick(MOUSE_INPUT_LEFT) > 1) {
        leftClickNow();
    }
    // クリックが離された瞬間
    if (input_state->isRereaseClick(MOUSE_INPUT_LEFT)) {
        leftClickEnd();
    }

    //---- キー入力処理
    // 上
    if (input_state->getKeyState(KEY_INPUT_W) == 1) {
        battle_select_state->upSelectNum();
    }
    // 右
    if (input_state->getKeyState(KEY_INPUT_D) == 1) {
        battle_select_state->rightMyDeck();
    }
    // 下
    if (input_state->getKeyState(KEY_INPUT_S) == 1) {
        battle_select_state->downSelectNum();
    }
    // 左
    if (input_state->getKeyState(KEY_INPUT_A) == 1) {
        battle_select_state->leftMyDeck();
    }

    // 上
    if (input_state->getKeyState(KEY_INPUT_UP) == 1) {
        battle_select_state->upSelectNum();
    }
    // 右
    if (input_state->getKeyState(KEY_INPUT_RIGHT) == 1) {
        battle_select_state->rightMyDeck();
    }
    // 下
    if (input_state->getKeyState(KEY_INPUT_DOWN) == 1) {
        battle_select_state->downSelectNum();
    }
    // 左
    if (input_state->getKeyState(KEY_INPUT_LEFT) == 1) {
        battle_select_state->leftMyDeck();
    }
}

//-----------------------------------------------------------
// 左クリック最初
//-----------------------------------------------------------
void BattleSelectManager::leftClickFirst()
{
    int mx = input_state->getPointX();
    int my = input_state->getPointY();
    int obj = battle_select_state->getPosObject(mx, my);

    //---- 戻るボタン
    if (obj == BattleSelectState::BUTTON_BACK) {
        game_state->getSceneState()->changeScene(SceneState::SCENE_HOME);
    }
    //---- 対戦ボタン
    if (obj == BattleSelectState::BUTTON_BATTLE) {
        game_state->getSceneState()->changeScene(SceneState::SCENE_BATTLE);
    }
    //----- 左
    if (obj == BattleSelectState::DECK_SELECT_LEFT) {
        battle_select_state->leftMyDeck();
    }
    //----- 右
    if (obj == BattleSelectState::DECK_SELECT_RIGHT) {
        battle_select_state->rightMyDeck();
    }
    //---- スクロールバーエリア
    if (battle_select_state->isPosBarArea(mx, my)) {
        battle_select_state->adjustmentBar(mx, my);
        scroll_flag = true;
    }
    //---- 対戦選択エリア
    if (obj == BattleSelectState::SELECT_AREA) {
        int n = battle_select_state->getPosBattleNum(mx, my);
        if (n > 0) {
            battle_select_state->selectBattleNum(n);
        }
    }
}

//-----------------------------------------------------------
// 左クリック中
//-----------------------------------------------------------
void BattleSelectManager::leftClickNow()
{
    int mx = input_state->getPointX();
    int my = input_state->getPointY();

    // スクロールバーがクリックされいたとき
    if (scroll_flag) {
        battle_select_state->adjustmentBar(mx, my);
    }

}

//-----------------------------------------------------------
// 左クリック最後
//-----------------------------------------------------------
void BattleSelectManager::leftClickEnd()
{
    scroll_flag = false;
}


//===========================================================
// getter
//===========================================================