//-----------------------------------------------------------
// BattleResultState.h
// 対戦結果画面の状態
// 制作日 2015.03.15
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"

class BattleResultState {
private:
public:
    BattleResultState(GameData*); // コンストラクタ
    ~BattleResultState();         // デストラクタ
    void init();                  // 初期化
    void update();                // 更新
};