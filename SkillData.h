//-----------------------------------------------------------
// SkillData.h
// スキル情報
// 制作日 2015.03.14
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include <string>

class SkillData {
public:
    static const int LINE_TEXT_NUM = 20;
private:
    std::string text[100];      // スキル説明
public:
    SkillData();                      // コンストラクタ
    ~SkillData();                     // デストラクタ
    std::string getSkillText1(int n);  // 1行目取得
    std::string getSkillText2(int n);  // 2行目取得
};