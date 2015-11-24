//-----------------------------------------------------------
// StorySelectManager.h
// �X�g�[���[�I����ʂ̐���
// ����� 2015.03.17
// ����� motumotu
//-----------------------------------------------------------
#include "StorySelectManager.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
StorySelectManager::StorySelectManager(GameData* data, GameState* state)
{
    game_data = data;
    game_state = state;
    input_state = state->getInputState();
    story_select_state = state->getSceneState()->getStorySelectState();
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
StorySelectManager::~StorySelectManager()
{

}
//-----------------------------------------------------------
// ������
//-----------------------------------------------------------
void StorySelectManager::init()
{

}

//-----------------------------------------------------------
// �X�V����
//-----------------------------------------------------------
void StorySelectManager::update()
{
    //---- �}�E�X���W
    story_select_state->updateMousePos(
        input_state->getPointX(),
        input_state->getPointY());

    //---- �}�E�X���͏���
    // ���N���b�N���ꂽ�u��
    if (input_state->getClick(MOUSE_INPUT_LEFT) == 1) {
        leftClickFirst();
    }
    //---- �L�[���͏���
    // ��
    if (input_state->getKeyState(KEY_INPUT_W) >= 1) {

    }
    // �E
    if (input_state->getKeyState(KEY_INPUT_D) >= 1) {
    }
    // ��
    if (input_state->getKeyState(KEY_INPUT_S) >= 1) {

    }
    // ��
    if (input_state->getKeyState(KEY_INPUT_A) >= 1) {
    }
}

//-----------------------------------------------------------
// ���N���b�N���ꂽ�u��
//-----------------------------------------------------------
void StorySelectManager::leftClickFirst()
{
    int obj = story_select_state->getPosObject(
        input_state->getPointX(),
        input_state->getPointY());

    //---- �߂�{�^��
    if (obj == StorySelectState::BUTTON_BACK) {
        game_state->getSceneState()->changeScene(SceneState::SCENE_HOME);
    }
    //---- ����{�^��
    if (obj == StorySelectState::BUTTON_DECISION) {
        game_state->getSceneState()->changeScene(SceneState::SCENE_STORY);
    }
    //---- �f�b�L�I���{�^����
    if (obj == StorySelectState::DECK_SELECT_LEFT) {
        story_select_state->deckSelectLeft();
    }
    //---- �f�b�L�I���{�^���E
    if (obj == StorySelectState::DECK_SELECT_RIGHT) {
        story_select_state->deckSekectRight();
    }
    //---- �X�g�[���[�G���A
    if (obj == StorySelectState::STORY_AREA) {
        int n = story_select_state->getMousePosStory();
        if (n != 0) story_select_state->selectStory(n);
    }
}

//-----------------------------------------------------------
// ���N���b�N����Ă���� 
//-----------------------------------------------------------
void StorySelectManager::leftClickNow()
{

}
//-----------------------------------------------------------
// ���N���b�N�I����
//-----------------------------------------------------------
void StorySelectManager::leftClickEnd()
{

}