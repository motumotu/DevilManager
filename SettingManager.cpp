//-----------------------------------------------------------
// SettingManager.cpp
// �ݒ��ʊǗ�
// ����� 2015.03.25
// ����� motumotu
//-----------------------------------------------------------
#include "SettingManager.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
SettingManager::SettingManager(GameData *data, GameState *state)
{
    game_data = data;
    game_state = state;
    input_state = state->getInputState();
    setting_state = state->getSceneState()->getSettingState();

}
//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
SettingManager::~SettingManager()
{

}

//-----------------------------------------------------------
// ������
//-----------------------------------------------------------
void SettingManager::init()
{


}
//-----------------------------------------------------------
// �X�V����
//-----------------------------------------------------------
void SettingManager::update()
{
    //---- �}�E�X���W
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
// ���N���b�N�̍ŏ�
//-----------------------------------------------------------
void SettingManager::leftClickFirst()
{
    int pre_scene = setting_state->getPreScene();
    game_state->getSceneState()->changeScene(pre_scene);
}

//-----------------------------------------------------------
// ���N���b�N��
//-----------------------------------------------------------
void SettingManager::leftClickNow()
{

}

//-----------------------------------------------------------
// ���N���b�N�̍Ō�
//-----------------------------------------------------------
void SettingManager::leftClickEnd()
{

}