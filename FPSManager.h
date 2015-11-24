//-----------------------------------------------------------
// FPSManager.h
// FPSの調整
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "DxLib.h"

class FPSManager {
public:
    static const int FPS = 60;  // FPS値
private:
    static const int N = 60;    // サンプル数
    int start_time;             // 計測開始時間
    int counter;                // カウンター
    double fps;                 // 実際のfps

public:
    FPSManager();               // コンストラクタ
    ~FPSManager();              // デストラクタ
    void init();                // 初期処理
    void update();              // 更新
    void wait();                // 調整のため待つ
};