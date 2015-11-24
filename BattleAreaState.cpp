//-----------------------------------------------------------
// BattleAreaState.cpp
// 領域情報
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#include "BattleAreaState.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
BattleAreaState::BattleAreaState()
{
    init();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
BattleAreaState::~BattleAreaState()
{

}

//-----------------------------------------------------------
// 初期処理
//-----------------------------------------------------------
void BattleAreaState::init()
{
    for (int y = 0; y < MapData::MAP_SIZE_MAX; y++) {
        for (int x = 0; x < MapData::MAP_SIZE_MAX; x++) {
            area_who[y][x] = 0;
            area_mp_my[y][x] = 0;
            area_mp_en[y][x] = 0;
        }
    }
}

//-----------------------------------------------------------
// 対戦情報初期化
//-----------------------------------------------------------
void BattleAreaState::battleInit()
{
    for (int y = 0; y < MapData::MAP_SIZE_MAX; y++) {
        for (int x = 0; x < MapData::MAP_SIZE_MAX; x++) {
            area_who[y][x] = 0;
            area_mp_my[y][x] = 0;
            area_mp_en[y][x] = 0;
        }
    }
}

//-----------------------------------------------------------
// 更新
//-----------------------------------------------------------
void BattleAreaState::update()
{
    discriminationArea();  // 領域情報更新
}
//-----------------------------------------------------------
// 魔力増加
//-----------------------------------------------------------
//-----------------------------------------------------------
// 自軍領域魔力増加
//-----------------------------------------------------------
void BattleAreaState::addAreaMpMy(int mp, int x, int y)
{
    area_mp_my[y][x] += mp;
    if (area_mp_my[y][x] > AREA_MP_MAX) {
        area_mp_my[y][x] = AREA_MP_MAX;
    }
}
// 周囲○マスを
void BattleAreaState::addAreaMpMy(int mp, int x, int y, int circ)
{
    for (int dx = -circ; dx <= circ; dx++) {
        for (int dy = -circ; dy <= circ; dy++) {
            int px = x + dx;
            int py = y + dy;
            if (map_data->outCheck(px, py)) continue;
            if (map_data->map_data[py][px] == MapData::MAP_WALL) continue;
            addAreaMpMy(mp, px, py);
        }
    }
}

//-----------------------------------------------------------
// 敵軍領域魔力増加
//-----------------------------------------------------------
void BattleAreaState::addAreaMpEn(int mp, int x, int y)
{
    area_mp_en[y][x] += mp;
    if (area_mp_en[y][x] > AREA_MP_MAX) {
        area_mp_en[y][x] = AREA_MP_MAX;
    }
}
// 周囲○マスを
void BattleAreaState::addAreaMpEn(int mp, int x, int y, int circ)
{
    for (int dx = -circ; dx <= circ; dx++) {
        for (int dy = -circ; dy <= circ; dy++) {
            int px = x + dx;
            int py = y + dy;
            if (map_data->outCheck(px, py)) continue;
            if (map_data->map_data[py][px] == MapData::MAP_WALL) continue;
            addAreaMpEn(mp, px, py);
        }
    }
}
//-----------------------------------------------------------
// 自軍領域魔力減少
//-----------------------------------------------------------
void BattleAreaState::subAreaMpMy(int mp, int x, int y)
{
    area_mp_my[y][x] -= mp;
    if (area_mp_my[y][x] < AREA_MP_MIN) {
        area_mp_my[y][x] = AREA_MP_MIN;
    }
}

//-----------------------------------------------------------
// 敵軍領域魔力減少
//-----------------------------------------------------------
void BattleAreaState::subAreaMpEn(int mp, int x, int y)
{
    area_mp_en[y][x] -= mp;
    if (area_mp_en[y][x] < AREA_MP_MIN) {
        area_mp_en[y][x] = AREA_MP_MIN;
    }
}

//-----------------------------------------------------------
// 領域判別
//-----------------------------------------------------------
void BattleAreaState::discriminationArea()
{
    for (int y = 0; y < map_data->map_size_height; y++) {
        for (int x = 0; x < map_data->map_size_width; x++) {
            area_who[y][x] = AREA_NONE;
            if (area_mp_my[y][x] > area_mp_en[y][x]) {
                area_who[y][x] = AREA_MY;
            }
            else if (area_mp_en[y][x] > area_mp_my[y][x]) {
                area_who[y][x] = AREA_ENE;
            }
        }
    }
}

//-----------------------------------------------------------
// マップデータ設定
//-----------------------------------------------------------
void BattleAreaState::setMapData(MapData* map)
{
    map_data = map;
}

//===========================================================
// getter
//===========================================================
int BattleAreaState::getAreaWho(int x, int y) {
    if (map_data->outCheck(x, y)) {
        printf("範囲外参照 BattleAreaState::getAreaWho(%d, %d)\n", x, y);
        return 0;
    }
    return area_who[y][x];
}
int BattleAreaState::getAreaMpMy(int x, int y) {
    if (map_data->outCheck(x, y)) {
        printf("範囲外参照 BattleAreaState::getAreaMpMy(%d, %d)\n", x, y);
        return 0;
    }
    return area_mp_my[y][x];
}
int BattleAreaState::getAreaMpEn(int x, int y) {
    if (map_data->outCheck(x, y)) {
        printf("範囲外参照 BattleAreaState::getAreaMpEn(%d, %d)\n", x, y);
        return 0;
    }
    return area_mp_en[y][x];
}