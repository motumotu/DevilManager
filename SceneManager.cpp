//-----------------------------------------------------------
// SceneManager.cpp
// �e�V�[���̐���
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#include "SceneManager.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
SceneManager::SceneManager(GameData *data, GameState *state)
{
    game_data = data;
    game_state = state;
    title_manager = new TitleManager(data, state);
    home_manager = new HomeManager(data, state);
    battle_manager = new BattleManager(data, state);
    battle_result_manager = new BattleResultManager(data, state);
    story_select_manager = new StorySelectManager(data, state);
    story_manager = new StoryManager(data, state);
    deck_list_manager = new DeckListManager(data, state);
    deck_edit_manager = new DeckEditManager(data, state);
    battle_select_manager = new BattleSelectManager(data, state);
    setting_manager = new SettingManager(data, state);
    init();       // ��������
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
SceneManager::~SceneManager()
{
    delete(setting_manager);
    delete(battle_select_manager);
    delete(deck_edit_manager);
    delete(deck_list_manager);
    delete(story_manager);
    delete(story_select_manager);
    delete(battle_result_manager);
    delete(battle_manager);
    delete(home_manager);
    delete(title_manager);
}

//-----------------------------------------------------------
// ������
//-----------------------------------------------------------
void SceneManager::init()
{
}

//-----------------------------------------------------------
// �X�V
//-----------------------------------------------------------
void SceneManager::update()
{
    //---- �t�F�[�h��
    if (game_state->getSceneState()->getIsFadeInNow() ||
        game_state->getSceneState()->getIsFadeOutNow()) {
        return;
    }

    int scene = game_state->getSceneState()->getNowScene();
    //---- �^�C�g�����
    if (scene == SceneState::SCENE_TITLE) {
        title_manager->update();
    }
    //---- �z�[�����
    else if (scene == SceneState::SCENE_HOME) {
        home_manager->update();
    }
    //---- �ΐ���
    else if (scene == SceneState::SCENE_BATTLE) {
        battle_manager->update();
    }
    //---- �ΐ팋�ʉ��
    else if (scene == SceneState::SCENE_BATTLE_RESULT) {
        battle_result_manager->update();
    }
    //---- �X�g�[���[�I�����
    else if (scene == SceneState::SCENE_STORY_SELECT) {
        story_select_manager->update();
    }
    //---- �X�g�[���[���
    else if (scene == SceneState::SCENE_STORY) {
        story_manager->update();
    }
    //---- �f�b�L�ꗗ���
    else if (scene == SceneState::SCENE_DECKLIST) {
        deck_list_manager->update();
    }
    //---- �f�b�L�ҏW���
    else if (scene == SceneState::SCENE_DECKEDIT) {
        deck_edit_manager->update();
    }
    //---- �ΐ�I�����
    else if (scene == SceneState::SCENE_BATTLE_SELECT) {
        battle_select_manager->update();
    }
    //---- �ݒ���
    else if (scene == SceneState::SCENE_SETTING) {
        setting_manager->update();
    }
}

//===========================================================
// getter
//===========================================================

