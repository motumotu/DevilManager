//-----------------------------------------------------------
// SceneManager.h
// �e�V�[���̐���
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"
#include "TitleManager.h"
#include "HomeManager.h"
#include "BattleManager.h"
#include "BattleResultManager.h"
#include "StorySelectManager.h"
#include "StoryManager.h"
#include "DeckListManager.h"
#include "DeckEditManager.h"
#include "BattleSelectManager.h"
#include "SettingManager.h"

class SceneManager {
public:

private:
    TitleManager *title_manager;                // �^�C�g�����
    HomeManager *home_manager;                  // �z�[�����
    BattleManager *battle_manager;              // �ΐ���
    BattleResultManager *battle_result_manager; // �ΐ팋�ʉ��
    StorySelectManager *story_select_manager;   // �X�g�[���[�I�����
    StoryManager *story_manager;                // �X�g�[���[���
    DeckListManager *deck_list_manager;         // �f�b�L�ꗗ���
    DeckEditManager *deck_edit_manager;         // �f�b�L�ҏW���
    BattleSelectManager *battle_select_manager; // �ΐ�I�����
    SettingManager *setting_manager;            // �ݒ���

    GameData *game_data;            // �Q�[���f�[�^
    GameState *game_state;          // �V�[���}�l�[�W���[
public:
    SceneManager(GameData*,GameState*); // �R���X�g���N�^
    ~SceneManager();             // �f�X�g���N�^
    void init();                 // ������
    void update();               // �X�V
};