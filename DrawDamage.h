//-----------------------------------------------------------
// DrawDamage.h
// ダメージの描画
// 制作日 2015.03.04
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "DxLib.h"
#include "GameData.h"
#include "BattleState.h"

class DrawDamage {
private:
    GameData* game_data;
    BattleState* battle_state;
    int color_white;    // 白
    int color_red;      // 赤
    int font;           // フォント
public:
    DrawDamage(GameData*, BattleState*);// コンストラクタ
    ~DrawDamage();      // デストラクタ
    void init();        // 初期処理
    void update();      // 更新
    void draw();        // 描画
    void loadImage();   // 画像読み込み
};