//-----------------------------------------------------------
// SkillData.h
// �X�L�����
// ����� 2015.03.14
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include <string>

class SkillData {
public:
    static const int LINE_TEXT_NUM = 20;
private:
    std::string text[100];      // �X�L������
public:
    SkillData();                      // �R���X�g���N�^
    ~SkillData();                     // �f�X�g���N�^
    std::string getSkillText1(int n);  // 1�s�ڎ擾
    std::string getSkillText2(int n);  // 2�s�ڎ擾
};