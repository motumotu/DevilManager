//-----------------------------------------------------------
// DeckListState.h
// �f�b�L�ꗗ��ʂ̏��
// ����� 2015.03.17
// ����� motumotu
//-----------------------------------------------------------
#include "DeckListState.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
DeckListState::DeckListState(GameData* data)
{
    game_data = data;
    save_data = data->getSaveData();
    
    SetKeyInputStringColor(
        GetColor(0, 0, 0),       // ���͕�����̐F
        GetColor(0, 0, 0),       // �h�l�d��g�p���̃J�[�\���̐F
        GetColor(255, 255, 255), // �h�l�d�g�p���̓��͕�����̎���̐F
        GetColor(255, 255, 255), // �h�l�d�g�p���̃J�[�\���̐F
        GetColor(0, 0, 0),       // �h�l�d�g�p���̕ϊ�������̉���
        GetColor(255, 255, 255), // �h�l�d�g�p���̑I��Ώۂ̕ϊ���╶����̐F
        GetColor(0, 0, 0),       // �h�l�d�g�p���̓��̓��[�h������̐F(�w�S�p�Ђ炪�ȁx��)
        GetColor(255, 0, 0),     // ���͕�����̉��̐F
        GetColor(0, 255, 0),     // �h�l�d�g�p���̑I��Ώۂ̕ϊ���╶����̉��̐F
        GetColor(255, 0, 0),     // �h�l�d�g�p���̓��̓��[�h������̉��̐F
        GetColor(255, 0, 0),     // �h�l�d�g�p���̕ϊ����E�C���h�E�̉��̐F
        GetColor(255, 0, 0),     // �h�l�d�g�p���̕ϊ����E�C���h�E�̉��n�̐F
        GetColor(51, 153, 255),  // ���͕�����̑I�𕔕�( SHIFT�L�[�������Ȃ��獶�E�L�[�őI�� )�̎���̐F
        GetColor(255, 255, 255), // ���͕�����̑I�𕔕�( SHIFT�L�[�������Ȃ��獶�E�L�[�őI�� )�̐F
        GetColor(51, 153, 5)     // ���͕�����̑I�𕔕�( SHIFT�L�[�������Ȃ��獶�E�L�[�őI�� )�̉��̐F
        //GetColor(255, 0, 0),   // �h�l�d�g�p���̓��͕�����̐F
        //GetColor(255, 0, 0));  // �h�l�d�g�p���̓��͕�����̉��̐F
        );
    init();
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
DeckListState::~DeckListState()
{
    DeleteKeyInput(input_handl);
}

//-----------------------------------------------------------
// ������
//-----------------------------------------------------------
void DeckListState::init()
{
    select_deck_num = 1;
    shift_pos_y = 0;
    input_active = 0;
    SetKeyInputString(
        save_data->getDeckData(1)->getDeckName().c_str(),
        input_handl);
    bar_pos = DeckListData::BAR_POS_Y;
}

//-----------------------------------------------------------
// �f�b�L�I��
//-----------------------------------------------------------
void DeckListState::selectDeckList(int n)
{
    select_deck_num = n;
    SetKeyInputString(save_data->getDeckData(n)->getDeckName().c_str(), input_handl);
}

//-----------------------------------------------------------
// �X�V
//-----------------------------------------------------------
void DeckListState::update()
{
    // ���̓{�b�N�X
    if (CheckKeyInput(input_handl) && input_active == 1) {
        offInputActive();
    }
    // �X���C�h�o�[
    if (is_bar_click_now) {
        slideBarAdjustment();
    }
}

//-----------------------------------------------------------
// �}�E�X���W�X�V
//-----------------------------------------------------------
void DeckListState::updateMousePos(int x, int y)
{
    mouse_x = x;
    mouse_y = y;
}

//-----------------------------------------------------------
// �X���C�h�o�[����
//-----------------------------------------------------------
void DeckListState::slideBarUp() { slideBarUp(3); }
void DeckListState::slideBarUp(int val)
{
    if (save_data->getDeckNum() <= 7) return;
    shift_pos_y -= val;
    double rate = (double)shift_pos_y / ((save_data->getDeckNum() - 7) * DeckListData::BUTTON_DECK_SIZE_Y);
    bar_pos = (int)(DeckListData::BAR_POS_Y + DeckListData::BAR_AREA_SIZE * rate);
    if (shift_pos_y < 0) {
        shift_pos_y = 0;
        bar_pos = DeckListData::BAR_POS_Y;
    }
}
void DeckListState::slideBarDown() { slideBarDown(3); }
void DeckListState::slideBarDown(int val)
{
    if (save_data->getDeckNum() <= 7) return;
    shift_pos_y += val;
    double rate = (double)shift_pos_y / ((save_data->getDeckNum() - 7) * DeckListData::BUTTON_DECK_SIZE_Y);
    bar_pos = (int)(DeckListData::BAR_POS_Y + DeckListData::BAR_AREA_SIZE * rate);
    if (shift_pos_y >= (save_data->getDeckNum() - 7) * DeckListData::BUTTON_DECK_SIZE_Y) {
        shift_pos_y = (save_data->getDeckNum() - 7) * DeckListData::BUTTON_DECK_SIZE_Y;
        bar_pos = DeckListData::BAR_POS_Y + DeckListData::BAR_AREA_SIZE;
    }
}
void DeckListState::slideBarAdjustment()
{
    if (save_data->getDeckNum() <= 7) return;
    int up_y = DeckListData::BAR_POS_Y + DeckListData::BAR_SIZE_Y / 2;
    int down_y = up_y + DeckListData::BAR_AREA_SIZE;
    double rate = (double)(mouse_y - up_y) / DeckListData::BAR_AREA_SIZE;
    if (rate < 0) rate = 0;
    if (rate > 1) rate = 1;
    shift_pos_y = (int)((save_data->getDeckNum() - 7) * DeckListData::BUTTON_DECK_SIZE_Y * rate);
    bar_pos = (int)(DeckListData::BAR_POS_Y + DeckListData::BAR_AREA_SIZE * rate);
}

//-----------------------------------------------------------
// �o�[���N���b�N
//-----------------------------------------------------------
void DeckListState::clickBar()
{
    is_bar_click_now = true;
}

//-----------------------------------------------------------
// ���N���b�N�I��
//-----------------------------------------------------------
void DeckListState::leftClickEnd()
{
    is_bar_click_now = false;
}

//-----------------------------------------------------------
// �}�E�X���W�ɂ��镨�̎擾
//-----------------------------------------------------------
int DeckListState::getMousePosObject()
{
    if (isPosButtonBack(mouse_x, mouse_y)) return BUTTON_BACK;
    if (isPosButtonEdit(mouse_x, mouse_y)) return BUTTON_EDIT;
    if (isPosButtonDelete(mouse_x, mouse_y)) return BUTTON_DELETE;
    if (isPosInputBox(mouse_x, mouse_y)) return INPUT_BOX;
    return NONE;
}

//-----------------------------------------------------------
// ���̈ʒu���{�^����
//-----------------------------------------------------------
bool DeckListState::isPosButtonBack(int x, int y) {
    int px = DeckListData::BUTTON_BACK_POS_X;
    int py = DeckListData::BUTTON_BACK_POS_Y;
    int sx = DeckListData::BUTTON_BACK_SIZE_X;
    int sy = DeckListData::BUTTON_BACK_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}
bool DeckListState::isPosButtonEdit(int x, int y) {
    int px = DeckListData::BUTTON_EDIT_POS_X;
    int py = DeckListData::BUTTON_EDIT_POS_Y;
    int sx = DeckListData::BUTTON_EDIT_SIZE_X;
    int sy = DeckListData::BUTTON_EDIT_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}
bool DeckListState::isPosButtonDelete(int x, int y) {
    int px = DeckListData::BUTTON_DELETE_POS_X;
    int py = DeckListData::BUTTON_DELETE_POS_Y;
    int sx = DeckListData::BUTTON_DELETE_SIZE_X;
    int sy = DeckListData::BUTTON_DELETE_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}
bool DeckListState::isPosInputBox(int x, int y) {
    int px = DeckListData::INPUT_BOX_POS_X;
    int py = DeckListData::INPUT_BOX_POS_Y;
    int sx = DeckListData::INPUT_BOX_SIZE_X;
    int sy = DeckListData::INPUT_BOX_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}
int DeckListState::isPosDeckList(int x, int y) {
    if (x < 26 || x > 279 || y < 70 || y > 564) return 0;
    int px = DeckListData::BUTTON_DECK_POS_X;
    int py = DeckListData::BUTTON_DECK_POS_Y - shift_pos_y;
    int sx = DeckListData::BUTTON_DECK_SIZE_X;
    int sy = DeckListData::BUTTON_DECK_SIZE_Y;
    for (int i = 0; i < game_data->getSaveData()->getDeckNum(); i++) {
        if (x >= px && x <= px + sx && y >= py + i * sy && y <= py + i * sy + sy) {
            return i + 1;
        }
    }
    return 0;
}
bool DeckListState::isPosBarUp(int x, int y) {
    int px = DeckListData::BAR_UP_POS_X;
    int py = DeckListData::BAR_UP_POS_Y;
    int sx = DeckListData::BAR_UP_SIZE_X;
    int sy = DeckListData::BAR_UP_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}
bool DeckListState::isPosBarDown(int x, int y) {
    int px = DeckListData::BAR_DOWN_POS_X;
    int py = DeckListData::BAR_DOWN_POS_Y;
    int sx = DeckListData::BAR_DOWN_SIZE_X;
    int sy = DeckListData::BAR_DOWN_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}
bool DeckListState::isPosBar(int x, int y) {
    int px = DeckListData::BAR_POS_X;
    int py = bar_pos;
    int sx = DeckListData::BAR_SIZE_X;
    int sy = DeckListData::BAR_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}
bool DeckListState::isPosBarArea(int x, int y) {
    int px = DeckListData::BAR_POS_X;
    int py = DeckListData::BAR_UP_POS_Y + DeckListData::BAR_UP_SIZE_Y;
    int sx = DeckListData::BAR_SIZE_X;
    int sy = DeckListData::BAR_AREA_SIZE + DeckListData::BAR_SIZE_Y;
    return (x >= px && x <= px + sx && y >= py && y <= py + sy);
}

//-----------------------------------------------------------
// ���͂��A�N�e�B�u����
//-----------------------------------------------------------
void DeckListState::offInputActive() {
    if (input_active == 0) return;
    char name[256];
    GetKeyInputString(name, input_handl);
    save_data->getDeckData(select_deck_num)->setDeckName(name);
    DeleteKeyInput(input_handl);
    input_active = 0; 
}
void DeckListState::onInputActive() {
    input_handl = MakeKeyInput(24, TRUE, FALSE, FALSE);
    SetKeyInputString(save_data->getDeckData(select_deck_num)->getDeckName().c_str(), input_handl);
    input_active = 1;
}

//===========================================================
// getter
//===========================================================
int DeckListState::getSelectDeckNum() { return select_deck_num; }
int DeckListState::getShiftPosY() { return shift_pos_y; }
int DeckListState::getInputActive() { return input_active; }
int DeckListState::getInputHandl() { return input_handl; }
int DeckListState::getBarPos() { return bar_pos; }