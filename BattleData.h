//-----------------------------------------------------------
// BattleData.h
// 対戦相手データ
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "DeckData.h"
#include <string>

class BattleData {
private:
    int id;          
    std::string name;       // 名前
    int rank;               // ランク
    int map_num;            // 使用マップ番号
    DeckData *deck_data;    // デッキデータ
public:
    BattleData();           // コンストラクタ
    ~BattleData();          // デストラクタ

    //---- setter
    void setId(int);
    void setName(std::string);
    void setRank(int);
    void setMapNum(int);
    //---- getter
    int getId();            // ID取得
    std::string getName();  // 名前取得
    int getRank();          // ランク取得
    int getMapNum();        // マップ番号取得
    DeckData *getDeckData();// デッキデータ取得
};