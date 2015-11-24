//-----------------------------------------------------------
// DeckListData.h
// �f�b�L�ꗗ��ʂ̃f�[�^
// ����� 2015.03.18
// ����� motumotu
//-----------------------------------------------------------
#pragma once
class DeckListData {
public:
    // UI
    // ���ǂ�{�^��
    static const int BUTTON_BACK_SIZE_X = 90;
    static const int BUTTON_BACK_SIZE_Y = 40;
    static const int BUTTON_BACK_POS_X = 0;
    static const int BUTTON_BACK_POS_Y = 0;
    // �f�b�L�ҏW�{�^��
    static const int BUTTON_EDIT_SIZE_X = 107;
    static const int BUTTON_EDIT_SIZE_Y = 31;
    static const int BUTTON_EDIT_POS_X = 550;
    static const int BUTTON_EDIT_POS_Y = 35;
    // �f�b�L�폜�{�^��
    static const int BUTTON_DELETE_SIZE_X = 107;
    static const int BUTTON_DELETE_SIZE_Y = 31;
    static const int BUTTON_DELETE_POS_X = 663;
    static const int BUTTON_DELETE_POS_Y = 35;
    // �f�b�L�ꗗ�{�^��
    static const int BUTTON_DECK_SIZE_X = 253;
    static const int BUTTON_DECK_SIZE_Y = 70;
    static const int BUTTON_DECK_POS_X = 26;
    static const int BUTTON_DECK_POS_Y = 70;
    // �f�b�L�����̓{�b�N�X
    static const int INPUT_BOX_SIZE_X = 211;
    static const int INPUT_BOX_SIZE_Y = 31;
    static const int INPUT_BOX_POS_X = 332;
    static const int INPUT_BOX_POS_Y = 35;
    // �X�N���[���o�[��
    static const int BAR_UP_SIZE_X = 21;
    static const int BAR_UP_SIZE_Y = 32;
    static const int BAR_UP_POS_X = 283;
    static const int BAR_UP_POS_Y = 73;
    // �X�N���[���o�[��
    static const int BAR_DOWN_SIZE_X = 21;
    static const int BAR_DOWN_SIZE_Y = 32;
    static const int BAR_DOWN_POS_X = 283;
    static const int BAR_DOWN_POS_Y = 529;
    // �X�N���[���o�[
    static const int BAR_SIZE_X = 21;
    static const int BAR_SIZE_Y = 70;
    static const int BAR_POS_X = 283;
    static const int BAR_POS_Y = 105;
    // �X�N���[���o�[�G���A
    static const int BAR_AREA_SIZE = 354;
    // �f�b�L�J�[�h�ꗗ
    static const int CARD_AREA_POS_X = 345;
    static const int CARD_AREA_POS_Y = 88;
public:
    DeckListData();                        // �R���X�g���N�^
    ~DeckListData();                       // �f�X�g���N�^
};