//-----------------------------------------------------------
// DeckData.h
// デッキデータ
// 制作日 2015.03.18
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include <string>

class DeckData {
public:
    static const int DECK_CARD_MAX = 100;  // デッキのカード枚数最大
    static const int DECK_CARD_MIN = 50;   // デッキのカード枚数最小
private:
    std::string deck_name;  // デッキ名
    int card_num;           // カード枚数
    int card[100];          // カード
public:
    DeckData();             // コンストラクタ
    ~DeckData();            // デストラクタ
    void addCard(int);      // カード追加
    void deletePosCard(int);   // n番目のカードを削除
    void addPosCard(int, int); // n番目にカードを挿入
    //---- getter/setter
    int getCard(int);       // カード取得
    void setDeckName(std::string);  // 名前設定
    int getCardNum();          // カード枚数取得
    std::string getDeckName(); // デッキ名取得
};