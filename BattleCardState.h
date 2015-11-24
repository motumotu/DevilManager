//-----------------------------------------------------------
// BattleCardState.h
// �ΐ�J�[�h�̏��
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>

class BattleCardState {
public:
    static const int HAND_MAX = 7;      // ��D�ő喇��
    static const int DECK_MAX = 100;    // �f�b�L�ő喇��
    static const int DECK_MIN = 80;     // �f�b�L�ŏ�����
private:
    int my_hand_num;           // ������D����
    int en_hand_num;           // �����D����
    int my_hand[HAND_MAX];     // ������D���
    int en_hand[HAND_MAX];     // �G��D���
    int my_deck_num;           // �����R�D����
    int en_deck_num;           // ����R�D����
    int my_deck[DECK_MAX];     // �����R�D���
    int en_deck[DECK_MAX];     // ����R�D���
    int select_card_my;        // �I�������J�[�h
public:
    BattleCardState();         // �R���X�g���N�^
    ~BattleCardState();        // �f�X�g���N�^
    void init();               // ������
    void battleInit();         // �ΐ��񏉊���
    void update();             // �X�V
    void battleSetting();      // �ΐ�ݒ�
    int selectHandCardMy(int); // ������D�̃J�[�h�I��
    int useHandCardEn(int);    // �����D�̃J�[�h�I��
    void addHandCardMy(int);   // ��D�ɃJ�[�h�ǉ�
    void addHandCardEn(int);   // ��D�ɃJ�[�h�ǉ�
    void drawCardMy();         // �J�[�h���ꖇ�h���[
    void drawCardEn();         // �J�[�h���ꖇ�h���[
    void cardShuffleMy();      // �����f�b�L�V���b�t��
    void cardShuffleEn();      // ����f�b�L�V���b�t��
    void setMyDeck(DeckData*); // �f�b�L���Z�b�g
    void setEnDeck(DeckData*); // �f�b�L���Z�b�g

    // getter
    int getMyHandNum();        // ������D�����擾
    int getEnHandNum();        // �����D�����擾
    int getMyHand(int);        // ������D���擾
    int getEnHand(int);        // �G��D���擾
    int getMyDeckNum();        // �����R�D�����擾
    int getEnDeckNum();        // ����R�D�����擾
    int getMyDeck(int);        // �����R�D���擾
    int getEnDeck(int);        // ����R�D���擾
    int getSelectCard();       // �I�������J�[�h�擾
};