//-----------------------------------------------------------
// StoryEnemyData.h
// ストーリーの対戦相手データ
// 制作日 2015.03.22
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include <string>
#include "DeckData.h"

class StoryEnemyData {
private:
    int num;                  // 番号
    std::string name;         // 名前
    int rank;                 // ランク
    int map_num;              // マップ番号
    DeckData *deck_data;      // デッキデータ
public:
    StoryEnemyData();         // コンストラクタ
    ~StoryEnemyData();        // デストラクタ

    //---- setter
    void setNum(int);           // 番号設定
    void setName(std::string);  // 名前設定
    void setRank(int);          // ランク設定
    void setMapNum(int);        // 番号設定

    //---- getter
    int getNum();               // 番号取得
    std::string getName();      // 名前取得
    int getRank();              // ランク取得
    int getMapNum();            // マップ番号取得
    DeckData *getDeckData();    // デッキデータ取得
};