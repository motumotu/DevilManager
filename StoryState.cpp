//-----------------------------------------------------------
// StoryState.h
// ストーリーの状態
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#include "StoryState.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
StoryState::StoryState(GameData *data)
{
    game_data = data;
    init();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
StoryState::~StoryState()
{

}

//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void StoryState::init()
{
    now_text_num = 1;
    cnt_frame = 0;
    now_text_len = 0;
    is_draw_end = false;
    is_close = false;
    is_auto = false;
    is_next_text = false;
    is_back_log = false;
    backlog_pos = 1;
    AdjustingBar();
}

//-----------------------------------------------------------
// 更新
//-----------------------------------------------------------
void StoryState::update()
{
    cnt_frame++;
    // 描画終了していないならテキスト更新
    if (is_draw_end == false) {
        now_text_len += isJapaneseCharacter(getNowText()[now_text_len]);
        if (now_text_len >= getNowText().length()) fullText();
    }
    // オートのとき、次の文に行くか判定
    if (is_auto == true && is_draw_end == true && cnt_frame >= 30) {
        is_next_text = true;
    }
}

//-----------------------------------------------------------
// マウス座標更新
//-----------------------------------------------------------
void StoryState::updateMousePos(int x, int y)
{
    mouse_x = x;
    mouse_y = y;
}
//-----------------------------------------------------------
// 現在の名前取得
//-----------------------------------------------------------
std::string StoryState::getNowName()
{
    return getNowStoryTextData()->getNmae();
}

//-----------------------------------------------------------
// 現在のテキスト１取得
//-----------------------------------------------------------
std::string StoryState::getNowText1()
{
    int len1 = (int)getNowStoryTextData()->getText1().length();
    if (now_text_len >= len1) {
        return getNowStoryTextData()->getText1();
    }
    return getNowStoryTextData()->getText1().substr(0, now_text_len);
}

//-----------------------------------------------------------
// マウス座標の物体取得
//-----------------------------------------------------------
std::string StoryState::getNowText2()
{
    int len1 = (int)getNowStoryTextData()->getText1().length();
    int len2 = (int)getNowStoryTextData()->getText2().length();
    if (now_text_len >= len1 + len2) {
        return getNowStoryTextData()->getText2();
    }
    else if (now_text_len <= len1) {
        return "";
    }
    return getNowStoryTextData()->getText2().substr(0, now_text_len - len1);
}

//-----------------------------------------------------------
// マウス座標の物体取得
//-----------------------------------------------------------
std::string StoryState::getNowText3()
{
    int len1 = (int)getNowStoryTextData()->getText1().length();
    int len2 = (int)getNowStoryTextData()->getText2().length();
    int len3 = (int)getNowStoryTextData()->getText3().length();
    if (now_text_len >= len1 + len2 + len3) {
        return getNowStoryTextData()->getText3();
    }
    else if (now_text_len <= len1 + len2) {
        return "";
    }
    return getNowStoryTextData()->getText3().substr(0, now_text_len - len1 - len2);
}

//-----------------------------------------------------------
// 日本語かどうか
//-----------------------------------------------------------
int StoryState::isJapaneseCharacter(unsigned char code)
{
    // shift_jisなら1
    if ((code >= 0x81 && code <= 0x9F) ||
        (code >= 0xE0 && code <= 0xFC)) {
        return 2;
    }
    return 1;
}

//-----------------------------------------------------------
// 次のテキストに
//-----------------------------------------------------------
void StoryState::changeNextText()
{
    now_text_num = getNowStoryTextData()->getNextNum();
    now_text_len = 0;
    cnt_frame = 0;
    is_draw_end = false;
    is_next_text = false;
    backlog_pos = now_text_num;
}

//-----------------------------------------------------------
// 全文表示
//-----------------------------------------------------------
void StoryState::fullText()
{
    is_draw_end = true;
    cnt_frame = 0;
    now_text_len = getNowText().length();
}

//-----------------------------------------------------------
// マウス座標の物体取得
//-----------------------------------------------------------
int StoryState::getMousePosObject()
{
    if (isPosButtonAuto(mouse_x, mouse_y) && is_back_log == false) return BUTTON_AUTO;
    if (isPosButtonSkip(mouse_x, mouse_y) && is_back_log == false) return BUTTON_SKIP;
    if (isPosButtonLog(mouse_x, mouse_y) && is_back_log == false) return BUTTON_LOG;
    if (isPosButtonConfig(mouse_x, mouse_y) && is_back_log == false) return BUTTON_CONFIG;
    if (isPosButtonClose(mouse_x, mouse_y) && is_back_log == false) return BUTTON_CLOSE;
    if (isPosButtonBack(mouse_x, mouse_y) && is_back_log == true) return BUTTON_BACK;
    if (isPosBarArea(mouse_x, mouse_y) && is_back_log == true) return BAR_AREA;
    return NONE;
}

//-----------------------------------------------------------
// 座標
//-----------------------------------------------------------
bool StoryState::isPosButtonAuto(int x, int y) {
    int px = StoryData::BUTTON_POS_X;
    int py = StoryData::BUTTON_POS_Y;
    int sx = StoryData::BUTTON_SIZE_X;
    int sy = StoryData::BUTTON_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}
bool StoryState::isPosButtonSkip(int x, int y) {
    int px = StoryData::BUTTON_POS_X;
    int py = StoryData::BUTTON_POS_Y + StoryData::BUTTON_SIZE_Y;
    int sx = StoryData::BUTTON_SIZE_X;
    int sy = StoryData::BUTTON_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}
bool StoryState::isPosButtonLog(int x, int y) {
    int px = StoryData::BUTTON_POS_X;
    int py = StoryData::BUTTON_POS_Y + StoryData::BUTTON_SIZE_Y * 2;
    int sx = StoryData::BUTTON_SIZE_X;
    int sy = StoryData::BUTTON_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}
bool StoryState::isPosButtonConfig(int x, int y) {
    int px = StoryData::BUTTON_POS_X;
    int py = StoryData::BUTTON_POS_Y + StoryData::BUTTON_SIZE_Y * 3;
    int sx = StoryData::BUTTON_SIZE_X;
    int sy = StoryData::BUTTON_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}
bool StoryState::isPosButtonClose(int x, int y) {
    int px = StoryData::BUTTON_CLOSE_POS_X;
    int py = StoryData::BUTTON_CLOSE_POS_Y;
    int sx = StoryData::BUTTON_CLOSE_SIZE_X;
    int sy = StoryData::BUTTON_CLOSE_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}
bool StoryState::isPosButtonBack(int x, int y) {
    int px = StoryData::BACKLOG_BUTTON_BACK_POS_X;
    int py = StoryData::BACKLOG_BUTTON_BACK_POS_Y;
    int sx = StoryData::BACKLOG_BUTTON_BACK_SIZE_X;
    int sy = StoryData::BACKLOG_BUTTON_BACK_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}
bool StoryState::isPosBarArea(int x, int y) {
    int px = StoryData::BACKLOG_BAR_AREA_POS_X;
    int py = StoryData::BACKLOG_BAR_AREA_POS_Y;
    int sx = StoryData::BACKLOG_BAR_AREA_SIZE_X;
    int sy = StoryData::BACKLOG_BAR_AREA_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}

//-----------------------------------------------------------
//  バーの位置取得
//-----------------------------------------------------------
int StoryState::getBarPosY()
{
    return bar_pos;
}

//-----------------------------------------------------------
//  バーの位置調整
//-----------------------------------------------------------
void StoryState::AdjustingBar()
{
    int len = StoryData::BACKLOG_BAR_AREA_SIZE_Y - 2;
    len -= StoryData::BACKLOG_BAR_SIZE_Y;
    if (now_text_num > 3) {
        len = (int)(len * ((double)(backlog_pos - 3) / (now_text_num - 3)));
    }
    bar_pos = StoryData::BACKLOG_BAR_AREA_POS_Y + len + 1;
}

//-----------------------------------------------------------
//  バーのマウス位置変更
//-----------------------------------------------------------
void StoryState::changeBarMousePos()
{
    /*
    if (now_text_num <= 3) return;

    int y1 = StoryData::BACKLOG_BAR_AREA_POS_Y + StoryData::BACKLOG_BAR_SIZE_Y / 2;
    int y2 = y1 + StoryData::BACKLOG_BAR_AREA_SIZE_Y - StoryData::BACKLOG_BAR_SIZE_Y;

    if (mouse_y < y1) {
        bar_pos = y1 - StoryData::BACKLOG_BAR_SIZE_Y / 2;
    }
    else if (mouse_y > y2) {
        bar_pos = y2 - StoryData::BACKLOG_BAR_SIZE_Y;
    }
    else {
        bar_pos = mouse_y - StoryData::BACKLOG_BAR_SIZE_Y / 2;
    }

    int t = (StoryData::BACKLOG_BAR_AREA_SIZE_Y - 2 - StoryData::BACKLOG_BAR_SIZE_Y);
    int t2 = (bar_pos - StoryData::BACKLOG_BAR_AREA_POS_Y - 1);
    backlog_pos = (int)((double)t2 / t * (now_text_num - 3) + 3);
    */
}

//-----------------------------------------------------------
//  バックログを上に
//-----------------------------------------------------------
void StoryState::backlogUp()
{
    // 最大まで行ってたら
    if (backlog_pos <= 3) {
        return;
    }
    backlog_pos--;
    AdjustingBar();
}

//-----------------------------------------------------------
//  バックログを下に
//-----------------------------------------------------------
void StoryState::backlogDown()
{
    // バックログをさらに下にしたら 消す
    if (backlog_pos == now_text_num) {
        is_back_log = false;
        return;
    }
    backlog_pos++;
    AdjustingBar();
}


//===========================================================
// setter
//===========================================================
void StoryState::setNowTextNum(int n) { now_text_num = n; }
void StoryState::setIsClose(bool n) { is_close = n; }
void StoryState::setIsAuto(bool n) { is_auto = n; }
void StoryState::setIsBackLog(bool n) { is_back_log = n; }

//===========================================================
// getter
//===========================================================
int StoryState::getNowTextNum() { return now_text_num; }
StoryTextData *StoryState::getNowStoryTextData() {
    return game_data->getAllStoryTextData()->getStoryTextData(now_text_num);
}
std::string StoryState::getNowText() {
    std::string s = getNowStoryTextData()->getText1();
    s += getNowStoryTextData()->getText2();
    s += getNowStoryTextData()->getText3();
    return s;
}
bool StoryState::isDrawEnd() { return is_draw_end; }
bool StoryState::isClose() { return is_close; }
bool StoryState::isAuto() { return is_auto; }
bool StoryState::isNextText() { return is_next_text; }
bool StoryState::isBackLog() { return is_back_log; }
int StoryState::getBacklogPos() { return backlog_pos; }