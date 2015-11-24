//-----------------------------------------------------------
// AllMapData.h
// �S�}�b�v�f�[�^
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "MapData.h"
#include <fstream>
#include <iostream>
#include <sstream>

class AllMapData {
public:
    static const int MAP_NUM = 2;    // �}�b�v�f�[�^��
private:
    MapData map_data[MAP_NUM + 1];   // �}�b�v�f�[�^
    bool loadAllMapData();           // �S�}�b�v�f�[�^�ǂݍ���
    bool loadMapData(int);           // �}�b�v�f�[�^�̓ǂݍ���
public:
    AllMapData();                    // �R���X�g���N�^
    ~AllMapData();                   // �f�X�g���N�^

    MapData *getMapData(int);        // �}�b�v�f�[�^�擾
};