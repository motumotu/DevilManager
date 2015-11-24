//-----------------------------------------------------------
// BattleUnitState.cpp
// ���j�b�g�f�[�^���
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#include "BattleUnitState.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
BattleUnitState::BattleUnitState()
{
    init();
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
BattleUnitState::~BattleUnitState()
{

}

//-----------------------------------------------------------
// ������
//-----------------------------------------------------------
void BattleUnitState::init()
{
    which = 0;              // �ǂ����̃��j�b�g��
    size_x = 1;             // �傫��x
    size_y = 1;             // �傫��y
    image_size_x = 50;      // �摜�̑傫��x
    image_size_y = 50;      // �摜�̑傫��y
    pos_x = 0;              // ���Wx
    pos_y = 0;              // ���Wy
    pixel_x = 0;            // �s�N�Z�����Wx
    pixel_y = 0;            // �s�N�Z�����Wy
    id = 0;                 // ID
    individual_id = 0;      // ��ID
    name = "";              // ���O
    kind = 0;               // ���
    mp = 0;                 // �K�v����
    max_hp = 0;             // �ő�̗͒l
    hp = 0;                 // ���݂̗̑͒l
    pow = 0;                // �U����
    def = 0;                // �h���
    mspeed = 0;             // �ړ����x
    aspeed = 0;             // �U�����x
    attribute = CardData::ATTR_NONE;  // ����
    search_range = 1;       // ���G�͈�
    increment_hp = 0;       // �����̗͗�
    increment_pow = 0;      // �����U���͗�
    increment_def = 0;      // �����h��͗�
    increment_mspeed = 0;   // �����ړ����x��
    increment_aspeed = 0;   // �����U�����x��
    skil.clear();           // �X�L��
    equipment.clear();      // ����
    fire = 0;               // ��
    water = 0;              // ��
    ice = 0;                // �X
    elect = 0;              // �d
    dark = 0;               // ��
    light = 0;              // ��
    earth = 0;              // �n
    poison = 0;             // ��
    wind = 0;               // ��

    now_state = STATE_WAIT;        // �ҋ@���
    now_dire = Define::DIRE_DOWN;  // ������
    now_command = COM_MOVE;        // ����
    move_x = 0;                    // x�����ɂǂꂾ����������
    move_y = 0;                    // y�����ɂǂꂾ����������
    cnt_frame = 0;                 // �o�߃t���[����
    survival_time = 0;             // ��������
}

//-----------------------------------------------------------
// �X�V
//-----------------------------------------------------------
void BattleUnitState::update()
{
    cnt_frame++;        // �o�߃t���[�����X�V
    survival_time++;    // �������ԍX�V
    //---- �ҋ@���
    if (now_state == STATE_WAIT) {

    }
    //---- �ړ����
    else if (now_state == STATE_MOVE) {
        if (cnt_frame % 2)
            moveDire(now_dire);
    }
    //---- �U�����
    else if (now_state == STATE_ATTACK) {
        if (cnt_frame >= 10000.0 / aspeed) {
            now_state = STATE_WAIT;
            cnt_frame = 0;
        }
    }
    //---- ���S�A�j���[�V�������
    else if (now_state == STATE_DEATH_ANI) {
        if (cnt_frame >= TIME_DEATH_ANI) {
            now_state = STATE_DEATH;
        }
    }
}

//-----------------------------------------------------------
// �w������Ɉړ�
//-----------------------------------------------------------
void BattleUnitState::moveDire(int dire)
{
    int dx[] = { 0, 1, 0, -1 };
    int dy[] = { -1, 0, 1, 0 };
    int speed = (int)(mspeed / 100.0);
    if (speed < 1) speed = 1;
    if (speed > MapData::MAP_IMAGE_SIZE)
        speed = MapData::MAP_IMAGE_SIZE;
    now_state = STATE_MOVE;
    int m_x = dx[dire] * speed;
    int m_y = dy[dire] * speed;
    move_x += m_x;
    move_y += m_y;

    if (move_x >= MapData::MAP_IMAGE_SIZE) {
        m_x -= move_x - MapData::MAP_IMAGE_SIZE;
        now_state = STATE_WAIT;
    }
    else if (move_x <= -MapData::MAP_IMAGE_SIZE) {
        m_x -= move_x + MapData::MAP_IMAGE_SIZE;
        now_state = STATE_WAIT;
    }
    else if (move_y >= MapData::MAP_IMAGE_SIZE) {
        m_y -= move_y - MapData::MAP_IMAGE_SIZE;
        now_state = STATE_WAIT;
    }
    else if (move_y <= -MapData::MAP_IMAGE_SIZE) {
        m_y -= move_y + MapData::MAP_IMAGE_SIZE;
        now_state = STATE_WAIT;
    }
    pixel_x += m_x;
    pixel_y += m_y;
}

//-----------------------------------------------------------
// �����Ă��邩
// �����Ă���Ftrue�A���Ffalse
//-----------------------------------------------------------
bool BattleUnitState::isAlive()
{
    return (hp > 0) ? true : false;
}

//-----------------------------------------------------------
// ���j�b�g�̃X�e�[�^�X�Z�b�g
//-----------------------------------------------------------
void BattleUnitState::setState(CardData* card_data, int x, int y, int ind, int _which)
{
    which = _which;
    pos_x = x;              // ���Wx
    pos_y = y;              // ���Wy
    size_x = card_data->size_x;  // �傫��x
    size_y = card_data->size_y;  // �傫��y
    image_size_x = card_data->image_size_x; // �摜�T�C�Yx
    image_size_y = card_data->image_size_y; // �摜�T�C�Yy
    pixel_x = x * MapData::MAP_IMAGE_SIZE;  // �`��p���Wx
    pixel_y = y * MapData::MAP_IMAGE_SIZE;  // �`��p���Wy
    id = card_data->id;     // ID
    individual_id = ind;    // �ŗLID
    name = card_data->name; // ���O
    mp = card_data->mp;     // �K�v����
    max_hp = card_data->hp; // �ő�̗͒l
    hp = card_data->hp;     // ���݂̗̑͒l
    pow = card_data->pow;   // �U����
    def = card_data->def;   // �h���
    mspeed = card_data->move_speed;   // �ړ����x
    aspeed = card_data->attack_speed; // �U�����x
    attribute = card_data->attribute; // ������
    search_range = card_data->search_range;  // ���G�͈�
    increment_hp = 0;       // �����̗͗�
    increment_pow = 0;      // �����U���͗�
    increment_def = 0;      // �����h��͗�
    increment_mspeed = 0;   // �����ړ����x��
    increment_aspeed = 0;   // �����U�����x��
    //---- �X�L��
    for (int i = 0; i < (int)card_data->skil.size(); i++) {
        skil.push_back(card_data->skil[i]);
    }
    equipment.clear();      // ����
    fire = card_data->fire;    // ��
    water = card_data->water;  // ��
    ice = card_data->ice;      // �X
    elect = card_data->elect;  // �d
    dark = card_data->dark;    // ��
    light = card_data->light;  // ��
    earth = card_data->earth;  // �n
    poison = card_data->poison;// ��
    wind = card_data->wind;    // ��
}

//-----------------------------------------------------------
// �R�}���h_�w������ɍU��
//-----------------------------------------------------------
void BattleUnitState::comAttackDire(int dire)
{
    now_state = STATE_ATTACK;
    now_dire = dire;
    cnt_frame = 0;
}
//-----------------------------------------------------------
// �R�}���h_�w������Ɉړ�
//-----------------------------------------------------------
void BattleUnitState::comMoveDire(int dire)
{
    int dx[] = { 0, 1, 0, -1 };
    int dy[] = { -1, 0, 1, 0 };
    now_state = STATE_MOVE;
    now_dire = dire;
    pos_x += dx[dire];
    pos_y += dy[dire];
    move_x = 0;
    move_y = 0;
    cnt_frame = 0;
}
//-----------------------------------------------------------
// �R�}���h_�_���[�W���󂯂�
//-----------------------------------------------------------
void BattleUnitState::comReceivedDamage(int dame)
{
    hp -= dame;
    // ���S
    if (hp <= 0) {
        hp = 0;
        now_state = STATE_DEATH_ANI;
        cnt_frame = 0;
    }
}

//-----------------------------------------------------------
// ���݂̉摜�擾
//-----------------------------------------------------------
int BattleUnitState::getImage()
{
    if (name == "���_") {
        return 0;
    }
    if (now_state == STATE_WAIT) {
        return now_dire * 4 + ((cnt_frame / 15) % 4);
    }
    if (now_state == STATE_MOVE) {
        return now_dire * 4 + ((int)(abs(move_x + move_y) / 6.25) % 4) + 16;
    }
    if (now_state == STATE_ATTACK) {
        //cnt_frame == 10000.0 / aspeed
        if (cnt_frame < 4000 / aspeed) {
            return now_dire * 4 + ((int)(cnt_frame * aspeed / 1000.0) % 4) + 32;
        }
        return now_dire * 4 + ((cnt_frame / 15) % 4);
    }
    if (now_state == STATE_DEATH_ANI) {
        return (cnt_frame * 4 / TIME_DEATH_ANI) % 4 + 48;
    }
    if (now_state == STATE_DEATH) {
        return 51;
    }
    return 0;
}

//-----------------------------------------------------------
// �㏸�\�͏�����
//-----------------------------------------------------------
void BattleUnitState::initIncrementStatus()
{
    increment_hp = 0;           // �����̗͗�
    increment_pow = 0;          // �����U���͗�
    increment_def = 0;          // �����h��͗�
    increment_mspeed = 0;       // �����ړ����x��
    increment_aspeed = 0;       // �����U�����x��
}

//-----------------------------------------------------------
// �X�e�[�^�X�㏸
//-----------------------------------------------------------
void BattleUnitState::incrementHp(int n)
{
    increment_hp += n;
    hp += n;
}
void BattleUnitState::incrementPow(int n)
{
    increment_pow += n;
}
void BattleUnitState::incrementDef(int n)
{
    increment_def += n;
}
void BattleUnitState::incrementMSpeed(int n)
{
    increment_mspeed += n;
}
void BattleUnitState::incrementASpeed(int n)
{
    increment_aspeed += n;
}

//===========================================================
// setter
//===========================================================
void BattleUnitState::setNowCommand(int com) {  now_command = com; }
void BattleUnitState::setMovePos(int x, int y) { move_pos_x = x; move_pos_y = y; }
void BattleUnitState::setAttackUnit(BattleUnitState* u) { specified_unit = u; }
void BattleUnitState::setDefenseUnit(BattleUnitState* u) { specified_unit = u; }
void BattleUnitState::setSpecifiedUnit(BattleUnitState* u) { specified_unit = u; }

//===========================================================
// getter
//===========================================================
int BattleUnitState::getWhich() { return which; }
int BattleUnitState::getSizeX() { return size_x; }
int BattleUnitState::getSizeY() { return size_y; }
int BattleUnitState::getX() { return pos_x; }
int BattleUnitState::getY() { return pos_y; }
int BattleUnitState::getImageSizeX() { return image_size_x; }
int BattleUnitState::getImageSizeY() { return image_size_y; }
int BattleUnitState::getPixelX() { return pixel_x; }
int BattleUnitState::getPixelY() { return pixel_y; }
int BattleUnitState::getId() { return id; }
std::string BattleUnitState::getName() { return name; }
int BattleUnitState::getKind() { return kind; }
int BattleUnitState::getMp() { return mp; }
int BattleUnitState::getMaxHp() { return max_hp + increment_hp; }
int BattleUnitState::getHp() { return hp; }
int BattleUnitState::getPow() { return pow + increment_pow; }
int BattleUnitState::getDef() { return def + increment_def; }
int BattleUnitState::getMoveSpeed() { return mspeed + increment_mspeed; }
int BattleUnitState::getAttackSpeed() { return aspeed + increment_aspeed; }
int BattleUnitState::getAttribute() { return attribute; }
int BattleUnitState::getSearchRange() { return search_range; }
int BattleUnitState::getIncrementHp() { return increment_hp; }
int BattleUnitState::getIncrementPow() { return increment_pow; }
int BattleUnitState::getIncrementDef() { return increment_def; }
int BattleUnitState::getIncrementMoveSpeed() { return increment_mspeed; }
int BattleUnitState::getIncrementAttackSpeed() { return increment_aspeed; }
int BattleUnitState::getAttrDef(int n) {
    switch (n) {
    case CardData::ATTR_FIRE: return fire;
    case CardData::ATTR_WATER: return water;
    case CardData::ATTR_ICE: return ice;
    case CardData::ATTR_ELECT: return elect;
    case CardData::ATTR_DARK: return dark;
    case CardData::ATTR_LIGHT: return light;
    case CardData::ATTR_EARTH: return earth;
    case CardData::ATTR_POISON: return poison;
    case CardData::ATTR_WIND: return wind;
    }
    return CardData::ATTR_NONE;
}
int BattleUnitState::getSkilNum() { return (int)skil.size(); }
int BattleUnitState::getSkil(int n) {
    if (n >= getSkilNum()) {
        puts("�͈͊O�Q�ƁFBattleUnitState::getSkil()");
        return 0;
    }
    return skil[n];
}
std::vector<int> BattleUnitState::getSkil() { return skil; }
int BattleUnitState::getEquipmentNum() { return (int)equipment.size(); }
int BattleUnitState::getEquipment(int n) {
    if (n >= getEquipmentNum()) {
        puts("�͈͊O�Q�ƁFBattleUnitState::getEquipmentNum()");
        return 0;
    }
    return equipment[n];
}
int BattleUnitState::getNowState() { return now_state; }
int BattleUnitState::getNowDire() { return now_dire; }
int BattleUnitState::getNowCommand() { return now_command; }
BattleUnitState* BattleUnitState::getSpecifiedUnit() { return specified_unit; }
int BattleUnitState::getMovePosX() { return move_pos_x; }
int BattleUnitState::getMovePosY() { return move_pos_y; }
int BattleUnitState::getSurvivalTime() { return survival_time; }