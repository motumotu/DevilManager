//-----------------------------------------------------------
// StorySelectData.h
// �X�g�[���[�I����ʂ̃f�[�^
// ����� 2015.03.22
// ����� motumotu
//-----------------------------------------------------------
#pragma once
class StorySelectData {
public:
    //---- UI
    // ���ǂ�{�^��
    static const int BUTTON_BACK_SIZE_X = 90;
    static const int BUTTON_BACK_SIZE_Y = 40;
    static const int BUTTON_BACK_POS_X = 0;
    static const int BUTTON_BACK_POS_Y = 0;
    // ����{�^��
    static const int BUTTON_DECISION_SIZE_X = 253;
    static const int BUTTON_DECISION_SIZE_Y = 70;
    static const int BUTTON_DECISION_POS_X = 537;
    static const int BUTTON_DECISION_POS_Y = 476;
    // �����f�b�L�G���A
    static const int DECK_AREA_POS_X = 537;
    static const int DECK_AREA_POS_Y = 344;
    static const int DECK_AREA_SIZE_X = 253;
    static const int DECK_AREA_SIZE_Y = 70;
    // �f�b�L�I���{�^��
    static const int DECK_SELECT_SIZE_X = 22;
    static const int DECK_SELECT_SIZE_Y = 41;
    // �f�b�L�I����
    static const int DECK_SELECT_LEFT_POS_X = 557;
    static const int DECK_SELECT_LEFT_POS_Y = 417;
    // �f�b�L�I���E
    static const int DECK_SELECT_RIGHT_POS_X = 748;
    static const int DECK_SELECT_RIGHT_POS_Y = 417;
    // �X�g�[���[�I��
    static const int STORY_SIZE_X = 150;
    static const int STORY_SIZE_Y = 100;
    static const int STORY_AREA_POS_X = 30;
    static const int STORY_AREA_POS_Y = 140;
    static const int STORY_AREA_SIZE_X = 509;
    static const int STORY_AREA_SIZE_Y = 438;
    // �X�g�[���[���
    static const int STORY_INFO_AREA_POS_X = 537;
    static const int STORY_INFO_AREA_POS_Y = 47;

    //---- �X�g�[���[�֌W
    static const int CHAPTER_NUM = 1;   // �`���v�^�[��
    static const int STORY_NUM_1 = 9;   // �`���v�^�[1�̃X�g�[���[��
    static const int STORY_NUM_2 = 9;   // �`���v�^�[2�̃X�g�[���[��

public:
    StorySelectData();            // �R���X�g���N�^
    ~StorySelectData();           // �f�X�g���N�^
};