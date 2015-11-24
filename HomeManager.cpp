//-----------------------------------------------------------
// HomeManager.cpp
// �z�[����ʂ̐���
// ����� 2015.03.16
// ����� motumotu
//-----------------------------------------------------------
#include "HomeManager.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
HomeManager::HomeManager(GameData *data, GameState *state)
{
    game_state = state;
    game_data = data;
    home_state = state->getSceneState()->getHomeState();
    input_state = state->getInputState();
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
HomeManager::~HomeManager()
{

}

//-----------------------------------------------------------
// ������
//-----------------------------------------------------------
void HomeManager::init()
{
}

//-----------------------------------------------------------
// �X�V
//-----------------------------------------------------------
void HomeManager::update()
{
    //---- �}�E�X�ʒu
    home_state->updateMousePos(
        input_state->getPointX(),
        input_state->getPointY());

    //---- �N���b�N����
    // ���N���b�N���ꂽ�u��
    if (input_state->getClick(MOUSE_INPUT_LEFT) == 1) {
        clickFirst();
    }
    // �N���b�N�������ꂽ�u��
    if (input_state->getClick(MOUSE_INPUT_LEFT) == 0 && home_state->isClickNow()) {
        clickEnd();
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
// �N���b�N�ŏ�
//-----------------------------------------------------------
void HomeManager::clickFirst()
{
    home_state->clickFirst(
        input_state->getPointX(),
        input_state->getPointY());
}

//-----------------------------------------------------------
// �N���b�N�Ō�
//-----------------------------------------------------------
void HomeManager::clickEnd()
{
    int obj = home_state->clickEnd(
        input_state->getPointX(),
        input_state->getPointY());

    // �X�g�[���[�{�^��
    if (obj == HomeState::CLICK_BUTTON_STORY) {
        game_state->getSceneState()->changeScene(SceneState::SCENE_STORY_SELECT);
    }
    // �ΐ�{�^��
    if (obj == HomeState::CLICK_BUTTON_BATTLE) {
        game_state->getSceneState()->changeScene(SceneState::SCENE_BATTLE_SELECT);
    }
    // �f�b�L�Ґ��{�^��
    if (obj == HomeState::CLICK_BUTTON_DECK) {
        game_state->getSceneState()->changeScene(SceneState::SCENE_DECKLIST);
    }
    // �V���b�v�{�^��
    if (obj == HomeState::CLICK_BUTTON_SHOP) {

    }
    // �Z�[�u�{�^��
    if (obj == HomeState::CLICK_BUTTON_SAVE) {

    }
    // �ݒ�{�^��
    if (obj == HomeState::CLICK_BUTTON_SETTING) {
        game_state->getSceneState()->changeScene(SceneState::SCENE_SETTING);
    }
}


//===========================================================
// getter
//===========================================================

