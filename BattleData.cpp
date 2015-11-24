//-----------------------------------------------------------
// BattleData.cpp
// 対戦相手データ
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#include "BattleData.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
BattleData::BattleData()
{
    deck_data = new DeckData();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
BattleData::~BattleData()
{
    delete(deck_data);
}

//===========================================================
// setter
//===========================================================
void BattleData::setId(int n) { id = n; }
void BattleData::setName(std::string n) { name = n; }
void BattleData::setRank(int n) { rank = n; }
void BattleData::setMapNum(int n) { map_num = n; }

//===========================================================
// getter
//===========================================================
int BattleData::getId() { return id; }
std::string BattleData::getName() { return name; }
int BattleData::getRank() { return rank; }
int BattleData::getMapNum() { return map_num; }
DeckData *BattleData::getDeckData() { return deck_data; }