//-----------------------------------------------------------
// DrawDeckList.h
// �f�b�L�ꗗ��ʂ̕`��
// ����� 2015.03.17
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "DxLib.h"
#include "GameData.h"
#include "GameState.h"

class DrawDeckList {
private:
    GameData *game_data;            // �Q�[���f�[�^
    GameState *game_state;          // �V�[���}�l�[�W���[
    DeckListState *deck_list_state; // �f�b�L�ꗗ��ʂ̏��
    DeckListData *deck_list_data;   // �f�b�L�ꗗ��ʂ̃f�[�^
    InputState *input_state;        // ���͏��
    SaveData *save_data;            // �Z�[�u�f�[�^
    ImageData *image_data;          // �摜�f�[�^
    int handl_back;                 // �w�i
    int handl_back1;
    int handl_back2;
    int handl_bar;
    int handl_bar_up;
    int handl_bar_down;
    int handl_button_back[2];       // ���ǂ�{�^��
    int handl_button_edit[2];       // �f�b�L�ҏW
    int handl_button_delete[2];     // �f�b�L�폜
    int handl_button_deck[2];       // �f�b�L�ꗗ�{�^��
    int font;
    int color_black;
public:
    DrawDeckList(GameData*, GameState*); // �R���X�g���N�^
    ~DrawDeckList();         // �f�X�g���N�^
    void init();             // ������
    void update();           // �X�V
    void loadImage();        // �摜�f�[�^�ǂݍ���
    void draw();             // �S�̕`��
    void drawBar();          // �o�[�`��
    void drawButton();       // �{�^���n�`��
    void drawDeckCard();     // �f�b�L�J�[�h�`��
    void drawDeckList();     // �f�b�L���X�g�`��
    void drawDeckName();     // �f�b�L���`��
};