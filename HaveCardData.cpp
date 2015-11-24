//-----------------------------------------------------------
// HaveCardData.h
// �����J�[�h�f�[�^
// ����� 2015.03.18
// ����� motumotu
//-----------------------------------------------------------
#include "HaveCardData.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
HaveCardData::HaveCardData()
{
    all_card_num = 0;
    for (int i = 0; i < 1000; i++) {
        card_num[i] = 0;
        hand_card[i] = 0;
    }
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
HaveCardData::~HaveCardData()
{

}

//-----------------------------------------------------------
// �J�[�h�ǉ�
//-----------------------------------------------------------
void HaveCardData::addCard(int n)
{
    card_num[n]++;
    hand_card[all_card_num] = n;
    all_card_num++;
}

//-----------------------------------------------------------
// �J�[�h�擾
//-----------------------------------------------------------
std::vector<int> HaveCardData::getCard()
{
    std::vector<int> vc;
    for (int i = 0; i < all_card_num; i++) {
        vc.push_back(hand_card[i]);
    }
    return vc;
}
int HaveCardData::getCard(int n) {
    return hand_card[n];
}
//-----------------------------------------------------------
// �J�[�h����
//-----------------------------------------------------------
int HaveCardData::getCardNum(int n)
{
    return card_num[n];
}

//-----------------------------------------------------------
// n�Ԗڂ̃J�[�h���폜
//-----------------------------------------------------------
void HaveCardData::deletePosCard(int n)
{
    card_num[hand_card[n]]--;
    for (int i = n; i < all_card_num; i++) {
        hand_card[i] = hand_card[i + 1];
    }
    all_card_num--;
    hand_card[all_card_num] = 0;
}

//-----------------------------------------------------------
// n�ԖڂɃJ�[�h��ǉ�
//-----------------------------------------------------------
void HaveCardData::addPosCard(int n, int card)
{
    for (int i = all_card_num; i > n; i--) {
        hand_card[i] = hand_card[i - 1];
    }
    hand_card[n] = card;
    all_card_num++;
}


//-----------------------------------------------------------
// getter
//-----------------------------------------------------------
int HaveCardData::getAllCardNum() { return all_card_num; }