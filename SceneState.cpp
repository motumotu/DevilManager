//-----------------------------------------------------------
// SceneState.cpp
// �e�V�[���̏��
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#include "SceneState.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
SceneState::SceneState(GameData* _game_data)
{
    game_data = _game_data;
    save_data = game_data->getSaveData();
    title_state = new TitleState(game_data);
    home_state = new HomeState(game_data);
    battle_state = new BattleState(game_data);
    battle_result_state = new BattleResultState(game_data);
    story_select_state = new StorySelectState(game_data);
    story_state = new StoryState(game_data);
    deck_list_state = new DeckListState(game_data);
    deck_edit_state = new DeckEditState(game_data);
    battle_select_state = new BattleSelectState(game_data);
    setting_state = new SettingState(game_data);
    init();     // ��������
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
SceneState::~SceneState()
{
    delete(setting_state);
    delete(battle_select_state);
    delete(deck_edit_state);
    delete(deck_list_state);
    delete(story_state);
    delete(story_select_state);
    delete(battle_result_state);
    delete(battle_state);
    delete(home_state);
    delete(title_state);
}

//-----------------------------------------------------------
// ������
//-----------------------------------------------------------
void SceneState::init()
{
    now_scene = SCENE_TITLE;
    is_fade_out_now = 0;
    is_fade_in_now = 0;
}

//-----------------------------------------------------------
// �X�V
//-----------------------------------------------------------
void SceneState::update()
{
    //---- �t�F�[�h�C����
    if (is_fade_in_now) {
        fade_val -= 20;
        if (fade_val <= 0) {
            fade_val = 0;
            is_fade_in_now = 0;
        }
        return;
    }
    //---- �t�F�[�h�A�E�g��
    if (is_fade_out_now) {
        fade_val += 20;
        if (fade_val >= 255) {
            change();
        }
        return;
    }
    //---- �^�C�g�����
    if (now_scene == SCENE_TITLE) {
        title_state->update();
    }
    //---- �z�[�����
    else if (now_scene == SCENE_HOME) {
        home_state->update();
    }
    //---- �ΐ���
    else if (now_scene == SCENE_BATTLE) {
        battle_state->update();
    }
    //---- �ΐ팋�ʉ��
    else if (now_scene == SCENE_BATTLE_RESULT) {
        battle_result_state->update();
    }
    //---- �X�g�[���[�I�����
    else if (now_scene == SCENE_STORY_SELECT) {
        story_select_state->update();
    }
    //---- �X�g�[���[���
    else if (now_scene == SCENE_STORY) {
        story_state->update();
    }
    //---- �f�b�L�ꗗ���
    else if (now_scene == SCENE_DECKLIST) {
        deck_list_state->update();
    }
    //---- �f�b�L�ҏW���
    else if (now_scene == SCENE_DECKEDIT) {
        deck_edit_state->update();
    }
    //---- �ΐ�I�����
    else if (now_scene == SCENE_BATTLE_SELECT) {
        battle_select_state->update();
    }
    //---- �ݒ���
    else if (now_scene == SCENE_SETTING) {
        setting_state->update();
    }
}

//-----------------------------------------------------------
// �V�[���ύX
//-----------------------------------------------------------
void SceneState::changeScene(int scene)
{
    // �ΐ�I����� �� �ΐ���
    if (now_scene == SCENE_BATTLE_SELECT && scene == SCENE_BATTLE) {
        int n = battle_select_state->getSelectNum();
        battle_state->battleInit();
        // ���R�f�b�L�Z�b�g
        DeckData *deck = save_data->getDeckData(battle_select_state->getMyDeckNum());
        battle_state->getCardState()->setMyDeck(deck);
        // ����f�b�L�Z�b�g
        deck = game_data->getAllBattleData()->getBattleData(n)->getDeckData();
        battle_state->getCardState()->setEnDeck(deck);
        // �}�b�v�f�[�^�Z�b�g
        int map_num = game_data->getAllBattleData()->getBattleData(n)->getMapNum();
        MapData *map = game_data->getAllMapData()->getMapData(map_num);
        battle_state->setMapData(map);
        // �ݒ�
        battle_state->battleSetting();
    }
    // �X�g�[���[ �� �ΐ���
    if (now_scene == SCENE_STORY && scene == SCENE_BATTLE) {
        battle_state->battleInit();
        // ���R�f�b�L�Z�b�g
        DeckData *deck = save_data->getDeckData(story_select_state->getDeckNum());
        battle_state->getCardState()->setMyDeck(deck);
        // �G�R�f�b�L�Z�b�g
        int n = story_select_state->getStoryNum();
        deck = game_data->getAllStoryEnemyData()->getStoryEnemyData(n)->getDeckData();
        battle_state->getCardState()->setEnDeck(deck);
        // �}�b�v�f�[�^�Z�b�g
        int map_num = game_data->getAllStoryEnemyData()->getStoryEnemyData(n)->getMapNum();
        MapData *map = game_data->getAllMapData()->getMapData(map_num);
        battle_state->setMapData(map);
        // �ݒ�
        battle_state->battleSetting();
    }
    // �� �ݒ���
    if (scene == SCENE_SETTING) {
        setting_state->setPreScene(now_scene);
    }
    change_scene = scene;
    is_fade_out_now = 1;
    fade_val = 0;
}

//-----------------------------------------------------------
// �`�F���W
//-----------------------------------------------------------
void SceneState::change()
{
    now_scene = change_scene;
    is_fade_in_now = 1;
    is_fade_out_now = 0;
    fade_val = 255;
}

//===========================================================
// getter
//===========================================================
TitleState *SceneState::getTitleState() { return title_state; }
HomeState *SceneState::getHomeState() { return home_state; }
BattleState *SceneState::getBattleState() { return battle_state; }
BattleResultState *SceneState::getBattleResultState() { return battle_result_state; }
StorySelectState *SceneState::getStorySelectState() { return story_select_state; }
StoryState *SceneState::getStoryState() { return story_state; }
DeckListState *SceneState::getDeckListState() { return deck_list_state; }
DeckEditState *SceneState::getDeckEditState() { return deck_edit_state; }
BattleSelectState *SceneState::getBattleSelectState() { return battle_select_state; }
SettingState *SceneState::getSettingState() { return setting_state; }
int SceneState::getNowScene() { return now_scene; }
int SceneState::getIsFadeOutNow() { return is_fade_out_now; }
int SceneState::getIsFadeInNow() { return is_fade_in_now; }
int SceneState::getFadeVal() { return fade_val; }