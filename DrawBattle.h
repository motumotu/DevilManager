//-----------------------------------------------------------
// DrawBattle.h
// �ΐ��ʕ`��
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "DxLib.h"
#include "GameData.h"
#include "GameState.h"
#include "DrawDamage.h"

class DrawBattle {
public:

private:
    GameData* game_data;
    InputState* input_state;
    BattleState* battle_state;
    BattleCardState *card_state;
    DrawDamage* draw_damage;
    ImageData *image_data;
    //---- �摜�n���h��
    int handl_base;
    int handl_map[100];         // �}�b�v�摜
    int hand_com_button[14];    // ���߃{�^��
    int handl_area_my;          // ���R�G���A
    int handl_area_ene;         // �G�R�G���A
    int handl_area_select;      // �G���A�I��
    int handl_area_select2;     // �G���A�I��
    int handl_area_grid;        // �G���A�O���b�h
    int handl_ui_card_back;     // �J�[�h�w�i
    int handl_ui_mp_back;       // mp�w�i
    int handl_ui_button_cancel; // �L�����Z���{�^��
    int handl_ui_button_end;    // �I���{�^��
    int handl_ui_card_intro;    // �J�[�h����
    int handl_res_win;          // ����
    int handl_res_lose;         // �s�k

    int color_white;            // �F_��
    int color_black;            // �F_��
    int color_blue;             // �F_��
    int color_red;              // �F_��
    int color_gray;             // �F_�O���[
    int color_green;            // �F_��
    int color_orange;           // �F_�I�����W

    int font_10;
    int font_12;

public:
    DrawBattle(GameData*,GameState*); // �R���X�g���N�^
    ~DrawBattle();              // �f�X�g���N�^
    void init();                // ������
    void update();              // �X�V
    void loadImage();           // �摜�ǂݍ���
    void draw();                // �`��
    void drawMap();             // �}�b�v�`��
    void drawUnit();            // ���j�b�g�`��
    void drawArea();            // �G���A�`��
    void drawAreaGrid();        // �G���A�O���b�h�`��
    void drawAreaMp();          // �G���A���͕`��
    void drawSelectUnit();      // �I�𒆂̃��j�b�g�`��
    void drawUnitArea(BattleUnitState*); // ���j�b�g�̗̈��`��
    void drawUnitArea(BattleUnitState*,int); // ���j�b�g�̗̈��`��
    void drawUnitArea(BattleUnitState*, int, int); // ���j�b�g�̗̈��`��
    void drawSelectMode();      // �I�����[�h���̕`��
    void drawSelectArea(int, int);// �I���G���A�`��
    void drawClickSelectArea(); // �N���b�N���̑I���G���A
    void drawUI();              // UI�`��
    void drawHpBar(BattleUnitState*);// ���j�b�gHP�Q�[�W�\��
    void drawHandCard();        // ��D�`��
    void drawTimeBar();         // �^�C���Q�[�W�\��
    void drawCardIntro(CardData*); // �J�[�h�����`��
    void drawResult();          // ���ʕ`��
};