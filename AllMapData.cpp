//-----------------------------------------------------------
// AllMapData.cpp
// 全マップデータ
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#include "AllMapData.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
AllMapData::AllMapData()
{
    loadAllMapData();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
AllMapData::~AllMapData()
{

}

//-----------------------------------------------------------
// 全マップデータ読み込み
//-----------------------------------------------------------
bool AllMapData::loadAllMapData()
{
    for (int id = 1; id <= MAP_NUM; id++) {
        if (loadMapData(id) == false) {
            return false;
        }
    }
    return true;
}

//-----------------------------------------------------------
// マップデータ読み込み
//-----------------------------------------------------------
bool AllMapData::loadMapData(int id)
{
    std::string str;
    std::stringstream ss;
    ss << "dat/map_" << id << ".dat";
    std::ifstream ifs(ss.str());
    if (ifs.fail()) {
        std::cout << ss.str() << "の読み込みに失敗しました。" << std::endl;
        return false;
    }
    //---- マップサイズ読み込み
    getline(ifs, str);
    map_data[id].map_size_height = atoi(str.c_str());
    getline(ifs, str);
    map_data[id].map_size_width = atoi(str.c_str());

    //---- マップデータ読み込み
    for (int i = 0; getline(ifs, str); i++) {
        for (int j = 0; j < (int)str.size(); j++) {
            switch (str[j]) {
            case '#': // 壁
                map_data[id].map_data[i][j] = MapData::MAP_WALL;
                break;
            case 'P': // プレイヤー拠点位置
                map_data[id].player_base_x = j;
                map_data[id].player_base_y = i;
                map_data[id].map_data[i][j] = MapData::MAP_FLOOR;
                break;
            case 'E': // 敵拠点位置
                map_data[id].enemy_base_x = j;
                map_data[id].enemy_base_y = i;
                map_data[id].map_data[i][j] = MapData::MAP_FLOOR;
                break;
            case '.': // 床
                map_data[id].map_data[i][j] = MapData::MAP_FLOOR;
                break;
            }
        }
    }
    ifs.close();
    return true;
}

//===========================================================
// getter
//===========================================================
MapData *AllMapData::getMapData(int n) { return &map_data[n]; }

