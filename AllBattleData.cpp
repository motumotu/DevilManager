//-----------------------------------------------------------
// AllBattleData.cpp
// �S�ΐ푊��f�[�^
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#include "AllBattleData.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
AllBattleData::AllBattleData()
{
    battle_data_num = 0;
    loadBattleData();
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
AllBattleData::~AllBattleData()
{

}

//-----------------------------------------------------------
// �o�g���f�[�^�ǂݍ���
//-----------------------------------------------------------
void AllBattleData::loadBattleData()
{
    //---- �t�@�C�����J��
    std::string str;
    std::ifstream ifs("dat/battle_data.dat");
    if (ifs.fail()) {
        puts("battle_data.dat�̓ǂݍ��݂Ɏ��s���܂����B");
        return;
    }
    puts("battle_data.dat�ǂݍ��ݐ���");
    //---- �J�[�h�f�[�^�ǂݍ���
    while (getline(ifs, str)) {
        battle_data_num++;
        std::stringstream ss(str);
        // ID
        ss >> str;
        int id = atoi(str.c_str());
        battle_data[id] = new BattleData();
        battle_data[id]->setId(id);
        // ���O
        ss >> str;
        battle_data[id]->setName(str);
        // �����N
        ss >> str;
        battle_data[id]->setRank(atoi(str.c_str()));
        // �}�b�v�ԍ�
        ss >> str;
        battle_data[id]->setMapNum(atoi(str.c_str()));
        // �f�b�L��
        ss >> str;
        battle_data[id]->getDeckData()->setDeckName(str);
        // �J�[�h����
        ss >> str;
        int n = atoi(str.c_str());
        for (int i = 0; i < n; i++) {
            ss >> str;
            battle_data[id]->getDeckData()->addCard(atoi(str.c_str()));
        }
    }
}

//===========================================================
// getter
//===========================================================
int AllBattleData::getBattleDataNum() { return battle_data_num; }
BattleData *AllBattleData::getBattleData(int n) { return battle_data[n]; }
