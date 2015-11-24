//-----------------------------------------------------------
// DeckListManager.h
// デッキ一覧画面の制御
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "DxLib.h"
#include "GameData.h"
#include "GameState.h"

class DeckListManager {
private:
    GameData *game_data;         // ゲームデータ
    GameState *game_state;       // ゲームの状態
    InputState *input_state;     // 入力状態
    DeckListState *deck_list_state; // 
public:
    DeckListManager(GameData*, GameState*); // コンストラクタ
    ~DeckListManager();          // デストラクタ
    void init();                 // 初期化
    void update();               // 更新
    void leftClickFirst();       // 左クリックされた瞬間
    void leftClickNow();         // 左クリックされている間 
    void leftClickEnd();         // 左クリック終了時
    void mouseWheel();           // マウスホイール
};