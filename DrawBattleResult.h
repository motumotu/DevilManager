//-----------------------------------------------------------
// DrawBattleResult.h
// 対戦結果画面描画
// 制作日 2015.03.15
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"

class DrawBattleResult {
private:
    GameData *game_data;         // ゲームデータ
    GameState *game_state;       // ゲームの状態
    int handl;
public:
    DrawBattleResult(GameData*, GameState*); // コンストラクタ
    ~DrawBattleResult();         // デストラクタ
    void init();                 // 初期化
    void update();               // 更新
    void loadImage();           // 画像読み込み
    void draw();                 // 描画
};