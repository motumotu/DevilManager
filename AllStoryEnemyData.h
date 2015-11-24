//-----------------------------------------------------------
// AllStoryEnemyData.h
// �X�g�[���[�̑ΐ푊��S�f�[�^
// ����� 2015.03.22
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "DxLib.h"
#include "StoryEnemyData.h"

class AllStoryEnemyData {
private:
    StoryEnemyData *story_enemy_data[100];   // �X�g�[���[�̑ΐ푊��f�[�^
    int story_enemy_data_num;                // ����
public:
    AllStoryEnemyData();         // �R���X�g���N�^
    ~AllStoryEnemyData();        // �f�X�g���N�^
    void loadStoryEnemyData();   // �f�[�^�ǂݍ���

    //---- getter
    StoryEnemyData *getStoryEnemyData(int); // �擾
    int getStoryEnemyDataNum();   // �����擾
};