//-----------------------------------------------------------
// BattleSelectManager.cpp
// �ΐ�I����ʂ̐���
// ����� 2015.03.17
// ����� motumotu
//-----------------------------------------------------------
#include "BattleSelectManager.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
BattleSelectManager::BattleSelectManager(GameData* data, GameState* state)
{
    game_data = data;
    game_state = state;
    input_state = state->getInputState();
    battle_select_state = state->getSceneState()->getBattleSelectState();
    init();
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
BattleSelectManager::~BattleSelectManager()
{

}

//-----------------------------------------------------------
// ������
//-----------------------------------------------------------
void BattleSelectManager::init()
{
    scroll_flag = false;
}

//-----------------------------------------------------------
// �X�V
//-----------------------------------------------------------
void BattleSelectManager::update()
{
    //---- �}�E�X�z�C�[��
    int wheel = input_state->getMouseWheel();
    battle_select_state->scrollBattleSelect(wheel);

    //---- �N���b�N����
    // ���N���b�N���ꂽ�u��
    if (input_state->getClick(MOUSE_INPUT_LEFT) == 1) {
        leftClickFirst();
    }
    // ���N���b�N��
    if (input_state->getClick(MOUSE_INPUT_LEFT) > 1) {
        leftClickNow();
    }
    // �N���b�N�������ꂽ�u��
    if (input_state->isRereaseClick(MOUSE_INPUT_LEFT)) {
        leftClickEnd();
    }

    //---- �L�[���͏���
    // ��
    if (input_state->getKeyState(KEY_INPUT_W) == 1) {
        battle_select_state->upSelectNum();
    }
    // �E
    if (input_state->getKeyState(KEY_INPUT_D) == 1) {
        battle_select_state->rightMyDeck();
    }
    // ��
    if (input_state->getKeyState(KEY_INPUT_S) == 1) {
        battle_select_state->downSelectNum();
    }
    // ��
    if (input_state->getKeyState(KEY_INPUT_A) == 1) {
        battle_select_state->leftMyDeck();
    }

    // ��
    if (input_state->getKeyState(KEY_INPUT_UP) == 1) {
        battle_select_state->upSelectNum();
    }
    // �E
    if (input_state->getKeyState(KEY_INPUT_RIGHT) == 1) {
        battle_select_state->rightMyDeck();
    }
    // ��
    if (input_state->getKeyState(KEY_INPUT_DOWN) == 1) {
        battle_select_state->downSelectNum();
    }
    // ��
    if (input_state->getKeyState(KEY_INPUT_LEFT) == 1) {
        battle_select_state->leftMyDeck();
    }
}

//-----------------------------------------------------------
// ���N���b�N�ŏ�
//-----------------------------------------------------------
void BattleSelectManager::leftClickFirst()
{
    int mx = input_state->getPointX();
    int my = input_state->getPointY();
    int obj = battle_select_state->getPosObject(mx, my);

    //---- �߂�{�^��
    if (obj == BattleSelectState::BUTTON_BACK) {
        game_state->getSceneState()->changeScene(SceneState::SCENE_HOME);
    }
    //---- �ΐ�{�^��
    if (obj == BattleSelectState::BUTTON_BATTLE) {
        game_state->getSceneState()->changeScene(SceneState::SCENE_BATTLE);
    }
    //----- ��
    if (obj == BattleSelectState::DECK_SELECT_LEFT) {
        battle_select_state->leftMyDeck();
    }
    //----- �E
    if (obj == BattleSelectState::DECK_SELECT_RIGHT) {
        battle_select_state->rightMyDeck();
    }
    //---- �X�N���[���o�[�G���A
    if (battle_select_state->isPosBarArea(mx, my)) {
        battle_select_state->adjustmentBar(mx, my);
        scroll_flag = true;
    }
    //---- �ΐ�I���G���A
    if (obj == BattleSelectState::SELECT_AREA) {
        int n = battle_select_state->getPosBattleNum(mx, my);
        if (n > 0) {
            battle_select_state->selectBattleNum(n);
        }
    }
}

//-----------------------------------------------------------
// ���N���b�N��
//-----------------------------------------------------------
void BattleSelectManager::leftClickNow()
{
    int mx = input_state->getPointX();
    int my = input_state->getPointY();

    // �X�N���[���o�[���N���b�N���ꂢ���Ƃ�
    if (scroll_flag) {
        battle_select_state->adjustmentBar(mx, my);
    }

}

//-----------------------------------------------------------
// ���N���b�N�Ō�
//-----------------------------------------------------------
void BattleSelectManager::leftClickEnd()
{
    scroll_flag = false;
}


//===========================================================
// getter
//===========================================================