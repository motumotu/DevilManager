//-----------------------------------------------------------
// DrawStorySelect.h
// �X�g�[���[�I����ʂ̕`��
// ����� 2015.03.17
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"

class DrawStorySelect {
public:
private:
    GameData *game_data;        // �Q�[���f�[�^
    GameState *game_state;      // �Q�[���̏��
    StorySelectState *story_select_state;
    SaveData *save_data;

    int handl_back;                 // �w�i�摜
    int handl_button_back[2];       // �߂�{�^��
    int handl_button_decision[2];   // ����{�^��
    int handl_deck_select_left[2];  // ���I���{�^��
    int handl_deck_select_right[2]; // �E�I���{�^��
    int handl_story[10][9];         // �X�g�[���[
    int handl_story_select;         // �I�𒆃X�g�[���[
    int handl_rank;                 // �����N
    int handl_mouseon;

    int color_black;                // �F��
    int font;                       // �t�H���g
public:
    DrawStorySelect(GameData*, GameState*); // �R���X�g���N�^
    ~DrawStorySelect();         // �f�X�g���N�^
    void init();                // ������
    void update();              // �X�V
    void loadImage();           // �摜�ǂݍ���
    void draw();                // �`��
    void drawMyDeck();          // �����f�b�L�`��
    void drawStory();           // �X�g�[���[�`��
    void drawStoryInfo();       // �X�g�[���[���`��
    void drawDeckCard();        // �f�b�L�̃J�[�h�`��
};