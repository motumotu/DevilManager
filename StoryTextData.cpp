//-----------------------------------------------------------
// StoryTextData.cpp
// �S�X�g�[���[�e�L�X�g�f�[�^
// ����� 2015.03.24
// ����� motumotu
//-----------------------------------------------------------
#include "StoryTextData.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
StoryTextData::StoryTextData()
{
    
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
StoryTextData::~StoryTextData()
{

}

//-----------------------------------------------------------
// ������
//-----------------------------------------------------------
void StoryTextData::init()
{
    num = 0;              // �ԍ�
    next_num = 0;         // ���̔ԍ�
    name = "";            // ���O
    text1 = "";           // �e�L�X�g�P
    text2 = "";           // �e�L�X�g�Q
    text3 = "";           // �e�L�X�g�R
}


//-----------------------------------------------------------
// setter
//-----------------------------------------------------------
void StoryTextData::setNum(int n) { num = n; }
void StoryTextData::setnextNum(int n) { next_num = n; }
void StoryTextData::setName(std::string n) { name = n; }
void StoryTextData::setText1(std::string n) { text1 = n; }
void StoryTextData::setText2(std::string n) { text2 = n; }
void StoryTextData::setText3(std::string n) { text3 = n; }

//-----------------------------------------------------------
// getter
//-----------------------------------------------------------
int StoryTextData::getNum() { return num; }
int StoryTextData::getNextNum() { return next_num; }
std::string StoryTextData::getNmae() { return name; }
std::string StoryTextData::getText1() { return text1; }
std::string StoryTextData::getText2() { return text2; }
std::string StoryTextData::getText3() { return text3; }
