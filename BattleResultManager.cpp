//-----------------------------------------------------------
// BattleResultManager.cpp
// �ΐ팋�ʉ�ʂ̐���
// ����� 2015.03.15
// ����� motumotu
//-----------------------------------------------------------
#include "BattleResultManager.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
BattleResultManager::BattleResultManager(GameData* data, GameState* state)
{
    game_data = data;
    game_state = state;
    input_state = state->getInputState();
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
BattleResultManager::~BattleResultManager()
{

}

//-----------------------------------------------------------
// ������
//-----------------------------------------------------------
void BattleResultManager::init()
{

}

//-----------------------------------------------------------
// �X�V
//-----------------------------------------------------------
void BattleResultManager::update()
{
    // ���N���b�N���ꂽ�u��
    if (input_state->getClick(MOUSE_INPUT_LEFT) == 1) {
        game_state->getSceneState()->changeScene(SceneState::SCENE_HOME);
    }
}