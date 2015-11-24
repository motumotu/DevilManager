//-----------------------------------------------------------
// BattleDamageState.h
// �_���[�W�̏��
// ����� 2015.03.04
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include <algorithm>

class BattleDamageState {
public:
    static const int DISPLAY_TIME = 30;  // �\������
    static const int WHICH_MY = 0;     // ����
    static const int WHICH_ENE = 1;    // ����
private:
    int damage;                // �_���[�W
    int cnt_frame;             // �o�߃t���[��
    int x;                     // x���W
    int y;                     // y���W
    int which;                 // �ǂ������󂯂��_���[�W��
public:
    BattleDamageState(int, int, int, int); // �R���X�g���N�^
    ~BattleDamageState();      // �f�X�g���N�^
    void update();             // �X�V
    bool isDelete();           // ������ׂ���
    int getDamage();           // �_���[�W
    int getCntFrame();         // �o�߃t���[��
    int getX();
    int getY();
    int getWhich();
    int getDamageDigits();      // ����
};