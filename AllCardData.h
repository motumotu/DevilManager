//-----------------------------------------------------------
// AllCardData.h
// �S�J�[�h�f�[�^
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "CardData.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

class AllCardData {
private:
    CardData card[100];
public:
    AllCardData();                 // �R���X�g���N�^
    ~AllCardData();                // �f�X�g���N�^
    void init();                   // ������
    void update();                 // �X�V
    bool readCardData();           // �J�[�h�f�[�^�ǂݍ���

    CardData *getCardData(int);    // �J�[�h�f�[�^�擾
};