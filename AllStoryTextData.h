//-----------------------------------------------------------
// AllStoryTextData.h
// �S�X�g�[���[�e�L�X�g�f�[�^
// ����� 2015.03.24
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "DxLib.h"
#include "StoryTextData.h"
#include <sstream>
#include <string>
#include <iostream>
class AllStoryTextData {
public:
private:
    StoryTextData *story_text_data[100]; // �X�g�[���[�f�[�^
public:
    AllStoryTextData();    // �R���X�g���N�^
    ~AllStoryTextData();   // �f�X�g���N�^
    void loadData();       // �f�[�^�ǂݍ���
    StoryTextData *getStoryTextData(int); // �擾
};