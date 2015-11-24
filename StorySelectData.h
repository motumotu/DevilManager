//-----------------------------------------------------------
// StorySelectData.h
// ストーリー選択画面のデータ
// 制作日 2015.03.22
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
class StorySelectData {
public:
    //---- UI
    // もどるボタン
    static const int BUTTON_BACK_SIZE_X = 90;
    static const int BUTTON_BACK_SIZE_Y = 40;
    static const int BUTTON_BACK_POS_X = 0;
    static const int BUTTON_BACK_POS_Y = 0;
    // 決定ボタン
    static const int BUTTON_DECISION_SIZE_X = 253;
    static const int BUTTON_DECISION_SIZE_Y = 70;
    static const int BUTTON_DECISION_POS_X = 537;
    static const int BUTTON_DECISION_POS_Y = 476;
    // 自分デッキエリア
    static const int DECK_AREA_POS_X = 537;
    static const int DECK_AREA_POS_Y = 344;
    static const int DECK_AREA_SIZE_X = 253;
    static const int DECK_AREA_SIZE_Y = 70;
    // デッキ選択ボタン
    static const int DECK_SELECT_SIZE_X = 22;
    static const int DECK_SELECT_SIZE_Y = 41;
    // デッキ選択左
    static const int DECK_SELECT_LEFT_POS_X = 557;
    static const int DECK_SELECT_LEFT_POS_Y = 417;
    // デッキ選択右
    static const int DECK_SELECT_RIGHT_POS_X = 748;
    static const int DECK_SELECT_RIGHT_POS_Y = 417;
    // ストーリー選択
    static const int STORY_SIZE_X = 150;
    static const int STORY_SIZE_Y = 100;
    static const int STORY_AREA_POS_X = 30;
    static const int STORY_AREA_POS_Y = 140;
    static const int STORY_AREA_SIZE_X = 509;
    static const int STORY_AREA_SIZE_Y = 438;
    // ストーリー情報
    static const int STORY_INFO_AREA_POS_X = 537;
    static const int STORY_INFO_AREA_POS_Y = 47;

    //---- ストーリー関係
    static const int CHAPTER_NUM = 1;   // チャプター数
    static const int STORY_NUM_1 = 9;   // チャプター1のストーリー数
    static const int STORY_NUM_2 = 9;   // チャプター2のストーリー数

public:
    StorySelectData();            // コンストラクタ
    ~StorySelectData();           // デストラクタ
};