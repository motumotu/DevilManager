//-----------------------------------------------------------
// ImageData.h
// 画像データ
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "DxLib.h"

class ImageData {
public:
    static const int MINICARD_SIZE_X = 33;
    static const int MINICARD_SIZE_Y = 46;
    static const int CARD_SIZE_X = 60;
    static const int CARD_SIZE_Y = 85;
private:
    int handl_card[100];        // 普通のカード
    int handl_card_mini[100];   // 小さいカード
    int handl_monster[100][52]; // モンスター
public:
    ImageData();                // コンストラクタ
    ~ImageData();               // デストラクタ

    int getCard(int);           // 普通のカード
    int getCardMini(int);       // 小さいカード
    int getMonster(int, int);   // モンスター
};