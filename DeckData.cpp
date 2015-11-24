//-----------------------------------------------------------
// DeckData.h
// �f�b�L�f�[�^
// ����� 2015.03.18
// ����� motumotu
//-----------------------------------------------------------
#include "DeckData.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
DeckData::DeckData()
{
    card_num = 0;
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
DeckData::~DeckData()
{

}

//-----------------------------------------------------------
// �J�[�h�ǉ�
//-----------------------------------------------------------
void DeckData::addCard(int n)
{
    card[card_num] = n;
    card_num++;
}

//-----------------------------------------------------------
// n�Ԗڂ̃J�[�h���폜
//-----------------------------------------------------------
void DeckData::deletePosCard(int n)
{
    for (int i = n; i < card_num; i++) {
        card[i] = card[i + 1];
    }
    card_num--;
    card[card_num] = 0;
}

//-----------------------------------------------------------
// n�ԖڂɃJ�[�h��}��
//-----------------------------------------------------------
void DeckData::addPosCard(int n, int c)
{
    for (int i = card_num; i > n; i--) {
        card[i] = card[i - 1];
    }
    card[n] = c;
    card_num++;
}

//===========================================================
// getter
//===========================================================
int DeckData::getCard(int n) {
    if (n < 0 || n >= card_num) {
        puts("�͈͊O�Q�� DeckData::getCard(int)");
        return 0;
    }
    return card[n];
}
void DeckData::setDeckName(std::string name) { deck_name = name; }
int DeckData::getCardNum() { return card_num; }
std::string DeckData::getDeckName() { return deck_name; }