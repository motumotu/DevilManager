//-----------------------------------------------------------
// StoryManager.h
// ストーリーの制御
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#include "StoryManager.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
StoryManager::StoryManager(GameData *data, GameState *state)
{
    game_state = state;
    game_data = data;
    input_state = state->getInputState();
    story_state = state->getSceneState()->getStoryState();
    init();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
StoryManager::~StoryManager()
{

}

//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void StoryManager::init()
{
    wheel = 0;
}

//-----------------------------------------------------------
// 更新
//-----------------------------------------------------------
void StoryManager::update()
{
    //---- オートの時、次の文に行く
    if (story_state->isAuto() && story_state->isNextText()) {
        nextText();
        return;
    }
    //---- マウスホイール
    mouseWheel();

    //---- マウス位置
    story_state->updateMousePos(
        input_state->getPointX(),
        input_state->getPointY());

    //---- クリック処理
    // 左クリックされた瞬間
    if (input_state->getClick(MOUSE_INPUT_LEFT) == 1) {
        leftClickFirst();
    }
    // クリックが離された瞬間
    
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
void StoryManager::leftClickFirst()
{
    int x = input_state->getPointX();
    int y = input_state->getPointY();
    int obj = story_state->getMousePosObject();

    // ウインドウが閉じてるとき
    if (story_state->isClose()) {
        story_state->setIsClose(false);
        story_state->setIsAuto(false);
        return;
    }
    // オートのとき
    if (story_state->isAuto()) {
        story_state->setIsAuto(false);
        return;
    }

    // オートボタン
    if (obj == StoryState::BUTTON_AUTO) {
        story_state->setIsAuto(true);
    }
    // スキップボタン
    if (obj == StoryState::BUTTON_SKIP) {
        game_state->getSceneState()->changeScene(SceneState::SCENE_BATTLE);
    }
    // ログ
    if (obj == StoryState::BUTTON_LOG) {
        story_state->setIsBackLog(true);
    }
    // コンフィグ
    if (obj == StoryState::BUTTON_CONFIG) {
        game_state->getSceneState()->changeScene(SceneState::SCENE_SETTING);
    }
    // 閉じるボタン
    if (obj == StoryState::BUTTON_CLOSE) {
        story_state->setIsClose(true);
    }
    // 戻るボタン
    if (obj == StoryState::BUTTON_BACK) {
        story_state->setIsBackLog(false);
    }
    // バーエリア
    if (obj == StoryState::BAR_AREA) {
        story_state->changeBarMousePos();
    }
    // 何もないところ
    if (obj == StoryState::NONE && story_state->isBackLog() == false) {
        // 描画終了時は次の文へ
        if (story_state->isDrawEnd()) {
            nextText();
        }
        // 描画中なら全文表示
        else {
            story_state->fullText();
        }
    }
}
//-----------------------------------------------------------
// 左クリックされている間 
//-----------------------------------------------------------
void StoryManager::leftClickNow()
{

}
//-----------------------------------------------------------
// 左クリック終了時
//-----------------------------------------------------------
void StoryManager::leftClickEnd()
{

}

//-----------------------------------------------------------
// マウスホイール
//-----------------------------------------------------------
void StoryManager::mouseWheel()
{
    wheel += input_state->getMouseWheel();
    // 下に
    if (wheel < 0) {
        // バックログ中
        if (story_state->isBackLog() == true) {
            story_state->backlogDown();
        }
        // 通常時
        else {
            // 描画終了時は次の文へ
            if (story_state->isDrawEnd() || wheel < -1) {
                nextText();
            }
            // 描画中なら全文表示
            else {
                story_state->fullText();
            }
        }
        wheel++;
    }
    // 上
    if (wheel > 0) {
        // バックログ中
        if (story_state->isBackLog() == true) {
            story_state->backlogUp();
        }
        // 通常時 バックログ表示
        else {
            story_state->setIsBackLog(true);
        }
        wheel--;
    }
}

//-----------------------------------------------------------
// 次のテキストへ
//-----------------------------------------------------------
void StoryManager::nextText()
{
    // 次の文があるなら次の文へ
    if (story_state->getNowStoryTextData()->getNextNum() != 0) {
        story_state->changeNextText();
    }
    // 最後なら対戦に遷移
    else {
        game_state->getSceneState()->changeScene(SceneState::SCENE_BATTLE);
    }
}


//===========================================================
// getter
//===========================================================

