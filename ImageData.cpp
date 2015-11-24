//-----------------------------------------------------------
// ImageData.cpp
// 画像データ
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#include "ImageData.h"


//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
ImageData::ImageData()
{
    //普通のカード
    handl_card[1] = LoadGraph("image/card/card_1.png");
    handl_card[2] = LoadGraph("image/card/card_2.png");
    handl_card[3] = LoadGraph("image/card/card_3.png");
    handl_card[4] = LoadGraph("image/card/card_4.png");
    handl_card[5] = LoadGraph("image/card/card_5.png");
    handl_card[6] = LoadGraph("image/card/card_6.png");
    handl_card[7] = LoadGraph("image/card/card_7.png");
    handl_card[8] = LoadGraph("image/card/card_8.png");
    handl_card[9] = LoadGraph("image/card/card_9.png");
    handl_card[10] = LoadGraph("image/card/card_10.png");
    handl_card[11] = LoadGraph("image/card/card_11.png");
    handl_card[12] = LoadGraph("image/card/card_12.png");
    handl_card[13] = LoadGraph("image/card/card_13.png");
    handl_card[14] = LoadGraph("image/card/card_14.png");
    handl_card[15] = LoadGraph("image/card/card_15.png");
    handl_card[16] = LoadGraph("image/card/card_16.png");
    handl_card[17] = LoadGraph("image/card/card_17.png");
    handl_card[18] = LoadGraph("image/card/card_18.png");
    handl_card[19] = LoadGraph("image/card/card_19.png");
    // 小さいカード
    handl_card_mini[1] = LoadGraph("image/card_mini/minicard_1.png");
    handl_card_mini[2] = LoadGraph("image/card_mini/minicard_2.png");
    handl_card_mini[3] = LoadGraph("image/card_mini/minicard_3.png");
    handl_card_mini[4] = LoadGraph("image/card_mini/minicard_4.png");
    handl_card_mini[5] = LoadGraph("image/card_mini/minicard_5.png");
    handl_card_mini[6] = LoadGraph("image/card_mini/minicard_6.png");
    handl_card_mini[7] = LoadGraph("image/card_mini/minicard_7.png");
    handl_card_mini[8] = LoadGraph("image/card_mini/minicard_8.png");
    handl_card_mini[9] = LoadGraph("image/card_mini/minicard_9.png");
    handl_card_mini[10] = LoadGraph("image/card_mini/minicard_10.png");
    handl_card_mini[11] = LoadGraph("image/card_mini/minicard_11.png");
    handl_card_mini[12] = LoadGraph("image/card_mini/minicard_12.png");
    handl_card_mini[13] = LoadGraph("image/card_mini/minicard_13.png");
    handl_card_mini[14] = LoadGraph("image/card_mini/minicard_14.png");
    handl_card_mini[15] = LoadGraph("image/card_mini/minicard_15.png");
    handl_card_mini[16] = LoadGraph("image/card_mini/minicard_16.png");
    handl_card_mini[17] = LoadGraph("image/card_mini/minicard_17.png");
    handl_card_mini[18] = LoadGraph("image/card_mini/minicard_18.png");
    handl_card_mini[19] = LoadGraph("image/card_mini/minicard_19.png");
    // モンスター
    LoadDivGraph("image/unit/unit_1.png", 52, 4, 13, 50, 50, handl_monster[1]);
    LoadDivGraph("image/unit/unit_2.png", 52, 4, 13, 50, 50, handl_monster[2]);
    LoadDivGraph("image/unit/unit_3.png", 52, 4, 13, 50, 50, handl_monster[3]);
    LoadDivGraph("image/unit/unit_4.png", 52, 4, 13, 50, 50, handl_monster[4]);
    LoadDivGraph("image/unit/unit_5.png", 52, 4, 13, 50, 50, handl_monster[5]);
    LoadDivGraph("image/unit/unit_6.png", 52, 4, 13, 50, 50, handl_monster[6]);
    LoadDivGraph("image/unit/unit_7.png", 52, 4, 13, 50, 50, handl_monster[7]);
    LoadDivGraph("image/unit/unit_8.png", 52, 4, 13, 50, 50, handl_monster[8]);
    LoadDivGraph("image/unit/unit_9.png", 52, 4, 13, 50, 50, handl_monster[9]);
    LoadDivGraph("image/unit/unit_10.png", 52, 4, 13, 100, 100, handl_monster[10]);
    LoadDivGraph("image/unit/unit_11.png", 52, 4, 13, 50, 50, handl_monster[11]);
    LoadDivGraph("image/unit/unit_12.png", 52, 4, 13, 50, 50, handl_monster[12]);
    LoadDivGraph("image/unit/unit_13.png", 52, 4, 13, 50, 50, handl_monster[13]);
    LoadDivGraph("image/unit/unit_14.png", 52, 4, 13, 50, 50, handl_monster[14]);
    LoadDivGraph("image/unit/unit_15.png", 52, 4, 13, 50, 50, handl_monster[15]);
    LoadDivGraph("image/unit/unit_16.png", 52, 4, 13, 50, 50, handl_monster[16]);
    LoadDivGraph("image/unit/unit_17.png", 52, 4, 13, 50, 50, handl_monster[17]);
    LoadDivGraph("image/unit/unit_18.png", 52, 4, 13, 50, 50, handl_monster[18]);
    LoadDivGraph("image/unit/unit_19.png", 52, 4, 13, 50, 50, handl_monster[19]);
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
ImageData::~ImageData()
{
    
}

//-----------------------------------------------------------
// 取得
//-----------------------------------------------------------
int ImageData::getCard(int n) { return handl_card[n]; }
int ImageData::getCardMini(int n) { return handl_card_mini[n]; }
int ImageData::getMonster(int n, int t) { return handl_monster[n][t]; }