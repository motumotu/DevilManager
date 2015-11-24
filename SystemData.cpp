//-----------------------------------------------------------
// SystemData.cpp
// システムデータ
// 制作日 2015.02.28
// 制作者 motumotu
//-----------------------------------------------------------
#include "SystemData.h"

int SystemData::window_width;      // 画面サイズ幅
int SystemData::window_height;     // 画面サイズ高さ
int SystemData::window_color;      // 使用カラー

//-----------------------------------------------------------
// システムデータ読み込み
//-----------------------------------------------------------
void SystemData::loadSystemData()
{
    std::string str;
    std::ifstream ifs("systemdata.dat");

    if (ifs.fail()) {
        std::cout << "systemdata.datの読み込みに失敗しました。" << std::endl;
        return;
    }
    //---- 画面幅
    getline(ifs, str);
    window_width = atoi(str.c_str());
    //---- 画面高さ
    getline(ifs, str);
    window_height = atoi(str.c_str());
    //---- 画面カラー
    getline(ifs, str);
    window_color = atoi(str.c_str());
}

//===========================================================
// getter
//===========================================================
int SystemData::getWindowWidth() { return window_width; }
int SystemData::getWindowHeight() { return window_height; }
int SystemData::getWindowColor() { return window_color; }
