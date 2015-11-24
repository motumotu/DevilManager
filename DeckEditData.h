//-----------------------------------------------------------
// DeckEditData.h
// デッキ編集画面のデータ
// 制作日 2015.03.19
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
class DeckEditData {
public:
    //---- UI
    // 戻るボタン
    static const int BUTTON_BACK_SIZE_X = 90;
    static const int BUTTON_BACK_SIZE_Y = 40;
    static const int BUTTON_BACK_POS_X = 0;
    static const int BUTTON_BACK_POS_Y = 0;
    // デッキエリアのカード
    static const int DECK_AREA_POS_X = 265;
    static const int DECK_AREA_POS_Y = 116;
    static const int DECK_AREA_SIZE_X = 330;
    static const int DECK_AREA_SIZE_Y = 460;
    static const int DECK_AREA_CARD_NUM_X = 10;
    static const int DECK_AREA_CARD_NUM_Y = 10;
    // カード説明
    static const int CARD_INTRO_AREA_POS_X = 11;
    static const int CARD_INTRO_AREA_POS_Y = 101;
    // カード一覧
    static const int CARD_AREA_POS_X = 614;
    static const int CARD_AREA_POS_Y = 116;
    static const int CARD_AREA_SIZE_X = 164;
    static const int CARD_AREA_SIZE_Y = 460;
    static const int CARD_SIZE_X = 33;
    static const int CARD_SIZE_Y = 46;
    static const int CARD_AREA_CARD_NUM_X = 5;
    // スライドバー
    static const int BAR_AREA_POS_X = 782;
    static const int BAR_AREA_POS_Y = 118;
    static const int BAR_AREA_SIZE_X = 8;
    static const int BAR_AREA_SIZE_Y = 458;
    static const int BAR_SIZE_X = 6;
    static const int BAR_SIZE_Y = 30;
public:
    DeckEditData();                        // コンストラクタ
    ~DeckEditData();                       // デストラクタ
};