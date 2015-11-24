//-----------------------------------------------------------
// SystemData.cpp
// �V�X�e���f�[�^
// ����� 2015.02.28
// ����� motumotu
//-----------------------------------------------------------
#include "SystemData.h"

int SystemData::window_width;      // ��ʃT�C�Y��
int SystemData::window_height;     // ��ʃT�C�Y����
int SystemData::window_color;      // �g�p�J���[

//-----------------------------------------------------------
// �V�X�e���f�[�^�ǂݍ���
//-----------------------------------------------------------
void SystemData::loadSystemData()
{
    std::string str;
    std::ifstream ifs("systemdata.dat");

    if (ifs.fail()) {
        std::cout << "systemdata.dat�̓ǂݍ��݂Ɏ��s���܂����B" << std::endl;
        return;
    }
    //---- ��ʕ�
    getline(ifs, str);
    window_width = atoi(str.c_str());
    //---- ��ʍ���
    getline(ifs, str);
    window_height = atoi(str.c_str());
    //---- ��ʃJ���[
    getline(ifs, str);
    window_color = atoi(str.c_str());
}

//===========================================================
// getter
//===========================================================
int SystemData::getWindowWidth() { return window_width; }
int SystemData::getWindowHeight() { return window_height; }
int SystemData::getWindowColor() { return window_color; }
