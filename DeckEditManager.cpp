//-----------------------------------------------------------
// DeckEditManager.cpp
// デッキ編集画面の制御
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#include "DeckEditManager.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
DeckEditManager::DeckEditManager(GameData* data, GameState* state)
{
    game_data = data;
    game_state = state;
    deck_edit_state = state->getSceneState()->getDeckEditState();
    input_state = state->getInputState();
    save_data = data->getSaveData();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
DeckEditManager::~DeckEditManager()
{

}

//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void DeckEditManager::init()
{

}

//-----------------------------------------------------------
// 更新
//-----------------------------------------------------------
void DeckEditManager::update()
{
    deck_edit_state->setSelectDeckNum(game_state->getSceneState()->getDeckListState()->getSelectDeckNum());
    //---- マウスホイール
    mouseWheel();

    //---- マウス座標
    /*
    deck_edit_state->updateMousePos(
        input_state->getPointX(),
        input_state->getPointY());
    */
    deck_edit_state->updateMousePos(
        input_state->getPointX(),
        input_state->getPointY());
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
// 左クリックがされた瞬間
//-----------------------------------------------------------
void DeckEditManager::leftClickFirst()
{
    int mx = input_state->getPointX();
    int my = input_state->getPointY();
    int obj = deck_edit_state->getPosObject(mx, my);
    
    //---- 戻るボタン
    if (obj == DeckEditState::BUTTON_BACK) {
        game_state->getSceneState()->changeScene(SceneState::SCENE_DECKLIST);
    }
    //---- デッキエリア
    else if (obj == DeckEditState::DECK_AREA) {
        int n = deck_edit_state->getPosDeckAreaNum(mx, my);
        deck_edit_state->selectDeckAreaCard(n);
    }
    //---- カードエリア
    else if (obj == DeckEditState::CARD_AREA) {
        int n = deck_edit_state->getPosCardAreaNum(mx, my);
        deck_edit_state->selectCardAreaCard(n);
    }
}

//-----------------------------------------------------------
// 左クリック中
//-----------------------------------------------------------
void DeckEditManager::leftClickNow()
{

}

//-----------------------------------------------------------
// 左クリックの終わり
//-----------------------------------------------------------
void DeckEditManager::leftClickEnd()
{
    int mx = input_state->getPointX();
    int my = input_state->getPointY();
    int obj = deck_edit_state->getPosObject(mx, my);

    //---- デッキエリア (カードが最大でなければ追加)
    if (obj == DeckEditState::DECK_AREA && !deck_edit_state->isDeckMax()) {
        int n = deck_edit_state->getPosDeckAreaNum(mx, my);
        deck_edit_state->addDeckAreaCard(n);
    }
    //---- カードエリア
    else if (obj == DeckEditState::CARD_AREA) {
        int n = deck_edit_state->getPosCardAreaNum(mx, my);
        deck_edit_state->addCardAreaCard(n);
    }
    //---- その他
    else {
        deck_edit_state->addCardAreaCard(-1);
    }

    deck_edit_state->mouseRelease();
}

//-----------------------------------------------------------
// マウスホイール
//-----------------------------------------------------------
void DeckEditManager::mouseWheel()
{
    int wheel = input_state->getMouseWheel();

    // 下スクロール
    if (wheel < 0) {
        for (int i = wheel; i < 0; i++) {
            deck_edit_state->slideBarDown(10);
        }
    }
    // 上スクロール
    else if (wheel > 0) {
        for (int i = 0; i < wheel; i++) {
            deck_edit_state->slideBarUp(10);
        }
    }
}

//===========================================================
// getter
//===========================================================