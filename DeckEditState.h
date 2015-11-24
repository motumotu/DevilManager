//-----------------------------------------------------------
// DeckEditState.h
// �f�b�L�ҏW��ʂ̏��
// ����� 2015.03.17
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"

class DeckEditState {
public:
    static const int NONE = 0;        // �����Ȃ�
    static const int BUTTON_BACK = 1; // �߂�{�^��
    static const int DECK_AREA = 2;   // �f�b�L�G���A
    static const int CARD_AREA = 3;   // �J�[�h�G���A
private:
    GameData *game_data;         // �Q�[���f�[�^
    SaveData *save_data;         // �Z�[�u�f�[�^
    int shift_pos_y;             // �V�t�g���W
    int bar_pos;                 // �X���C�h�o�[�̈ʒu
    int select_deck_num;         // �I������Ă�f�b�L�ԍ�
    int select_now_card;         // �I�𒆂̃J�[�h
    int mouse_x;                 // �}�E�X���W
    int mouse_y;                 // �}�E�X���W
public:
    DeckEditState(GameData*);    // �R���X�g���N�^
    ~DeckEditState();            // �f�X�g���N�^
    void init();                 // ������
    void update();               // �X�V
    void updateMousePos(int, int); // �}�E�X���W�X�V
    void slideBarUp();           // ��ɃX���C�h
    void slideBarUp(int);        // ��ɃX���C�h
    void slideBarDown();         // ���ɃX���C�h
    void slideBarDown(int);      // ���ɃX���C�h
    void slideBarAdjustment();   // �X���C�h�o�[�̒���
    void selectDeckAreaCard(int);// �f�b�L�G���A��n�Ԗڂ�I��
    void selectCardAreaCard(int);// �J�[�h�G���A��n�Ԗڂ�I��
    void mouseRelease();         // �}�E�X�������ꂽ
    void addDeckAreaCard(int);   // �f�b�L�G���A��n�ԖڂɑI�𒆂̃J�[�h��ǉ�
    void addCardAreaCard(int);   // �J�[�h�G���A��n�ԖڂɑI�𒆂̃J�[�h��ǉ�
    bool isDeckMax();            // �f�b�L���ő傩

    int getPosObject(int, int);     // ���̈ʒu�̕���
    int getMousePosObject();        // �}�E�X���W�̕��̎擾
    int getPosCard(int, int);       // ���̍��W�̃J�[�h�擾
    int getMousePosCard();          // �}�E�X�̍��W�ʒu�̃J�[�h�擾
    int getPosDeckAreaNum(int, int);// ���̍��W���f�b�L�G���A�̉��Ԗڂ��擾
    int getPosCardAreaNum(int, int);// ���̍��W���J�[�h�G���A�̉��Ԗڂ��擾
    bool isPosButtonBack(int, int); // �߂�{�^���̈ʒu��
    bool isPosDeckArea(int, int);   // �f�b�L�G���A��
    bool isPosCardArea(int, int);   // �J�[�h�G���A��
    int getShiftPosY();             // �V�t�g
    int getBarPosY();               // �o�[�̈ʒu
    void setSelectDeckNum(int);     // �I���f�b�L���Z�b�g
    int getSelectNowCard();         
};