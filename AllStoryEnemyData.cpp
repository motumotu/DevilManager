//-----------------------------------------------------------
// AllStoryEnemyData.cpp
// �X�g�[���[�̑ΐ푊��S�f�[�^
// ����� 2015.03.22
// ����� motumotu
//-----------------------------------------------------------
#include "AllStoryEnemyData.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
AllStoryEnemyData::AllStoryEnemyData()
{
    story_enemy_data_num = 0;
    loadStoryEnemyData();
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
AllStoryEnemyData::~AllStoryEnemyData()
{
    for (int i = 1; i <= story_enemy_data_num; i++) {
        delete(story_enemy_data[i]);
    }
}

//-----------------------------------------------------------
// �f�[�^�ǂݍ���
//-----------------------------------------------------------
void AllStoryEnemyData::loadStoryEnemyData()
{
    char str[1024];
    int num;
    int fp = FileRead_open("dat/story_data.dat");
    if (fp == 0) {
        puts("story_data.dat�t�@�C���ǂݍ��ݎ��s");
        return;
    }
    for (story_enemy_data_num = 0; FileRead_scanf(fp, "%d", &num) != -1; story_enemy_data_num++) {
        story_enemy_data[num] = new StoryEnemyData();
        // �ԍ�
        story_enemy_data[num]->setNum(num);
        // �X�g�[���[�^�C�g��
        FileRead_scanf(fp, "%s", str);
        story_enemy_data[num]->setName(str);
        // �����N
        int rank;
        FileRead_scanf(fp, "%d", &rank);
        story_enemy_data[num]->setRank(rank);
        // �}�b�v�ԍ�
        int map;
        FileRead_scanf(fp, "%d", &map);
        story_enemy_data[num]->setMapNum(map);
        // �f�b�L��
        FileRead_scanf(fp, "%s", str);
        story_enemy_data[num]->getDeckData()->setDeckName(str);
        // �f�b�L����
        int deck_num;
        FileRead_scanf(fp, "%d", &deck_num);
        // �e�J�[�h
        for (int i = 0; i < deck_num; i++) {
            int card;
            FileRead_scanf(fp, "%d", &card);
            story_enemy_data[num]->getDeckData()->addCard(card);
        }
    }

    FileRead_close(fp);
}

//-----------------------------------------------------------
// getter
//-----------------------------------------------------------
StoryEnemyData *AllStoryEnemyData::getStoryEnemyData(int n) { return story_enemy_data[n]; }
int AllStoryEnemyData::getStoryEnemyDataNum() { return story_enemy_data_num; }