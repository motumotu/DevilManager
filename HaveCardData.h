//-----------------------------------------------------------
// HaveCardData.h
// �����J�[�h�f�[�^
// ����� 2015.03.18
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include <vector>

class HaveCardData {
private:
    int all_card_num;           // �S�J�[�h����
    int card_num[1000];         // �eid�̃J�[�h����
    int hand_card[1000];        // �����J�[�h
public:
    HaveCardData();             // �R���X�g���N�^
    ~HaveCardData();            // �f�X�g���N�^
    void addCard(int);          // �J�[�h�ǉ�
    std::vector<int> getCard(); // �J�[�h�擾
    int getCard(int);           // �J�[�h�擾
    int getCardNum(int);        // �J�[�h�����擾
    void deletePosCard(int);    // n�Ԗڂ̃J�[�h���폜
    void addPosCard(int, int);  // n�ԖڂɃJ�[�h��ǉ�
    int getAllCardNum();        // �J�[�h�����擾
};