//-----------------------------------------------------------
// DrawBattleSelect.cpp
// �f�b�L�ꗗ��ʂ̕`��
// ����� 2015.03.17
// ����� motumotu
//-----------------------------------------------------------
#include "DrawBattleSelect.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
DrawBattleSelect::DrawBattleSelect(GameData *data, GameState *state)
{
    game_data = data;
    game_state = state;
    battle_select_state = state->getSceneState()->getBattleSelectState();
    input_state = state->getInputState();
    image_data = data->getImageData();
    save_data = data->getSaveData();

    font = CreateFontToHandle("PixelMplus12", 12, 1, DX_FONTTYPE_NORMAL);
    color_black = GetColor(0, 0, 0);
    loadImage();
    init();
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
DrawBattleSelect::~DrawBattleSelect()
{
    DeleteFontToHandle(font);
}

//-----------------------------------------------------------
// ������
//-----------------------------------------------------------
void DrawBattleSelect::init()
{
}

//-----------------------------------------------------------
// �X�V
//-----------------------------------------------------------
void DrawBattleSelect::update()
{
}

//-----------------------------------------------------------
// �摜�ǂݍ���
//-----------------------------------------------------------
void DrawBattleSelect::loadImage()
{
    handl_back = LoadGraph("image/battle_select/back.png");
    handl_back_1 = LoadGraph("image/battle_select/back_1.png");
    handl_back_2 = LoadGraph("image/battle_select/back_2.png");
    LoadDivGraph("image/battle_select/button_back.png", 2, 1, 2,
        BattleSelectData::BUTTON_BACK_SIZE_X, BattleSelectData::BUTTON_BACK_SIZE_Y, handl_button_back);
    LoadDivGraph("image/battle_select/button_battle.png", 2, 1, 2,
        BattleSelectData::BUTTON_BATTLE_SIZE_X, BattleSelectData::BUTTON_BATTLE_SIZE_Y, handl_button_battle);
    handl_select = LoadGraph("image/battle_select/select.png");
    handl_select_now = LoadGraph("image/battle_select/select_now.png");
    handl_chara[1] = LoadGraph("image/battle_select/chara1.png");
    handl_lank = LoadGraph("image/battle_select/lank.png");
    LoadDivGraph("image/battle_select/select_left.png", 2, 1, 2,
        BattleSelectData::DECK_SELECT_SIZE_X, BattleSelectData::DECK_SELECT_SIZE_Y, handl_select_left);
    LoadDivGraph("image/battle_select/select_right.png", 2, 1, 2,
        BattleSelectData::DECK_SELECT_SIZE_X, BattleSelectData::DECK_SELECT_SIZE_Y, handl_select_right);
    handl_bar = LoadGraph("image/battle_select/bar.png");
}

//-----------------------------------------------------------
// �`��
//-----------------------------------------------------------
void DrawBattleSelect::draw()
{
    DrawGraph(0, 0, handl_back, TRUE);
    drawAllOpponent();   // �ΐ푊��`��
    //---- �I�𒆂̑�����`��
    drawOpponent(battle_select_state->getSelectNum(), 1); // �ΐ�L�����`��
    drawEnemyDeck();    // �f�b�L�`��
    drawBattleData();   // �ΐ�f�[�^�`��
    //---- �������`��
    drawMyDeck();       // �f�b�L�`��
    drawDeckSelect();   // �f�b�L�I�����`��
    //
    DrawGraph(0, 0, handl_back_1, TRUE);
    DrawGraph(0, 545, handl_back_2, TRUE);
    // �{�^���`��
    drawButton();
    // �X�N���[���o�[�`��
    drawBar();
}

//-----------------------------------------------------------
// �ΐ푊��`��
//-----------------------------------------------------------
void DrawBattleSelect::drawAllOpponent()
{
    for (int n = 1; n <= game_data->getAllBattleData()->getBattleDataNum(); n++) {
        drawOpponent(n, 0);
    }
}
void DrawBattleSelect::drawOpponent(int n, int flag)
{
    BattleData *battle_data = game_data->getAllBattleData()->getBattleData(n);
    int x = BattleSelectData::SELECT_AREA_POS_X + 5;
    int y = BattleSelectData::SELECT_AREA_POS_Y + 5 + (n - 1) * (BattleSelectData::SELECT_SIZE_Y + 5);
    y -= battle_select_state->getShiftPosY();
    if (flag) {
        x = BattleSelectData::ENEMY_INFO_POS_X;
        y = BattleSelectData::ENEMY_INFO_POS_Y;
    }
    int level = battle_data->getRank();
    DrawGraph(x, y, handl_select, TRUE);             // �x�[�X
    DrawGraph(x + 4, y + 3, handl_chara[1], TRUE);   // �L�����摜
    // �G�����N
    for (int i = 0; i < level; i++) {
        DrawGraph(x + 260 - i * 12, y + 47, handl_lank, TRUE);
    }
    DrawFormatStringToHandle(x + 83, y + 15, color_black, font, "%s",
        battle_data->getName().c_str());
    // �I�𒆂�
    if (flag == 0 && n == battle_select_state->getSelectNum()) {
        DrawGraph(x, y, handl_select_now, TRUE);
    }
}

//-----------------------------------------------------------
// �f�b�L�`��
//-----------------------------------------------------------
void DrawBattleSelect::drawEnemyDeck()
{
    int x = BattleSelectData::ENEMY_INFO_POS_X;
    int y = BattleSelectData::ENEMY_INFO_POS_Y + BattleSelectData::SELECT_SIZE_Y + 10;
    int n = battle_select_state->getSelectNum();
    BattleData *battle_data = game_data->getAllBattleData()->getBattleData(n);
    int card = battle_data->getDeckData()->getCard(0);

    DrawGraph(x, y + 5, image_data->getCardMini(card), TRUE);  // �J�[�h�`��
    DrawFormatStringToHandle(x + 48, y + 17, color_black, font, "%s", // �f�b�L��
        battle_data->getDeckData()->getDeckName().c_str());
}

//-----------------------------------------------------------
// �ΐ�f�[�^�`��
//-----------------------------------------------------------
void DrawBattleSelect::drawBattleData()
{
    int x = BattleSelectData::ENEMY_INFO_POS_X;
    int y = BattleSelectData::ENEMY_INFO_POS_Y + BattleSelectData::SELECT_SIZE_Y + 10;
    DrawFormatStringToHandle(x, y + 70, color_black, font, "�ō��X�R�A %d",
        0);
    DrawFormatStringToHandle(x, y + 90, color_black, font, "������  %d",
        0);
}

//-----------------------------------------------------------
// �����̃f�b�L�`��
//-----------------------------------------------------------
void DrawBattleSelect::drawMyDeck()
{
    int x = BattleSelectData::MY_INFO_POS_X;
    int y = BattleSelectData::MY_INFO_POS_Y + 10;
    DeckData *deck = save_data->getDeckData(battle_select_state->getMyDeckNum());
    int card = deck->getCard(0);

    DrawGraph(x, y + 5, image_data->getCardMini(card), TRUE);  // �J�[�h�`��
    DrawFormatStringToHandle(x + 48, y + 17, color_black, font, "%s", // �f�b�L��
        deck->getDeckName().c_str());
}

//-----------------------------------------------------------
// �f�b�L�I���̕`��
//-----------------------------------------------------------
void DrawBattleSelect::drawDeckSelect()
{
    int mx = input_state->getPointX();
    int my = input_state->getPointY();
    // ��
    int image = (battle_select_state->isPosDeckSelectLeft(mx, my)) ? 1 : 0;
    DrawGraph(
        BattleSelectData::DECK_SELECT_LEFT_POS_X,
        BattleSelectData::DECK_SELECT_LEFT_POS_Y,
        handl_select_left[image], TRUE);
    // �E
    image = (battle_select_state->isPosDeckSelectRight(mx, my)) ? 1 : 0;
    DrawGraph(
        BattleSelectData::DECK_SELECT_RIGHT_POS_X,
        BattleSelectData::DECK_SELECT_RIGHT_POS_Y,
        handl_select_right[image], TRUE);
}

//-----------------------------------------------------------
// �X�N���[���o�[�`��
//-----------------------------------------------------------
void DrawBattleSelect::drawBar()
{
    int x = BattleSelectData::BAR_POS_X;
    int y = battle_select_state->getBarPos();
    DrawGraph(x, y, handl_bar, TRUE);
}

//-----------------------------------------------------------
// �{�^���`��
//-----------------------------------------------------------
void DrawBattleSelect::drawButton()
{
    int mx = input_state->getPointX();
    int my = input_state->getPointY();

    DrawGraph(
        BattleSelectData::BUTTON_BACK_POS_X,
        BattleSelectData::BUTTON_BACK_POS_Y,
        handl_button_back[((battle_select_state->isPosButtonBack(mx, my)) ? 1 : 0)],
        TRUE);
    DrawGraph(
        BattleSelectData::BUTTON_BATTLE_POS_X,
        BattleSelectData::BUTTON_BATTLE_POS_Y,
        handl_button_battle[((battle_select_state->isPosButtonBattle(mx, my)) ? 1 : 0)],
        TRUE);
}

//===========================================================
// getter
//===========================================================
