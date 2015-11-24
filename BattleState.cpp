//-----------------------------------------------------------
// BattleState.cpp
// �ΐ��ʂ̏��
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#include "BattleState.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
BattleState::BattleState(GameData* _game_data)
{
    game_data = _game_data;
    map_state = new BattleMapState(game_data);
    card_state = new BattleCardState();
    init();     // ��������
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
BattleState::~BattleState()
{
    delete(card_state);
    delete(map_state);
}

//-----------------------------------------------------------
// ������
//-----------------------------------------------------------
void BattleState::init()
{
    now_turn = TURN_CURD_SELECT;    // �J�[�h�I���^�[��
    now_battle_select_mode = BATTLE_SELECT_NORMAL;
    select_unit_com = -1;
    player_pos_x = -1;         // �v���C���[�̍��Wx
    player_pos_y = -1;         // �v���C���[�̍��Wy
    shift_pos_x = 0;           // ���炷���Wx
    shift_pos_y = 0;           // ���炷���Wy
    time_cnt = TURN_TIME;      // �o�g���c�莞��
    my_mp = INIT_MP;           // ��������
    en_mp = INIT_MP;           // �G����
    mouse_on_unit = NULL;      // �J�[�\��������Ă郆�j�b�g
    winner = -1;               // ������
}

//-----------------------------------------------------------
// �ΐ��񏉊���
//-----------------------------------------------------------
void BattleState::battleInit()
{
    now_turn = TURN_CURD_SELECT;    // �J�[�h�I���^�[��
    now_battle_select_mode = BATTLE_SELECT_NORMAL; // �I�����[�h
    select_unit_com = -1;      // �I�𒆂̃R�}���h
    player_pos_x = -1;         // �v���C���[�̍��Wx
    player_pos_y = -1;         // �v���C���[�̍��Wy
    shift_pos_x = 0;           // ���炷���Wx
    shift_pos_y = 0;           // ���炷���Wy
    time_cnt = TURN_TIME;      // �o�g���c�莞��
    my_mp = INIT_MP;           // ��������
    en_mp = INIT_MP;           // �G����
    while (!select_unit.empty()) select_unit.pop();
    mouse_on_unit = NULL;      // �J�[�\��������Ă郆�j�b�g
    winner = -1;               // ������

    map_state->battleInit();   // �}�b�v��񏉊���
    card_state->battleInit();  // �J�[�h��񏉊���
}

//-----------------------------------------------------------
// �ΐ�ݒ�
//-----------------------------------------------------------
void BattleState::battleSetting()
{
    setInitShiftPos();
    map_state->battleSetting();
    card_state->battleSetting();
}

//-----------------------------------------------------------
// �X�V
//-----------------------------------------------------------
void BattleState::update()
{
    card_state->update();

    //---- �ΐ�^�[��
    if (now_turn == TURN_BATTLE) {
        map_state->update();
        if (--time_cnt <= 0) {
            changeCardSelectTurn();
        }
        checkEnd();    // �I������
    }
    //---- �J�[�h�I���^�[��
    else if (now_turn == TURN_CURD_SELECT) {

    }
    //---- �J�[�h�g�p�^�[��
    else if (now_turn == TURN_CURD_USE) {

    }
}

//-----------------------------------------------------------
// �J�[�h�g�p�^�[���Ɉڍs
//-----------------------------------------------------------
void BattleState::changeCardSelectTurn()
{
    card_state->drawCardMy();    // �J�[�h������
    card_state->drawCardMy();    // �J�[�h������
    card_state->drawCardEn();    // �J�[�h������
    card_state->drawCardEn();    // �J�[�h������
    my_mp += ONETURN_MP;         // ���̓v���X
    en_mp += ONETURN_MP;         // ���̓v���X
    now_turn = TURN_CURD_SELECT; // �^�[���ύX
    time_cnt = 0;                // ����
    deselectUnit();              // ���j�b�g�I������
    left_click_now = 0;          // �N���b�N����
    click_first_pos_x = 0;       // �N���b�N�����ʒux
    click_first_pos_y = 0;       // �N���b�N�����ʒuy
    click_now_pos_x = 0;         // �N���b�N�I���ʒux
    click_now_pos_y = 0;         // �N���b�N�I���ʒuy
    select_unit_com = -1;
}

//-----------------------------------------------------------
// �}�E�X���W�X�V
//-----------------------------------------------------------
void BattleState::updateMousePos(int x, int y)
{
    int px = changeMousePosX(x);
    int py = changeMousePosY(y);
    player_pos_x = -1;
    player_pos_y = -1;
    if (getMapData()->outCheck(px, py)) return;
    if (getMapData()->map_data[py][px] == MapData::MAP_FLOOR) {
        player_pos_x = px;
        player_pos_y = py;
    }
}

//-----------------------------------------------------------
// ���W�ύX
//-----------------------------------------------------------
void BattleState::moveShiftPos(int dire, int movement)
{
    int dx[] = { 0, -1, 0, 1 };
    int dy[] = { 1, 0, -1, 0 };
    shift_pos_x += dx[dire] * movement;
    shift_pos_y += dy[dire] * movement;
}

//-----------------------------------------------------------
// �w����W�ɂ��炷
//-----------------------------------------------------------
void BattleState::setShiftPos(int x, int y)
{
    shift_pos_x = SystemData::getWindowWidth() / 2;
    shift_pos_y = SystemData::getWindowHeight() / 2;
    shift_pos_x -= x * MapData::MAP_IMAGE_SIZE;
    shift_pos_y -= y * MapData::MAP_IMAGE_SIZE;
    shift_pos_x -= MapData::MAP_IMAGE_SIZE / 2;
    shift_pos_y -= MapData::MAP_IMAGE_SIZE / 2;
}
void BattleState::setInitShiftPos()
{
    setShiftPos(
        getMapData()->player_base_x,
        getMapData()->player_base_y);
}

//-----------------------------------------------------------
// �}�E�X���W���}�b�v���W�ɕϊ�
//-----------------------------------------------------------
int BattleState::changeMousePosX(int x) {
    return (x - shift_pos_x) / MapData::MAP_IMAGE_SIZE;
}
int BattleState::changeMousePosY(int y) {
    return (y - shift_pos_y) / MapData::MAP_IMAGE_SIZE;
}

//-----------------------------------------------------------
// �}�b�v�f�[�^�ݒ�
//-----------------------------------------------------------
void BattleState::setMapData(MapData* data)
{
    map_state->setMapData(data);
}

//-----------------------------------------------------------
// �J�[�h�I��
//-----------------------------------------------------------
void BattleState::selectCard(int n)
{
    card_state->selectHandCardMy(n);
    now_turn = TURN_CURD_USE;
}

//-----------------------------------------------------------
// �L�����Z���{�^���I��
//-----------------------------------------------------------
void BattleState::selectCancelButton()
{
    puts("�L�����Z�����܂���");
}

//-----------------------------------------------------------
// �I���{�^���I��
//-----------------------------------------------------------
void BattleState::selectEndButton()
{
    now_turn = TURN_BATTLE;  // �ΐ탂�[�h�Ɉڍs
    now_battle_select_mode = BATTLE_SELECT_NORMAL;  // �ʏ�I�����[�h
    time_cnt = TURN_TIME;    // ���Ԑݒ�
}

//-----------------------------------------------------------
// ���j�b�g�ݒu
//-----------------------------------------------------------
void BattleState::putUnit()
{
    now_turn = TURN_CURD_SELECT;
}

//-----------------------------------------------------------
// ���͎g�p
// �g�p�Ftrue�A�s�g�p�Ffalse
//-----------------------------------------------------------
bool BattleState::useMyMp(int mp)
{
    if (mp > my_mp) {
        return false;
    }
    my_mp -= mp;
    return true;
}
bool BattleState::useEnMp(int mp)
{
    if (mp > en_mp) {
        return false;
    }
    en_mp -= mp;
    return true;
}

//-----------------------------------------------------------
// �ŏ��̍��N���b�N
//-----------------------------------------------------------
void BattleState::firstLeftClick(int x, int y)
{
    BattleAllUnitState *unit = getMapState()->getUnitState();

    //---- �ʏ�I�����[�h��
    if (now_battle_select_mode == BATTLE_SELECT_NORMAL) {
        click_first_pos_x = x - shift_pos_x;
        click_first_pos_y = y - shift_pos_y;
        click_now_pos_x = x - shift_pos_x;
        click_now_pos_y = y - shift_pos_y;
        left_click_now = 1;
        updateSelectUnit();
    }
    //---- �G���A�I�����[�h��
    else if (now_battle_select_mode == BATTLE_SELECT_AREA) {
        // �G���A�擾
        int px = changeMousePosX(x);
        int py = changeMousePosY(y);
        if (getMapData()->isFloor(px, py)) {
            commandSelectUnit(select_unit_com, px, py);
            deselectUnit();
        }
    }
    //---- ���R���j�b�g�I�����[�h
    else if (now_battle_select_mode == BATTLE_SELECT_MYUNIT) {
        for (int i = 0; i < unit->getMyUnitNum(); i++) {
            BattleUnitState *state = unit->getMyUnit();
            if (x > state->getPixelX() + shift_pos_x && x < state->getPixelX() + state->getImageSizeX() + shift_pos_x &&
                y > state->getPixelY() + shift_pos_y && y < state->getPixelY() + state->getImageSizeY() + shift_pos_y) {
                commandSelectUnit(select_unit_com, state);
                deselectUnit();
            }
        }
    }
    //---- �G�R���j�b�g�I�����[�h
    else if (now_battle_select_mode == BATTLE_SELECT_ENUNIT) {
        for (int i = 0; i < unit->getEnUnitNum(); i++) {
            BattleUnitState *state = unit->getEnUnit();
            if (x > state->getPixelX() + shift_pos_x && x < state->getPixelX() + state->getImageSizeX() + shift_pos_x&&
                y > state->getPixelY() + shift_pos_y && y < state->getPixelY() + state->getImageSizeY() + shift_pos_y) {
                commandSelectUnit(select_unit_com, state);
                deselectUnit();
            }
        }
    }
}

//-----------------------------------------------------------
// ���N���b�N��
//-----------------------------------------------------------
void BattleState::nowLeftClick(int x, int y)
{
    if (left_click_now) {
        click_now_pos_x = x - shift_pos_x;
        click_now_pos_y = y - shift_pos_y;
        updateSelectUnit();
    }
}

//-----------------------------------------------------------
// ���N���b�N�̍Ō�
//-----------------------------------------------------------
void BattleState::endLeftClick(int x, int y)
{
    if (left_click_now) {
        updateSelectUnit();
    }
    left_click_now = 0;
    click_first_pos_x = -10000;
    click_first_pos_y = -10000;
    click_now_pos_x = -10000;
    click_now_pos_y = -10000;
}

//-----------------------------------------------------------
// �I�����j�b�g�X�V
//-----------------------------------------------------------
void BattleState::updateSelectUnit()
{
    deselectUnit();
    BattleAllUnitState *unit = getMapState()->getUnitState();
    for (int i = 0; i < unit->getMyUnitNum(); i++) {
        BattleUnitState *state = unit->getMyUnit();
        int ax1 = click_first_pos_x;
        int ay1 = click_first_pos_y;
        int ax2 = click_now_pos_x;
        int ay2 = click_now_pos_y;
        if (ay1 > ay2) std::swap(ay1, ay2);
        if (ax1 > ax2) std::swap(ax1, ax2);
        int bx1 = state->getPixelX();
        int by1 = state->getPixelY();
        int bx2 = state->getPixelX() + state->getImageSizeX();
        int by2 = state->getPixelY() + state->getImageSizeY();
        if (Algo::crossTwoSquare(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2)) {
            select_unit.push(state);
        }
    }
}

//-----------------------------------------------------------
// ���j�b�g�I������
//-----------------------------------------------------------
void BattleState::deselectUnit()
{
    while (!select_unit.empty()) select_unit.pop();
}

//-----------------------------------------------------------
// �I�𒆂̃��j�b�g�ɑ΂�����
//-----------------------------------------------------------
void BattleState::commandSelectUnit(int com)
{
    for (int i = 0; i < (int)select_unit.size(); i++) {
        BattleUnitState *unit = select_unit.front();
        unit->setNowCommand(com);
        select_unit.pop();
        select_unit.push(unit);
    }
    changeSelectMode(BATTLE_SELECT_NORMAL);  // �ʏ�I�����[�h�ɒ���
    select_unit_com = -1;
}
void BattleState::commandSelectUnit(int com, int x, int y)
{
    for (int i = 0; i < (int)select_unit.size(); i++) {
        BattleUnitState *unit = select_unit.front();
        unit->setMovePos(x, y);
        unit->setNowCommand(com);
        select_unit.pop();
        select_unit.push(unit);
    }
    changeSelectMode(BATTLE_SELECT_NORMAL);  // �ʏ�I�����[�h�ɒ���
    select_unit_com = -1;
}
void BattleState::commandSelectUnit(int com, BattleUnitState* u)
{
    for (int i = 0; i < (int)select_unit.size(); i++) {
        BattleUnitState *unit = select_unit.front();
        if (com == BattleUnitState::COM_SPE_ATTACK)
            unit->setAttackUnit(u);
        if (com == BattleUnitState::COM_SPE_DEFENSE)
            unit->setDefenseUnit(u);
        unit->setNowCommand(com);
        select_unit.pop();
        select_unit.push(unit);
    }
    changeSelectMode(BATTLE_SELECT_NORMAL);  // �ʏ�I�����[�h�ɒ���
    select_unit_com = -1;
}

//-----------------------------------------------------------
// �I�����[�h�ύX
//-----------------------------------------------------------
void BattleState::changeSelectMode(int mode)
{
    now_battle_select_mode = mode;
}

//-----------------------------------------------------------
// ���j�b�g�ɑ΂��閽�߃Z�b�g
//-----------------------------------------------------------
void BattleState::setSelectUnitCom(int com)
{
    if (select_unit.size() == 0) return;
    select_unit_com = com;
    // �w��ړ�
    if (com == BattleUnitState::COM_SPE_MOVE) {
        changeSelectMode(BattleState::BATTLE_SELECT_AREA);
    }
    // �w��U��
    else if (com == BattleUnitState::COM_SPE_ATTACK) {
        changeSelectMode(BattleState::BATTLE_SELECT_ENUNIT);
    }
    // �w��h��
    else if (com == BattleUnitState::COM_SPE_DEFENSE) {
        changeSelectMode(BattleState::BATTLE_SELECT_MYUNIT);
    }
    // �ҋ@�E���R�E�U���E�h��
    else {
        commandSelectUnit(select_unit_com);
        deselectUnit();
    }
}

//-----------------------------------------------------------
// ���j�b�g��u���邩
//-----------------------------------------------------------
bool BattleState::isPutUnitMy(CardData* card, int x, int y)
{
    if (card->mp > my_mp) return false;
    for (int py = y; py < y + card->size_y; py++) {
        for (int px = x; px < x + card->size_x; px++) {
            if (map_state->isUnit(px, py)) return false;
            if (!map_state->getMapData()->isFloor(px, py)) return false;
            if (map_state->getAreaState()->getAreaWho(px, py) != BattleAreaState::AREA_MY) return false;
        }
    }
    return true;
}

//-----------------------------------------------------------
// ���j�b�g�ɑ΂��閽�߃Z�b�g
//-----------------------------------------------------------
bool BattleState::isPutUnitEn(CardData* card, int x, int y)
{
    if (card->mp > en_mp) return false;
    for (int py = y; py < y + card->size_y; py++) {
        for (int px = x; px < x + card->size_x; px++) {
            if (map_state->isUnit(px, py)) return false;
            if (!map_state->getMapData()->isFloor(px, py)) return false;
            if (map_state->getAreaState()->getAreaWho(px, py) != BattleAreaState::AREA_ENE) return false;
        }
    }
    return true;
}

//-----------------------------------------------------------
// ���R���j�b�g����
//-----------------------------------------------------------
void BattleState::createUnitMy(CardData* card, int x, int y)
{
    useMyMp(card->mp);                    // ���͎g�p
    map_state->createMyUnit(card, x, y);  // �}�b�v�ɐݒu
}

//-----------------------------------------------------------
// �G�R���j�b�g����
//-----------------------------------------------------------
void BattleState::createUnitEn(CardData* card, int x, int y)
{
    useEnMp(card->mp);                    // ���͎g�p
    map_state->createEnUnit(card, x, y);  // �}�b�v�ɐݒu
}

//-----------------------------------------------------------
// �}�E�X������Ă郆�j�b�g�X�V
//-----------------------------------------------------------
void BattleState::updateMouseOnUnit(int x, int y)
{
    mouse_on_unit = NULL;
    BattleAllUnitState *unit = getMapState()->getUnitState();

    //---- ���R
    for (int i = 0; i < unit->getMyUnitNum(); i++) {
        BattleUnitState *state = unit->getMyUnit();
        if (x >= state->getX() && x <= state->getX() + state->getImageSizeX() &&
            y >= state->getY() && y <= state->getY() + state->getImageSizeY()) {
            mouse_on_unit = state;
        }
    }
    //---- �G�R
    for (int i = 0; i < unit->getEnUnitNum(); i++) {
        BattleUnitState *state = unit->getEnUnit();
        if (x >= state->getX() && x <= state->getX() + state->getImageSizeX() &&
            y >= state->getY() && y <= state->getY() + state->getImageSizeY()) {
            mouse_on_unit = state;
        }
    }
}

//-----------------------------------------------------------
// �I������
//-----------------------------------------------------------
void BattleState::checkEnd()
{
    BattleAllUnitState *unit = map_state->getUnitState();
    int px = getMapData()->player_base_x;
    int py = getMapData()->player_base_y;
    int ex = getMapData()->enemy_base_x;
    int ey = getMapData()->enemy_base_y;

    // �v���C���[����
    if (unit->getUnit(ex, ey) == NULL) {
        now_turn = TURN_END;
        winner = PLAYER;
    }
    // �v���C���[�s�k
    if (unit->getUnit(px, py) == NULL) {
        now_turn = TURN_END;
        winner = ENEMY;
    }
}

//===========================================================
// getter
//===========================================================
BattleMapState *BattleState::getMapState() { return map_state; }
BattleCardState *BattleState::getCardState() { return card_state; }
MapData *BattleState::getMapData() { return map_state->getMapData(); }
int BattleState::getSelectUnitNum() { return (int)select_unit.size(); }
BattleUnitState* BattleState::getSelectUnit() {
    BattleUnitState* unit = select_unit.front();
    select_unit.pop();
    select_unit.push(unit);
    return unit;
}
int BattleState::getPlayerPosX() { return player_pos_x; }
int BattleState::getPlayerPosY() { return player_pos_y; }
int BattleState::getShiftPosX() { return shift_pos_x; }
int BattleState::getShiftPosY() { return shift_pos_y; }
int BattleState::getNowTurn() { return now_turn; }
int BattleState::getNowTimeCnt() { return time_cnt; }
int BattleState::getMyMp() { return my_mp; }
int BattleState::getEnMp() { return en_mp; }
bool BattleState::isLeftClickNow() { return (left_click_now) ? true : false; }
int BattleState::getClickFirstPosX() { return click_first_pos_x; }
int BattleState::getClickFirstPosY() { return click_first_pos_y; }
int BattleState::getClickNowPosX() { return click_now_pos_x; }
int BattleState::getClickNowPosY() { return click_now_pos_y; }
int BattleState::getNowSelectMode() { return now_battle_select_mode; }
int BattleState::getSelectUnitCom() { return select_unit_com; }
int BattleState::getWinner() { return winner; }