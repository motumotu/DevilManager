//-----------------------------------------------------------
// BattleSelectData.h
// 対戦選択画面のデータ
// 制作日 2015.03.20
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once

class BattleSelectData {
public:
    //---- UI
    // 戻るボタン
    static const int BUTTON_BACK_SIZE_X = 90;
    static const int BUTTON_BACK_SIZE_Y = 40;
    static const int BUTTON_BACK_POS_X = 0;
    static const int BUTTON_BACK_POS_Y = 0;
    // 対戦開始ボタン
    static const int BUTTON_BATTLE_SIZE_X = 146;
    static const int BUTTON_BATTLE_SIZE_Y = 56;
    static const int BUTTON_BATTLE_POS_X = 625;
    static const int BUTTON_BATTLE_POS_Y = 520;
    // 対戦相手選択
    static const int SELECT_AREA_POS_X = 29;
    static const int SELECT_AREA_POS_Y = 80;
    static const int SELECT_AREA_SIZE_X = 289;
    static const int SELECT_AREA_SIZE_Y = 465;
    static const int SELECT_SIZE_X = 279;
    static const int SELECT_SIZE_Y = 63;
    // 対戦相手情報エリア
    static const int ENEMY_INFO_POS_X = 425;
    static const int ENEMY_INFO_POS_Y = 70;
    // 自分デッキ情報
    static const int MY_INFO_POS_X = 425;
    static const int MY_INFO_POS_Y = 354;
    // デッキ選択
    static const int DECK_SELECT_LEFT_POS_X = 440;
    static const int DECK_SELECT_LEFT_POS_Y = 465;
    static const int DECK_SELECT_RIGHT_POS_X = 640;
    static const int DECK_SELECT_RIGHT_POS_Y = 465;
    static const int DECK_SELECT_SIZE_X = 11;
    static const int DECK_SELECT_SIZE_Y = 19;
    // スクロールバー
    static const int BAR_POS_X = 328;
    static const int BAR_POS_Y = 80;
    static const int BAR_SIZE_X = 11;
    static const int BAR_SIZE_Y = 56;
    static const int BAR_AREA_SIZE_X = 11;
    static const int BAR_AREA_SIZE_Y = 465;
private:
public:
    BattleSelectData();             // コンストラクタ
    ~BattleSelectData();            // デストラクタ
};