//-----------------------------------------------------------
// AllBattleData.h
// �S�ΐ푊��f�[�^
// ����� 2015.03.01
// ����� motumotu
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
    int battle_data_num;           // �o�g���f�[�^��
    BattleData *battle_data[100];  // �o�g���f�[�^

public:
    AllBattleData();           // �R���X�g���N�^
    ~AllBattleData();          // �f�X�g���N�^
    void loadBattleData();     // �o�g���f�[�^�ǂݍ���

    int getBattleDataNum();
    BattleData *getBattleData(int); // �o�g���f�[�^�擾
};