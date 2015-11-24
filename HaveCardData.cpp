//-----------------------------------------------------------
// HaveCardData.h
// 所持カードデータ
// 制作日 2015.03.18
// 制作者 motumotu
//-----------------------------------------------------------
#include "HaveCardData.h"

//-----------------------------------------------------------
// コンストラクタ
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
// デストラクタ
//-----------------------------------------------------------
HaveCardData::~HaveCardData()
{

}

//-----------------------------------------------------------
// カード追加
//-----------------------------------------------------------
void HaveCardData::addCard(int n)
{
    card_num[n]++;
    hand_card[all_card_num] = n;
    all_card_num++;
}

//-----------------------------------------------------------
// カード取得
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
// カード枚数
//-----------------------------------------------------------
int HaveCardData::getCardNum(int n)
{
    return card_num[n];
}

//-----------------------------------------------------------
// n番目のカードを削除
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
// n番目にカードを追加
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