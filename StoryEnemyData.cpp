//-----------------------------------------------------------
// StoryEnemyData.cpp
// �X�g�[���[�̑ΐ푊��f�[�^
// ����� 2015.03.22
// ����� motumotu
//-----------------------------------------------------------
#include "StoryEnemyData.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
StoryEnemyData::StoryEnemyData()
{
    num = 0;
    name = "";
    rank = 0;
    map_num = 0;
    deck_data = new DeckData();
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
StoryEnemyData::~StoryEnemyData()
{

}

//-----------------------------------------------------------
// setter
//-----------------------------------------------------------
void StoryEnemyData::setNum(int n) { num = n; }
void StoryEnemyData::setName(std::string n) { name = n; }
void StoryEnemyData::setRank(int n) { rank = n; }
void StoryEnemyData::setMapNum(int n) { map_num = n; }
//-----------------------------------------------------------
// getter
//-----------------------------------------------------------
int StoryEnemyData::getNum() { return num; }
std::string StoryEnemyData::getName() { return name; }
int StoryEnemyData::getRank() { return rank; }
int StoryEnemyData::getMapNum() { return map_num; }
DeckData *StoryEnemyData::getDeckData() { return deck_data; }