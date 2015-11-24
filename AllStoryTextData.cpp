//-----------------------------------------------------------
// AllStoryTextData.cpp
// 全ストーリーテキストデータ
// 制作日 2015.03.24
// 制作者 motumotu
//-----------------------------------------------------------
#include "AllStoryTextData.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
AllStoryTextData::AllStoryTextData()
{
    for (int i = 0; i < 100; i++) {
        story_text_data[i] = NULL;
    }
    loadData();     // データ読み込み
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
AllStoryTextData::~AllStoryTextData()
{
    for (int i = 0; i < 100; i++) {
        if (story_text_data[i] != NULL) {
            delete(story_text_data[i]);
            story_text_data[i] = NULL;
        }
    }
}

//-----------------------------------------------------------
// データ読み込み
//-----------------------------------------------------------
void AllStoryTextData::loadData()
{
    char str[1024];
    std::string s;
    std::stringstream ss;
    int num;
    int fp = FileRead_open("dat/story_text.dat");
    // ファイル読み込み失敗
    if (fp == 0) {
        puts("story_text.datファイル読み込み失敗");
        return;
    }
    // ファイル読み込み処理
    while (FileRead_gets(str, 256, fp) != -1) {
        ss.clear();
        ss.str(str);
        ss >> s;
        //---- 番号
        if (s == "#NUM") {
            ss >> s;
            num = atoi(s.c_str());
            story_text_data[num] = new StoryTextData();
            story_text_data[num]->setNum(num);
        }
        //---- 名前
        if (s == "#NAME") {
            ss >> s;
            story_text_data[num]->setName(s);
        }
        //---- テキスト1
        if (s == "#TEXT1") {
            ss >> s;
            story_text_data[num]->setText1(s);
        }
        //---- テキスト2
        if (s == "#TEXT2") {
            ss >> s;
            story_text_data[num]->setText2(s);
        }
        //---- テキスト3
        if (s == "#TEXT3") {
            ss >> s;
            story_text_data[num]->setText3(s);
        }
        //---- 次
        if (s == "#NEXT") {
            ss >> s;
            story_text_data[num]->setnextNum(atoi(s.c_str()));
        }
    }

    FileRead_close(fp);
}

//-----------------------------------------------------------
// データ取得
//-----------------------------------------------------------
StoryTextData *AllStoryTextData::getStoryTextData(int n) {
    return story_text_data[n];
}