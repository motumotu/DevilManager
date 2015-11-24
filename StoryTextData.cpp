//-----------------------------------------------------------
// StoryTextData.cpp
// 全ストーリーテキストデータ
// 制作日 2015.03.24
// 制作者 motumotu
//-----------------------------------------------------------
#include "StoryTextData.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
StoryTextData::StoryTextData()
{
    
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
StoryTextData::~StoryTextData()
{

}

//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void StoryTextData::init()
{
    num = 0;              // 番号
    next_num = 0;         // 次の番号
    name = "";            // 名前
    text1 = "";           // テキスト１
    text2 = "";           // テキスト２
    text3 = "";           // テキスト３
}


//-----------------------------------------------------------
// setter
//-----------------------------------------------------------
void StoryTextData::setNum(int n) { num = n; }
void StoryTextData::setnextNum(int n) { next_num = n; }
void StoryTextData::setName(std::string n) { name = n; }
void StoryTextData::setText1(std::string n) { text1 = n; }
void StoryTextData::setText2(std::string n) { text2 = n; }
void StoryTextData::setText3(std::string n) { text3 = n; }

//-----------------------------------------------------------
// getter
//-----------------------------------------------------------
int StoryTextData::getNum() { return num; }
int StoryTextData::getNextNum() { return next_num; }
std::string StoryTextData::getNmae() { return name; }
std::string StoryTextData::getText1() { return text1; }
std::string StoryTextData::getText2() { return text2; }
std::string StoryTextData::getText3() { return text3; }
