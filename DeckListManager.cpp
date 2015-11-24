//-----------------------------------------------------------
// DeckListManager.cpp
// �f�b�L�ꗗ��ʂ̐���
// ����� 2015.03.17
// ����� motumotu
//-----------------------------------------------------------
#include "DeckListManager.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
DeckListManager::DeckListManager(GameData* data, GameState* state)
{
    game_data = data;
    game_state = state;
    input_state = state->getInputState();
    deck_list_state = state->getSceneState()->getDeckListState();
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
DeckListManager::~DeckListManager()
{
}

//-----------------------------------------------------------
// ������
//-----------------------------------------------------------
void DeckListManager::init()
{
}

//-----------------------------------------------------------
// �X�V
//-----------------------------------------------------------
void DeckListManager::update()
{
    //---- �}�E�X�z�C�[��
    mouseWheel();

    //---- �}�E�X���W
    deck_list_state->updateMousePos(
        input_state->getPointX(),
        input_state->getPointY());

    //---- �N���b�N����
    // ���N���b�N���ꂽ�u��
    if (input_state->getClick(MOUSE_INPUT_LEFT) == 1) {
        leftClickFirst();
        //game_state->getSceneState()->changeScene(SceneState::SCENE_DECKEDIT);
    }
    // ���N���b�N��������Ă����
    if (input_state->getClick(MOUSE_INPUT_LEFT) > 1) {
        leftClickNow();
    }
    // �N���b�N�������ꂽ�u��
    if (input_state->isRereaseClick(MOUSE_INPUT_LEFT)) {
        leftClickEnd();
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
void DeckListManager::leftClickFirst()
{
    int mx = input_state->getPointX();
    int my = input_state->getPointY();

    //---- �߂�{�^��
    if (deck_list_state->isPosButtonBack(mx, my)) {
        game_state->getSceneState()->changeScene(SceneState::SCENE_HOME);
    }
    //---- �ҏW�{�^��
    if (deck_list_state->isPosButtonEdit(mx, my)) {
        game_state->getSceneState()->changeScene(SceneState::SCENE_DECKEDIT);
    }

    //---- �폜�{�^��
    if (deck_list_state->isPosButtonDelete(mx, my)) {
        puts("�폜�I�폜�I�폜�I�폜������������������");
    }
    //---- ���̓{�b�N�X
    if (deck_list_state->isPosInputBox(mx, my)) {
        deck_list_state->onInputActive();
        SetActiveKeyInput(deck_list_state->getInputHandl());
    }
    else {
        deck_list_state->offInputActive();
    }
    //---- �f�b�L���X�g�I��
    int n = deck_list_state->isPosDeckList(mx, my);
    if (n > 0) {
        deck_list_state->selectDeckList(n);
    }
    //---- �f�b�L�ǉ�
    //---- ��X���C�h�{�^��
    if (deck_list_state->isPosBarUp(mx, my)) {
        deck_list_state->slideBarUp();
    }
    //---- ���X���C�h�{�^��
    if (deck_list_state->isPosBarDown(mx, my)) {
        deck_list_state->slideBarDown();
    }
    //---- �X���C�h�o�[
    if (deck_list_state->isPosBarArea(mx, my)) {
        deck_list_state->clickBar();
    }
}

//-----------------------------------------------------------
// ���N���b�N����Ă����
//-----------------------------------------------------------
void DeckListManager::leftClickNow()
{
    int mx = input_state->getPointX();
    int my = input_state->getPointY();

    //---- ��X���C�h�{�^��
    if (deck_list_state->isPosBarUp(mx, my)) {
        deck_list_state->slideBarUp();
    }
    //---- ���X���C�h�{�^��
    if (deck_list_state->isPosBarDown(mx, my)) {
        deck_list_state->slideBarDown();
    }
}

//-----------------------------------------------------------
// ���N���b�N�I����
//-----------------------------------------------------------
void DeckListManager::leftClickEnd()
{
    deck_list_state->leftClickEnd();
}

//-----------------------------------------------------------
// �}�E�X�z�C�[��
//-----------------------------------------------------------
void DeckListManager::mouseWheel()
{
    int wheel = input_state->getMouseWheel();
    // ���X�N���[��
    if (wheel < 0) {
        for (int i = wheel; i < 0; i++) {
            deck_list_state->slideBarDown(10);
        }
    }
    // ��X�N���[��
    else if (wheel > 0) {
        for (int i = 0; i < wheel; i++) {
            deck_list_state->slideBarUp(10);
        }
    }
}

//===========================================================
// getter
//===========================================================