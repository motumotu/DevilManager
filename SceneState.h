//-----------------------------------------------------------
// SceneState.h
// �e�V�[���̏��
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "TitleState.h"
#include "HomeState.h"
#include "BattleState.h"
#include "BattleResultState.h"
#include "StorySelectState.h"
#include "StoryState.h"
#include "DeckListState.h"
#include "DeckEditState.h"
#include "BattleSelectState.h"
#include "SettingState.h"

class SceneState {
public:
    static const int SCENE_TITLE = 0;         // �^�C�g��
    static const int SCENE_HOME = 1;          // �z�[��
    static const int SCENE_BATTLE = 2;        // �ΐ�
    static const int SCENE_BATTLE_RESULT = 3; // �ΐ팋��
    static const int SCENE_STORY_SELECT = 4;  // �X�g�[���[�I��
    static const int SCENE_BATTLE_SELECT = 5; // �ΐ�I��
    static const int SCENE_STORY = 6;         // �X�g�[���[���
    static const int SCENE_DECKLIST = 7;      // �f�b�L���
    static const int SCENE_DECKEDIT = 8;      // �f�b�L�ҏW���
    static const int SCENE_SETTING = 9;       // �ݒ���
private:
    GameData *game_data;                    // �Q�[���f�[�^
    SaveData *save_data;                    // �Z�[�u�f�[�^
    TitleState *title_state;                // �^�C�g�����
    HomeState *home_state;                  // �z�[�����
    BattleState *battle_state;              // �ΐ���
    BattleResultState *battle_result_state; // �ΐ팋�ʉ��
    StorySelectState * story_select_state;  // �X�g�[���[�I�����
    StoryState *story_state;                // �X�g�[���[���
    DeckListState *deck_list_state;         // �f�b�L�ꗗ���
    DeckEditState *deck_edit_state;         // �f�b�L�ҏW���
    BattleSelectState *battle_select_state; // �ΐ�I�����
    SettingState *setting_state;            // �ݒ���

    int now_scene;             // ���݃V�[��
    int change_scene;          // �ω���̃V�[��
    int is_fade_out_now;       // �t�F�[�h�A�E�g����
    int is_fade_in_now;        // �t�F�[�h�C������
    int fade_val;              // �t�F�[�h�ʎ擾
public:
    SceneState(GameData*);     // �R���X�g���N�^
    ~SceneState();             // �f�X�g���N�^
    void init();               // ������
    void update();             // �X�V
    void changeScene(int);     // �V�[���ύX
    void change();             // �`�F���W

    TitleState *getTitleState();               // �^�C�g����ʏ�Ԏ擾
    HomeState *getHomeState();                 // �z�[����ʏ�Ԏ擾
    BattleState *getBattleState();             // �ΐ��ʏ�Ԏ擾
    BattleResultState *getBattleResultState(); // �ΐ팋�ʉ�ʏ�Ԏ擾
    StorySelectState *getStorySelectState();   // �X�g�[���[�I����ʏ��
    StoryState *getStoryState();               // �X�g�[���[��ʏ�Ԏ擾
    DeckListState *getDeckListState();         // �f�b�L�ꗗ��ʏ�Ԏ擾
    DeckEditState *getDeckEditState();         // �f�b�L�ꗗ��ʏ�Ԏ擾
    BattleSelectState *getBattleSelectState(); // �ΐ�I����ʏ�Ԏ擾
    SettingState *getSettingState();           // �ݒ��ʂ̎擾
    int getNowScene();                         // ���݂̃V�[���擾
    int getIsFadeOutNow();                     // �t�F�[�h����
    int getIsFadeInNow();                      // �t�F�[�h����
    int getFadeVal();                          // �t�F�[�h�ʎ擾
};