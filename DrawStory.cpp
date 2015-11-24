//-----------------------------------------------------------
// DrawStory.cpp
// ストーリー画面の描画
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#include "DrawStory.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
DrawStory::DrawStory(GameData *data, GameState *state)
{
    game_state = state;
    game_data = data;
    story_state = state->getSceneState()->getStoryState();
    font = CreateFontToHandle("MSゴシック", 20, 5, DX_FONTTYPE_ANTIALIASING_EDGE);
    color_white = GetColor(255, 255, 255);
    loadImage();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
DrawStory::~DrawStory()
{

}

//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void DrawStory::init()
{
}

//-----------------------------------------------------------
// 更新
//-----------------------------------------------------------
void DrawStory::update()
{
    
}

//-----------------------------------------------------------
// 画像読み込み
//-----------------------------------------------------------
void DrawStory::loadImage()
{
    handl_back = LoadGraph("image/story/back.png");
    handl_window = LoadGraph("image/story/window.png");
    LoadDivGraph("image/story/button.png", 8, 4, 2,
        StoryData::BUTTON_SIZE_X, StoryData::BUTTON_SIZE_Y, handl_button);
    LoadDivGraph("image/story/button_close.png", 2, 2, 1,
        StoryData::BUTTON_CLOSE_SIZE_X, StoryData::BUTTON_CLOSE_SIZE_Y, handl_button_close);
    handl_back_log = LoadGraph("image/story/back_log.png");
    LoadDivGraph("image/story/button_back.png", 2, 2, 1,
        StoryData::BACKLOG_BUTTON_BACK_SIZE_X, StoryData::BACKLOG_BUTTON_BACK_SIZE_Y, handl_button_back);
    handl_bar_area = LoadGraph("image/story/bar_area.png");
    handl_bar = LoadGraph("image/story/bar.png");
}

//-----------------------------------------------------------
// 描画
//-----------------------------------------------------------
void DrawStory::draw()
{
    //---- 背景描画
    DrawGraph(0, 0, handl_back, TRUE);

    //---- テキストウインドウ描画
    if (story_state->isClose() == false && story_state->isBackLog() == false) {
        DrawGraph(         // ベース
            StoryData::WINDOW_POS_X,
            StoryData::WINDOW_POS_Y,
            handl_window, TRUE);
        drawButton();      // ボタン描画
        drawText();        // テキスト描画
    }
    //----- バックログ表示
    if (story_state->isBackLog()) {
        drawBackLog();
    }
}

//-----------------------------------------------------------
// ボタン描画
//-----------------------------------------------------------
void DrawStory::drawButton()
{
    int image;
    int obj = story_state->getMousePosObject();
    // オート
    image = 0 + (obj == StoryState::BUTTON_AUTO) ? 4 : 0;
    image = (story_state->isAuto()) ? 4 : image;
    DrawGraph(
        StoryData::BUTTON_POS_X,
        StoryData::BUTTON_POS_Y + StoryData::BUTTON_SIZE_Y * 0,
        handl_button[image],
        TRUE);
    // スキップ
    DrawGraph(
        StoryData::BUTTON_POS_X,
        StoryData::BUTTON_POS_Y + StoryData::BUTTON_SIZE_Y * 1,
        handl_button[1 + ((obj == StoryState::BUTTON_SKIP) ? 4 : 0)],
        TRUE);
    // ログ
    DrawGraph(
        StoryData::BUTTON_POS_X,
        StoryData::BUTTON_POS_Y + StoryData::BUTTON_SIZE_Y * 2,
        handl_button[2 + ((obj == StoryState::BUTTON_LOG) ? 4 : 0)],
        TRUE);
    // コンフィグ
    DrawGraph(
        StoryData::BUTTON_POS_X,
        StoryData::BUTTON_POS_Y + StoryData::BUTTON_SIZE_Y * 3,
        handl_button[3 + ((obj == StoryState::BUTTON_CONFIG) ? 4 : 0)],
        TRUE);
    // 閉じる
    DrawGraph(
        StoryData::BUTTON_CLOSE_POS_X,
        StoryData::BUTTON_CLOSE_POS_Y,
        handl_button_close[((obj == StoryState::BUTTON_CLOSE) ? 1 : 0)],
        TRUE);
}

//-----------------------------------------------------------
// テキスト描画
//-----------------------------------------------------------
void DrawStory::drawText()
{
    //---- 名前
    if (story_state->getNowName() != "") {
        DrawFormatStringToHandle(
            StoryData::TEXT_AREA_POS_X - 20,
            StoryData::TEXT_AREA_POS_Y - 20,
            color_white,
            font,
            "【%s】",
            story_state->getNowName().c_str());
    }
    //---- 1行目
    DrawFormatStringToHandle(
        StoryData::TEXT_AREA_POS_X,
        StoryData::TEXT_AREA_POS_Y + 10,
        color_white,
        font,
        "%s",
        story_state->getNowText1().c_str());
    //---- 2行目
    DrawFormatStringToHandle(
        StoryData::TEXT_AREA_POS_X,
        StoryData::TEXT_AREA_POS_Y + 30 + 10,
        color_white,
        font,
        "%s",
        story_state->getNowText2().c_str());
    //---- 3行目
    DrawFormatStringToHandle(
        StoryData::TEXT_AREA_POS_X,
        StoryData::TEXT_AREA_POS_Y + 60 + 10,
        color_white,
        font,
        "%s",
        story_state->getNowText3().c_str());
}
void DrawStory::drawLogText(int x, int y, StoryTextData* text)
{
    //---- 名前
    if (text->getNmae() != "") {
        DrawFormatStringToHandle(
            x - 20,
            y - 20,
            color_white,
            font,
            "【%s】",
            text->getNmae().c_str());
    }
    //---- 1行目
    DrawFormatStringToHandle(
        x,
        y + 10,
        color_white,
        font,
        "%s",
        text->getText1().c_str());
    //---- 2行目
    DrawFormatStringToHandle(
        x,
        y + 40,
        color_white,
        font,
        "%s",
        text->getText2().c_str());
    //---- 3行目
    DrawFormatStringToHandle(
        x,
        y + 70,
        color_white,
        font,
        "%s",
        text->getText3().c_str());
}

//-----------------------------------------------------------
// バックログ描画
//-----------------------------------------------------------
void DrawStory::drawBackLog()
{
    int n = story_state->getBacklogPos();
    int obj = story_state->getMousePosObject();
    int image;
    // ベース
    DrawGraph(0, 0, handl_back_log, TRUE);
    // もどるボタン
    image = (obj == StoryState::BUTTON_BACK) ? 1 : 0;
    DrawGraph(
        StoryData::BACKLOG_BUTTON_BACK_POS_X,
        StoryData::BACKLOG_BUTTON_BACK_POS_Y,
        handl_button_back[image], TRUE);
    // スクロールバーエリア
    DrawGraph(
        StoryData::BACKLOG_BAR_AREA_POS_X,
        StoryData::BACKLOG_BAR_AREA_POS_Y,
        handl_bar_area, TRUE);
    // スクロールバー
    DrawGraph(
        StoryData::BACKLOG_BAR_AREA_POS_X + 1,
        story_state->getBarPosY(),
        handl_bar, TRUE);
    // テキスト
    if (n >= 1) {
        int t1 = n - 2;
        if (n <= 2) t1 = 1;
        drawLogText(
            StoryData::BACKLOG_TEXT_AREA_POS_X,
            StoryData::BACKLOG_BAR_AREA_POS_Y + 50,
            game_data->getAllStoryTextData()->getStoryTextData(t1));
    }
    if (n >= 2) {
        int t2 = n - 1;
        if (n == 2) t2 = 2;
        drawLogText(
            StoryData::BACKLOG_TEXT_AREA_POS_X,
            StoryData::BACKLOG_BAR_AREA_POS_Y + 200,
            game_data->getAllStoryTextData()->getStoryTextData(t2));
    }
    if (n >= 3) {
        drawLogText(
            StoryData::BACKLOG_TEXT_AREA_POS_X,
            StoryData::BACKLOG_BAR_AREA_POS_Y + 350,
            game_data->getAllStoryTextData()->getStoryTextData(n));
    }
}

//===========================================================
// getter
//===========================================================