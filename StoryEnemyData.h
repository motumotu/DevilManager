//-----------------------------------------------------------
// StoryEnemyData.h
// �X�g�[���[�̑ΐ푊��f�[�^
// ����� 2015.03.22
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include <string>
#include "DeckData.h"

class StoryEnemyData {
private:
    int num;                  // �ԍ�
    std::string name;         // ���O
    int rank;                 // �����N
    int map_num;              // �}�b�v�ԍ�
    DeckData *deck_data;      // �f�b�L�f�[�^
public:
    StoryEnemyData();         // �R���X�g���N�^
    ~StoryEnemyData();        // �f�X�g���N�^

    //---- setter
    void setNum(int);           // �ԍ��ݒ�
    void setName(std::string);  // ���O�ݒ�
    void setRank(int);          // �����N�ݒ�
    void setMapNum(int);        // �ԍ��ݒ�

    //---- getter
    int getNum();               // �ԍ��擾
    std::string getName();      // ���O�擾
    int getRank();              // �����N�擾
    int getMapNum();            // �}�b�v�ԍ��擾
    DeckData *getDeckData();    // �f�b�L�f�[�^�擾
};