//-----------------------------------------------------------
// AllStoryEnemyData.h
// ストーリーの対戦相手全データ
// 制作日 2015.03.22
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "DxLib.h"
#include "StoryEnemyData.h"

class AllStoryEnemyData {
private:
    StoryEnemyData *story_enemy_data[100];   // ストーリーの対戦相手データ
    int story_enemy_data_num;                // 総数
public:
    AllStoryEnemyData();         // コンストラクタ
    ~AllStoryEnemyData();        // デストラクタ
    void loadStoryEnemyData();   // データ読み込み

    //---- getter
    StoryEnemyData *getStoryEnemyData(int); // 取得
    int getStoryEnemyDataNum();   // 総数取得
};