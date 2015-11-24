//-----------------------------------------------------------
// BattleAllUnitState.cpp
// �S���j�b�g�f�[�^���
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#include "BattleAllUnitState.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
BattleAllUnitState::BattleAllUnitState(GameData* _game_data)
{
    game_data = _game_data;
    card_data = game_data->getAllCardData();
    init();
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
BattleAllUnitState::~BattleAllUnitState()
{
    
}

//-----------------------------------------------------------
// ������
//-----------------------------------------------------------
void BattleAllUnitState::init()
{
    while (!my_unit.empty()) {
        BattleUnitState *u = my_unit.front();
        my_unit.pop();
        delete(u);
    }
    while (!en_unit.empty()) {
        BattleUnitState *u = en_unit.front();
        en_unit.pop();
        delete(u);
    }
    all_unit_num = 0;
    for (int i = 0; i < MapData::MAP_SIZE_MAX; i++) {
        for (int j = 0; j < MapData::MAP_SIZE_MAX; j++) {
            map_unit[i][j] = NULL;
        }
    }
}

//-----------------------------------------------------------
// �ΐ��񏉊���
//-----------------------------------------------------------
void BattleAllUnitState::battleInit()
{
    while (!my_unit.empty()) {
        BattleUnitState *u = my_unit.front();
        my_unit.pop();
        delete(u);
    }
    while (!en_unit.empty()) {
        BattleUnitState *u = en_unit.front();
        en_unit.pop();
        delete(u);
    }
    all_unit_num = 0;
    for (int i = 0; i < MapData::MAP_SIZE_MAX; i++) {
        for (int j = 0; j < MapData::MAP_SIZE_MAX; j++) {
            map_unit[i][j] = NULL;
        }
    }
}

//-----------------------------------------------------------
// �X�V
//-----------------------------------------------------------
void BattleAllUnitState::update()
{
    //---- ���R���j�b�g�s��
    for (int i = 0; i < getMyUnitNum(); i++) {
        BattleUnitState *unit = popMyUnit();
        // ���S
        if (unit->getNowState() == unit->STATE_DEATH) {
            deleteUnit(unit);
        }
        else {
            unit->update();
            pushMyUnit(unit);
        }
    }
    //---- �G�R���j�b�g�s��
    for (int i = 0; i < getEnUnitNum(); i++) {
        BattleUnitState *unit = popEnUnit();
        // ���S
        if (unit->getNowState() == unit->STATE_DEATH) {
            deleteUnit(unit);
        }
        else {
            unit->update();
            pushEnUnit(unit);
        }
    }
}

//-----------------------------------------------------------
// ���R���j�b�g����
//-----------------------------------------------------------
void BattleAllUnitState::createMyUnit(CardData *card_data, int x, int y)
{
    BattleUnitState *unit = new BattleUnitState();
    unit->setState(card_data, x, y, all_unit_num++, BattleUnitState::UNIT_MY);
    for (int py = 0; py < card_data->size_y; py++) {
        for (int px = 0; px < card_data->size_x; px++) {
            map_unit[y + py][x + px] = unit;
        }
    }
    my_unit.push(unit);
}

//-----------------------------------------------------------
// �G�R���j�b�g����
//-----------------------------------------------------------
void BattleAllUnitState::createEnUnit(CardData *card_data, int x, int y)
{
    BattleUnitState *unit = new BattleUnitState();
    unit->setState(card_data, x, y, all_unit_num++, BattleUnitState::UNIT_ENE);
    for (int py = 0; py < card_data->size_y; py++) {
        for (int px = 0; px < card_data->size_x; px++) {
            map_unit[y + py][x + px] = unit;
        }
    }
    en_unit.push(unit);
}

//-----------------------------------------------------------
// ���͂̓G���擾
//-----------------------------------------------------------
BattleUnitState* BattleAllUnitState::getAroundEnemyMy(BattleUnitState* unit)
{
    int x = unit->getX();
    int y = unit->getY();
    int dx[] = { 0, 1, 0, -1 };
    int dy[] = { -1, 0, 1, 0 };
    // ��
    for (int i = 0; i < unit->getSizeX(); i++) {
        int px = x + i;
        int py = y - 1;
        if (px < 0 || px >= MapData::MAP_SIZE_MAX ||
            py < 0 || py >= MapData::MAP_SIZE_MAX) continue;
        if (map_unit[py][px] == NULL) continue;
        if (map_unit[py][px]->getWhich() == BattleUnitState::UNIT_ENE) {
            return map_unit[py][px];
        }
    }
    // �E
    for (int i = 0; i < unit->getSizeY(); i++) {
        int px = x + unit->getSizeX();
        int py = y + i;
        if (px < 0 || px >= MapData::MAP_SIZE_MAX ||
            py < 0 || py >= MapData::MAP_SIZE_MAX) continue;
        if (map_unit[py][px] == NULL) continue;
        if (map_unit[py][px]->getWhich() == BattleUnitState::UNIT_ENE) {
            return map_unit[py][px];
        }
    }
    // ��
    for (int i = 0; i < unit->getSizeX(); i++) {
        int px = x + i;
        int py = y + unit->getSizeY();
        if (px < 0 || px >= MapData::MAP_SIZE_MAX ||
            py < 0 || py >= MapData::MAP_SIZE_MAX) continue;
        if (map_unit[py][px] == NULL) continue;
        if (map_unit[py][px]->getWhich() == BattleUnitState::UNIT_ENE) {
            return map_unit[py][px];
        }
    }
    // ��
    for (int i = 0; i < unit->getSizeY(); i++) {
        int px = x - 1;
        int py = y + i;
        if (px < 0 || px >= MapData::MAP_SIZE_MAX ||
            py < 0 || py >= MapData::MAP_SIZE_MAX) continue;
        if (map_unit[py][px] == NULL) continue;
        if (map_unit[py][px]->getWhich() == BattleUnitState::UNIT_ENE) {
            return map_unit[py][px];
        }
    }
    return NULL;
}

//-----------------------------------------------------------
// ���͂̓G���擾
//-----------------------------------------------------------
BattleUnitState* BattleAllUnitState::getAroundEnemyEn(BattleUnitState* unit)
{
    int x = unit->getX();
    int y = unit->getY();
    int dx[] = { 0, 1, 0, -1 };
    int dy[] = { -1, 0, 1, 0 };
    // ��
    for (int i = 0; i < unit->getSizeX(); i++) {
        int px = x + i;
        int py = y - 1;
        if (px < 0 || px >= MapData::MAP_SIZE_MAX ||
            py < 0 || py >= MapData::MAP_SIZE_MAX) continue;
        if (map_unit[py][px] == NULL) continue;
        if (map_unit[py][px]->getWhich() == BattleUnitState::UNIT_MY) {
            return map_unit[py][px];
        }
    }
    // �E
    for (int i = 0; i < unit->getSizeY(); i++) {
        int px = x + unit->getSizeX();
        int py = y + i;
        if (px < 0 || px >= MapData::MAP_SIZE_MAX ||
            py < 0 || py >= MapData::MAP_SIZE_MAX) continue;
        if (map_unit[py][px] == NULL) continue;
        if (map_unit[py][px]->getWhich() == BattleUnitState::UNIT_MY) {
            return map_unit[py][px];
        }
    }
    // ��
    for (int i = 0; i < unit->getSizeX(); i++) {
        int px = x + i;
        int py = y + unit->getSizeY();
        if (px < 0 || px >= MapData::MAP_SIZE_MAX ||
            py < 0 || py >= MapData::MAP_SIZE_MAX) continue;
        if (map_unit[py][px] == NULL) continue;
        if (map_unit[py][px]->getWhich() == BattleUnitState::UNIT_MY) {
            return map_unit[py][px];
        }
    }
    // ��
    for (int i = 0; i < unit->getSizeY(); i++) {
        int px = x - 1;
        int py = y + i;
        if (px < 0 || px >= MapData::MAP_SIZE_MAX ||
            py < 0 || py >= MapData::MAP_SIZE_MAX) continue;
        if (map_unit[py][px] == NULL) continue;
        if (map_unit[py][px]->getWhich() == BattleUnitState::UNIT_MY) {
            return map_unit[py][px];
        }
    }
    return NULL;
}
//-----------------------------------------------------------
// ���͂̓G���擾
//-----------------------------------------------------------
BattleUnitState* BattleAllUnitState::getAroundEnemy(BattleUnitState* unit)
{
    if (unit->getWhich() == BattleUnitState::UNIT_MY) {
        return getAroundEnemyMy(unit);
    }
    if (unit->getWhich() == BattleUnitState::UNIT_ENE) {
        return getAroundEnemyEn(unit);
    }
    return NULL;
}

//-----------------------------------------------------------
// ���G�͈͓��̓G���擾
//-----------------------------------------------------------
BattleUnitState* BattleAllUnitState::getSearchRangeEnemy(BattleUnitState* unit)
{
    BattleUnitState *u;
    for (int k = 0; k < unit->getSearchRange(); k++) {
        for (int y = unit->getY() - k; y <= unit->getY() + unit->getSizeY() + k; y++) {
            for (int x = unit->getX() - k; x <= unit->getX() + unit->getSizeX() + k; x++) {
                u = getUnit(x, y);
                if (u == NULL) continue;
                if (u->getWhich() != unit->getWhich()) return u;
            }
        }
    }
    return NULL;
}

//-----------------------------------------------------------
// ���͂ɋ󂫂܂������邩
// ����Ftrue�A�Ȃ��Ffalse
//-----------------------------------------------------------
bool BattleAllUnitState::isSpaceAround(int x, int y)
{
    int dx[] = { 0, 1, 0, -1 };
    int dy[] = { -1, 0, 1, 0 };

    for (int i = 0; i < 4; i++) {
        if (isSpaceDire(x + dx[i], y + dy[i]))
            return true;
    }
    return false;
}

//-----------------------------------------------------------
// �w��������󂫃}�X�����邩
// ����Ftrue�A�Ȃ��Ffalse
//-----------------------------------------------------------
bool BattleAllUnitState::isSpaceDire(int x, int y)
{
    if (x < 0 || x >= MapData::MAP_SIZE_MAX ||
        y < 0 || y >= MapData::MAP_SIZE_MAX) return false;
    if (map_unit[y][x] == NULL) return true;
    return false;
}

//-----------------------------------------------------------
// �w������Ɉړ�
//-----------------------------------------------------------
void BattleAllUnitState::moveDire(BattleUnitState* unit, int dire)
{
    int x = unit->getX();
    int y = unit->getY();

    // ��
    if (dire == Define::DIRE_UP) {
        for (int py = 0; py < unit->getSizeY(); py++) {
            for (int px = 0; px < unit->getSizeX(); px++) {
                map_unit[y + py - 1][x + px] = map_unit[y + py][x + px];
                map_unit[y + py][x + px] = NULL;
            }
        }
    }
    // �E
    else if (dire == Define::DIRE_RIGHT) {
        for (int px = unit->getSizeX() - 1; px >= 0; px--) {
            for (int py = 0; py < unit->getSizeY(); py++) {
                map_unit[y + py][x + px + 1] = map_unit[y + py][x + px];
                map_unit[y + py][x + px] = NULL;
            }
        }
    }
    // ��
    else if (dire == Define::DIRE_DOWN) {
        for (int py = unit->getSizeY() - 1; py >= 0; py--) {
            for (int px = 0; px < unit->getSizeX(); px++) {
                map_unit[y + py + 1][x + px] = map_unit[y + py][x + px];
                map_unit[y + py][x + px] = NULL;
            }
        }
    }
    // ��
    else if (dire == Define::DIRE_LEFT) {
        for (int px = 0; px < unit->getSizeX(); px++) {
            for (int py = 0; py < unit->getSizeY(); py++) {
                map_unit[y + py][x + px - 1] = map_unit[y + py][x + px];
                map_unit[y + py][x + px] = NULL;
            }
        }
    }
    unit->comMoveDire(dire);
}

//-----------------------------------------------------------
// ���R�擪���j�b�g���o��
//-----------------------------------------------------------
BattleUnitState *BattleAllUnitState::popMyUnit()
{
    BattleUnitState *unit = my_unit.front();
    my_unit.pop();
    return unit;
}
//-----------------------------------------------------------
// ���R���j�b�g�����
//-----------------------------------------------------------
void BattleAllUnitState::pushMyUnit(BattleUnitState* unit)
{
    my_unit.push(unit);
}
//-----------------------------------------------------------
// �G�R�擪���j�b�g���o��
//-----------------------------------------------------------
BattleUnitState *BattleAllUnitState::popEnUnit()
{
    BattleUnitState *unit = en_unit.front();
    en_unit.pop();
    return unit;
}
//-----------------------------------------------------------
// �G�R���j�b�g�����
//-----------------------------------------------------------
void BattleAllUnitState::pushEnUnit(BattleUnitState* unit)
{
    en_unit.push(unit);
}
//-----------------------------------------------------------
// ���j�b�g�폜
//-----------------------------------------------------------
void BattleAllUnitState::deleteUnit(BattleUnitState* unit)
{
    // �}�b�v�������
    for (int y = unit->getY(); y < unit->getY() + unit->getSizeY(); y++) {
        for (int x = unit->getX(); x < unit->getX() + unit->getSizeX(); x++) {
            map_unit[y][x] = NULL;
        }
    }
    // ���R�w�胆�j�b�g���X�V
    for (int i = 0; i < getMyUnitNum(); i++) {
        BattleUnitState*state = getMyUnit();
        if (state->getSpecifiedUnit() == unit) {
            state->setSpecifiedUnit(NULL);
        }
    }
    // �G�R�w�胆�j�b�g���X�V
    for (int i = 0; i < getEnUnitNum(); i++) {
        BattleUnitState*state = getEnUnit();
        if (state->getSpecifiedUnit() == unit) {
            state->setSpecifiedUnit(NULL);
        }
    }
    // ���S���X�L������
    deathSkil(unit);

    delete(unit);
}

//-----------------------------------------------------------
// ���S���X�L������
//-----------------------------------------------------------
void BattleAllUnitState::deathSkil(BattleUnitState* unit)
{
    int x = unit->getX();
    int y = unit->getY();
    int id = unit->getId();
    std::vector<int> skil = unit->getSkil();
    for (int i = 0; i < (int)skil.size(); i++) {
        //---- �X���C���Q�̏���
        if (skil[i] == 2) {
            if (unit->getWhich() == unit->UNIT_MY) {
                createMyUnit(card_data->getCardData(1), x, y);
                createMyUnit(card_data->getCardData(1), x + 1, y);
            }
            else {
                createEnUnit(card_data->getCardData(1), x, y);
                createEnUnit(card_data->getCardData(1), x + 1, y);
            }
        }

    }
}

//===========================================================
// getter
//===========================================================
BattleUnitState *BattleAllUnitState::getUnit(int x, int y) {
    if (x < 0 || x >= MapData::MAP_SIZE_MAX ||
        y < 0 || y >= MapData::MAP_SIZE_MAX) return NULL;
    return map_unit[y][x];
}
int BattleAllUnitState::getMyUnitNum() { return (int)my_unit.size(); }
int BattleAllUnitState::getEnUnitNum() { return (int)en_unit.size(); }
BattleUnitState *BattleAllUnitState::getMyUnit() {
    BattleUnitState *unit = my_unit.front();
    my_unit.pop();
    my_unit.push(unit);
    return unit;
}
BattleUnitState *BattleAllUnitState::getEnUnit() {
    BattleUnitState *unit = en_unit.front();
    en_unit.pop();
    en_unit.push(unit);
    return unit;
}