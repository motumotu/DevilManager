//-----------------------------------------------------------
// HaveCardData.h
// 所持カードデータ
// 制作日 2015.03.18
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include <vector>

class HaveCardData {
private:
    int all_card_num;           // 全カード枚数
    int card_num[1000];         // 各idのカード枚数
    int hand_card[1000];        // 所持カード
public:
    HaveCardData();             // コンストラクタ
    ~HaveCardData();            // デストラクタ
    void addCard(int);          // カード追加
    std::vector<int> getCard(); // カード取得
    int getCard(int);           // カード取得
    int getCardNum(int);        // カード枚数取得
    void deletePosCard(int);    // n番目のカードを削除
    void addPosCard(int, int);  // n番目にカードを追加
    int getAllCardNum();        // カード枚数取得
};