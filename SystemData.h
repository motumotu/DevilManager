//-----------------------------------------------------------
// SystemData.h
// システムデータ
// 制作日 2015.02.28
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include <fstream>
#include <iostream>
#include <sstream>

class SystemData {
private:
    static int window_width;      // 画面サイズ幅
    static int window_height;     // 画面サイズ高さ
    static int window_color;      // 使用カラー
public:
    static void loadSystemData(); // システムデータ読み込み
    static int getWindowWidth();  // 画面幅取得
    static int getWindowHeight(); // 画面高さ取得
    static int getWindowColor();  // 使用カラー取得
};