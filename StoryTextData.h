//-----------------------------------------------------------
// StoryTextData.h
// �X�g�[���[�e�L�X�g�f�[�^
// ����� 2015.03.24
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include <string>

class StoryTextData {
public:
private:
    int num;              // �ԍ�
    int next_num;         // ���̔ԍ�
    std::string name;     // ���O
    std::string text1;    // �e�L�X�g�P
    std::string text2;    // �e�L�X�g�Q
    std::string text3;    // �e�L�X�g�R
public:
    StoryTextData();    // �R���X�g���N�^
    ~StoryTextData();   // �f�X�g���N�^
    void init();        // ��������
    //---- setter
    void setNum(int);
    void setnextNum(int);
    void setName(std::string);
    void setText1(std::string);
    void setText2(std::string);
    void setText3(std::string);

    //---- getter
    int getNum();
    int getNextNum();
    std::string getNmae();
    std::string getText1();
    std::string getText2();
    std::string getText3();
};