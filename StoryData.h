//-----------------------------------------------------------
// StoryData.h
// �X�g�[���[��ʂ̃f�[�^
// ����� 2015.03.23
// ����� motumotu
//-----------------------------------------------------------
#pragma once

class StoryData {
public:
    static const int WINDOW_POS_X = 0;
    static const int WINDOW_POS_Y = 385;
    // �{�^��
    static const int BUTTON_POS_X = 685;
    static const int BUTTON_POS_Y = 485;
    static const int BUTTON_SIZE_X = 110;
    static const int BUTTON_SIZE_Y = 26;
    // �e�L�X�g
    static const int TEXT_AREA_POS_X = 155;
    static const int TEXT_AREA_POS_Y = 480;
    // ����{�^��
    static const int BUTTON_CLOSE_POS_X = 634;
    static const int BUTTON_CLOSE_POS_Y = 455;
    static const int BUTTON_CLOSE_SIZE_X = 25;
    static const int BUTTON_CLOSE_SIZE_Y = 25;
    // �o�b�N���O�X�N���[���o�[�G���A
    static const int BACKLOG_BAR_AREA_POS_X = 746;
    static const int BACKLOG_BAR_AREA_POS_Y = 39;
    static const int BACKLOG_BAR_AREA_SIZE_X = 19;
    static const int BACKLOG_BAR_AREA_SIZE_Y = 460;
    // �o�b�N���O�o�[
    static const int BACKLOG_BAR_SIZE_X = 17;
    static const int BACKLOG_BAR_SIZE_Y = 41;
    // �o�b�N���O�߂�{�^��
    static const int BACKLOG_BUTTON_BACK_SIZE_X = 82;
    static const int BACKLOG_BUTTON_BACK_SIZE_Y = 60;
    static const int BACKLOG_BUTTON_BACK_POS_X = 683;
    static const int BACKLOG_BUTTON_BACK_POS_Y = 530;
    // �o�b�N���O�e�L�X�g�G���A
    static const int BACKLOG_TEXT_AREA_POS_X = 70;
    static const int BACKLOG_TEXT_AREA_POS_Y = 60;
    static const int BACKLOG_TEXT_AREA_SIZE_X = 650;
    static const int BACKLOG_TEXT_AREA_SIZE_Y = 460;
private:
public:
    StoryData();    // �R���X�g���N�^
    ~StoryData();   // �f�X�g���N�^
};