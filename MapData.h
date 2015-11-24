//-----------------------------------------------------------
// MapData.h
// マップデータ
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once

class MapData {
public:
    // 定数
    static const int MAP_WALL = 0;   // 壁
    static const int MAP_FLOOR = 1;  // 床
    static const int MAP_SIZE_MAX = 100; // マップサイズ最大
    static const int MAP_IMAGE_SIZE = 50; // マップサイズ
    // 変数
    int map_size_width;                        // マップの幅
    int map_size_height;                       // マップの高さ
    int map_data[MAP_SIZE_MAX][MAP_SIZE_MAX];  // マップデータ
    int player_base_x;                         // 自拠点座標x
    int player_base_y;                         // 自拠点座標y
    int enemy_base_x;                          // 敵拠点座標x
    int enemy_base_y;                          // 敵拠点座標y
    // メソッド
    MapData();                 // コンストラクタ
    ~MapData();                // デストラクタ
    void init();               // 初期化
    bool outCheck(int, int);   // 範囲内チェック
    bool isFloor(int, int);    // 床かどうか判定
};