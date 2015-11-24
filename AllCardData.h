//-----------------------------------------------------------
// AllCardData.h
// 全カードデータ
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "CardData.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

class AllCardData {
private:
    CardData card[100];
public:
    AllCardData();                 // コンストラクタ
    ~AllCardData();                // デストラクタ
    void init();                   // 初期化
    void update();                 // 更新
    bool readCardData();           // カードデータ読み込み

    CardData *getCardData(int);    // カードデータ取得
};