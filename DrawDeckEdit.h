//-----------------------------------------------------------
// DrawDeckEdit.h
// �f�b�L�ҏW��ʂ̕`��
// ����� 2015.03.17
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "DxLib.h"
#include "GameData.h"
#include "GameState.h"

class DrawDeckEdit {
private:
    GameData *game_data;            // �Q�[���f�[�^
    GameState *game_state;          // �V�[���}�l�[�W���[
    DeckEditState *deck_edit_state; // �z�[���̏��
    InputState *input_state;        // ���͏��
    SaveData *save_data;            // �Z�[�u�f�[�^
    int handl_back;                 // �w�i
    int handl_back1;                // �w�i1
    int handl_back2;                // �w�i2
    int handl_button_back[2];       // ���ǂ�{�^��
    int handl_bar;
    int font_10;
    int font_12;
    int color_black;
public:
    DrawDeckEdit(GameData*, GameState*); // �R���X�g���N�^
    ~DrawDeckEdit();             // �f�X�g���N�^
    void init();             // ������
    void update();           // �X�V
    void loadImage();        // �摜�f�[�^�ǂݍ���
    void draw();             // �S�̕`��
    void drawDeckArea();     // �f�b�L�̃J�[�h�`��
    void drawCardIntro(CardData*); // �J�[�h�����`��
    void drawCardList();     // �J�[�h���X�g�`��
    void drawBar();          // �o�[�̕`��
    void drawSelectNowCard();// �I�𒆂̃J�[�h�`��
};