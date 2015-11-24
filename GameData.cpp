//-----------------------------------------------------------
// GameData.cpp
// ゲームのデータ部
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#include "GameData.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
GameData::GameData()
{
    skill_data = new SkillData();
    all_card_data = new AllCardData();
    all_map_data = new AllMapData();
    all_battle_data = new AllBattleData();
    all_story_enemy_data = new AllStoryEnemyData();
    all_story_text_data = new AllStoryTextData();
    home_data = new HomeData();
    title_data = new TitleData();
    image_data = new ImageData();
    save_data = new SaveData();
    deck_edit_data = new DeckEditData();
    battle_select_data = new BattleSelectData();
    story_select_data = new StorySelectData();
    story_data = new StoryData();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
GameData::~GameData()
{
    delete(story_data);
    delete(story_select_data);
    delete(deck_edit_data);
    delete(save_data);
    delete(image_data);
    delete(title_data);
    delete(home_data);
    delete(all_story_text_data);
    delete(all_story_enemy_data);
    delete(all_battle_data);
    delete(all_map_data);
    delete(all_card_data);
    delete(skill_data);
}

//===========================================================
// getter
//===========================================================
AllCardData *GameData::getAllCardData() { return all_card_data; }
AllMapData *GameData::getAllMapData() { return all_map_data; }
AllBattleData *GameData::getAllBattleData() { return all_battle_data; }
AllStoryEnemyData *GameData::getAllStoryEnemyData() { return all_story_enemy_data; }
AllStoryTextData *GameData::getAllStoryTextData() { return all_story_text_data; }
SkillData *GameData::getSkillData() { return skill_data; }
HomeData *GameData::getHomeData() { return home_data; }
TitleData *GameData::getTitleData() { return title_data; }
ImageData *GameData::getImageData() { return image_data; }
DeckListData *GameData::getDeckListData() { return deck_list_data; }
SaveData *GameData::getSaveData() { return save_data; }
DeckEditData *GameData::getDeckEditData() { return deck_edit_data; }
BattleSelectData *GameData::getBattleSelectData() { return battle_select_data; }
StorySelectData *GameData::getStorySelectData() { return story_select_data; }
StoryData *GameData::getStoryData() { return story_data; }