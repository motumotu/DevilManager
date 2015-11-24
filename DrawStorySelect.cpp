//-----------------------------------------------------------
// DrawStorySelect.cpp
// �X�g�[���[�I����ʂ̕`��
// ����� 2015.03.17
// ����� motumotu
//-----------------------------------------------------------
#include "DrawStorySelect.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
DrawStorySelect::DrawStorySelect(GameData* data, GameState* state)
{
    game_data = data;
    game_state = state;
    story_select_state = state->getSceneState()->getStorySelectState();
    save_data = data->getSaveData();
    color_black = GetColor(0, 0, 0);
    font = CreateFontToHandle("PixelMplus12", 12, 1, DX_FONTTYPE_NORMAL);
    loadImage();
}


//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
DrawStorySelect::~DrawStorySelect()
{
    DeleteFontToHandle(font);
}
//-----------------------------------------------------------
// ������
//-----------------------------------------------------------
void DrawStorySelect::init()
{

}

//-----------------------------------------------------------
// �X�V����
//-----------------------------------------------------------
void DrawStorySelect::update()
{

}

//-----------------------------------------------------------
// �摜�ǂݍ���
//-----------------------------------------------------------
void DrawStorySelect::loadImage()
{
    handl_back = LoadGraph("image/story_select/back.png");
    LoadDivGraph("image/story_select/button_back.png", 2, 1, 2,
        StorySelectData::BUTTON_BACK_SIZE_X,
        StorySelectData::BUTTON_BACK_SIZE_Y, handl_button_back);
    LoadDivGraph("image/story_select/button_decision.png", 2, 1, 2,
        StorySelectData::BUTTON_DECISION_SIZE_X,
        StorySelectData::BUTTON_DECISION_SIZE_Y, handl_button_decision);
    LoadDivGraph("image/story_select/deck_select_left.png", 2, 1, 2,
        StorySelectData::DECK_SELECT_SIZE_X,
        StorySelectData::DECK_SELECT_SIZE_Y, handl_deck_select_left);
    LoadDivGraph("image/story_select/deck_select_right.png", 2, 1, 2,
        StorySelectData::DECK_SELECT_SIZE_X,
        StorySelectData::DECK_SELECT_SIZE_Y, handl_deck_select_right);
    LoadDivGraph("image/story_select/story_1.png", 9, 3, 3,
        StorySelectData::STORY_SIZE_X,
        StorySelectData::STORY_SIZE_Y, handl_story[1]);
    LoadDivGraph("image/story_select/story_2.png", 9, 3, 3,
        StorySelectData::STORY_SIZE_X,
        StorySelectData::STORY_SIZE_Y, handl_story[2]);
    handl_story_select = LoadGraph("image/story_select/story_select.png");
    handl_rank = LoadGraph("image/story_select/rank.png");
    handl_mouseon = LoadGraph("image/story_select/story_mouseon.png");
}

//-----------------------------------------------------------
// �`�揈��
//-----------------------------------------------------------
void DrawStorySelect::draw()
{
    int image;
    int obj = story_select_state->getMousePosObject();
    // �w�i�`��
    DrawGraph(0, 0, handl_back, TRUE);
    // �߂�{�^��
    image = (obj == StorySelectState::BUTTON_BACK) ? 1 : 0;
    DrawGraph(
        StorySelectData::BUTTON_BACK_POS_X,
        StorySelectData::BUTTON_BACK_POS_Y,
        handl_button_back[image], TRUE);
    // ����{�^��
    image = (obj == StorySelectState::BUTTON_DECISION) ? 1 : 0;
    DrawGraph(
        StorySelectData::BUTTON_DECISION_POS_X,
        StorySelectData::BUTTON_DECISION_POS_Y,
        handl_button_decision[image], TRUE);
    // �����f�b�L�`��
    drawMyDeck();
    // �f�b�L�I����
    image = (obj == StorySelectState::DECK_SELECT_LEFT) ? 1 : 0;
    DrawGraph(
        StorySelectData::DECK_SELECT_LEFT_POS_X,
        StorySelectData::DECK_SELECT_LEFT_POS_Y,
        handl_deck_select_left[image], TRUE);
    // �f�b�L�I���E
    image = (obj == StorySelectState::DECK_SELECT_RIGHT) ? 1 : 0;
    DrawGraph(
        StorySelectData::DECK_SELECT_RIGHT_POS_X,
        StorySelectData::DECK_SELECT_RIGHT_POS_Y,
        handl_deck_select_right[image], TRUE);
    // �X�g�[���[�`��
    drawStory();
    // �X�g�[���[���`��
    drawStoryInfo();
    // �f�b�L���
    /*
    if (obj == StorySelectState::DECK_AREA) {
        drawDeckCard();
    }
    */
}

