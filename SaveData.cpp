//-----------------------------------------------------------
// SaveData.h
// セーブデータ
// 制作日 2015.03.18
// 制作者 motumotu
//-----------------------------------------------------------
#include "SaveData.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
SaveData::SaveData()
{
    have_card = new HaveCardData();
    loadSaveData();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
SaveData::~SaveData()
{
    saveSaveData();
    delete(have_card);
}

//-----------------------------------------------------------
// セーブデータ読み込み
//-----------------------------------------------------------
void SaveData::loadSaveData()
{
    std::string str;
    std::ifstream ifs("savedata/savedata001.dat");
    if (ifs.fail()) {
        std::cout << "セーブデータの読み込みに失敗しました。" << std::endl;
        return;
    }
    //---- プレイヤー名
    getline(ifs, str);
    player_name = str;

    //---- セーブデータ作成日
    getline(ifs, str);
    create_savedata_day = atoi(str.c_str());

    //---- プレイ時間
    getline(ifs, str);
    player_time = atoi(str.c_str());

    //---- デッキ情報
    // デッキ枚数
    getline(ifs, str);
    deck_num = atoi(str.c_str());
    for (int i = 1; i <= deck_num; i++) {
        DeckData *deck = new DeckData();
        // 名前
        getline(ifs, str);
        deck->setDeckName(str);
        // カード
        getline(ifs, str);
        std::stringstream ss(str);
        while (ss >> str) {
            int n = atoi(str.c_str());
            deck->addCard(n);
        }
        deck_data[i] = deck;
    }
    
    //---- 所持カード情報
    // 所持カード枚数
    getline(ifs, str);
    have_card_num = atoi(str.c_str());
    // カード情報
    getline(ifs, str);
    std::stringstream ss(str);
    while (ss >> str) {
        int n = atoi(str.c_str());
        have_card->addCard(n);
    }
}

//-----------------------------------------------------------
// セーブデータ保存
//-----------------------------------------------------------
void SaveData::saveSaveData()
{

}

//===========================================================
// getter
//===========================================================
int SaveData::getDeckNum() { return deck_num; }
DeckData *SaveData::getDeckData(int n) { return deck_data[n]; }
int SaveData::getHaveCardNum() { return have_card->getAllCardNum(); }
HaveCardData *SaveData::getHaveCardData() { return have_card; }