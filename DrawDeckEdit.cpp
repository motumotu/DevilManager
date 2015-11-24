//-----------------------------------------------------------
// DrawDeckEdit.cpp
// デッキ編集画面の描画
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#include "DrawDeckEdit.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
DrawDeckEdit::DrawDeckEdit(GameData *data, GameState *state)
{
    game_data = data;
    game_state = state;
    deck_edit_state = state->getSceneState()->getDeckEditState();
    input_state = state->getInputState();
    save_data = data->getSaveData();
    // フォント作成
    font_10 = CreateFontToHandle("PixelMplus10", 10, 1, DX_FONTTYPE_NORMAL);
    font_12 = CreateFontToHandle("PixelMplus12", 12, -1, DX_FONTTYPE_NORMAL);
    // 画像読み込み
    loadImage();
    // 色
    color_black = GetColor(0, 0, 0);
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
DrawDeckEdit::~DrawDeckEdit()
{
    DeleteFontToHandle(font_10);
    DeleteFontToHandle(font_12);
}

//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void DrawDeckEdit::init()
{
}

//-----------------------------------------------------------
// 更新
//-----------------------------------------------------------
void DrawDeckEdit::update()
{
}

//-----------------------------------------------------------
// 画像読み込み
//-----------------------------------------------------------
void DrawDeckEdit::loadImage()
{
    handl_back = LoadGraph("image/deck_edit/back.png");
    handl_back1 = LoadGraph("image/deck_edit/back1.png");
    handl_back2 = LoadGraph("image/deck_edit/back2.png");
    LoadDivGraph("image/deck_edit/button_back.png", 2, 1, 2,
        DeckEditData::BUTTON_BACK_SIZE_X, DeckEditData::BUTTON_BACK_SIZE_Y, handl_button_back);
    handl_bar = LoadGraph("image/deck_edit/bar.png");
}

//-----------------------------------------------------------
// 描画
//-----------------------------------------------------------
void DrawDeckEdit::draw()
{
    int obj = deck_edit_state->getMousePosObject();
    DrawGraph(0, 0, handl_back, TRUE);
    drawDeckArea();   // デッキエリア
    drawCardList();   // カード一覧
    drawBar();        // バーの描画
    // カード説明
    int n = deck_edit_state->getMousePosCard();
    if (n > 0)
        drawCardIntro(game_data->getAllCardData()->getCardData(n));
    DrawGraph(        // 戻るボタン
        DeckEditData::BUTTON_BACK_POS_X,
        DeckEditData::BUTTON_BACK_POS_Y,
        handl_button_back[((obj == DeckEditState::BUTTON_BACK) ? 1 : 0)], TRUE);
    drawSelectNowCard(); // 現在選択中のカード描画
}

//-----------------------------------------------------------
// デッキエリア描画
//-----------------------------------------------------------
void DrawDeckEdit::drawDeckArea()
{
    int n = game_state->getSceneState()->getDeckListState()->getSelectDeckNum();
    DeckData *deck = save_data->getDeckData(n);
    for (int i = 0; i < deck->getCardNum(); i++) {
        DrawGraph(
            DeckEditData::DECK_AREA_POS_X + (i % 10) * 33,
            DeckEditData::DECK_AREA_POS_Y + (i / 10) * 46,
            game_data->getImageData()->getCardMini(deck->getCard(i)),
            TRUE);
    }
}

//-----------------------------------------------------------
// カード説明描画
//-----------------------------------------------------------
void DrawDeckEdit::drawCardIntro(CardData* card)
{
    int x = DeckEditData::CARD_INTRO_AREA_POS_X;
    int y = DeckEditData::CARD_INTRO_AREA_POS_Y;

    // イラスト
    int t = (card->name != "拠点") ? 8 : 0;
    DrawGraph(
        x + 43 - card->image_size_x / 2,
        y + 60 - card->image_size_y / 2,
        game_data->getImageData()->getMonster(card->id, t), TRUE);
    // 名前
    DrawFormatStringToHandle(x + 92, y + 28, color_black, font_12, "%s", card->name.c_str(), font_12);
    // 種類
    // 属性
    //---- 魔力
    t = (card->mp / 10 <= 0) ? 0 : -3;
    DrawFormatStringToHandle(x + 202 + t, y + 73, color_black, font_12, "%d", card->mp);
    // 攻撃力
    DrawFormatStringToHandle(x + 58, y + 136, color_black, font_12, "%d", card->pow);
    // 守備力
    DrawFormatStringToHandle(x + 172, y + 136, color_black, font_12, "%d", card->def);
    // 移動速度
    DrawFormatStringToHandle(x + 58, y + 165, color_black, font_12, "%d", card->move_speed);
    // 攻撃速度
    DrawFormatStringToHandle(x + 172, y + 165, color_black, font_12, "%d", card->attack_speed);
    // 索敵範囲
    DrawFormatStringToHandle(x + 58, y + 194, color_black, font_12, "%d", card->search_range);
    // 体力
    DrawFormatStringToHandle(x + 172, y + 194, color_black, font_12, "%d", card->hp);
    //---- 属性
    DrawFormatStringToHandle(x + 40, y + 247, color_black, font_12, "%d", card->fire);
    DrawFormatStringToHandle(x + 117, y + 247, color_black, font_12, "%d", card->water);
    DrawFormatStringToHandle(x + 194, y + 247, color_black, font_12, "%d", card->ice);
    DrawFormatStringToHandle(x + 40, y + 266, color_black, font_12, "%d", card->elect);
    DrawFormatStringToHandle(x + 117, y + 266, color_black, font_12, "%d", card->dark);
    DrawFormatStringToHandle(x + 194, y + 266, color_black, font_12, "%d", card->light);
    DrawFormatStringToHandle(x + 40, y + 285, color_black, font_12, "%d", card->earth);
    DrawFormatStringToHandle(x + 117, y + 285, color_black, font_12, "%d", card->poison);
    DrawFormatStringToHandle(x + 194, y + 285, color_black, font_12, "%d", card->wind);
    //---- スキル
    for (int i = 0; i < (int)card->skil.size(); i++) {
        int n = card->skil[i];
        DrawFormatStringToHandle(x + 28, y + 338 + i * 38, color_black, font_10,
            "%s", game_data->getSkillData()->getSkillText1(n).c_str());
        DrawFormatStringToHandle(x + 28, y + 351 + i * 38, color_black, font_10,
            "%s", game_data->getSkillData()->getSkillText2(n).c_str());
    }
}

//-----------------------------------------------------------
// カードリストの描画
//-----------------------------------------------------------
void DrawDeckEdit::drawCardList()
{
    for (int i = 0; i < save_data->getHaveCardNum(); i++) {
        int n = save_data->getHaveCardData()->getCard(i);
        DrawGraph(
            DeckEditData::CARD_AREA_POS_X + (i % 5) * DeckEditData::CARD_SIZE_X,
            DeckEditData::CARD_AREA_POS_Y + (i / 5) * DeckEditData::CARD_SIZE_Y - deck_edit_state->getShiftPosY(),
            game_data->getImageData()->getCardMini(n), TRUE);
    }
    DrawGraph(DeckEditData::CARD_AREA_POS_X, 0, handl_back1, TRUE);
    DrawGraph(DeckEditData::CARD_AREA_POS_X, 576, handl_back2, TRUE);
}

//-----------------------------------------------------------
// バー描画
//-----------------------------------------------------------
void DrawDeckEdit::drawBar()
{
    if (save_data->getHaveCardNum() > 50 || deck_edit_state->getShiftPosY() > 0) {
        DrawGraph(
            DeckEditData::BAR_AREA_POS_X,
            deck_edit_state->getBarPosY(),
            handl_bar, TRUE);
    }
}

//-----------------------------------------------------------
// 選択中のカード描画
//-----------------------------------------------------------
void DrawDeckEdit::drawSelectNowCard()
{
    int n = deck_edit_state->getSelectNowCard();
    if (n == 0) return;
    DrawGraph(
        input_state->getPointX() - DeckEditData::CARD_SIZE_X / 2,
        input_state->getPointY() - DeckEditData::CARD_SIZE_Y / 2,
        game_data->getImageData()->getCardMini(n), TRUE);
}


//===========================================================
// getter
//===========================================================
