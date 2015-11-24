//-----------------------------------------------------------
// BattleMapState.cpp
// �ΐ�}�b�v���
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#include "BattleMapState.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
BattleMapState::BattleMapState(GameData* _game_data)
{
    game_data = _game_data;
    srand((unsigned)time(NULL));
    unit = new BattleAllUnitState(_game_data);
    area = new BattleAreaState();
    init();     // ��������
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
BattleMapState::~BattleMapState()
{
    delete(area);
    delete(unit);
    while (!damage.empty()) {
        BattleDamageState *d = damage.front();
        damage.pop();
        delete(d);
    }
}

//-----------------------------------------------------------
// ������
//-----------------------------------------------------------
void BattleMapState::init()
{
    while (!damage.empty()) damage.pop();
}

//-----------------------------------------------------------
// �ΐ��񏉊���
//-----------------------------------------------------------
void BattleMapState::battleInit()
{
    while (!damage.empty()) {
        BattleDamageState *d = damage.front();
        damage.pop();
        delete(d);
    }
    area->battleInit();
    unit->battleInit();
}

//-----------------------------------------------------------
// �ΐ�ݒ�
//-----------------------------------------------------------
void BattleMapState::battleSetting()
{
    // ���_����
    createMyBase(game_data->getAllCardData()->getCardData(0));
    createEnBase(game_data->getAllCardData()->getCardData(0));
    getAreaState()->discriminationArea();
}

//-----------------------------------------------------------
// �X�V
//-----------------------------------------------------------
void BattleMapState::update()
{
    //---- �t���[�����߃X�L��
    for (int i = 0; i < unit->getMyUnitNum(); i++)
        frameFirstSkil(unit->getMyUnit());
    for (int i = 0; i < unit->getEnUnitNum(); i++)
        frameFirstSkil(unit->getEnUnit());
    updateDamage();         // �_���[�W�\���X�V
    updateMyUnitState();    // ���R���j�b�g��ԍX�V
    updateEnUnitState();    // �G�R���j�b�g��ԍX�V
    unit->update();         // ���j�b�g���X�V
    area->update();         // �̈���X�V
    //---- �t���[���I���X�L��
    for (int i = 0; i < unit->getMyUnitNum(); i++)
        frameEndSkil(unit->getMyUnit());
    for (int i = 0; i < unit->getEnUnitNum(); i++)
        frameEndSkil(unit->getEnUnit());
}

//-----------------------------------------------------------
// �ݒ�
//-----------------------------------------------------------
void BattleMapState::setMapData(MapData* data)
{
    map_data = data;
    area->setMapData(data);
}

//-----------------------------------------------------------
// ���R���j�b�g����
//-----------------------------------------------------------
void BattleMapState::createMyUnit(CardData* card, int x, int y)
{
    unit->createMyUnit(card, x, y);
    for (int px = x; px < x + card->size_x; px++)
    for (int py = y; py < y + card->size_y; py++) {
        area->addAreaMpMy(card->mp, px, py);
        area->subAreaMpEn(card->mp, px, py);
    }
}

//-----------------------------------------------------------
// �G�R���j�b�g����
//-----------------------------------------------------------
void BattleMapState::createEnUnit(CardData* card, int x, int y)
{
    unit->createEnUnit(card, x, y);
    for (int px = x; px < x + card->size_x; px++)
    for (int py = y; py < y + card->size_y; py++) {
        area->addAreaMpEn(card->mp, px, py);
        area->subAreaMpMy(card->mp, px, py);
    }
}
//-----------------------------------------------------------
// ���R���_����
//-----------------------------------------------------------
void BattleMapState::createMyBase(CardData* card)
{
    int x = map_data->player_base_x;
    int y = map_data->player_base_y;
    unit->createMyUnit(card, x, y);
    for (int px = x - 2; px < x + card->size_x + 2; px++)
    for (int py = y - 2; py < y + card->size_y + 2; py++)
    if (map_data->isFloor(px, py))
    area->addAreaMpMy(BattleAreaState::AREA_MP_MAX, px, py);
}
//-----------------------------------------------------------
// �G�R���_����
//-----------------------------------------------------------
void BattleMapState::createEnBase(CardData* card)
{
    int x = map_data->enemy_base_x;
    int y = map_data->enemy_base_y;
    unit->createEnUnit(card, x, y);
    for (int px = x - 2; px < x + card->size_x + 2; px++)
    for (int py = y - 2; py < y + card->size_y + 2; py++)
    if (map_data->isFloor(px, py))
    area->addAreaMpEn(BattleAreaState::AREA_MP_MAX, px, py);
}

//-----------------------------------------------------------
// ���R���j�b�g��ԍX�V
//-----------------------------------------------------------
void BattleMapState::updateMyUnitState()
{
    for (int i = 0; i < unit->getMyUnitNum(); i++) {
        BattleUnitState *state = unit->getMyUnit();
        if (state->getSurvivalTime() <= 60) continue;  // �����E�F�C�g
        int com = state->getNowCommand();
        //---- �{��
        if (state->getName() == "���_") return;
        //---- �ҋ@���
        if (state->getNowState() == BattleUnitState::STATE_WAIT) {
            if (com == BattleUnitState::COM_WAIT) actionWait(state);
            if (com == BattleUnitState::COM_MOVE) actionFree(state);
            if (com == BattleUnitState::COM_ATTACK) actionAttack(state);
            if (com == BattleUnitState::COM_DEFENSE) actionDefense(state);
            if (com == BattleUnitState::COM_SPE_MOVE) actionSpeMove(state);
            if (com == BattleUnitState::COM_SPE_ATTACK) actionSpeAttack(state);
            if (com == BattleUnitState::COM_SPE_DEFENSE) actionSpeDefense(state);
        }
    }
}

//-----------------------------------------------------------
// �G�R���j�b�g��ԍX�V
//-----------------------------------------------------------
void BattleMapState::updateEnUnitState()
{
    for (int i = 0; i < unit->getEnUnitNum(); i++) {
        BattleUnitState *state = unit->getEnUnit();
        if (state->getSurvivalTime() <= 60) continue;  // �����E�F�C�g
        int com = state->getNowCommand();
        //---- �{��
        if (state->getName() == "���_") return;
        //---- �ҋ@���
        if (state->getNowState() == BattleUnitState::STATE_WAIT) {
            if (com == BattleUnitState::COM_WAIT) actionWait(state);
            if (com == BattleUnitState::COM_MOVE) actionFree(state);
            if (com == BattleUnitState::COM_ATTACK) actionAttack(state);
            if (com == BattleUnitState::COM_DEFENSE) actionDefense(state);
            if (com == BattleUnitState::COM_SPE_MOVE) actionSpeMove(state);
            if (com == BattleUnitState::COM_SPE_ATTACK) actionSpeAttack(state);
            if (com == BattleUnitState::COM_SPE_DEFENSE) actionSpeDefense(state);
        }
    }
}

//-----------------------------------------------------------
// ���j�b�g�����邩
// ����Ftrue�A���Ȃ��Ffalse
//-----------------------------------------------------------
bool BattleMapState::isUnit(int x, int y)
{
    BattleUnitState *state = unit->getUnit(x, y);
    if (state == NULL) return false;
    return true;
}

//-----------------------------------------------------------
// �w����W�Ɏ��R���j�b�g�����邩
// ����Ftrue�A���Ȃ��Ffalse
//-----------------------------------------------------------
bool BattleMapState::isMyUnit(int x, int y)
{
    BattleUnitState *state = unit->getUnit(x, y);
    if (state == NULL) return false;
    if (state->getWhich() == state->UNIT_ENE) return false;
    return true;
}
bool BattleMapState::isEnUnit(int x, int y)
{
    BattleUnitState *state = unit->getUnit(x, y);
    if (state == NULL) return false;
    if (state->getWhich() == state->UNIT_MY) return false;
    return true;
}

//-----------------------------------------------------------
// ���͂Ɉړ��ł���}�X�����邩
// ����Ftrue�A���Ȃ��Ffalse
//-----------------------------------------------------------
bool BattleMapState::isMobileSpaceAround(BattleUnitState* u, int x, int y)
{
    for (int dire = 0; dire < 4; dire++) {
        if (isMobileSpaceDire(u, dire, x, y)) return true;
    }
    return false;
}

//-----------------------------------------------------------
// �w������̃}�X�Ɉړ��ł��邩
// �ł���Ftrue�A�ł��Ȃ��Ffalse
//-----------------------------------------------------------
bool BattleMapState::isMobileSpaceDire(BattleUnitState* u, int x, int y)
{
    if (!unit->isSpaceDire(x, y)) return false; // ��Ȃ�
    if (!map_data->isFloor(x, y)) return false; // ���ȊO
    return true;
}
bool BattleMapState::isMobileSpaceDire(BattleUnitState* u, int dire, int x, int y)
{
    // ��
    if (dire == Define::DIRE_UP) {
        for (int i = 0; i < u->getSizeX(); i++) {
            if (!isMobileSpaceDire(u, x + i, y - 1))
                return false;
        }
    }
    // �E
    else if (dire == Define::DIRE_RIGHT) {
        for (int i = 0; i < u->getSizeY(); i++) {
            if (!isMobileSpaceDire(u, x + u->getSizeX(), y + i))
                return false;
        }
    }
    // ��
    else if (dire == Define::DIRE_DOWN) {
        for (int i = 0; i < u->getSizeX(); i++) {
            if (!isMobileSpaceDire(u, x + i, y + u->getSizeY()))
                return false;
        }
    }
    // ��
    else if (dire == Define::DIRE_LEFT) {
        for (int i = 0; i < u->getSizeY(); i++) {
            if (!isMobileSpaceDire(u, x - 1, y + i))
                return false;
        }
    }
    return true;
}

//-----------------------------------------------------------
// �w������Ɉړ�
//-----------------------------------------------------------
void BattleMapState::moveDire(BattleUnitState* state, int dire)
{
    int dx[] = { 0, 1, 0, -1 };
    int dy[] = { -1, 0, 1, 0 };
    int px = state->getX() + dx[dire];
    int py = state->getY() + dy[dire];

    unit->moveDire(state, dire);
    //---- ���R���j�b�g
    if (state->getWhich() == state->UNIT_MY) {
        for (int i = px; i < px + state->getSizeX(); i++)
        for (int j = py; j < py + state->getSizeY(); j++) {
            area->addAreaMpMy(state->getMp(), i, j);
            area->subAreaMpEn(state->getMp(), i, j);
        }
    }
    //---- �G�R���j�b�g
    if (state->getWhich() == state->UNIT_ENE) {
        for (int i = px; i < px + state->getSizeX(); i++)
        for (int j = py; j < py + state->getSizeY(); j++) {
            area->addAreaMpEn(state->getMp(), i, j);
            area->subAreaMpMy(state->getMp(), i, j);
        }
    }
}

//-----------------------------------------------------------
// �U��
// att��rec�ɍU��
//-----------------------------------------------------------
void BattleMapState::attack(BattleUnitState* att, BattleUnitState* rec)
{
    // �l�v�Z
    // att�U���� - rec����� * att�̑����ɑ΂���rec�̑ϋv��
    double def = rec->getDef() * (rec->getAttrDef(att->getAttribute()) / 100);
    def = 800 / (def * 10);
    if (def >= 1) def = 1;
    int dame = (int)(att->getPow() * def);
    dame = (int)(((rand() % 40) + 80) / 100.0 * dame);
    dame = max(dame, 1);

    att->comAttackDire(getDirection(att, rec));
    rec->comReceivedDamage(dame);
    damage.push(new BattleDamageState(dame,
        rec->getPixelX() + rec->getImageSizeX() / 2,
        rec->getPixelY() + rec->getImageSizeY() / 2,
        rec->getWhich()));
}

//-----------------------------------------------------------
// �����擾
//-----------------------------------------------------------
int BattleMapState::getDirection(BattleUnitState* from, BattleUnitState* to)
{
    for (int x1 = from->getX(); x1 < from->getX() + from->getSizeX(); x1++)
    for (int y1 = from->getY(); y1 < from->getY() + from->getSizeY(); y1++)
    for (int x2 = to->getX(); x2 < to->getX() + to->getSizeX(); x2++)
    for (int y2 = to->getY(); y2 < to->getY() + to->getSizeY(); y2++) {
        int x = x2 - x1;
        int y = y2 - y1;
        if (y < 0 && x == 0) return Define::DIRE_UP;
        if (x > 0 && y == 0) return Define::DIRE_RIGHT;
        if (y > 0 && x == 0) return Define::DIRE_DOWN;
        if (x < 0 && y == 0) return Define::DIRE_LEFT;
    }
    return 0;
}
int BattleMapState::getDire(BattleUnitState* from, BattleUnitState* to)
{
    return getDire(from, from->getX(), from->getY(), to->getX(), to->getY());
}
int BattleMapState::getDire(BattleUnitState* from, int to_x, int to_y)
{
    return getDire(from, from->getX(), from->getY(), to_x, to_y);
}
int BattleMapState::getDire(BattleUnitState* u, int from_x, int from_y, int to_x, int to_y)
{
    // ��
    if (from_x == to_x && from_y > to_y) {
        if (isMobileSpaceDire(u, Define::DIRE_UP, from_x, from_y)) return Define::DIRE_UP;
        if (rand() % 2) {
            if (isMobileSpaceDire(u, Define::DIRE_RIGHT, from_x, from_y)) return Define::DIRE_RIGHT;
            if (isMobileSpaceDire(u, Define::DIRE_LEFT, from_x, from_y)) return Define::DIRE_LEFT;
        }
        else {
            if (isMobileSpaceDire(u, Define::DIRE_LEFT, from_x, from_y)) return Define::DIRE_LEFT;
            if (isMobileSpaceDire(u, Define::DIRE_RIGHT, from_x, from_y)) return Define::DIRE_RIGHT;
        }
    }
    // �E
    if (from_x < to_x && from_y == to_y) {
        if (isMobileSpaceDire(u, Define::DIRE_RIGHT, from_x, from_y)) return Define::DIRE_RIGHT;
        if (rand() % 2) {
            if (isMobileSpaceDire(u, Define::DIRE_UP, from_x, from_y)) return Define::DIRE_UP;
            if (isMobileSpaceDire(u, Define::DIRE_DOWN, from_x, from_y)) return Define::DIRE_DOWN;
        }
        else {
            if (isMobileSpaceDire(u, Define::DIRE_DOWN, from_x, from_y)) return Define::DIRE_DOWN;
            if (isMobileSpaceDire(u, Define::DIRE_UP, from_x, from_y)) return Define::DIRE_UP;
        }
    }
    // ��
    if (from_x == to_x && from_y < to_y) {
        if (isMobileSpaceDire(u, Define::DIRE_DOWN, from_x, from_y)) return Define::DIRE_DOWN;
        if (rand() % 2) {
            if (isMobileSpaceDire(u, Define::DIRE_RIGHT, from_x, from_y)) return Define::DIRE_RIGHT;
            if (isMobileSpaceDire(u, Define::DIRE_LEFT, from_x, from_y)) return Define::DIRE_LEFT;
        }
        else {
            if (isMobileSpaceDire(u, Define::DIRE_LEFT, from_x, from_y)) return Define::DIRE_LEFT;
            if (isMobileSpaceDire(u, Define::DIRE_RIGHT, from_x, from_y)) return Define::DIRE_RIGHT;
        }
        
    }
    // ��
    if (from_x > to_x && from_y == to_y) {
        if (isMobileSpaceDire(u, Define::DIRE_LEFT, from_x, from_y)) return Define::DIRE_LEFT;
        if (rand() % 2) {
            if (isMobileSpaceDire(u, Define::DIRE_UP, from_x, from_y)) return Define::DIRE_UP;
            if (isMobileSpaceDire(u, Define::DIRE_DOWN, from_x, from_y)) return Define::DIRE_DOWN;
        }
        else {
            if (isMobileSpaceDire(u, Define::DIRE_DOWN, from_x, from_y)) return Define::DIRE_DOWN;
            if (isMobileSpaceDire(u, Define::DIRE_UP, from_x, from_y)) return Define::DIRE_UP;
        }
    }
    // �E��
    if (from_x < to_x && from_y > to_y) {
        if (rand() % 2) {
            if (isMobileSpaceDire(u, Define::DIRE_UP, from_x, from_y)) return Define::DIRE_UP;
            if (isMobileSpaceDire(u, Define::DIRE_RIGHT, from_x, from_y)) return Define::DIRE_RIGHT;
        }
        else {
            if (isMobileSpaceDire(u, Define::DIRE_RIGHT, from_x, from_y)) return Define::DIRE_RIGHT;
            if (isMobileSpaceDire(u, Define::DIRE_UP, from_x, from_y)) return Define::DIRE_UP;
        }
    }
    // �E��
    if (from_x < to_x && from_y < to_y) {
        if (rand() % 2) {
            if (isMobileSpaceDire(u, Define::DIRE_DOWN, from_x, from_y)) return Define::DIRE_DOWN;
            if (isMobileSpaceDire(u, Define::DIRE_RIGHT, from_x, from_y)) return Define::DIRE_RIGHT;
        }
        else {
            if (isMobileSpaceDire(u, Define::DIRE_RIGHT, from_x, from_y)) return Define::DIRE_RIGHT;
            if (isMobileSpaceDire(u, Define::DIRE_DOWN, from_x, from_y)) return Define::DIRE_DOWN;
        }
    }
    // ����
    if (from_x > to_x && from_y < to_y) {
        if (rand() % 2) {
            if (isMobileSpaceDire(u, Define::DIRE_DOWN, from_x, from_y)) return Define::DIRE_DOWN;
            if (isMobileSpaceDire(u, Define::DIRE_LEFT, from_x, from_y)) return Define::DIRE_LEFT;
        }
        else {
            if (isMobileSpaceDire(u, Define::DIRE_LEFT, from_x, from_y)) return Define::DIRE_LEFT;
            if (isMobileSpaceDire(u, Define::DIRE_DOWN, from_x, from_y)) return Define::DIRE_DOWN;
        }
    }
    // ����
    if (from_x > to_x && from_y > to_y) {
        if (rand() % 2) {
            if (isMobileSpaceDire(u, Define::DIRE_UP, from_x, from_y)) return Define::DIRE_UP;
            if (isMobileSpaceDire(u, Define::DIRE_LEFT, from_x, from_y)) return Define::DIRE_LEFT;
        }
        else {
            if (isMobileSpaceDire(u, Define::DIRE_LEFT, from_x, from_y)) return Define::DIRE_LEFT;
            if (isMobileSpaceDire(u, Define::DIRE_UP, from_x, from_y)) return Define::DIRE_UP;
        }
    }
    return -1;
}

//-----------------------------------------------------------
// �_���[�W�X�V
//-----------------------------------------------------------
void BattleMapState::updateDamage()
{
    int n = damage.size();
    for (int i = 0; i < n; i++) {
        BattleDamageState *d = damage.front();
        damage.pop();
        d->update();
        if (d->isDelete()) {
            delete(d);
            continue;
        }
        damage.push(d);
    }
}

//===========================================================
// ���j�b�g�s��
//===========================================================
//-----------------------------------------------------------
// �ҋ@���[�h���̍s��
//-----------------------------------------------------------
void BattleMapState::actionWait(BattleUnitState* state)
{

}
//-----------------------------------------------------------
// ���R���[�h���̍s��
//-----------------------------------------------------------
void BattleMapState::actionFree(BattleUnitState* state)
{
    /*
    �����_���ňړ�
    */
    int x = state->getX();
    int y = state->getY();
    BattleUnitState* u;

    //---- �U���͈͂ɓG������΍U��
    u = unit->getAroundEnemy(state);
    if (u != NULL && u->isAlive()) {
        attack(state, u);
        return;
    }

    //---- ������ꏊ���Ȃ���Αҋ@
    if (!isMobileSpaceAround(state, x, y)) return;
    //---- ���R�ړ�
    int dire;
    while (1) {
        dire = rand() % 4;
        if (isMobileSpaceDire(state, dire, x, y)) break;
    }
    moveDire(state, dire);
}

//-----------------------------------------------------------
// �U�����[�h���̍s��
//-----------------------------------------------------------
void BattleMapState::actionAttack(BattleUnitState* state)
{
    /*
    �G�R�x�[�X�Ɍ������Đi�R
    ���G�͈͓��ɓG������Ό������Ă����U��
    */
    int x = state->getX();
    int y = state->getY();
    int which = state->getWhich();
    int gx = (which == state->UNIT_MY) ? map_data->enemy_base_x : map_data->player_base_x;
    int gy = (which == state->UNIT_MY) ? map_data->enemy_base_y : map_data->player_base_y;
    int dire;
    BattleUnitState* u;


    //---- �U���͈͂ɓG������΍U��
    u = unit->getAroundEnemy(state);
    if (u != NULL && u->isAlive()) {
        attack(state, u);
        return;
    }
    // ������ꏊ���Ȃ���Αҋ@
    if (!isMobileSpaceAround(state, x, y)) return;
    //---- ���G
    u = unit->getSearchRangeEnemy(state);
    if (u != NULL) {
        dire = getDire(state, u);
        if (dire != -1) {
            moveDire(state, dire);
            return;
        }
    }
    //---- �i�R
    dire = getDire(state, gx, gy);
    if (dire != -1) {
        moveDire(state, dire);
        return;
    }
}
//-----------------------------------------------------------
// ������[�h���̍s��
//-----------------------------------------------------------
void BattleMapState::actionDefense(BattleUnitState* state)
{
    /*
    ���R�x�[�X�t�߂�p�j
    ���G�͈͓��ɓG������Ό������Ă����U��
    */
    int x = state->getX();
    int y = state->getY();
    int which = state->getWhich();
    int gx = (which == state->UNIT_MY) ? map_data->player_base_x : map_data->enemy_base_x;
    int gy = (which == state->UNIT_MY) ? map_data->player_base_y : map_data->enemy_base_y;
    int dire;
    BattleUnitState* u;

    //---- �U���͈͂ɓG������΍U��
    u = unit->getAroundEnemy(state);
    if (u != NULL && u->isAlive()) {
        attack(state, u);
        return;
    }
    // ������ꏊ���Ȃ���Αҋ@
    if (!isMobileSpaceAround(state, x, y)) {
        return;
    }
    //---- ���G
    u = unit->getSearchRangeEnemy(state);
    if (u != NULL) {
        dire = getDire(state, u);
        if (dire != -1) {
            moveDire(state, dire);
            return;
        }
    }
    //---- ���R�ɖ߂�
    dire = getDire(state, gx, gy);
    if (dire != -1) {
        moveDire(state, dire);
        return;
    }
}
//-----------------------------------------------------------
// �w��ړ����[�h���̍s��
//-----------------------------------------------------------
void BattleMapState::actionSpeMove(BattleUnitState* state)
{
    /*
    �w��ꏊ�Ɉړ�
    �w��ꏊ�ɂ����玩�R�s��
    ���G�͈͓��ɓG������Ό������Ă����U��
    */

    int x = state->getX();
    int y = state->getY();
    int which = state->getWhich();
    int gx = state->getMovePosX();
    int gy = state->getMovePosY();
    int dire;
    BattleUnitState* u;

    //---- ���łɖړI�n
    if (x == gx && y == gy) {
        state->setNowCommand(BattleUnitState::COM_WAIT);
        return;
    }
    //---- �U���͈͂ɓG������΍U��
    u = unit->getAroundEnemy(state);
    if (u != NULL && u->isAlive()) {
        attack(state, u);
        return;
    }
    //---- ������ꏊ���Ȃ���Αҋ@
    if (!isMobileSpaceAround(state, x, y)) {
        return;
    }
    /*
    //---- ���G
    u = unit->getSearchRangeEnemy(state);
    if (u != NULL) {
        dire = getDire(state, u);
        if (dire != -1) {
            moveDire(state, dire);
            return;
        }
    }
    */
    //---- �w��ꏊ�Ɉړ�
    dire = getDire(state, gx, gy);
    if (dire != -1) {
        moveDire(state, dire);
        return;
    }
}
//-----------------------------------------------------------
// �w��U�����[�h���̍s��
//-----------------------------------------------------------
void BattleMapState::actionSpeAttack(BattleUnitState* state)
{
    /*
    �w�胆�j�b�g�ɍU��
    �w�胆�j�b�g�����S���Ă���Ύ��R�ړ��ɐ؂�ւ�
    ���G�͈͓��ɓG������Ό������Ă����U��
    */
    if (state->getSpecifiedUnit() == NULL) {
        state->setNowCommand(BattleUnitState::COM_ATTACK);
        return;
    }

    int x = state->getX();
    int y = state->getY();
    int which = state->getWhich();
    int gx = state->getSpecifiedUnit()->getX();
    int gy = state->getSpecifiedUnit()->getY();
    int dire;
    BattleUnitState* u;

    //---- �U���͈͂ɓG������΍U��
    u = unit->getAroundEnemy(state);
    if (u != NULL && u->isAlive()) {
        attack(state, u);
        return;
    }
    //---- ������ꏊ���Ȃ���Αҋ@
    if (!isMobileSpaceAround(state, x, y)) {
        return;
    }
    /*
    //---- ���G
    u = unit->getSearchRangeEnemy(state);
    if (u != NULL) {
        dire = getDire(state, u);
        if (dire != -1) {
            moveDire(state, dire);
            return;
        }
    }
    */
    //---- �w�胆�j�b�g�߂��Ɉړ�
    dire = getDire(state, gx, gy);
    if (dire != -1) {
        moveDire(state, dire);
        return;
    }
}
//-----------------------------------------------------------
// �w��h�䃂�[�h���̍s��
//-----------------------------------------------------------
void BattleMapState::actionSpeDefense(BattleUnitState* state)
{
    /*
    �w�胆�j�b�g����q
    �w�胆�j�b�g�����S���Ă���Ύ��R�ړ��ɐ؂�ւ�
    ���G�͈͓��ɓG������Ό������Ă����U��
    */
    if (state->getSpecifiedUnit() == NULL) {
        state->setNowCommand(BattleUnitState::COM_DEFENSE);
        return;
    }

    int x = state->getX();
    int y = state->getY();
    int which = state->getWhich();
    int gx = state->getSpecifiedUnit()->getX();
    int gy = state->getSpecifiedUnit()->getY();
    int dire;
    BattleUnitState* u;

    //---- �U���͈͂ɓG������΍U��
    u = unit->getAroundEnemy(state);
    if (u != NULL && u->isAlive()) {
        attack(state, u);
        return;
    }
    //---- ������ꏊ���Ȃ���Αҋ@
    if (!isMobileSpaceAround(state, x, y)) {
        return;
    }
    /*
    //---- ���G
    u = unit->getSearchRangeEnemy(state);
    if (u != NULL) {
        dire = getDire(state, u);
        if (dire != -1) {
            moveDire(state, dire);
            return;
        }
    }
    */
    //---- �w�胆�j�b�g�߂��Ɉړ�
    dire = getDire(state, gx, gy);
    if (dire != -1) {
        moveDire(state, dire);
        return;
    }
}

//===========================================================
// �X�L��
//===========================================================
//-----------------------------------------------------------
// �t���[�����߂̃X�L��
//-----------------------------------------------------------
void BattleMapState::frameFirstSkil(BattleUnitState* u)
{
    for (int i = 0; i < u->getSkilNum(); i++) {
        switch (u->getSkil(i)) {
        case 1: skil1(u); break;
        }
    }
}

//-----------------------------------------------------------
// �t���[���I���̃X�L��
//-----------------------------------------------------------
void BattleMapState::frameEndSkil(BattleUnitState* u)
{
    u->initIncrementStatus();      // �㏸�X�e�[�^�X������
}

//-----------------------------------------------------------
// �X�L��1
//-----------------------------------------------------------
// ���͂P�}�X���́u�X���C���v�Ɩ��̕t�����j�b�g�̐����P�O����
// �U���͂��㏸����
//-----------------------------------------------------------
void BattleMapState::skil1(BattleUnitState* u)
{
    for (int y = u->getY() - 1; y <= u->getY() + u->getSizeY(); y++) {
        for (int x = u->getX() - 1; x <= u->getX() + u->getSizeX(); x++) {
            BattleUnitState *m = unit->getUnit(x, y);
            if (m == NULL) continue;
            if (m->getWhich() != u->getWhich()) continue;
            if (x >= u->getX() && x < u->getX() + u->getSizeX() &&
                y >= u->getY() && y < u->getY() + u->getSizeY()) continue;
            // �X���C���Ɩ��̕t����
            if (strstr(m->getName().c_str(), "�X���C��") != NULL) {
                u->incrementPow(10);
            }
        }
    }
}

//===========================================================
// getter
//===========================================================
MapData *BattleMapState::getMapData() { return map_data; }
BattleAreaState *BattleMapState::getAreaState() { return area; }
BattleAllUnitState *BattleMapState::getUnitState() { return unit; }
int BattleMapState::getDamageStateNum() { return (int)damage.size(); }
BattleDamageState* BattleMapState::getDamageState() {
    BattleDamageState* d = damage.front();
    damage.pop();
    damage.push(d);
    return d;
}