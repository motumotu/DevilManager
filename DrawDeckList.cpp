//-----------------------------------------------------------
// DrawDeckList.cpp
// �f�b�L�ꗗ��ʂ̕`��
// ����� 2015.03.17
// ����� motumotu
//-----------------------------------------------------------
#include "DrawDeckList.h"

//-----------------------------------------------------------
// �R���X�g���N�^
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
// �f�X�g���N�^
//-----------------------------------------------------------
DrawDeckList::~DrawDeckList()
{
}

//-----------------------------------------------------------
// ������
//-----------------------------------------------------------
void DrawDeckList::init()
{
    ChangeFont("PixelMplus12", DX_CHARSET_DEFAULT);
    SetFontSize(12);
    SetFontThickness(1);
}

//-----------------------------------------------------------
// �X�V
//-----------------------------------------------------------
void DrawDeckList::update()
{
}

//-----------------------------------------------------------
// �摜�ǂݍ���
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
// �`��
//-----------------------------------------------------------
void DrawDeckList::draw()
{
    DrawGraph(0, 0, handl_back, TRUE);
    drawDeckList();   // �f�b�L���X�g�`��
    DrawGraph(0, 0, handl_back1, TRUE);
    DrawGraph(0, 564, handl_back2, TRUE);
    drawBar();        // �o�[�`��
    drawButton();     // �{�^���̕`��
    drawDeckCard();   // �f�b�L�̃J�[�h�`��
    drawDeckName();   // �f�b�L���`��
}

//-----------------------------------------------------------
// �o�[�`��
//-----------------------------------------------------------
void DrawDeckList::drawBar()
{
    // �X�N���[����{�^��
    DrawGraph(
        DeckListData::BAR_UP_POS_X,
        DeckListData::BAR_UP_POS_Y,
        handl_bar_up, TRUE);
    // �X�N���[�����{�^��
    DrawGraph(
        DeckListData::BAR_DOWN_POS_X,
        DeckListData::BAR_DOWN_POS_Y,
        handl_bar_down, TRUE);
    // �X�N���[���o�[
    if (save_data->getDeckNum() > 7) {
        DrawGraph(
            DeckListData::BAR_POS_X,
            deck_list_state->getBarPos(),
            handl_bar, TRUE);
    }
}

//-----------------------------------------------------------
// �{�^���n�`��
//-----------------------------------------------------------
void DrawDeckList::drawButton()
{
    int obj = deck_list_state->getMousePosObject();
    //---- �߂�{�^��
    DrawGraph(
        DeckListData::BUTTON_BACK_POS_X,
        DeckListData::BUTTON_BACK_POS_Y,
        handl_button_back[((obj == DeckListState::BUTTON_BACK) ? 1 : 0)],
        FALSE);
    //---- �ҏW�{�^��
    DrawGraph(
        DeckListData::BUTTON_EDIT_POS_X,
        DeckListData::BUTTON_EDIT_POS_Y,
        handl_button_edit[((obj == DeckListState::BUTTON_EDIT) ? 1 : 0)],
        FALSE);
    //---- �폜�{�^��
    DrawGraph(
        DeckListData::BUTTON_DELETE_POS_X,
        DeckListData::BUTTON_DELETE_POS_Y,
        handl_button_delete[((obj == DeckListState::BUTTON_DELETE) ? 1 : 0)],
        FALSE);
}

//-----------------------------------------------------------
// �f�b�L�J�[�h�`��
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
// �f�b�L���X�g�`��
//-----------------------------------------------------------
void DrawDeckList::drawDeckList()
{
    int n = deck_list_state->getSelectDeckNum();
    for (int i = 0; i < save_data->getDeckNum(); i++) {
        int x = DeckListData::BUTTON_DECK_POS_X;
        int y = DeckListData::BUTTON_DECK_POS_Y + i * DeckListData::BUTTON_DECK_SIZE_Y;
        y -= deck_list_state->getShiftPosY();
        DrawGraph(x, y, handl_button_deck[((i == n - 1) ? 1 : 0)], TRUE);
        // �J�[�h
        int id = save_data->getDeckData(i + 1)->getCard(0);
        DrawGraph(x + 12, y + 12, image_data->getCardMini(id), TRUE);
        // �f�b�L��
        DrawFormatStringToHandle(x + 70, y + 27, color_black, font,
            "%s", save_data->getDeckData(i + 1)->getDeckName().c_str());
    }
}

//-----------------------------------------------------------
// �f�b�L���`��
//-----------------------------------------------------------
void DrawDeckList::drawDeckName()
{
    // �������͒�
    if (deck_list_state->getInputActive()) {
        DrawKeyInputString(
            DeckListData::INPUT_BOX_POS_X + 15,
            DeckListData::INPUT_BOX_POS_Y + 9,
            deck_list_state->getInputHandl());
    }
    // �������͒��ȊO
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
