//-----------------------------------------------------------
// DrawManager.cpp
// 描画制御
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#include "DrawManager.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
DrawManager::DrawManager(GameData* data, GameState* state)
{
    game_data = data;
    game_state = state;
    scene_state = state->getSceneState();
    draw_title = new DrawTitle(data, state);
    draw_home = new DrawHome(data, state);
    draw_battle = new DrawBattle(data, state);
    draw_battle_result = new DrawBattleResult(data, state);
    draw_story_select = new DrawStorySelect(data, state);
    draw_story = new DrawStory(data, state);
    draw_deck_list = new DrawDeckList(data, state);
    draw_deck_edit = new DrawDeckEdit(data, state);
    draw_battle_select = new DrawBattleSelect(data, state);
    draw_setting = new DrawSetting(data, state);
    color_black = GetColor(0, 0, 0);
    init();      // 初期処理
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
DrawManager::~DrawManager()
{
    delete(draw_setting);
    delete(draw_battle_select);
    delete(draw_deck_edit);
    delete(draw_deck_list);
    delete(draw_story_select);
    delete(draw_battle_result);
    delete(draw_battle);
    delete(draw_home);
    delete(draw_title);
}

//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void DrawManager::init()
{

}

//-----------------------------------------------------------
// 更新
//-----------------------------------------------------------
void DrawManager::update()
{

}

//-----------------------------------------------------------
// 描画
//-----------------------------------------------------------
void DrawManager::draw()
{
    int scene = scene_state->getNowScene();
    //---- タイトル画面
    if (scene == SceneState::SCENE_TITLE) {
        draw_title->draw();
    }
    //---- ホーム画面
    else if (scene == SceneState::SCENE_HOME) {
        draw_home->draw();
    }
    //---- 対戦画面
    else if (scene == SceneState::SCENE_BATTLE) {
        draw_battle->draw();
    }
    //---- 対戦結果画面
    else if (scene == SceneState::SCENE_BATTLE_RESULT) {
        draw_battle_result->draw();
    }
    //---- ストーリー選択画面
    else if (scene == SceneState::SCENE_STORY_SELECT) {
        draw_story_select->draw();
    }
    //---- ストーリー画面
    else if (scene == SceneState::SCENE_STORY) {
        draw_story->draw();
    }
    //---- デッキ一覧画面
    else if (scene == SceneState::SCENE_DECKLIST) {
        draw_deck_list->draw();
    }
    //---- デッキ編集画面
    else if (scene == SceneState::SCENE_DECKEDIT) {
        draw_deck_edit->draw();
    }
    //---- 対戦選択画面
    else if (scene == SceneState::SCENE_BATTLE_SELECT) {
        draw_battle_select->draw();
    }
    //---- 設定画面
    else if (scene == SceneState::SCENE_SETTING) {
        draw_setting->draw();
    }

    //---- フェードイン中
    if (scene_state->getIsFadeInNow()) {
        int val = scene_state->getFadeVal();
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, val);
        DrawBox(0, 0, SystemData::getWindowWidth(), SystemData::getWindowHeight(),
            color_black, TRUE);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
    //---- フェードアウト中
    if (scene_state->getIsFadeOutNow()) {
        int val = scene_state->getFadeVal();
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, val);
        DrawBox(0, 0, SystemData::getWindowWidth(), SystemData::getWindowHeight(),
            color_black, TRUE);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
    // 裏画面描画
    ScreenFlip();
}

//===========================================================
// getter
//===========================================================

