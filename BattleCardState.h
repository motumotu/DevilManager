//-----------------------------------------------------------
// BattleCardState.h
// 対戦カードの状態
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>

class BattleCardState {
public:
    static const int HAND_MAX = 7;      // 手札最大枚数
    static const int DECK_MAX = 100;    // デッキ最大枚数
    static const int DECK_MIN = 80;     // デッキ最小枚数
private:
    int my_hand_num;           // 自分手札枚数
    int en_hand_num;           // 相手手札枚数
    int my_hand[HAND_MAX];     // 自分手札情報
    int en_hand[HAND_MAX];     // 敵手札情報
    int my_deck_num;           // 自分山札枚数
    int en_deck_num;           // 相手山札枚数
    int my_deck[DECK_MAX];     // 自分山札情報
    int en_deck[DECK_MAX];     // 相手山札情報
    int select_card_my;        // 選択したカード
public:
    BattleCardState();         // コンストラクタ
    ~BattleCardState();        // デストラクタ
    void init();               // 初期化
    void battleInit();         // 対戦情報初期化
    void update();             // 更新
    void battleSetting();      // 対戦設定
    int selectHandCardMy(int); // 自分手札のカード選択
    int useHandCardEn(int);    // 相手手札のカード選択
    void addHandCardMy(int);   // 手札にカード追加
    void addHandCardEn(int);   // 手札にカード追加
    void drawCardMy();         // カードを一枚ドロー
    void drawCardEn();         // カードを一枚ドロー
    void cardShuffleMy();      // 自分デッキシャッフル
    void cardShuffleEn();      // 相手デッキシャッフル
    void setMyDeck(DeckData*); // デッキをセット
    void setEnDeck(DeckData*); // デッキをセット

    // getter
    int getMyHandNum();        // 自分手札枚数取得
    int getEnHandNum();        // 相手手札枚数取得
    int getMyHand(int);        // 自分手札情報取得
    int getEnHand(int);        // 敵手札情報取得
    int getMyDeckNum();        // 自分山札枚数取得
    int getEnDeckNum();        // 相手山札枚数取得
    int getMyDeck(int);        // 自分山札情報取得
    int getEnDeck(int);        // 相手山札情報取得
    int getSelectCard();       // 選択したカード取得
};