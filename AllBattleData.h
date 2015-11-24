//-----------------------------------------------------------
// AllBattleData.h
// 全対戦相手データ
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "BattleData.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

class AllBattleData {
private:
    int battle_data_num;           // バトルデータ数
    BattleData *battle_data[100];  // バトルデータ

public:
    AllBattleData();           // コンストラクタ
    ~AllBattleData();          // デストラクタ
    void loadBattleData();     // バトルデータ読み込み

    int getBattleDataNum();
    BattleData *getBattleData(int); // バトルデータ取得
};