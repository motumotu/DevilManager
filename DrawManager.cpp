//-----------------------------------------------------------
// DrawManager.cpp
// �`�搧��
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#include "DrawManager.h"

//-----------------------------------------------------------
// �R���X�g���N�^
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
    init();      // ��������
}

//-----------------------------------------------------------
// �f�X�g���N�^
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
// ������
//-----------------------------------------------------------
void DrawManager::init()
{

}

//-----------------------------------------------------------
// �X�V
//-----------------------------------------------------------
void DrawManager::update()
{

}

//-----------------------------------------------------------
// �`��
//-----------------------------------------------------------
void DrawManager::draw()
{
    int scene = scene_state->getNowScene();
    //---- �^�C�g�����
    if (scene == SceneState::SCENE_TITLE) {
        draw_title->draw();
    }
    //---- �z�[�����
    else if (scene == SceneState::SCENE_HOME) {
        draw_home->draw();
    }
    //---- �ΐ���
    else if (scene == SceneState::SCENE_BATTLE) {
        draw_battle->draw();
    }
    //---- �ΐ팋�ʉ��
    else if (scene == SceneState::SCENE_BATTLE_RESULT) {
        draw_battle_result->draw();
    }
    //---- �X�g�[���[�I�����
    else if (scene == SceneState::SCENE_STORY_SELECT) {
        draw_story_select->draw();
    }
    //---- �X�g�[���[���
    else if (scene == SceneState::SCENE_STORY) {
        draw_story->draw();
    }
    //---- �f�b�L�ꗗ���
    else if (scene == SceneState::SCENE_DECKLIST) {
        draw_deck_list->draw();
    }
    //---- �f�b�L�ҏW���
    else if (scene == SceneState::SCENE_DECKEDIT) {
        draw_deck_edit->draw();
    }
    //---- �ΐ�I�����
    else if (scene == SceneState::SCENE_BATTLE_SELECT) {
        draw_battle_select->draw();
    }
    //---- �ݒ���
    else if (scene == SceneState::SCENE_SETTING) {
        draw_setting->draw();
    }

    //---- �t�F�[�h�C����
    if (scene_state->getIsFadeInNow()) {
        int val = scene_state->getFadeVal();
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, val);
        DrawBox(0, 0, SystemData::getWindowWidth(), SystemData::getWindowHeight(),
            color_black, TRUE);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
    //---- �t�F�[�h�A�E�g��
    if (scene_state->getIsFadeOutNow()) {
        int val = scene_state->getFadeVal();
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, val);
        DrawBox(0, 0, SystemData::getWindowWidth(), SystemData::getWindowHeight(),
            color_black, TRUE);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
    // ����ʕ`��
    ScreenFlip();
}

//===========================================================
// getter
//===========================================================

