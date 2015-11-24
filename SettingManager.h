//-----------------------------------------------------------
// SettingManager.h
// 設定画面管理
// 制作日 2015.03.25
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "DxLib.h"
#include "GameData.h"
#include "GameState.h"

class SettingManager {
private:
    GameData *game_data;         // ゲームデータ
    GameState *game_state;       // ゲームの状態
    InputState *input_state;     // 入力状態
    SettingState *setting_state; // 設定画面
public:
    SettingManager(GameData*, GameState*); // コンストラクタ
    ~SettingManager();          // デストラクタ
    void init();                 // 初期化
    void update();               // 更新
    void leftClickFirst();       // 左クリックされた瞬間
    void leftClickNow();         // 左クリックされている間 
    void leftClickEnd();         // 左クリック終了時
};