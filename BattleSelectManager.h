//-----------------------------------------------------------
// BattleSelectManager.h
// 対戦選択画面の制御
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"

class BattleSelectManager {
private:
    GameData *game_data;         // ゲームデータ
    GameState *game_state;       // ゲームの状態
    InputState *input_state;     // 入力状態
    BattleSelectState *battle_select_state; // 対戦選択画面の状態
    bool scroll_flag;            // スクロールするか
public:
    BattleSelectManager(GameData*, GameState*); // コンストラクタ
    ~BattleSelectManager();      // デストラクタ
    void init();                 // 初期化
    void update();               // 更新

    void leftClickFirst();       // 左クリック最初
    void leftClickNow();         // 左クリック中
    void leftClickEnd();         // 左クリック終了時
};