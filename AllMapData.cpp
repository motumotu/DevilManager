//-----------------------------------------------------------
// AllMapData.cpp
// �S�}�b�v�f�[�^
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#include "AllMapData.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
AllMapData::AllMapData()
{
    loadAllMapData();
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
AllMapData::~AllMapData()
{

}

//-----------------------------------------------------------
// �S�}�b�v�f�[�^�ǂݍ���
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
// �}�b�v�f�[�^�ǂݍ���
//-----------------------------------------------------------
bool AllMapData::loadMapData(int id)
{
    std::string str;
    std::stringstream ss;
    ss << "dat/map_" << id << ".dat";
    std::ifstream ifs(ss.str());
    if (ifs.fail()) {
        std::cout << ss.str() << "�̓ǂݍ��݂Ɏ��s���܂����B" << std::endl;
        return false;
    }
    //---- �}�b�v�T�C�Y�ǂݍ���
    getline(ifs, str);
    map_data[id].map_size_height = atoi(str.c_str());
    getline(ifs, str);
    map_data[id].map_size_width = atoi(str.c_str());

    //---- �}�b�v�f�[�^�ǂݍ���
    for (int i = 0; getline(ifs, str); i++) {
        for (int j = 0; j < (int)str.size(); j++) {
            switch (str[j]) {
            case '#': // ��
                map_data[id].map_data[i][j] = MapData::MAP_WALL;
                break;
            case 'P': // �v���C���[���_�ʒu
                map_data[id].player_base_x = j;
                map_data[id].player_base_y = i;
                map_data[id].map_data[i][j] = MapData::MAP_FLOOR;
                break;
            case 'E': // �G���_�ʒu
                map_data[id].enemy_base_x = j;
                map_data[id].enemy_base_y = i;
                map_data[id].map_data[i][j] = MapData::MAP_FLOOR;
                break;
            case '.': // ��
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

