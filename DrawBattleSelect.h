//-----------------------------------------------------------
// DrawBattleSelect.h
// �f�b�L�ꗗ��ʂ̕`��
// ����� 2015.03.17
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "DxLib.h"
#include "GameData.h"
#include "GameState.h"

class DrawBattleSelect {
private:
    GameData *game_data;            // �Q�[���f�[�^
    GameState *game_state;          // �V�[���}�l�[�W���[
    BattleSelectState *battle_select_state; // �z�[���̏��
    InputState *input_state;        // ���͏��
    ImageData *image_data;          // �摜�f�[�^
    SaveData *save_data;            // �Z�[�u�f�[�^

    int handl_back;                 // �w�i
    int handl_back_1;               // �w�i�̏�ɂ��Ԃ�����
    int handl_back_2;               // �w�i�̏�ɂ��Ԃ�����
    int handl_button_back[2];       // �߂�{�^��
    int handl_button_battle[2];     // �ΐ�{�^��
    int handl_select;               // �I���}�X
    int handl_select_now;           // ���ݑI�𒆂�
    int handl_chara[10];            // �L�����C���X�g
    int handl_lank;                 // �����N
    int handl_select_left[2];       // ���I��
    int handl_select_right[2];      // �E�I��
    int handl_bar;
    int font;                       // �t�H���g
    int color_black;                // �F_��
public:
    DrawBattleSelect(GameData*, GameState*); // �R���X�g���N�^
    ~DrawBattleSelect();             // �f�X�g���N�^
    void init();             // ������
    void update();           // �X�V
    void loadImage();        // �摜�f�[�^�ǂݍ���
    void draw();             // �S�̕`��
    void drawAllOpponent();  // �ΐ푊��`��
    void drawOpponent(int, int);// �ΐ푊��`��
    void drawEnemyDeck();    // �f�b�L�`��
    void drawBattleData();   // �ΐ�f�[�^�`��
    void drawMyDeck();       // �����̃f�b�L�`��
    void drawDeckSelect();   // �f�b�L�I��`��
    void drawBar();          // �X�N���[���o�[�`��
    void drawButton();       // �{�^���`��
};