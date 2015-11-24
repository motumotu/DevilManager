//-----------------------------------------------------------
// BattleSelectState.h
// �ΐ�I����ʂ̏��
// ����� 2015.03.17
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"

class BattleSelectState {
public:
    static const int NONE = 0;               // �����Ȃ��ꏊ
    static const int BUTTON_BACK = 1;        // �߂�{�^��
    static const int BUTTON_BATTLE = 2;      // �ΐ�{�^��
    static const int DECK_SELECT_LEFT = 3;   // �f�b�L������
    static const int DECK_SELECT_RIGHT = 4;  // �f�b�L���E��
    static const int BAR_AREA = 5;           // �X�N���[���o�[�G���A
    static const int BAR = 6;                // �X�N���[���o�[
    static const int SELECT_AREA = 7;        // �I���G���A
private:
    GameData *game_data;          // �Q�[���f�[�^
    SaveData *save_data;          // �Z�[�u�f�[�^
    int select_num;               // �I��ԍ�
    int my_deck_num;              // �����̃f�b�L�ԍ�
    int shift_pos_y;              // ���炷���W�̗�
public:
    BattleSelectState(GameData*); // �R���X�g���N�^
    ~BattleSelectState();         // �f�X�g���N�^
    void init();                  // ������
    void update();                // �X�V
    void upSelectNum();           // �I��ԍ������
    void downSelectNum();         // �I��ԍ�������
    void leftMyDeck();            // ���Ƀf�b�L�ړ�
    void rightMyDeck();           // �E�Ƀf�b�L�ړ�
    void scrollBattleSelect(int);  // �X�N���[��
    void adjustmentBar(int, int);  // �o�[�̈ʒu����
    void selectBattleNum(int);    // �ΐ푊��I��

    int getPosObject(int, int);        // ���̍��W�̃I�u�W�F�N�g�擾
    bool isPosButtonBack(int, int);    // �߂�{�^����
    bool isPosButtonBattle(int, int);  // �ΐ�{�^����
    bool isPosDeckSelectLeft(int, int);   // �f�b�L�I����
    bool isPosDeckSelectRight(int, int);  // �f�b�L�I���E
    bool isPosBarArea(int, int);       // �X�N���[���o�[�G���A��
    bool isPosBar(int, int);           // �X�N���[���o�[
    bool isPosSelectArea(int, int);    // �I���G���A��
    int getPosBattleNum(int, int);     // ���̏ꏊ�̑ΐ푊��ԍ��擾
    //---- getter
    int getSelectNum();           // �I��ԍ��`��
    int getMyDeckNum();           // �����̃f�b�L�ԍ�
    int getShiftPosY();           // ���炷���W�ʎ擾
    int getMaxShiftPosY();        // �ő�X�N���[���ʎ擾
    double getShiftRate();        // �X�N���[�����Ă��銄���擾
    int getBarPos();              // �o�[�̈ʒu�擾
};