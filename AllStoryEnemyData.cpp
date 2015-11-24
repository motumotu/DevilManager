//-----------------------------------------------------------
// AllStoryEnemyData.cpp
// ストーリーの対戦相手全データ
// 制作日 2015.03.22
// 制作者 motumotu
//-----------------------------------------------------------
#include "AllStoryEnemyData.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
AllStoryEnemyData::AllStoryEnemyData()
{
    story_enemy_data_num = 0;
    loadStoryEnemyData();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
AllStoryEnemyData::~AllStoryEnemyData()
{
    for (int i = 1; i <= story_enemy_data_num; i++) {
        delete(story_enemy_data[i]);
    }
}

//-----------------------------------------------------------
// データ読み込み
//-----------------------------------------------------------
void AllStoryEnemyData::loadStoryEnemyData()
{
    char str[1024];
    int num;
    int fp = FileRead_open("dat/story_data.dat");
    if (fp == 0) {
        puts("story_data.datファイル読み込み失敗");
        return;
    }
    for (story_enemy_data_num = 0; FileRead_scanf(fp, "%d", &num) != -1; story_enemy_data_num++) {
        story_enemy_data[num] = new StoryEnemyData();
        // 番号
        story_enemy_data[num]->setNum(num);
        // ストーリータイトル
        FileRead_scanf(fp, "%s", str);
        story_enemy_data[num]->setName(str);
        // ランク
        int rank;
        FileRead_scanf(fp, "%d", &rank);
        story_enemy_data[num]->setRank(rank);
        // マップ番号
        int map;
        FileRead_scanf(fp, "%d", &map);
        story_enemy_data[num]->setMapNum(map);
        // デッキ名
        FileRead_scanf(fp, "%s", str);
        story_enemy_data[num]->getDeckData()->setDeckName(str);
        // デッキ枚数
        int deck_num;
        FileRead_scanf(fp, "%d", &deck_num);
        // 各カード
        for (int i = 0; i < deck_num; i++) {
            int card;
            FileRead_scanf(fp, "%d", &card);
            story_enemy_data[num]->getDeckData()->addCard(card);
        }
    }

    FileRead_close(fp);
}

//-----------------------------------------------------------
// getter
//-----------------------------------------------------------
StoryEnemyData *AllStoryEnemyData::getStoryEnemyData(int n) { return story_enemy_data[n]; }
int AllStoryEnemyData::getStoryEnemyDataNum() { return story_enemy_data_num; }