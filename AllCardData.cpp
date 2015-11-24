//-----------------------------------------------------------
// AllCardData.cpp
// ゲームのデータ部
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#include "AllCardData.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
AllCardData::AllCardData()
{
    readCardData();             // カードデータ読み込み
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
AllCardData::~AllCardData()
{

}

//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void AllCardData::init()
{

}

//-----------------------------------------------------------
// 更新
//-----------------------------------------------------------
void AllCardData::update()
{

}

//-----------------------------------------------------------
// カードデータ読み込み
//-----------------------------------------------------------
// 【説明】 全カードデータを読み込む
// 【引数】 なし
// 【返値】 成功：true、失敗：false
//-----------------------------------------------------------
bool AllCardData::readCardData()
{
    //---- ファイルを開く
    std::string str;
    std::ifstream ifs("dat/card_data.dat");
    if (ifs.fail()) {
        puts("card_data.datの読み込みに失敗しました。");
        return false;
    }
    puts("card_data.dat読み込み成功");
    //---- カードデータ読み込み
    while (getline(ifs, str)) {
        std::stringstream ss(str);
        // ID
        ss >> str;
        int id = atoi(str.c_str());
        card[id].id = id;
        // 名前
        ss >> str;
        card[id].name = str;
        // 魔力
        ss >> str;
        card[id].mp = atoi(str.c_str());
        // 体力
        ss >> str;
        card[id].hp = atoi(str.c_str());
        // 攻撃力
        ss >> str;
        card[id].pow = atoi(str.c_str());
        // 防御力
        ss >> str;
        card[id].def = atoi(str.c_str());
        // 移動速度
        ss >> str;
        card[id].move_speed = atoi(str.c_str());
        // 攻撃速度
        ss >> str;
        card[id].attack_speed = atoi(str.c_str());
        // 火耐性
        ss >> str;
        card[id].fire = atoi(str.c_str());
        // 水耐性
        ss >> str;
        card[id].water = atoi(str.c_str());
        // 氷耐性
        ss >> str;
        card[id].ice = atoi(str.c_str());
        // 電耐性
        ss >> str;
        card[id].elect = atoi(str.c_str());
        // 闇耐性
        ss >> str;
        card[id].dark = atoi(str.c_str());
        // 光耐性
        ss >> str;
        card[id].light = atoi(str.c_str());
        // 地耐性
        ss >> str;
        card[id].earth = atoi(str.c_str());
        // 毒耐性
        ss >> str;
        card[id].poison = atoi(str.c_str());
        // 風耐性
        ss >> str;
        card[id].wind = atoi(str.c_str());
        // 属性
        ss >> str;
        if (str == "火") card[id].attribute = CardData::ATTR_FIRE;
        else if (str == "水") card[id].attribute = CardData::ATTR_WATER;
        else if (str == "氷") card[id].attribute = CardData::ATTR_ICE;
        else if (str == "電") card[id].attribute = CardData::ATTR_ELECT;
        else if (str == "闇") card[id].attribute = CardData::ATTR_DARK;
        else if (str == "光") card[id].attribute = CardData::ATTR_LIGHT;
        else if (str == "地") card[id].attribute = CardData::ATTR_EARTH;
        else if (str == "毒") card[id].attribute = CardData::ATTR_POISON;
        else if (str == "風") card[id].attribute = CardData::ATTR_WIND;
        // 索敵範囲
        ss >> str;
        card[id].search_range = atoi(str.c_str());
        // 画像大きさx
        ss >> str;
        card[id].image_size_x = atoi(str.c_str());
        // 画像大きさy
        ss >> str;
        card[id].image_size_y = atoi(str.c_str());
        // 大きさx
        ss >> str;
        card[id].size_x = atoi(str.c_str());
        // 大きさy
        ss >> str;
        card[id].size_y = atoi(str.c_str());
        // スキル
        ss >> str;
        int n = atoi(str.c_str());
        for (int i = 0; i < n; i++) {
            ss >> str;
            card[id].skil.push_back(atoi(str.c_str()));
        }
    }
    return true;
}

//===========================================================
// getter
//===========================================================
CardData *AllCardData::getCardData(int id) { return &card[id]; }