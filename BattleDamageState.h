//-----------------------------------------------------------
// BattleDamageState.h
// ダメージの状態
// 制作日 2015.03.04
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include <algorithm>

class BattleDamageState {
public:
    static const int DISPLAY_TIME = 30;  // 表示時間
    static const int WHICH_MY = 0;     // 自分
    static const int WHICH_ENE = 1;    // 相手
private:
    int damage;                // ダメージ
    int cnt_frame;             // 経過フレーム
    int x;                     // x座標
    int y;                     // y座標
    int which;                 // どっちが受けたダメージか
public:
    BattleDamageState(int, int, int, int); // コンストラクタ
    ~BattleDamageState();      // デストラクタ
    void update();             // 更新
    bool isDelete();           // 消えるべきか
    int getDamage();           // ダメージ
    int getCntFrame();         // 経過フレーム
    int getX();
    int getY();
    int getWhich();
    int getDamageDigits();      // 桁数
};