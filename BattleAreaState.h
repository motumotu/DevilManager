//-----------------------------------------------------------
// BattleAreaState.h
// �̈���
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "MapData.h"
#include <cstdio>

class BattleAreaState {
public:
    static const int AREA_NONE = 0;      // �����G���A
    static const int AREA_MY = 1;        // ���R�G���A
    static const int AREA_ENE = 2;       // �G�R�G���A
    static const int AREA_MP_MAX = 99;   // �ő�G���A����
    static const int AREA_MP_MIN = 0;    // �ŏ��G���A����
private:
    MapData *map_data;
    int area_who[MapData::MAP_SIZE_MAX][MapData::MAP_SIZE_MAX];   // �ǂ����̗̈悩
    int area_mp_my[MapData::MAP_SIZE_MAX][MapData::MAP_SIZE_MAX]; // ���R���͕ۗL��
    int area_mp_en[MapData::MAP_SIZE_MAX][MapData::MAP_SIZE_MAX]; // �G�R���͕ۗL��
public:
    BattleAreaState();     // �R���X�g���N�^
    ~BattleAreaState();    // �f�X�g���N�^
    void init();           // ��������
    void battleInit();     // �ΐ��񏉊���
    void update();         // �X�V����
    void addAreaMpMy(int, int, int);       // ���R�̈斂�͑���
    void addAreaMpMy(int, int, int, int);  // ���R�̈斂�͑���
    void addAreaMpEn(int, int, int);       // �G�R�̈斂�͑���
    void addAreaMpEn(int, int, int, int);  // �G�R�̈斂�͑���
    void subAreaMpMy(int, int, int);       // ���R�̈斂�͌���
    void subAreaMpEn(int, int, int);       // �G�R�̈斂�͌���

    void discriminationArea();             // �̈攻��
    void setMapData(MapData*);             // �}�b�v�f�[�^�ݒ�

    int getAreaWho(int, int);   // �ǂ���̃G���A���擾
    int getAreaMpMy(int, int);  // ���R�G���A���͏��擾
    int getAreaMpEn(int, int);  // �G�R�G���A���͏��擾
};