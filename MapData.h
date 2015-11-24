//-----------------------------------------------------------
// MapData.h
// �}�b�v�f�[�^
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#pragma once

class MapData {
public:
    // �萔
    static const int MAP_WALL = 0;   // ��
    static const int MAP_FLOOR = 1;  // ��
    static const int MAP_SIZE_MAX = 100; // �}�b�v�T�C�Y�ő�
    static const int MAP_IMAGE_SIZE = 50; // �}�b�v�T�C�Y
    // �ϐ�
    int map_size_width;                        // �}�b�v�̕�
    int map_size_height;                       // �}�b�v�̍���
    int map_data[MAP_SIZE_MAX][MAP_SIZE_MAX];  // �}�b�v�f�[�^
    int player_base_x;                         // �����_���Wx
    int player_base_y;                         // �����_���Wy
    int enemy_base_x;                          // �G���_���Wx
    int enemy_base_y;                          // �G���_���Wy
    // ���\�b�h
    MapData();                 // �R���X�g���N�^
    ~MapData();                // �f�X�g���N�^
    void init();               // ������
    bool outCheck(int, int);   // �͈͓��`�F�b�N
    bool isFloor(int, int);    // �����ǂ�������
};