//-----------------------------------------------------------
// �����f�b�L�`�揈��
//-----------------------------------------------------------
void DrawStorySelect::drawMyDeck()
{
    int x = StorySelectData::DECK_AREA_POS_X;
    int y = StorySelectData::DECK_AREA_POS_Y;
    int n = story_select_state->getDeckNum();
    // �J�[�h
    int card = save_data->getDeckData(n)->getCard(0);
    DrawGraph(x + 12, y + 12, game_data->getImageData()->getCardMini(card), TRUE);
    // �f�b�L��
    DrawFormatStringToHandle(x + 70, y + 27, color_black, font,
        "%s", save_data->getDeckData(n)->getDeckName().c_str());
}

//-----------------------------------------------------------
// �X�g�[���[�`��
//-----------------------------------------------------------
void DrawStorySelect::drawStory()
{
    int chapter_num = story_select_state->getChapterNum();
    int story_num = story_select_state->getStoryNum();

    for (int n = 0; n < story_select_state->getNowChapterStoryNum(); n++) {
        int x = StorySelectData::STORY_AREA_POS_X + (StorySelectData::STORY_SIZE_X + 15) * (n % 3);
        int y = StorySelectData::STORY_AREA_POS_Y + (StorySelectData::STORY_SIZE_Y + 35) * (n / 3);
        DrawGraph(x, y, handl_story[chapter_num][n], TRUE);
        if (story_num == n + 1) DrawGraph(x, y, handl_story_select, TRUE);
        if (story_select_state->getMousePosStory() == n + 1) DrawGraph(x, y, handl_mouseon, TRUE);
    }
}

//-----------------------------------------------------------
// �X�g�[���[���`��
//-----------------------------------------------------------
void DrawStorySelect::drawStoryInfo()
{
    int x = StorySelectData::STORY_INFO_AREA_POS_X + 20;
    int y = StorySelectData::STORY_INFO_AREA_POS_Y + 20;
    int story_num = story_select_state->getStoryNum();
    int n = story_select_state->getMousePosStory();
    if (n != 0) story_num = n;
    StoryEnemyData *s = game_data->getAllStoryEnemyData()->getStoryEnemyData(story_num);
    
    // �X�g�[���[�ԍ�
    DrawFormatStringToHandle(x, y, color_black, font,
        "�X�g�[���[�ԍ� %d", story_num);
    // �X�g�[���[�^�C�g��
    DrawFormatStringToHandle(x, y + 20, color_black, font,
        "�w%s�x", s->getName().c_str());
    // �����N
    DrawStringToHandle(x, y + 40, "�����N", color_black, font);
    for (int i = 0; i < s->getRank(); i++) {
        DrawGraph(40 + x + i * 12, y + 40, handl_rank, TRUE);
    }
    // �N���A��
    DrawFormatStringToHandle(x, y + 80, color_black, font,
        "�N���A�� %d", 0);
    // �ō��X�R�A
    DrawFormatStringToHandle(x, y + 100, color_black, font,
        "�ō��X�R�A %d", 0);
}

//-----------------------------------------------------------
// �f�b�L�̃J�[�h�`��
//-----------------------------------------------------------
void DrawStorySelect::drawDeckCard()
{
    int n = story_select_state->getDeckNum();
    for (int i = 0; i < save_data->getDeckData(n)->getCardNum(); i++) {
        int card = save_data->getDeckData(n)->getCard(i);
        int x = - (i % 10) * ImageData::MINICARD_SIZE_X;
        int y = - (i / 10) * ImageData::MINICARD_SIZE_Y;
        DrawGraph(x, y, game_data->getImageData()->getCardMini(card), TRUE);
    }
}