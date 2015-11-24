//-----------------------------------------------------------
// DrawStory.h
// �X�g�[���[��ʂ̕`��
// ����� 2015.03.17
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"

class DrawStory {
public:
private:
    GameData *game_data;      // �Q�[���f�[�^
    GameState *game_state;    // �Q�[�����
    StoryState *story_state;  // �X�g�[���[���
    int handl_back;           // �w�i
    int handl_window;         // �E�C���h�E
    int handl_button[8];      // �{�^��
    int handl_button_close[2];// ����{�^��
    int handl_back_log;       // �o�b�N���O
    int handl_button_back[2]; // �߂�{�^��
    int handl_bar_area;       // �X�N���[���o�[�G���A
    int handl_bar;            // �X�N���[���o�[
    int font;                 // �t�H���g
    int color_white;          // �F_��
public:
    DrawStory(GameData*, GameState*); // �R���X�g���N�^
    ~DrawStory();             // �f�X�g���N�^
    void init();              // ������
    void update();            // �X�V
    void draw();              // �`��
    void loadImage();         // �摜�ǂݍ���
    void drawButton();        // �{�^���`��
    void drawText();          // �e�L�X�g�`��
    void drawLogText(int, int, StoryTextData*);  // �e�L�X�g�`��
    void drawBackLog();       // �o�b�N���O�`��
};