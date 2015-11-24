//-----------------------------------------------------------
// StoryState.h
// �X�g�[���[�̏��
// ����� 2015.03.17
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"

class StoryState {
public:
    static const int NONE = 0;
    static const int BUTTON_AUTO = 1;
    static const int BUTTON_SKIP = 2;
    static const int BUTTON_LOG = 3;
    static const int BUTTON_CONFIG = 4;
    static const int BUTTON_CLOSE = 5;
    static const int BUTTON_BACK = 6;
    static const int BAR_AREA = 7;
private:
    GameData *game_data;       // �Q�[���f�[�^
    int mouse_x;               // �}�E�X���Wx
    int mouse_y;               // �}�E�X���Wy
    int now_text_num;          // ���݂̃e�L�X�g�ԍ�
    int now_text_len;          // ���݂̃e�L�X�g��
    int cnt_frame;             // �o�߃t���[��
    bool is_draw_end;          // �`��I�����Ă邩
    bool is_close;             // �E�C���h�E����Ă��邩
    bool is_auto;              // �I�[�g��
    bool is_next_text;         // ���̕��ɍs����
    bool is_back_log;          // �o�b�N���O�\����
    int backlog_pos;           // �o�b�N���O�̏ꏊ
    int bar_pos;               // �o�[�̈ʒu
public:
    StoryState(GameData*);     // �R���X�g���N�^
    ~StoryState();             // �f�X�g���N�^
    void init();               // ������
    void update();             // �X�V
    void updateMousePos(int, int); // �}�E�X���W

    //---- �e�L�X�g�֘A
    std::string getNowName();  // ���݂̖��O�擾
    std::string getNowText1(); // ���݂̃e�L�X�g�P�擾
    std::string getNowText2(); // ���݂̃e�L�X�g�Q�擾
    std::string getNowText3(); // ���݂̃e�L�X�g�R�擾
    int isJapaneseCharacter(unsigned char); // ���{�ꂩ
    void changeNextText();           // ���̃e�L�X�g
    void fullText();                 // �S���\��
    //----- �I�u�W�F�N�g�֘A
    int getMousePosObject(); // �}�E�X�̍��W�̕��̎擾
    bool isPosButtonAuto(int, int);
    bool isPosButtonSkip(int, int);
    bool isPosButtonLog(int, int);
    bool isPosButtonConfig(int, int);
    bool isPosButtonClose(int, int);
    bool isPosButtonBack(int, int);
    bool isPosBarArea(int, int);
    //---- �o�b�N���O
    int getBarPosY();           // �o�[�̈ʒu�擾
    void AdjustingBar();        // �o�[�̈ʒu����
    void changeBarMousePos();   // �o�[�̈ʒu�ύX
    void backlogUp();           // �o�b�N���O�����
    void backlogDown();         // �o�b�N���O������

    //---- setter
    void setNowTextNum(int);   // ���݃e�L�X�g�ԍ��ݒ�
    void setIsClose(bool);     // �E�C���h�E����Ă邩
    void setIsAuto(bool);      // �I�[�g����ݒ�
    void setIsBackLog(bool);   // �o�b�N���O�\����
    //---- getter
    int getNowTextNum();       // ���݃e�L�X�g�ԍ��擾
    StoryTextData *getNowStoryTextData();
    std::string getNowText();  // ���݂̃e�L�X�g�擾
    bool isDrawEnd();          // �`��I�����Ă邩
    bool isClose();            // �E�B���h�E����Ƃ�̂�
    bool isAuto();             // �I�[�g��
    bool isNextText();         // ���̃e�L�X�g�s����
    bool isBackLog();          // �o�b�N���O�\����
    int getBacklogPos();       // �o�b�N���O�ꏊ
};