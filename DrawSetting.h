//-----------------------------------------------------------
// DrawSetting.h
// 設定画面の描画
// 制作日 2015.03.25
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"

class DrawSetting {
public:
private:
    GameData *game_data;        // ゲームデータ
    GameState *game_state;      // ゲームの状態
    SaveData *save_data;        // セーブデータ
    SettingState *setting_state; // 設定画面

    int handl_back;             // 背景
public:
    DrawSetting(GameData*, GameState*); // コンストラクタ
    ~DrawSetting();             // デストラクタ
    void init();                // 初期化
    void update();              // 更新
    void loadImage();           // 画像読み込み
    void draw();                // 描画
};