//-----------------------------------------------------------
// DeckEditManager.h
// デッキ編集画面の制御
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"

class DeckEditManager {
private:
    GameData *game_data;            // ゲームデータ
    GameState *game_state;          // ゲームの状態
    DeckEditState *deck_edit_state; // デッキ編集画面の状態
    InputState *input_state;        // 入力状態
    SaveData *save_data;            // セーブデータ
public:
    DeckEditManager(GameData*, GameState*); // コンストラクタ
    ~DeckEditManager();          // デストラクタ
    void init();                 // 初期化
    void update();               // 更新
    void leftClickFirst();       // 左クリックがされた瞬間
    void leftClickNow();         // 左クリック中
    void leftClickEnd();         // 左クリックの終わり
    void mouseWheel();           // マウスホイール
};