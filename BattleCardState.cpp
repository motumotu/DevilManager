//-----------------------------------------------------------
// BattleCardState.h
// �ΐ�J�[�h�̏��
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#include "BattleCardState.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
BattleCardState::BattleCardState()
{
    srand((unsigned)time(NULL));
    init();
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
BattleCardState::~BattleCardState()
{

}

//-----------------------------------------------------------
// ������
//-----------------------------------------------------------
void BattleCardState::init()
{
    my_hand_num = 0;
    en_hand_num = 0;
    my_deck_num = 0;
    en_deck_num = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 10; j++) {
            my_deck[my_deck_num++] = 0;
            en_deck[en_deck_num++] = 0;
        }
    }
    select_card_my = -1;
}

//-----------------------------------------------------------
// �ΐ��񏉊���
//-----------------------------------------------------------
void BattleCardState::battleInit()
{
    my_hand_num = 0;
    en_hand_num = 0;
    my_deck_num = 0;
    en_deck_num = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 10; j++) {
            my_deck[my_deck_num++] = 0;
            en_deck[en_deck_num++] = 0;
        }
    }
    select_card_my = -1;
}
//-----------------------------------------------------------
// �X�V
//-----------------------------------------------------------
void BattleCardState::update()
{

}
//-----------------------------------------------------------
// �ΐ�ݒ�
//-----------------------------------------------------------
void BattleCardState::battleSetting()
{
    // �J�[�h�V���b�t��
    cardShuffleMy();
    cardShuffleEn();

    // �J�[�h�h���[
    for (int i = 0; i < HAND_MAX; i++) {
        drawCardMy();
        drawCardEn();
    }
}

//-----------------------------------------------------------
// ��D�̃J�[�h�I��
//-----------------------------------------------------------
int BattleCardState::selectHandCardMy(int n)
{
    select_card_my = my_hand[n];
    for (int i = n; i < my_hand_num - 1; i++) {
        my_hand[i] = my_hand[i + 1];
    }
    my_hand[my_hand_num - 1] = 0;
    my_hand_num--;
    return select_card_my;
}

//-----------------------------------------------------------
// ��D�̃J�[�h�g�p
//-----------------------------------------------------------
int BattleCardState::useHandCardEn(int n)
{
    int card = en_hand[n];
    for (int i = n; i < en_hand_num - 1; i++) {
        en_hand[i] = en_hand[i + 1];
    }
    en_hand[en_hand_num - 1] = 0;
    en_hand_num--;
    return card;
}

//-----------------------------------------------------------
// ��D�̃J�[�h�ǉ�
//-----------------------------------------------------------
void BattleCardState::addHandCardMy(int n)
{
    if (my_hand_num < HAND_MAX) {
        my_hand[my_hand_num] = n;
        my_hand_num++;
    }
}

//-----------------------------------------------------------
// ��D�̃J�[�h�ǉ�
//-----------------------------------------------------------
void BattleCardState::addHandCardEn(int n)
{
    if (en_hand_num < HAND_MAX) {
        en_hand[en_hand_num] = n;
        en_hand_num++;
    }
}

//-----------------------------------------------------------
// �J�[�h���ꖇ�h���[
//-----------------------------------------------------------
void BattleCardState::drawCardMy()
{
    if (my_hand_num >= HAND_MAX) return;
    if (my_deck_num <= 0) return;
    my_deck_num--;
    addHandCardMy(my_deck[my_deck_num]);
    my_deck[my_deck_num] = 0;
}

//-----------------------------------------------------------
// �J�[�h���ꖇ�h���[
//-----------------------------------------------------------
void BattleCardState::drawCardEn()
{
    if (en_hand_num >= HAND_MAX) return;
    if (en_deck_num <= 0) return;
    en_deck_num--;
    addHandCardEn(en_deck[en_deck_num]);
    en_deck[en_deck_num] = 0;
}

//-----------------------------------------------------------
// �����̃f�b�L���V���b�t��
//-----------------------------------------------------------
void BattleCardState::cardShuffleMy()
{
    for (int i = 0; i < 10000; i++) {
        int card1 = rand() % my_deck_num;
        int card2 = rand() % my_deck_num;
        int t = my_deck[card1];
        my_deck[card1] = my_deck[card2];
        my_deck[card2] = t;
    }
}

//-----------------------------------------------------------
// ����̃f�b�L���V���b�t��
//-----------------------------------------------------------
void BattleCardState::cardShuffleEn()
{
    for (int i = 0; i < 10000; i++) {
        int card1 = rand() % en_deck_num;
        int card2 = rand() % en_deck_num;
        int t = en_deck[card1];
        en_deck[card1] = en_deck[card2];
        en_deck[card2] = t;
    }
}

//-----------------------------------------------------------
// �J�[�h���Z�b�g
//-----------------------------------------------------------
void BattleCardState::setMyDeck(DeckData* deck)
{
    my_deck_num = deck->getCardNum();
    for (int i = 0; i < my_deck_num; i++) {
        my_deck[i] = deck->getCard(i);
    }
}
void BattleCardState::setEnDeck(DeckData* deck)
{
    en_deck_num = deck->getCardNum();
    for (int i = 0; i < en_deck_num; i++) {
        en_deck[i] = deck->getCard(i);
    }
}

//===========================================================
// getter
//===========================================================
int BattleCardState::getMyHandNum() { return my_hand_num; }
int BattleCardState::getEnHandNum() { return en_hand_num; }
int BattleCardState::getMyHand(int n) {
    if (n < 0 || n >= my_hand_num) {
        puts("�͈͊O�Q�� BattleCardState::getMyHand");
        return -1;
    }
    return my_hand[n];
}
int BattleCardState::getEnHand(int n) {
    if (n < 0 || n >= en_hand_num) {
        puts("�͈͊O�Q�� BattleCardState::getEnHand");
        return -1;
    }
    return en_hand[n];
}
int BattleCardState::getMyDeckNum() { return my_deck_num; }
int BattleCardState::getEnDeckNum() { return en_deck_num; }
int BattleCardState::getMyDeck(int n) {
    if (n < 0 || n >= my_deck_num) {
        puts("�͈͊O�Q�� BattleCardState::getMyDeck");
        return -1;
    }
    return my_deck[n];
}
int BattleCardState::getEnDeck(int n) {
    if (n < 0 || n >= en_deck_num) {
        puts("�͈͊O�Q�� BattleCardState::getEnDeck");
        return -1;
    }
    return en_deck[n];
}
int BattleCardState::getSelectCard() { return select_card_my; }