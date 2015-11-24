//-----------------------------------------------------------
// StorySelectManager.h
// �X�g�[���[�I����ʂ̐���
// ����� 2015.03.17
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"

class StorySelectManager {
public:
private:
    GameData *game_data;
    GameState *game_state;
    InputState *input_state;
    StorySelectState *story_select_state;
public:
    StorySelectManager(GameData*, GameState*);// �R���X�g���N�^
    ~StorySelectManager();       // �f�X�g���N�^
    void init();                 // ������
    void update();               // �X�V
    void leftClickFirst();       // ���N���b�N���ꂽ�u��
    void leftClickNow();         // ���N���b�N����Ă���� 
    void leftClickEnd();         // ���N���b�N�I����
};