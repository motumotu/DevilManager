//-----------------------------------------------------------
// BattleManager.cpp
// �ΐ��ʂ̐���
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#include "BattleManager.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
BattleManager::BattleManager(GameData *data, GameState *state)
{
    enemy_manager = new BattleEnemyManager(data, state);
    game_data = data;
    game_state = state;
    battle_state = state->getSceneState()->getBattleState();
    map_state = battle_state->getMapState();
    card_state = battle_state->getCardState();
    input_state = state->getInputState();
    init();
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
BattleManager::~BattleManager()
{
    delete(enemy_manager);
}

//-----------------------------------------------------------
// ������
//-----------------------------------------------------------
void BattleManager::init()
{
    
}

//-----------------------------------------------------------
// �X�V
//-----------------------------------------------------------
void BattleManager::update()
{
    clickProcess();                  // �v���C���[
    enemy_manager->updateCommand();  // �G
}

//-----------------------------------------------------------
// �N���b�N����
//-----------------------------------------------------------
void BattleManager::clickProcess()
{
    int x = input_state->getPointX();
    int y = input_state->getPointY();
    //---- �}�E�X���W
    battle_state->updateMousePos(x, y);
    battle_state->updateMouseOnUnit(x, y);
    if (x <= 0) {
        battle_state->moveShiftPos(Define::DIRE_LEFT, 3);
    }
    if (x >= SystemData::getWindowWidth()) {
        battle_state->moveShiftPos(Define::DIRE_RIGHT, 3);
    }
    if (y <= 0) {
        battle_state->moveShiftPos(Define::DIRE_UP, 3);
    }
    if (y >= SystemData::getWindowHeight()) {
        battle_state->moveShiftPos(Define::DIRE_DOWN, 3);
    }
    //---- �}�E�X�N���b�N����
    // ���N���b�N���ꂽ�u��
    if (input_state->getClick(MOUSE_INPUT_LEFT) == 1) {
        leftClickProcess();
    }
    // �E�N���b�N���ꂽ�u��
    if (input_state->getClick(MOUSE_INPUT_RIGHT) == 1) {
        rightClickProcess();
    }
    // ���N���b�N��
    if (input_state->getClick(MOUSE_INPUT_LEFT) > 1) {
        if (battle_state->getNowTurn() == BattleState::TURN_BATTLE) {
            battle_state->nowLeftClick(x, y);
        }
    }
    // ���N���b�N�I��
    if (battle_state->isLeftClickNow() && input_state->getClick(MOUSE_INPUT_LEFT) == 0) {
        if (battle_state->getNowTurn() == BattleState::TURN_BATTLE) {
            battle_state->endLeftClick(x, y);
        }
    }

    //---- �L�[����
    // ��
    if (input_state->getKeyState(KEY_INPUT_W) >= 1) {
        battle_state->moveShiftPos(Define::DIRE_UP, 5);
    }
    // �E
    if (input_state->getKeyState(KEY_INPUT_D) >= 1) {
        battle_state->moveShiftPos(Define::DIRE_RIGHT, 5);
    }
    // ��
    if (input_state->getKeyState(KEY_INPUT_S) >= 1) {
        battle_state->moveShiftPos(Define::DIRE_DOWN, 5);
    }
    // ��
    if (input_state->getKeyState(KEY_INPUT_A) >= 1) {
        battle_state->moveShiftPos(Define::DIRE_LEFT, 5);
    }
}

//-----------------------------------------------------------
// ���R���j�b�g����
//-----------------------------------------------------------
void BattleManager::createMyUnit(int id)
{
    createMyUnit(id,
        battle_state->getPlayerPosX(),
        battle_state->getPlayerPosY());
}
void BattleManager::createMyUnit(int id, int x, int y)
{
    if (battle_state->getMapState()->getMapData()->outCheck(x, y)) return;
    battle_state->getMapState()->createMyUnit(
        game_data->getAllCardData()->getCardData(id), x, y);
}

//-----------------------------------------------------------
// �G�R���j�b�g����
//-----------------------------------------------------------
void BattleManager::createEnUnit(int id, int x, int y)
{
    if (battle_state->getMapState()->getMapData()->outCheck(x, y)) return;
    battle_state->getMapState()->createEnUnit(
        game_data->getAllCardData()->getCardData(id), x, y);

}

//-----------------------------------------------------------
// �E�N���b�N����
//-----------------------------------------------------------
void BattleManager::rightClickProcess()
{

}

//-----------------------------------------------------------
// ���N���b�N����
//-----------------------------------------------------------
void BattleManager::leftClickProcess()
{
    int mx = input_state->getPointX();
    int my = input_state->getPointY();
    int px = battle_state->changeMousePosX(mx);
    int py = battle_state->changeMousePosY(my);

    //---- �ΐ풆�̏���
    if (battle_state->getNowTurn() == BattleState::TURN_BATTLE) {
        // �}�b�v����
        if (my < SystemData::getWindowHeight() - 90) {
            battle_state->firstLeftClick(mx, my);
        }
        // UI����
        if (my >= SystemData::getWindowHeight() - 90) {
            for (int i = 0; i < 7; i++) {
                if (mx >= i * 70 + 21 && mx <= i * 70 + 81 && my >= 535 && my <= 595) {
                    battle_state->setSelectUnitCom(i);
                }
            }
        }
    }
    //---- �J�[�h�I�𒆂̏���
    else if (battle_state->getNowTurn() == BattleState::TURN_CURD_SELECT) {
        // �L�����Z���{�^��
        if (mx >= BattleState::BUTTON_CANCEL_TOP_X &&
            mx <= BattleState::BUTTON_CANCEL_TOP_X + BattleState::BUTTON_CANCEL_SIZE_X &&
            my >= BattleState::BUTTON_CANCEL_TOP_Y &&
            my <= BattleState::BUTTON_CANCEL_TOP_Y + BattleState::BUTTON_CANCEL_SIZE_Y) {
            battle_state->selectCancelButton();
        }
        // �I���{�^��
        if (mx >= BattleState::BUTTON_END_TOP_X &&
            mx <= BattleState::BUTTON_END_TOP_X + BattleState::BUTTON_END_SIZE_X &&
            my >= BattleState::BUTTON_END_TOP_Y &&
            my <= BattleState::BUTTON_END_TOP_Y + BattleState::BUTTON_END_SIZE_Y) {
            enemy_manager->useCard();
            battle_state->selectEndButton();
        }
        // �J�[�h�I��
        for (int i = 0; i < card_state->getMyHandNum(); i++) {
            if (mx >= 21 + i * 70 && mx <= 21 + i * 70 + 60 &&
                my >= 510 && my <= 595) {
                battle_state->selectCard(i);
            }
        }
    }
    //---- �J�[�h�g�p���̏���
    else if (battle_state->getNowTurn() == BattleState::TURN_CURD_USE) {
        int id = card_state->getSelectCard();
        if (!battle_state->isPutUnitMy(game_data->getAllCardData()->getCardData(id), px, py)) return;
        createMyUnit(id, px, py);
        battle_state->putUnit();
        battle_state->useMyMp(game_data->getAllCardData()->getCardData(id)->mp);
    }
    //---- �ΐ�I����
    else if (battle_state->getNowTurn() == BattleState::TURN_END) {
        // ���ʂ�BattleResultState�Ɋi�[�ナ�U���g��ʂɉ�ʑJ��
        game_state->getSceneState()->changeScene(SceneState::SCENE_BATTLE_RESULT);
    }
}

//===========================================================
// getter
//===========================================================

