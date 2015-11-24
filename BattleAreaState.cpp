//-----------------------------------------------------------
// BattleAreaState.cpp
// �̈���
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#include "BattleAreaState.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
BattleAreaState::BattleAreaState()
{
    init();
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
BattleAreaState::~BattleAreaState()
{

}

//-----------------------------------------------------------
// ��������
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
// �ΐ��񏉊���
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
// �X�V
//-----------------------------------------------------------
void BattleAreaState::update()
{
    discriminationArea();  // �̈���X�V
}
//-----------------------------------------------------------
// ���͑���
//-----------------------------------------------------------
//-----------------------------------------------------------
// ���R�̈斂�͑���
//-----------------------------------------------------------
void BattleAreaState::addAreaMpMy(int mp, int x, int y)
{
    area_mp_my[y][x] += mp;
    if (area_mp_my[y][x] > AREA_MP_MAX) {
        area_mp_my[y][x] = AREA_MP_MAX;
    }
}
// ���́��}�X��
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
// �G�R�̈斂�͑���
//-----------------------------------------------------------
void BattleAreaState::addAreaMpEn(int mp, int x, int y)
{
    area_mp_en[y][x] += mp;
    if (area_mp_en[y][x] > AREA_MP_MAX) {
        area_mp_en[y][x] = AREA_MP_MAX;
    }
}
// ���́��}�X��
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
// ���R�̈斂�͌���
//-----------------------------------------------------------
void BattleAreaState::subAreaMpMy(int mp, int x, int y)
{
    area_mp_my[y][x] -= mp;
    if (area_mp_my[y][x] < AREA_MP_MIN) {
        area_mp_my[y][x] = AREA_MP_MIN;
    }
}

//-----------------------------------------------------------
// �G�R�̈斂�͌���
//-----------------------------------------------------------
void BattleAreaState::subAreaMpEn(int mp, int x, int y)
{
    area_mp_en[y][x] -= mp;
    if (area_mp_en[y][x] < AREA_MP_MIN) {
        area_mp_en[y][x] = AREA_MP_MIN;
    }
}

//-----------------------------------------------------------
// �̈攻��
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
// �}�b�v�f�[�^�ݒ�
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
        printf("�͈͊O�Q�� BattleAreaState::getAreaWho(%d, %d)\n", x, y);
        return 0;
    }
    return area_who[y][x];
}
int BattleAreaState::getAreaMpMy(int x, int y) {
    if (map_data->outCheck(x, y)) {
        printf("�͈͊O�Q�� BattleAreaState::getAreaMpMy(%d, %d)\n", x, y);
        return 0;
    }
    return area_mp_my[y][x];
}
int BattleAreaState::getAreaMpEn(int x, int y) {
    if (map_data->outCheck(x, y)) {
        printf("�͈͊O�Q�� BattleAreaState::getAreaMpEn(%d, %d)\n", x, y);
        return 0;
    }
    return area_mp_en[y][x];
}