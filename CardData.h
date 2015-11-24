//-----------------------------------------------------------
// CardData.h
// カードデータ
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include <string>
#include <vector>

class CardData {
public:
    //---- 定数
    static const int ATTR_NONE = 0;       // 属性 無
    static const int ATTR_FIRE = 1;       // 属性 火
    static const int ATTR_WATER = 2;      // 属性 水
    static const int ATTR_ICE = 3;        // 属性 氷
    static const int ATTR_ELECT = 4;      // 属性 電
    static const int ATTR_DARK = 5;       // 属性 闇
    static const int ATTR_LIGHT = 6;      // 属性 光
    static const int ATTR_EARTH = 7;      // 属性 地
    static const int ATTR_POISON = 8;     // 属性 毒
    static const int ATTR_WIND = 9;       // 属性 風
    //---- 変数
    int id;                // ID
    std::string name;      // 名前
    int mp;                // 必要魔力
    int hp;                // 体力
    int pow;               // 攻撃力
    int def;               // 防御力
    int move_speed;        // 移動速度
    int attack_speed;      // 攻撃速度
    int attribute;         // 自分の属性
    int search_range;      // 索敵範囲
    int image_size_x;      // 画像サイズx
    int image_size_y;      // 画像サイズy
    int size_x;            // 大きさx
    int size_y;            // 大きさy
    std::vector<int> skil; // スキル
    // 耐性 基本値100
    int fire;              // 火
    int water;             // 水
    int ice;               // 氷
    int elect;             // 電
    int dark;              // 闇
    int light;             // 光
    int earth;             // 地
    int poison;            // 毒
    int wind;              // 風
    //---- メソッド
    CardData();            // コンストラクタ
    ~CardData();           // デストラクタ
    void init();           // 初期化
    void update();         // 更新
};