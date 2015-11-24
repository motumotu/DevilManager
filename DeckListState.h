//-----------------------------------------------------------
// DeckListState.h
// �f�b�L�ꗗ��ʂ̏��
// ����� 2015.03.17
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"

class DeckListState {
public:
    static const int NONE = 0;
    static const int BUTTON_BACK = 1;
    static const int BUTTON_EDIT = 2;
    static const int BUTTON_DELETE = 3;
    static const int INPUT_BOX = 4;
private:
    GameData *game_data;       // �Q�[���f�[�^
    SaveData *save_data;       // �Z�[�u�f�[�^
    int mouse_x;               // �}�E�X�̍��Wx
    int mouse_y;               // �}�E�X�̍��Wy
    int select_deck_num;       // �I�𒆂̃f�b�L
    int shift_pos_y;           // ���炷���W
    int input_handl;           // ���̓n���h��
    int input_active;          // ���͂��A�N�e�B�u��
    int bar_pos;               // �o�[�̈ʒu
    bool is_bar_click_now;     // �o�[���N���b�N����
public:
    DeckListState(GameData*);  // �R���X�g���N�^
    ~DeckListState();          // �f�X�g���N�^
    void init();               // ������
    void update();             // �X�V
    void updateMousePos(int, int); // �}�E�X�̍��W�X�V
    void selectDeckList(int);      // �f�b�L�I��
    void slideBarUp();             // �X���C�h�o�[�����
    void slideBarUp(int);          // �X���C�h�o�[�����
    void slideBarDown();           // �X���C�h�o�[������
    void slideBarDown(int);        // �X���C�h�o�[������
    void slideBarAdjustment();     // �X���C�h�o�[����
    void clickBar();               // �o�[���N���b�N
    void leftClickEnd();           // �}�E�X�N���b�N�I��

    int getMousePosObject();       // �}�E�X�̈ʒu�ɂ���I�u�W�F�N�g�擾
    bool isPosButtonBack(int, int);
    bool isPosButtonEdit(int, int);
    bool isPosButtonDelete(int, int);
    bool isPosInputBox(int, int);       // ���̓{�b�N�X
    int isPosDeckList(int, int);        // �f�b�L���X�g��
    bool isPosBarUp(int, int);          // ��X�N���[��
    bool isPosBarDown(int, int);        // ���X�N���[��
    bool isPosBar(int, int);            // �X�N���[���o�[
    bool isPosBarArea(int, int);        // �X�N���[���o�[�G���A
    int getSelectDeckNum();         // �I�𒆂̃f�b�L�擾
    int getShiftPosY();             // ���炷���W�擾
    void offInputActive();
    void onInputActive();
    int getInputActive();
    int getInputHandl();
    int getBarPos();                 // �X�N���[���o�[�̍��W�擾
};