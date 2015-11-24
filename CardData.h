//-----------------------------------------------------------
// CardData.h
// �J�[�h�f�[�^
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include <string>
#include <vector>

class CardData {
public:
    //---- �萔
    static const int ATTR_NONE = 0;       // ���� ��
    static const int ATTR_FIRE = 1;       // ���� ��
    static const int ATTR_WATER = 2;      // ���� ��
    static const int ATTR_ICE = 3;        // ���� �X
    static const int ATTR_ELECT = 4;      // ���� �d
    static const int ATTR_DARK = 5;       // ���� ��
    static const int ATTR_LIGHT = 6;      // ���� ��
    static const int ATTR_EARTH = 7;      // ���� �n
    static const int ATTR_POISON = 8;     // ���� ��
    static const int ATTR_WIND = 9;       // ���� ��
    //---- �ϐ�
    int id;                // ID
    std::string name;      // ���O
    int mp;                // �K�v����
    int hp;                // �̗�
    int pow;               // �U����
    int def;               // �h���
    int move_speed;        // �ړ����x
    int attack_speed;      // �U�����x
    int attribute;         // �����̑���
    int search_range;      // ���G�͈�
    int image_size_x;      // �摜�T�C�Yx
    int image_size_y;      // �摜�T�C�Yy
    int size_x;            // �傫��x
    int size_y;            // �傫��y
    std::vector<int> skil; // �X�L��
    // �ϐ� ��{�l100
    int fire;              // ��
    int water;             // ��
    int ice;               // �X
    int elect;             // �d
    int dark;              // ��
    int light;             // ��
    int earth;             // �n
    int poison;            // ��
    int wind;              // ��
    //---- ���\�b�h
    CardData();            // �R���X�g���N�^
    ~CardData();           // �f�X�g���N�^
    void init();           // ������
    void update();         // �X�V
};