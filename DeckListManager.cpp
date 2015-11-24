//-----------------------------------------------------------
// DeckListManager.cpp
// デッキ一覧画面の制御
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#include "DeckListManager.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
DeckListManager::DeckListManager(GameData* data, GameState* state)
{
    game_data = data;
    game_state = state;
    input_state = state->getInputState();
    deck_list_state = state->getSceneState()->getDeckListState();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
DeckListManager::~DeckListManager()
{
}

//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void DeckListManager::init()
{
}

//-----------------------------------------------------------
// 更新
//-----------------------------------------------------------
void DeckListManager::update()
{
    //---- マウスホイール
    mouseWheel();

    //---- マウス座標
    deck_list_state->updateMousePos(
        input_state->getPointX(),
        input_state->getPointY());

    //---- クリック処理
    // 左クリックされた瞬間
    if (input_state->getClick(MOUSE_INPUT_LEFT) == 1) {
        leftClickFirst();
        //game_state->getSceneState()->changeScene(SceneState::SCENE_DECKEDIT);
    }
    // 左クリックが押されている間
    if (input_state->getClick(MOUSE_INPUT_LEFT) > 1) {
        leftClickNow();
    }
    // クリックが離された瞬間
    if (input_state->isRereaseClick(MOUSE_INPUT_LEFT)) {
        leftClickEnd();
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
// 左クリックされた瞬間
//-----------------------------------------------------------
void DeckListManager::leftClickFirst()
{
    int mx = input_state->getPointX();
    int my = input_state->getPointY();

    //---- 戻るボタン
    if (deck_list_state->isPosButtonBack(mx, my)) {
        game_state->getSceneState()->changeScene(SceneState::SCENE_HOME);
    }
    //---- 編集ボタン
    if (deck_list_state->isPosButtonEdit(mx, my)) {
        game_state->getSceneState()->changeScene(SceneState::SCENE_DECKEDIT);
    }

    //---- 削除ボタン
    if (deck_list_state->isPosButtonDelete(mx, my)) {
        puts("削除！削除！削除！削除おおおおおおおおお");
    }
    //---- 入力ボックス
    if (deck_list_state->isPosInputBox(mx, my)) {
        deck_list_state->onInputActive();
        SetActiveKeyInput(deck_list_state->getInputHandl());
    }
    else {
        deck_list_state->offInputActive();
    }
    //---- デッキリスト選択
    int n = deck_list_state->isPosDeckList(mx, my);
    if (n > 0) {
        deck_list_state->selectDeckList(n);
    }
    //---- デッキ追加
    //---- 上スライドボタン
    if (deck_list_state->isPosBarUp(mx, my)) {
        deck_list_state->slideBarUp();
    }
    //---- 下スライドボタン
    if (deck_list_state->isPosBarDown(mx, my)) {
        deck_list_state->slideBarDown();
    }
    //---- スライドバー
    if (deck_list_state->isPosBarArea(mx, my)) {
        deck_list_state->clickBar();
    }
}

//-----------------------------------------------------------
// 左クリックされている間
//-----------------------------------------------------------
void DeckListManager::leftClickNow()
{
    int mx = input_state->getPointX();
    int my = input_state->getPointY();

    //---- 上スライドボタン
    if (deck_list_state->isPosBarUp(mx, my)) {
        deck_list_state->slideBarUp();
    }
    //---- 下スライドボタン
    if (deck_list_state->isPosBarDown(mx, my)) {
        deck_list_state->slideBarDown();
    }
}

//-----------------------------------------------------------
// 左クリック終了時
//-----------------------------------------------------------
void DeckListManager::leftClickEnd()
{
    deck_list_state->leftClickEnd();
}

//-----------------------------------------------------------
// マウスホイール
//-----------------------------------------------------------
void DeckListManager::mouseWheel()
{
    int wheel = input_state->getMouseWheel();
    // 下スクロール
    if (wheel < 0) {
        for (int i = wheel; i < 0; i++) {
            deck_list_state->slideBarDown(10);
        }
    }
    // 上スクロール
    else if (wheel > 0) {
        for (int i = 0; i < wheel; i++) {
            deck_list_state->slideBarUp(10);
        }
    }
}

//===========================================================
// getter
//===========================================================