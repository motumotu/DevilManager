//-----------------------------------------------------------
// HomeState.h
// �z�[����ʂ̏��
// ����� 2015.03.16
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"

class HomeState {
public:
    static const int CLICK_NONE = 0;             // �����N���b�N����ĂȂ�
    static const int CLICK_BUTTON_STORY = 1;
    static const int CLICK_BUTTON_BATTLE = 2;
    static const int CLICK_BUTTON_DECK = 3;
    static const int CLICK_BUTTON_SHOP = 4;
    static const int CLICK_BUTTON_SAVE = 5;
    static const int CLICK_BUTTON_SETTING = 6;
private:
    GameData *game_data;         // �Q�[���f�[�^
    int click_now;               // �N���b�N����
    int click_pos_x;             // �N���b�N���ꂽ�ꏊ
    int click_pos_y;             // �N���b�N���ꂽ�ꏊ
    int mouse_x;
    int mouse_y;
public:
    HomeState(GameData*);        // �R���X�g���N�^
    ~HomeState();                // �f�X�g���N�^
    void init();                 // ������
    void update();               // �X�V
    void updateMousePos(int, int);  // �}�E�X�ʒu�X�V
    void clickPosUpdate(int, int);  // �N���b�N���W�擾      
    void clickFirst(int, int);      // �ŏ��̃N���b�N
    int clickEnd(int, int);         // �N���b�N���ꂽ���̂�Ԃ�
    // �N���b�N�̏ꏊ��
    bool isPosButtonStory();
    bool isPosButtonStory(int, int);
    bool isPosButtonBattle();
    bool isPosButtonBattle(int, int);
    bool isPosButtonDeck();
    bool isPosButtonDeck(int, int);
    bool isPosButtonShop();
    bool isPosButtonShop(int, int);
    bool isPosButtonSave();
    bool isPosButtonSave(int, int);
    bool isPosButtonSetting();
    bool isPosButtonSetting(int, int);
    // �摜��Ԏ擾
    int getImageButtonStory();
    int getImageButtonBattle();
    int getImageButtonDeck();
    int getImageButtonShop();
    int getImageButtonSave();
    int getImageButtonSetting();
    bool isClickNow();           // �N���b�N����
};