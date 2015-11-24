//-----------------------------------------------------------
// BattleData.cpp
// �ΐ푊��f�[�^
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#include "BattleData.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
BattleData::BattleData()
{
    deck_data = new DeckData();
}

//-----------------------------------------------------------
// �f�X�g���N�^
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