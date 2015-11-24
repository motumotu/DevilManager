//-----------------------------------------------------------
// AllBattleData.cpp
// 全対戦相手データ
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#include "AllBattleData.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
AllBattleData::AllBattleData()
{
    battle_data_num = 0;
    loadBattleData();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
AllBattleData::~AllBattleData()
{

}

//-----------------------------------------------------------
// バトルデータ読み込み
//-----------------------------------------------------------
void AllBattleData::loadBattleData()
{
    //---- ファイルを開く
    std::string str;
    std::ifstream ifs("dat/battle_data.dat");
    if (ifs.fail()) {
        puts("battle_data.datの読み込みに失敗しました。");
        return;
    }
    puts("battle_data.dat読み込み成功");
    //---- カードデータ読み込み
    while (getline(ifs, str)) {
        battle_data_num++;
        std::stringstream ss(str);
        // ID
        ss >> str;
        int id = atoi(str.c_str());
        battle_data[id] = new BattleData();
        battle_data[id]->setId(id);
        // 名前
        ss >> str;
        battle_data[id]->setName(str);
        // ランク
        ss >> str;
        battle_data[id]->setRank(atoi(str.c_str()));
        // マップ番号
        ss >> str;
        battle_data[id]->setMapNum(atoi(str.c_str()));
        // デッキ名
        ss >> str;
        battle_data[id]->getDeckData()->setDeckName(str);
        // カード枚数
        ss >> str;
        int n = atoi(str.c_str());
        for (int i = 0; i < n; i++) {
            ss >> str;
            battle_data[id]->getDeckData()->addCard(atoi(str.c_str()));
        }
    }
}

//===========================================================
// getter
//===========================================================
int AllBattleData::getBattleDataNum() { return battle_data_num; }
BattleData *AllBattleData::getBattleData(int n) { return battle_data[n]; }
