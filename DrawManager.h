//-----------------------------------------------------------
// DrawManager.h
// �`�搧��
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"
#include "DrawTitle.h"
#include "DrawHome.h"
#include "DrawBattle.h"
#include "DrawBattleResult.h"
#include "DrawStorySelect.h"
#include "DrawStory.h"
#include "DrawDeckList.h"
#include "DrawDeckEdit.h"
#include "DrawBattleSelect.h"
#include "DrawSetting.h"

class DrawManager {
private:
    DrawTitle *draw_title;                // �^�C�g�����
    DrawHome *draw_home;                  // �z�[�����
    DrawBattle *draw_battle;              // �ΐ���
    DrawBattleResult *draw_battle_result; // �ΐ팋�ʉ��
    DrawStorySelect *draw_story_select;   // �X�g�[���[�I����ʂ̕`��
    DrawStory *draw_story;                // �X�g�[���[��ʂ̕`��
    DrawDeckList *draw_deck_list;         // �f�b�L�ꗗ���
    DrawDeckEdit *draw_deck_edit;         // �f�b�L�ꗗ���
    DrawBattleSelect *draw_battle_select; // �ΐ�I�����
    DrawSetting *draw_setting;            // �ݒ��ʂ̕`��
    //----------
    GameData *game_data;                  // �Q�[���f�[�^
    GameState *game_state;                // �Q�[���̏��
    SceneState *scene_state;              // �V�[���̏��
    int color_black;
public:
    DrawManager(GameData*, GameState*);   // �R���X�g���N�^
    ~DrawManager();                       // �f�X�g���N�^
    void init();                          // ������
    void update();                        // �X�V
    void draw();                          // �`��
};