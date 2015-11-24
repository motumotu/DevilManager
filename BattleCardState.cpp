//-----------------------------------------------------------
// BattleCardState.h
// 対戦カードの状態
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#include "BattleCardState.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
BattleCardState::BattleCardState()
{
    srand((unsigned)time(NULL));
    init();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
BattleCardState::~BattleCardState()
{

}

//-----------------------------------------------------------
// 初期化
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
// 対戦情報初期化
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
// 更新
//-----------------------------------------------------------
void BattleCardState::update()
{

}
//-----------------------------------------------------------
// 対戦設定
//-----------------------------------------------------------
void BattleCardState::battleSetting()
{
    // カードシャッフル
    cardShuffleMy();
    cardShuffleEn();

    // カードドロー
    for (int i = 0; i < HAND_MAX; i++) {
        drawCardMy();
        drawCardEn();
    }
}

//-----------------------------------------------------------
// 手札のカード選択
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
// 手札のカード使用
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
// 手札のカード追加
//-----------------------------------------------------------
void BattleCardState::addHandCardMy(int n)
{
    if (my_hand_num < HAND_MAX) {
        my_hand[my_hand_num] = n;
        my_hand_num++;
    }
}

//-----------------------------------------------------------
// 手札のカード追加
//-----------------------------------------------------------
void BattleCardState::addHandCardEn(int n)
{
    if (en_hand_num < HAND_MAX) {
        en_hand[en_hand_num] = n;
        en_hand_num++;
    }
}

//-----------------------------------------------------------
// カードを一枚ドロー
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
// カードを一枚ドロー
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
// 自分のデッキをシャッフル
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
// 相手のデッキをシャッフル
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
// カードをセット
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
        puts("範囲外参照 BattleCardState::getMyHand");
        return -1;
    }
    return my_hand[n];
}
int BattleCardState::getEnHand(int n) {
    if (n < 0 || n >= en_hand_num) {
        puts("範囲外参照 BattleCardState::getEnHand");
        return -1;
    }
    return en_hand[n];
}
int BattleCardState::getMyDeckNum() { return my_deck_num; }
int BattleCardState::getEnDeckNum() { return en_deck_num; }
int BattleCardState::getMyDeck(int n) {
    if (n < 0 || n >= my_deck_num) {
        puts("範囲外参照 BattleCardState::getMyDeck");
        return -1;
    }
    return my_deck[n];
}
int BattleCardState::getEnDeck(int n) {
    if (n < 0 || n >= en_deck_num) {
        puts("範囲外参照 BattleCardState::getEnDeck");
        return -1;
    }
    return en_deck[n];
}
int BattleCardState::getSelectCard() { return select_card_my; }