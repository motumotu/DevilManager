//-----------------------------------------------------------
// AllMapData.h
// 全マップデータ
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "MapData.h"
#include <fstream>
#include <iostream>
#include <sstream>

class AllMapData {
public:
    static const int MAP_NUM = 2;    // マップデータ数
private:
    MapData map_data[MAP_NUM + 1];   // マップデータ
    bool loadAllMapData();           // 全マップデータ読み込み
    bool loadMapData(int);           // マップデータの読み込み
public:
    AllMapData();                    // コンストラクタ
    ~AllMapData();                   // デストラクタ

    MapData *getMapData(int);        // マップデータ取得
};