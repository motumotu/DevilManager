//-----------------------------------------------------------
// SaveData.h
// セーブデータ
// 制作日 2015.03.18
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "DeckData.h"
#include "HaveCardData.h"

class SaveData {
private:
    std::string player_name;    // プレイヤー名
    int create_savedata_day;    // セーブデータ作成日
    int player_time;            // プレイ時間
    int deck_num;               // デッキ数
    DeckData *deck_data[100];   // デッキデータ
    int have_card_num;          // 所持カード数
    HaveCardData *have_card;    // 所持カードデータ
    // クリアストーリー情報
    // クリアバトル情報
    // システムデータ
public:
    SaveData();       // コンストラクタ
    ~SaveData();      // デストラクタ
    void loadSaveData();  // セーブデータ読み込み
    void saveSaveData();  // セーブデータ保存
    bool isSaveData();    // セーブデータがあるか
    //---- getter
    int getDeckNum();                // デッキ数取得
    DeckData *getDeckData(int);      // デッキデータ取得
    int getHaveCardNum();            // 所持カード枚数取得
    HaveCardData *getHaveCardData(); // 所持カードデータ取得
};