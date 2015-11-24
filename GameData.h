//-----------------------------------------------------------
// GameData.h
// ゲームのデータ部
// 制作日 2015.03.01
// 制作者 motumotu
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
    AllCardData *all_card_data;        // カードデータ
    AllMapData *all_map_data;          // マップデータ
    AllBattleData *all_battle_data;    // 対戦相手データ
    AllStoryEnemyData *all_story_enemy_data; // ストーリーの対戦相手データ
    AllStoryTextData *all_story_text_data;   // ストーリーテキストデータ
    SkillData *skill_data;             // スキルデータ
    HomeData *home_data;               // ホーム画面のデータ
    TitleData *title_data;             // タイトル画面のデータ
    ImageData *image_data;             // 画像データ
    DeckListData *deck_list_data;      // デッキ一覧画面のデータ
    SaveData *save_data;               // セーブデータ
    DeckEditData *deck_edit_data;      // デッキ編集画面のデータ
    BattleSelectData *battle_select_data; // 対戦選択画面のデータ      
    StorySelectData *story_select_data;   // ストーリー選択画面のデータ
    StoryData *story_data;             // ストーリー画面のデータ
public:
    GameData();                        // コンストラクタ
    ~GameData();                       // デストラクタ
    AllCardData *getAllCardData();     // カードデータ取得
    AllMapData *getAllMapData();       // マップデータ取得
    AllBattleData *getAllBattleData(); // 対戦データ取得
    AllStoryEnemyData *getAllStoryEnemyData(); // ストーリーの対戦相手データ取得
    AllStoryTextData *getAllStoryTextData();   // ストーリーデータ取得
    SkillData *getSkillData();         // スキルデータ取得
    HomeData *getHomeData();           // ホーム画面のデータ取得
    TitleData *getTitleData();         // タイトル画面のデータ取得
    ImageData *getImageData();         // 画像データ取得
    DeckListData *getDeckListData();   // デッキ一覧画面のデータ取得
    SaveData *getSaveData();           // セーブデータ取得
    DeckEditData *getDeckEditData();   // デッキ編集画面データの取得
    BattleSelectData *getBattleSelectData(); // 対戦選択画面のデータ取得
    StorySelectData *getStorySelectData(); // ストーリー選択画面のデータ取得
    StoryData *getStoryData();         // ストーリー画面のデータ取得
};