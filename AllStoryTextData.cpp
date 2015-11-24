//-----------------------------------------------------------
// AllStoryTextData.cpp
// �S�X�g�[���[�e�L�X�g�f�[�^
// ����� 2015.03.24
// ����� motumotu
//-----------------------------------------------------------
#include "AllStoryTextData.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
AllStoryTextData::AllStoryTextData()
{
    for (int i = 0; i < 100; i++) {
        story_text_data[i] = NULL;
    }
    loadData();     // �f�[�^�ǂݍ���
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
AllStoryTextData::~AllStoryTextData()
{
    for (int i = 0; i < 100; i++) {
        if (story_text_data[i] != NULL) {
            delete(story_text_data[i]);
            story_text_data[i] = NULL;
        }
    }
}

//-----------------------------------------------------------
// �f�[�^�ǂݍ���
//-----------------------------------------------------------
void AllStoryTextData::loadData()
{
    char str[1024];
    std::string s;
    std::stringstream ss;
    int num;
    int fp = FileRead_open("dat/story_text.dat");
    // �t�@�C���ǂݍ��ݎ��s
    if (fp == 0) {
        puts("story_text.dat�t�@�C���ǂݍ��ݎ��s");
        return;
    }
    // �t�@�C���ǂݍ��ݏ���
    while (FileRead_gets(str, 256, fp) != -1) {
        ss.clear();
        ss.str(str);
        ss >> s;
        //---- �ԍ�
        if (s == "#NUM") {
            ss >> s;
            num = atoi(s.c_str());
            story_text_data[num] = new StoryTextData();
            story_text_data[num]->setNum(num);
        }
        //---- ���O
        if (s == "#NAME") {
            ss >> s;
            story_text_data[num]->setName(s);
        }
        //---- �e�L�X�g1
        if (s == "#TEXT1") {
            ss >> s;
            story_text_data[num]->setText1(s);
        }
        //---- �e�L�X�g2
        if (s == "#TEXT2") {
            ss >> s;
            story_text_data[num]->setText2(s);
        }
        //---- �e�L�X�g3
        if (s == "#TEXT3") {
            ss >> s;
            story_text_data[num]->setText3(s);
        }
        //---- ��
        if (s == "#NEXT") {
            ss >> s;
            story_text_data[num]->setnextNum(atoi(s.c_str()));
        }
    }

    FileRead_close(fp);
}

//-----------------------------------------------------------
// �f�[�^�擾
//-----------------------------------------------------------
StoryTextData *AllStoryTextData::getStoryTextData(int n) {
    return story_text_data[n];
}