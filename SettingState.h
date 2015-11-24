//-----------------------------------------------------------
// SettingState.h
// セッティング画面の状態
// 制作日 2015.03.25
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"

class SettingState {
public:
private:
    GameData *game_data;       // ゲームデータ
    int pre_scene;             // 前シーン
public:
    SettingState(GameData*);   // コンストラクタ
    ~SettingState();           // デストラクタ
    void init();               // 初期化
    void update();             // 更新
    void setPreScene(int);     // 前シーン設定
    int getPreScene();         // 前シーン取得
};