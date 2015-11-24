//-----------------------------------------------------------
// StoryManager.h
// �X�g�[���[�̐���
// ����� 2015.03.17
// ����� motumotu
//-----------------------------------------------------------
#include "StoryManager.h"

//-----------------------------------------------------------
// �R���X�g���N�^
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
// �f�X�g���N�^
//-----------------------------------------------------------
StoryManager::~StoryManager()
{

}

//-----------------------------------------------------------
// ������
//-----------------------------------------------------------
void StoryManager::init()
{
    wheel = 0;
}

//-----------------------------------------------------------
// �X�V
//-----------------------------------------------------------
void StoryManager::update()
{
    //---- �I�[�g�̎��A���̕��ɍs��
    if (story_state->isAuto() && story_state->isNextText()) {
        nextText();
        return;
    }
    //---- �}�E�X�z�C�[��
    mouseWheel();

    //---- �}�E�X�ʒu
    story_state->updateMousePos(
        input_state->getPointX(),
        input_state->getPointY());

    //---- �N���b�N����
    // ���N���b�N���ꂽ�u��
    if (input_state->getClick(MOUSE_INPUT_LEFT) == 1) {
        leftClickFirst();
    }
    // �N���b�N�������ꂽ�u��
    
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
void StoryManager::leftClickFirst()
{
    int x = input_state->getPointX();
    int y = input_state->getPointY();
    int obj = story_state->getMousePosObject();

    // �E�C���h�E�����Ă�Ƃ�
    if (story_state->isClose()) {
        story_state->setIsClose(false);
        story_state->setIsAuto(false);
        return;
    }
    // �I�[�g�̂Ƃ�
    if (story_state->isAuto()) {
        story_state->setIsAuto(false);
        return;
    }

    // �I�[�g�{�^��
    if (obj == StoryState::BUTTON_AUTO) {
        story_state->setIsAuto(true);
    }
    // �X�L�b�v�{�^��
    if (obj == StoryState::BUTTON_SKIP) {
        game_state->getSceneState()->changeScene(SceneState::SCENE_BATTLE);
    }
    // ���O
    if (obj == StoryState::BUTTON_LOG) {
        story_state->setIsBackLog(true);
    }
    // �R���t�B�O
    if (obj == StoryState::BUTTON_CONFIG) {
        game_state->getSceneState()->changeScene(SceneState::SCENE_SETTING);
    }
    // ����{�^��
    if (obj == StoryState::BUTTON_CLOSE) {
        story_state->setIsClose(true);
    }
    // �߂�{�^��
    if (obj == StoryState::BUTTON_BACK) {
        story_state->setIsBackLog(false);
    }
    // �o�[�G���A
    if (obj == StoryState::BAR_AREA) {
        story_state->changeBarMousePos();
    }
    // �����Ȃ��Ƃ���
    if (obj == StoryState::NONE && story_state->isBackLog() == false) {
        // �`��I�����͎��̕���
        if (story_state->isDrawEnd()) {
            nextText();
        }
        // �`�撆�Ȃ�S���\��
        else {
            story_state->fullText();
        }
    }
}
//-----------------------------------------------------------
// ���N���b�N����Ă���� 
//-----------------------------------------------------------
void StoryManager::leftClickNow()
{

}
//-----------------------------------------------------------
// ���N���b�N�I����
//-----------------------------------------------------------
void StoryManager::leftClickEnd()
{

}

//-----------------------------------------------------------
// �}�E�X�z�C�[��
//-----------------------------------------------------------
void StoryManager::mouseWheel()
{
    wheel += input_state->getMouseWheel();
    // ����
    if (wheel < 0) {
        // �o�b�N���O��
        if (story_state->isBackLog() == true) {
            story_state->backlogDown();
        }
        // �ʏ펞
        else {
            // �`��I�����͎��̕���
            if (story_state->isDrawEnd() || wheel < -1) {
                nextText();
            }
            // �`�撆�Ȃ�S���\��
            else {
                story_state->fullText();
            }
        }
        wheel++;
    }
    // ��
    if (wheel > 0) {
        // �o�b�N���O��
        if (story_state->isBackLog() == true) {
            story_state->backlogUp();
        }
        // �ʏ펞 �o�b�N���O�\��
        else {
            story_state->setIsBackLog(true);
        }
        wheel--;
    }
}

//-----------------------------------------------------------
// ���̃e�L�X�g��
//-----------------------------------------------------------
void StoryManager::nextText()
{
    // ���̕�������Ȃ玟�̕���
    if (story_state->getNowStoryTextData()->getNextNum() != 0) {
        story_state->changeNextText();
    }
    // �Ō�Ȃ�ΐ�ɑJ��
    else {
        game_state->getSceneState()->changeScene(SceneState::SCENE_BATTLE);
    }
}


//===========================================================
// getter
//===========================================================

