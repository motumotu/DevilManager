//-----------------------------------------------------------
// StoryTextData.h
// ストーリーテキストデータ
// 制作日 2015.03.24
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include <string>

class StoryTextData {
public:
private:
    int num;              // 番号
    int next_num;         // 次の番号
    std::string name;     // 名前
    std::string text1;    // テキスト１
    std::string text2;    // テキスト２
    std::string text3;    // テキスト３
public:
    StoryTextData();    // コンストラクタ
    ~StoryTextData();   // デストラクタ
    void init();        // 初期処理
    //---- setter
    void setNum(int);
    void setnextNum(int);
    void setName(std::string);
    void setText1(std::string);
    void setText2(std::string);
    void setText3(std::string);

    //---- getter
    int getNum();
    int getNextNum();
    std::string getNmae();
    std::string getText1();
    std::string getText2();
    std::string getText3();
};