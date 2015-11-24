//-----------------------------------------------------------
// BattleAreaState.h
// 領域情報
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "MapData.h"
#include <cstdio>

class BattleAreaState {
public:
    static const int AREA_NONE = 0;      // 中立エリア
    static const int AREA_MY = 1;        // 自軍エリア
    static const int AREA_ENE = 2;       // 敵軍エリア
    static const int AREA_MP_MAX = 99;   // 最大エリア魔力
    static const int AREA_MP_MIN = 0;    // 最小エリア魔力
private:
    MapData *map_data;
    int area_who[MapData::MAP_SIZE_MAX][MapData::MAP_SIZE_MAX];   // どっちの領域か
    int area_mp_my[MapData::MAP_SIZE_MAX][MapData::MAP_SIZE_MAX]; // 自軍魔力保有量
    int area_mp_en[MapData::MAP_SIZE_MAX][MapData::MAP_SIZE_MAX]; // 敵軍魔力保有量
public:
    BattleAreaState();     // コンストラクタ
    ~BattleAreaState();    // デストラクタ
    void init();           // 初期処理
    void battleInit();     // 対戦情報初期化
    void update();         // 更新処理
    void addAreaMpMy(int, int, int);       // 自軍領域魔力増加
    void addAreaMpMy(int, int, int, int);  // 自軍領域魔力増加
    void addAreaMpEn(int, int, int);       // 敵軍領域魔力増加
    void addAreaMpEn(int, int, int, int);  // 敵軍領域魔力増加
    void subAreaMpMy(int, int, int);       // 自軍領域魔力減少
    void subAreaMpEn(int, int, int);       // 敵軍領域魔力現象

    void discriminationArea();             // 領域判別
    void setMapData(MapData*);             // マップデータ設定

    int getAreaWho(int, int);   // どちらのエリアか取得
    int getAreaMpMy(int, int);  // 自軍エリア魔力情報取得
    int getAreaMpEn(int, int);  // 敵軍エリア魔力情報取得
};