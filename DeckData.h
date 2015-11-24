//-----------------------------------------------------------
// DeckData.h
// �f�b�L�f�[�^
// ����� 2015.03.18
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include <string>

class DeckData {
public:
    static const int DECK_CARD_MAX = 100;  // �f�b�L�̃J�[�h�����ő�
    static const int DECK_CARD_MIN = 50;   // �f�b�L�̃J�[�h�����ŏ�
private:
    std::string deck_name;  // �f�b�L��
    int card_num;           // �J�[�h����
    int card[100];          // �J�[�h
public:
    DeckData();             // �R���X�g���N�^
    ~DeckData();            // �f�X�g���N�^
    void addCard(int);      // �J�[�h�ǉ�
    void deletePosCard(int);   // n�Ԗڂ̃J�[�h���폜
    void addPosCard(int, int); // n�ԖڂɃJ�[�h��}��
    //---- getter/setter
    int getCard(int);       // �J�[�h�擾
    void setDeckName(std::string);  // ���O�ݒ�
    int getCardNum();          // �J�[�h�����擾
    std::string getDeckName(); // �f�b�L���擾
};