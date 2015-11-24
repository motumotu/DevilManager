//-----------------------------------------------------------
// BattleUnitState.cpp
// ユニットデータ情報
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#include "BattleUnitState.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
BattleUnitState::BattleUnitState()
{
    init();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
BattleUnitState::~BattleUnitState()
{

}

//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void BattleUnitState::init()
{
    which = 0;              // どっちのユニットか
    size_x = 1;             // 大きさx
    size_y = 1;             // 大きさy
    image_size_x = 50;      // 画像の大きさx
    image_size_y = 50;      // 画像の大きさy
    pos_x = 0;              // 座標x
    pos_y = 0;              // 座標y
    pixel_x = 0;            // ピクセル座標x
    pixel_y = 0;            // ピクセル座標y
    id = 0;                 // ID
    individual_id = 0;      // 個別ID
    name = "";              // 名前
    kind = 0;               // 種類
    mp = 0;                 // 必要魔力
    max_hp = 0;             // 最大体力値
    hp = 0;                 // 現在の体力値
    pow = 0;                // 攻撃力
    def = 0;                // 防御力
    mspeed = 0;             // 移動速度
    aspeed = 0;             // 攻撃速度
    attribute = CardData::ATTR_NONE;  // 属性
    search_range = 1;       // 索敵範囲
    increment_hp = 0;       // 増加体力量
    increment_pow = 0;      // 増加攻撃力量
    increment_def = 0;      // 増加防御力量
    increment_mspeed = 0;   // 増加移動速度量
    increment_aspeed = 0;   // 増加攻撃速度量
    skil.clear();           // スキル
    equipment.clear();      // 装備
    fire = 0;               // 火
    water = 0;              // 水
    ice = 0;                // 氷
    elect = 0;              // 電
    dark = 0;               // 闇
    light = 0;              // 光
    earth = 0;              // 地
    poison = 0;             // 毒
    wind = 0;               // 風

    now_state = STATE_WAIT;        // 待機状態
    now_dire = Define::DIRE_DOWN;  // 下向き
    now_command = COM_MOVE;        // 動く
    move_x = 0;                    // x方向にどれだけ動いたか
    move_y = 0;                    // y方向にどれだけ動いたか
    cnt_frame = 0;                 // 経過フレーム数
    survival_time = 0;             // 生存時間
}

//-----------------------------------------------------------
// 更新
//-----------------------------------------------------------
void BattleUnitState::update()
{
    cnt_frame++;        // 経過フレーム数更新
    survival_time++;    // 生存時間更新
    //---- 待機状態
    if (now_state == STATE_WAIT) {

    }
    //---- 移動状態
    else if (now_state == STATE_MOVE) {
        if (cnt_frame % 2)
            moveDire(now_dire);
    }
    //---- 攻撃状態
    else if (now_state == STATE_ATTACK) {
        if (cnt_frame >= 10000.0 / aspeed) {
            now_state = STATE_WAIT;
            cnt_frame = 0;
        }
    }
    //---- 死亡アニメーション状態
    else if (now_state == STATE_DEATH_ANI) {
        if (cnt_frame >= TIME_DEATH_ANI) {
            now_state = STATE_DEATH;
        }
    }
}

//-----------------------------------------------------------
// 指定方向に移動
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
// 生きているか
// 生きている：true、死：false
//-----------------------------------------------------------
bool BattleUnitState::isAlive()
{
    return (hp > 0) ? true : false;
}

//-----------------------------------------------------------
// ユニットのステータスセット
//-----------------------------------------------------------
void BattleUnitState::setState(CardData* card_data, int x, int y, int ind, int _which)
{
    which = _which;
    pos_x = x;              // 座標x
    pos_y = y;              // 座標y
    size_x = card_data->size_x;  // 大きさx
    size_y = card_data->size_y;  // 大きさy
    image_size_x = card_data->image_size_x; // 画像サイズx
    image_size_y = card_data->image_size_y; // 画像サイズy
    pixel_x = x * MapData::MAP_IMAGE_SIZE;  // 描画用座標x
    pixel_y = y * MapData::MAP_IMAGE_SIZE;  // 描画用座標y
    id = card_data->id;     // ID
    individual_id = ind;    // 固有ID
    name = card_data->name; // 名前
    mp = card_data->mp;     // 必要魔力
    max_hp = card_data->hp; // 最大体力値
    hp = card_data->hp;     // 現在の体力値
    pow = card_data->pow;   // 攻撃力
    def = card_data->def;   // 防御力
    mspeed = card_data->move_speed;   // 移動速度
    aspeed = card_data->attack_speed; // 攻撃速度
    attribute = card_data->attribute; // 自属性
    search_range = card_data->search_range;  // 索敵範囲
    increment_hp = 0;       // 増加体力量
    increment_pow = 0;      // 増加攻撃力量
    increment_def = 0;      // 増加防御力量
    increment_mspeed = 0;   // 増加移動速度量
    increment_aspeed = 0;   // 増加攻撃速度量
    //---- スキル
    for (int i = 0; i < (int)card_data->skil.size(); i++) {
        skil.push_back(card_data->skil[i]);
    }
    equipment.clear();      // 装備
    fire = card_data->fire;    // 火
    water = card_data->water;  // 水
    ice = card_data->ice;      // 氷
    elect = card_data->elect;  // 電
    dark = card_data->dark;    // 闇
    light = card_data->light;  // 光
    earth = card_data->earth;  // 地
    poison = card_data->poison;// 毒
    wind = card_data->wind;    // 風
}

//-----------------------------------------------------------
// コマンド_指定方向に攻撃
//-----------------------------------------------------------
void BattleUnitState::comAttackDire(int dire)
{
    now_state = STATE_ATTACK;
    now_dire = dire;
    cnt_frame = 0;
}
//-----------------------------------------------------------
// コマンド_指定方向に移動
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
// コマンド_ダメージを受ける
//-----------------------------------------------------------
void BattleUnitState::comReceivedDamage(int dame)
{
    hp -= dame;
    // 死亡
    if (hp <= 0) {
        hp = 0;
        now_state = STATE_DEATH_ANI;
        cnt_frame = 0;
    }
}

//-----------------------------------------------------------
// 現在の画像取得
//-----------------------------------------------------------
int BattleUnitState::getImage()
{
    if (name == "拠点") {
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
// 上昇能力初期化
//-----------------------------------------------------------
void BattleUnitState::initIncrementStatus()
{
    increment_hp = 0;           // 増加体力量
    increment_pow = 0;          // 増加攻撃力量
    increment_def = 0;          // 増加防御力量
    increment_mspeed = 0;       // 増加移動速度量
    increment_aspeed = 0;       // 増加攻撃速度量
}

//-----------------------------------------------------------
// ステータス上昇
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
        puts("範囲外参照：BattleUnitState::getSkil()");
        return 0;
    }
    return skil[n];
}
std::vector<int> BattleUnitState::getSkil() { return skil; }
int BattleUnitState::getEquipmentNum() { return (int)equipment.size(); }
int BattleUnitState::getEquipment(int n) {
    if (n >= getEquipmentNum()) {
        puts("範囲外参照：BattleUnitState::getEquipmentNum()");
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