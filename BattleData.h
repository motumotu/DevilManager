//-----------------------------------------------------------
// BattleData.h
// �ΐ푊��f�[�^
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "DeckData.h"
#include <string>

class BattleData {
private:
    int id;          
    std::string name;       // ���O
    int rank;               // �����N
    int map_num;            // �g�p�}�b�v�ԍ�
    DeckData *deck_data;    // �f�b�L�f�[�^
public:
    BattleData();           // �R���X�g���N�^
    ~BattleData();          // �f�X�g���N�^

    //---- setter
    void setId(int);
    void setName(std::string);
    void setRank(int);
    void setMapNum(int);
    //---- getter
    int getId();            // ID�擾
    std::string getName();  // ���O�擾
    int getRank();          // �����N�擾
    int getMapNum();        // �}�b�v�ԍ��擾
    DeckData *getDeckData();// �f�b�L�f�[�^�擾
};