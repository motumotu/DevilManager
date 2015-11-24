//-----------------------------------------------------------
// DeckListData.h
// デッキ一覧画面のデータ
// 制作日 2015.03.18
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
class DeckListData {
public:
    // UI
    // もどるボタン
    static const int BUTTON_BACK_SIZE_X = 90;
    static const int BUTTON_BACK_SIZE_Y = 40;
    static const int BUTTON_BACK_POS_X = 0;
    static const int BUTTON_BACK_POS_Y = 0;
    // デッキ編集ボタン
    static const int BUTTON_EDIT_SIZE_X = 107;
    static const int BUTTON_EDIT_SIZE_Y = 31;
    static const int BUTTON_EDIT_POS_X = 550;
    static const int BUTTON_EDIT_POS_Y = 35;
    // デッキ削除ボタン
    static const int BUTTON_DELETE_SIZE_X = 107;
    static const int BUTTON_DELETE_SIZE_Y = 31;
    static const int BUTTON_DELETE_POS_X = 663;
    static const int BUTTON_DELETE_POS_Y = 35;
    // デッキ一覧ボタン
    static const int BUTTON_DECK_SIZE_X = 253;
    static const int BUTTON_DECK_SIZE_Y = 70;
    static const int BUTTON_DECK_POS_X = 26;
    static const int BUTTON_DECK_POS_Y = 70;
    // デッキ名入力ボックス
    static const int INPUT_BOX_SIZE_X = 211;
    static const int INPUT_BOX_SIZE_Y = 31;
    static const int INPUT_BOX_POS_X = 332;
    static const int INPUT_BOX_POS_Y = 35;
    // スクロールバー上
    static const int BAR_UP_SIZE_X = 21;
    static const int BAR_UP_SIZE_Y = 32;
    static const int BAR_UP_POS_X = 283;
    static const int BAR_UP_POS_Y = 73;
    // スクロールバー下
    static const int BAR_DOWN_SIZE_X = 21;
    static const int BAR_DOWN_SIZE_Y = 32;
    static const int BAR_DOWN_POS_X = 283;
    static const int BAR_DOWN_POS_Y = 529;
    // スクロールバー
    static const int BAR_SIZE_X = 21;
    static const int BAR_SIZE_Y = 70;
    static const int BAR_POS_X = 283;
    static const int BAR_POS_Y = 105;
    // スクロールバーエリア
    static const int BAR_AREA_SIZE = 354;
    // デッキカード一覧
    static const int CARD_AREA_POS_X = 345;
    static const int CARD_AREA_POS_Y = 88;
public:
    DeckListData();                        // コンストラクタ
    ~DeckListData();                       // デストラクタ
};