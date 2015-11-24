//-----------------------------------------------------------
// StorySelectState.h
// �X�g�[���[�I����ʂ̏��
// ����� 2015.03.17
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"

class StorySelectState {
public:
    static const int NONE = 0;
    static const int BUTTON_BACK = 1;
    static const int BUTTON_DECISION = 2;
    static const int DECK_SELECT_LEFT = 3;
    static const int DECK_SELECT_RIGHT = 4;
    static const int STORY_AREA = 5;
    static const int DECK_AREA = 6;
private:
    GameData *game_data;   // �Q�[���f�[�^
    SaveData *save_data;   // �Z�[�u�f�[�^
    int mouse_x;           // �}�E�X���Wx
    int mouse_y;           // �}�E�X���Wy
    int deck_num;          // �f�b�L�ԍ�
    int story_num;         // �X�g�[���[�ԍ�
    int chapter_num;       // �`���v�^�[�ԍ�
public:
    StorySelectState(GameData*);    // �R���X�g���N�^
    ~StorySelectState();            // �f�X�g���N�^
    void init();                    // ������
    void update();                  // �X�V
    void updateMousePos(int, int);  // �}�E�X���W�X�V
    void deckSelectLeft();          // �f�b�L�I��������
    void deckSekectRight();         // �f�b�L�I�����E��
    void selectStory(int);          // �X�g�[���[��I��
    
    int getMousePosObject();             // �}�E�X���W�̕��̎擾
    int getPosObject(int, int);          // ���̍��W�ɂ��镨�̎擾
    bool isPosButtonBack(int,int);       // �߂�{�^����
    bool isPosButtonDecision(int, int);  // ����{�^����
    bool isPosDeckSelectLeft(int, int);  // �f�b�L�I���{�^����
    bool isPosDeckSelectRight(int, int); // �f�b�L�I���{�^���E
    bool isPosStoryArea(int, int);       // �X�g�[���[�G���A��
    bool isPosDeckArea(int, int);        // �f�b�L�G���A��
    int getMousePosStory();              // �}�E�X�̈ʒu�ɂ���X�g�[���[���擾
    //---- getter
    int getDeckNum();      // �f�b�L�ԍ��擾
    int getStoryNum();     // �X�g�[���[�ԍ��擾
    int getChapterNum();   // �`���v�^�[�ԍ��擾
    int getNowChapterStoryNum(); // ���݃`���v�^�[�̃X�g�[���[���擾
};