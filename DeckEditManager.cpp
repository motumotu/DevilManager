//-----------------------------------------------------------
// DeckEditManager.cpp
// �f�b�L�ҏW��ʂ̐���
// ����� 2015.03.17
// ����� motumotu
//-----------------------------------------------------------
#include "DeckEditManager.h"

//-----------------------------------------------------------
// �R���X�g���N�^
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
// �f�X�g���N�^
//-----------------------------------------------------------
DeckEditManager::~DeckEditManager()
{

}

//-----------------------------------------------------------
// ������
//-----------------------------------------------------------
void DeckEditManager::init()
{

}

//-----------------------------------------------------------
// �X�V
//-----------------------------------------------------------
void DeckEditManager::update()
{
    deck_edit_state->setSelectDeckNum(game_state->getSceneState()->getDeckListState()->getSelectDeckNum());
    //---- �}�E�X�z�C�[��
    mouseWheel();

    //---- �}�E�X���W
    /*
    deck_edit_state->updateMousePos(
        input_state->getPointX(),
        input_state->getPointY());
    */
    deck_edit_state->updateMousePos(
        input_state->getPointX(),
        input_state->getPointY());
    //---- �N���b�N����
    // ���N���b�N���ꂽ�u��
    if (input_state->getClick(MOUSE_INPUT_LEFT) == 1) {
        leftClickFirst();
    }
    // ���N���b�N��������Ă����
    if (input_state->getClick(MOUSE_INPUT_LEFT) > 1) {
        leftClickNow();
    }
    // �N���b�N�������ꂽ�u��
    if (input_state->isRereaseClick(MOUSE_INPUT_LEFT)) {
        leftClickEnd();
    }
}

//-----------------------------------------------------------
// ���N���b�N�����ꂽ�u��
//-----------------------------------------------------------
void DeckEditManager::leftClickFirst()
{
    int mx = input_state->getPointX();
    int my = input_state->getPointY();
    int obj = deck_edit_state->getPosObject(mx, my);
    
    //---- �߂�{�^��
    if (obj == DeckEditState::BUTTON_BACK) {
        game_state->getSceneState()->changeScene(SceneState::SCENE_DECKLIST);
    }
    //---- �f�b�L�G���A
    else if (obj == DeckEditState::DECK_AREA) {
        int n = deck_edit_state->getPosDeckAreaNum(mx, my);
        deck_edit_state->selectDeckAreaCard(n);
    }
    //---- �J�[�h�G���A
    else if (obj == DeckEditState::CARD_AREA) {
        int n = deck_edit_state->getPosCardAreaNum(mx, my);
        deck_edit_state->selectCardAreaCard(n);
    }
}

//-----------------------------------------------------------
// ���N���b�N��
//-----------------------------------------------------------
void DeckEditManager::leftClickNow()
{

}

//-----------------------------------------------------------
// ���N���b�N�̏I���
//-----------------------------------------------------------
void DeckEditManager::leftClickEnd()
{
    int mx = input_state->getPointX();
    int my = input_state->getPointY();
    int obj = deck_edit_state->getPosObject(mx, my);

    //---- �f�b�L�G���A (�J�[�h���ő�łȂ���Βǉ�)
    if (obj == DeckEditState::DECK_AREA && !deck_edit_state->isDeckMax()) {
        int n = deck_edit_state->getPosDeckAreaNum(mx, my);
        deck_edit_state->addDeckAreaCard(n);
    }
    //---- �J�[�h�G���A
    else if (obj == DeckEditState::CARD_AREA) {
        int n = deck_edit_state->getPosCardAreaNum(mx, my);
        deck_edit_state->addCardAreaCard(n);
    }
    //---- ���̑�
    else {
        deck_edit_state->addCardAreaCard(-1);
    }

    deck_edit_state->mouseRelease();
}

//-----------------------------------------------------------
// �}�E�X�z�C�[��
//-----------------------------------------------------------
void DeckEditManager::mouseWheel()
{
    int wheel = input_state->getMouseWheel();

    // ���X�N���[��
    if (wheel < 0) {
        for (int i = wheel; i < 0; i++) {
            deck_edit_state->slideBarDown(10);
        }
    }
    // ��X�N���[��
    else if (wheel > 0) {
        for (int i = 0; i < wheel; i++) {
            deck_edit_state->slideBarUp(10);
        }
    }
}

//===========================================================
// getter
//===========================================================