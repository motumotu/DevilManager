//-----------------------------------------------------------
// GameData.h
// �Q�[���̃f�[�^��
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "AllCardData.h"
#include "AllMapData.h"
#include "AllBattleData.h"
#include "AllStoryEnemyData.h"
#include "AllStoryTextData.h"
#include "SkillData.h"
#include "HomeData.h"
#include "TitleData.h"
#include "ImageData.h"
#include "DeckListData.h"
#include "SaveData.h"
#include "DeckEditData.h"
#include "BattleSelectData.h"
#include "StorySelectData.h"
#include "StoryData.h"

class GameData {
private:
    AllCardData *all_card_data;        // �J�[�h�f�[�^
    AllMapData *all_map_data;          // �}�b�v�f�[�^
    AllBattleData *all_battle_data;    // �ΐ푊��f�[�^
    AllStoryEnemyData *all_story_enemy_data; // �X�g�[���[�̑ΐ푊��f�[�^
    AllStoryTextData *all_story_text_data;   // �X�g�[���[�e�L�X�g�f�[�^
    SkillData *skill_data;             // �X�L���f�[�^
    HomeData *home_data;               // �z�[����ʂ̃f�[�^
    TitleData *title_data;             // �^�C�g����ʂ̃f�[�^
    ImageData *image_data;             // �摜�f�[�^
    DeckListData *deck_list_data;      // �f�b�L�ꗗ��ʂ̃f�[�^
    SaveData *save_data;               // �Z�[�u�f�[�^
    DeckEditData *deck_edit_data;      // �f�b�L�ҏW��ʂ̃f�[�^
    BattleSelectData *battle_select_data; // �ΐ�I����ʂ̃f�[�^      
    StorySelectData *story_select_data;   // �X�g�[���[�I����ʂ̃f�[�^
    StoryData *story_data;             // �X�g�[���[��ʂ̃f�[�^
public:
    GameData();                        // �R���X�g���N�^
    ~GameData();                       // �f�X�g���N�^
    AllCardData *getAllCardData();     // �J�[�h�f�[�^�擾
    AllMapData *getAllMapData();       // �}�b�v�f�[�^�擾
    AllBattleData *getAllBattleData(); // �ΐ�f�[�^�擾
    AllStoryEnemyData *getAllStoryEnemyData(); // �X�g�[���[�̑ΐ푊��f�[�^�擾
    AllStoryTextData *getAllStoryTextData();   // �X�g�[���[�f�[�^�擾
    SkillData *getSkillData();         // �X�L���f�[�^�擾
    HomeData *getHomeData();           // �z�[����ʂ̃f�[�^�擾
    TitleData *getTitleData();         // �^�C�g����ʂ̃f�[�^�擾
    ImageData *getImageData();         // �摜�f�[�^�擾
    DeckListData *getDeckListData();   // �f�b�L�ꗗ��ʂ̃f�[�^�擾
    SaveData *getSaveData();           // �Z�[�u�f�[�^�擾
    DeckEditData *getDeckEditData();   // �f�b�L�ҏW��ʃf�[�^�̎擾
    BattleSelectData *getBattleSelectData(); // �ΐ�I����ʂ̃f�[�^�擾
    StorySelectData *getStorySelectData(); // �X�g�[���[�I����ʂ̃f�[�^�擾
    StoryData *getStoryData();         // �X�g�[���[��ʂ̃f�[�^�擾
};