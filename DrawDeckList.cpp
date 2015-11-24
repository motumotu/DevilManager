//-----------------------------------------------------------
// DrawDeckList.cpp
// デッキ一覧画面の描画
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#include "DrawDeckList.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
DrawDeckList::DrawDeckList(GameData *data, GameState *state)
{
    game_data = data;
    game_state = state;
    deck_list_state = state->getSceneState()->getDeckListState();
    deck_list_data = data->getDeckListData();
    input_state = state->getInputState();
    save_data = data->getSaveData();
    image_data = data->getImageData();
    font = CreateFontToHandle("PixelMplus12", 12, 1, DX_FONTTYPE_NORMAL);
    color_black = GetColor(0, 0, 0);
    loadImage();
    init();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
DrawDeckList::~DrawDeckList()
{
}

//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void DrawDeckList::init()
{
    ChangeFont("PixelMplus12", DX_CHARSET_DEFAULT);
    SetFontSize(12);
    SetFontThickness(1);
}

//-----------------------------------------------------------
// 更新
//-----------------------------------------------------------
void DrawDeckList::update()
{
}

//-----------------------------------------------------------
// 画像読み込み
//-----------------------------------------------------------
void DrawDeckList::loadImage()
{
    handl_back = LoadGraph("image/deck_list/back.png");
    handl_back1 = LoadGraph("image/deck_list/back1.png");
    handl_back2 = LoadGraph("image/deck_list/back2.png");
    handl_bar = LoadGraph("image/deck_list/bar.png");
    handl_bar_up = LoadGraph("image/deck_list/bar_up.png");
    handl_bar_down = LoadGraph("image/deck_list/bar_down.png");
    LoadDivGraph("image/deck_list/button_back.png", 2, 1, 2,
        DeckListData::BUTTON_BACK_SIZE_X, DeckListData::BUTTON_BACK_SIZE_Y, handl_button_back);
    LoadDivGraph("image/deck_list/button_edit.png", 2, 1, 2,
        DeckListData::BUTTON_EDIT_SIZE_X, DeckListData::BUTTON_EDIT_SIZE_Y, handl_button_edit);
    LoadDivGraph("image/deck_list/button_delete.png", 2, 1, 2,
        DeckListData::BUTTON_DELETE_SIZE_X, DeckListData::BUTTON_DELETE_SIZE_Y, handl_button_delete);
    LoadDivGraph("image/deck_list/button_deck.png", 2, 1, 2,
        DeckListData::BUTTON_DECK_SIZE_X, DeckListData::BUTTON_DECK_SIZE_Y, handl_button_deck);
}

//-----------------------------------------------------------
// 描画
//-----------------------------------------------------------
void DrawDeckList::draw()
{
    DrawGraph(0, 0, handl_back, TRUE);
    drawDeckList();   // デッキリスト描画
    DrawGraph(0, 0, handl_back1, TRUE);
    DrawGraph(0, 564, handl_back2, TRUE);
    drawBar();        // バー描画
    drawButton();     // ボタンの描画
    drawDeckCard();   // デッキのカード描画
    drawDeckName();   // デッキ名描画
}

//-----------------------------------------------------------
// バー描画
//-----------------------------------------------------------
void DrawDeckList::drawBar()
{
    // スクロール上ボタン
    DrawGraph(
        DeckListData::BAR_UP_POS_X,
        DeckListData::BAR_UP_POS_Y,
        handl_bar_up, TRUE);
    // スクロール下ボタン
    DrawGraph(
        DeckListData::BAR_DOWN_POS_X,
        DeckListData::BAR_DOWN_POS_Y,
        handl_bar_down, TRUE);
    // スクロールバー
    if (save_data->getDeckNum() > 7) {
        DrawGraph(
            DeckListData::BAR_POS_X,
            deck_list_state->getBarPos(),
            handl_bar, TRUE);
    }
}

//-----------------------------------------------------------
// ボタン系描画
//-----------------------------------------------------------
void DrawDeckList::drawButton()
{
    int obj = deck_list_state->getMousePosObject();
    //---- 戻るボタン
    DrawGraph(
        DeckListData::BUTTON_BACK_POS_X,
        DeckListData::BUTTON_BACK_POS_Y,
        handl_button_back[((obj == DeckListState::BUTTON_BACK) ? 1 : 0)],
        FALSE);
    //---- 編集ボタン
    DrawGraph(
        DeckListData::BUTTON_EDIT_POS_X,
        DeckListData::BUTTON_EDIT_POS_Y,
        handl_button_edit[((obj == DeckListState::BUTTON_EDIT) ? 1 : 0)],
        FALSE);
    //---- 削除ボタン
    DrawGraph(
        DeckListData::BUTTON_DELETE_POS_X,
        DeckListData::BUTTON_DELETE_POS_Y,
        handl_button_delete[((obj == DeckListState::BUTTON_DELETE) ? 1 : 0)],
        FALSE);
}

//-----------------------------------------------------------
// デッキカード描画
//-----------------------------------------------------------
void DrawDeckList::drawDeckCard()
{
    int n = deck_list_state->getSelectDeckNum();
    DeckData *deck = save_data->getDeckData(n);
    for (int i = 0; i < deck->getCardNum(); i++) {
        DrawGraph(
            DeckListData::CARD_AREA_POS_X + (i % 10) * 42,
            DeckListData::CARD_AREA_POS_Y + (i / 10) * 47,
            game_data->getImageData()->getCardMini(deck->getCard(i)),
            TRUE);
    }
}

//-----------------------------------------------------------
// デッキリスト描画
//-----------------------------------------------------------
void DrawDeckList::drawDeckList()
{
    int n = deck_list_state->getSelectDeckNum();
    for (int i = 0; i < save_data->getDeckNum(); i++) {
        int x = DeckListData::BUTTON_DECK_POS_X;
        int y = DeckListData::BUTTON_DECK_POS_Y + i * DeckListData::BUTTON_DECK_SIZE_Y;
        y -= deck_list_state->getShiftPosY();
        DrawGraph(x, y, handl_button_deck[((i == n - 1) ? 1 : 0)], TRUE);
        // カード
        int id = save_data->getDeckData(i + 1)->getCard(0);
        DrawGraph(x + 12, y + 12, image_data->getCardMini(id), TRUE);
        // デッキ名
        DrawFormatStringToHandle(x + 70, y + 27, color_black, font,
            "%s", save_data->getDeckData(i + 1)->getDeckName().c_str());
    }
}

//-----------------------------------------------------------
// デッキ名描画
//-----------------------------------------------------------
void DrawDeckList::drawDeckName()
{
    // 文字入力中
    if (deck_list_state->getInputActive()) {
        DrawKeyInputString(
            DeckListData::INPUT_BOX_POS_X + 15,
            DeckListData::INPUT_BOX_POS_Y + 9,
            deck_list_state->getInputHandl());
    }
    // 文字入力中以外
    else {
        int n = deck_list_state->getSelectDeckNum();
        DrawFormatStringToHandle(
            DeckListData::INPUT_BOX_POS_X + 15,
            DeckListData::INPUT_BOX_POS_Y + 9,
            color_black, font,
            "%s", save_data->getDeckData(n)->getDeckName().c_str());
    }
}

//===========================================================
// getter
//===========================================================
