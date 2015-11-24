//-----------------------------------------------------------
// StorySelectState.h
// ストーリー選択画面の状態
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#include "StorySelectState.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
StorySelectState::StorySelectState(GameData* data)
{
    game_data = data;
    save_data = data->getSaveData();
    init();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
StorySelectState::~StorySelectState()
{

}
//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void StorySelectState::init()
{
    deck_num = 1;      // 選択デッキ番号
    story_num = 1;     // 選択ストーリー番号
    chapter_num = 1;   // 選択チャプター番号
}

//-----------------------------------------------------------
// 更新処理
//-----------------------------------------------------------
void StorySelectState::update()
{

}

//-----------------------------------------------------------
// マウス座標更新処理
//-----------------------------------------------------------
void StorySelectState::updateMousePos(int x, int y)
{
    mouse_x = x;
    mouse_y = y;
}

//-----------------------------------------------------------
// デッキ操作
//-----------------------------------------------------------
void StorySelectState::deckSelectLeft()
{
    deck_num--;
    if (deck_num <= 0) deck_num = save_data->getDeckNum();
}
void StorySelectState::deckSekectRight()
{
    deck_num++;
    if (deck_num > save_data->getDeckNum()) deck_num = 1;
}

//-----------------------------------------------------------
// デッキ操作
//-----------------------------------------------------------
void StorySelectState::selectStory(int n)
{
    story_num = n;
}

//-----------------------------------------------------------
// マウス座標位置の物体取得
//-----------------------------------------------------------
int StorySelectState::getMousePosObject()
{
    return getPosObject(mouse_x, mouse_y);
}

//-----------------------------------------------------------
// マウス座標位置の物体取得
//-----------------------------------------------------------
int StorySelectState::getPosObject(int x, int y)
{
    if (isPosButtonBack(x, y)) return BUTTON_BACK;
    if (isPosButtonDecision(x, y)) return BUTTON_DECISION;
    if (isPosDeckSelectLeft(x, y)) return DECK_SELECT_LEFT;
    if (isPosDeckSelectRight(x, y)) return DECK_SELECT_RIGHT;
    if (isPosStoryArea(x, y)) return STORY_AREA;
    if (isPosDeckArea(x, y)) return DECK_AREA;
    return NONE;
}

//-----------------------------------------------------------
// 座標
//-----------------------------------------------------------
bool StorySelectState::isPosButtonBack(int x, int y) {
    int px = StorySelectData::BUTTON_BACK_POS_X;
    int py = StorySelectData::BUTTON_BACK_POS_Y;
    int sx = StorySelectData::BUTTON_BACK_SIZE_X;
    int sy = StorySelectData::BUTTON_BACK_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}
bool StorySelectState::isPosButtonDecision(int x, int y) {
    int px = StorySelectData::BUTTON_DECISION_POS_X;
    int py = StorySelectData::BUTTON_DECISION_POS_Y;
    int sx = StorySelectData::BUTTON_DECISION_SIZE_X;
    int sy = StorySelectData::BUTTON_DECISION_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}
bool StorySelectState::isPosDeckSelectLeft(int x, int y) {
    int px = StorySelectData::DECK_SELECT_LEFT_POS_X;
    int py = StorySelectData::DECK_SELECT_LEFT_POS_Y;
    int sx = StorySelectData::DECK_SELECT_SIZE_X;
    int sy = StorySelectData::DECK_SELECT_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}
bool StorySelectState::isPosDeckSelectRight(int x, int y) {
    int px = StorySelectData::DECK_SELECT_RIGHT_POS_X;
    int py = StorySelectData::DECK_SELECT_RIGHT_POS_Y;
    int sx = StorySelectData::DECK_SELECT_SIZE_X;
    int sy = StorySelectData::DECK_SELECT_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}
bool StorySelectState::isPosStoryArea(int x, int y) {
    int px = StorySelectData::STORY_AREA_POS_X;
    int py = StorySelectData::STORY_AREA_POS_Y;
    int sx = StorySelectData::STORY_AREA_SIZE_X;
    int sy = StorySelectData::STORY_AREA_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}
bool StorySelectState::isPosDeckArea(int x, int y) {
    int px = StorySelectData::DECK_AREA_POS_X;
    int py = StorySelectData::DECK_AREA_POS_Y;
    int sx = StorySelectData::DECK_AREA_SIZE_X;
    int sy = StorySelectData::DECK_AREA_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}
//-----------------------------------------------------------
// 座標
//-----------------------------------------------------------
int StorySelectState::getMousePosStory()
{
    for (int n = 0; n < getNowChapterStoryNum(); n++) {
        int x = StorySelectData::STORY_AREA_POS_X + (StorySelectData::STORY_SIZE_X + 15) * (n % 3);
        int y = StorySelectData::STORY_AREA_POS_Y + (StorySelectData::STORY_SIZE_Y + 35) * (n / 3);
        if (mouse_x >= x && mouse_x <= x + StorySelectData::STORY_SIZE_X &&
            mouse_y >= y && mouse_y <= y + StorySelectData::STORY_SIZE_Y) return n + 1;
    }
    return 0;
}

//-----------------------------------------------------------
// getter
//-----------------------------------------------------------
int StorySelectState::getDeckNum() { return deck_num; }
int StorySelectState::getStoryNum() { return story_num; }
int StorySelectState::getChapterNum() { return chapter_num; }
int StorySelectState::getNowChapterStoryNum() {
    int n = 0;
    switch (chapter_num) {
    case 1: n = StorySelectData::STORY_NUM_1; break;
    }
    return n;
}