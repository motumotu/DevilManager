//-----------------------------------------------------------
// BattleMapState.cpp
// 対戦マップ情報
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#include "BattleMapState.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
BattleMapState::BattleMapState(GameData* _game_data)
{
    game_data = _game_data;
    srand((unsigned)time(NULL));
    unit = new BattleAllUnitState(_game_data);
    area = new BattleAreaState();
    init();     // 初期処理
}

//-----------------------------------------------------------
// デストラクタ
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
// 初期化
//-----------------------------------------------------------
void BattleMapState::init()
{
    while (!damage.empty()) damage.pop();
}

//-----------------------------------------------------------
// 対戦情報初期化
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
// 対戦設定
//-----------------------------------------------------------
void BattleMapState::battleSetting()
{
    // 拠点生成
    createMyBase(game_data->getAllCardData()->getCardData(0));
    createEnBase(game_data->getAllCardData()->getCardData(0));
    getAreaState()->discriminationArea();
}

//-----------------------------------------------------------
// 更新
//-----------------------------------------------------------
void BattleMapState::update()
{
    //---- フレーム初めスキル
    for (int i = 0; i < unit->getMyUnitNum(); i++)
        frameFirstSkil(unit->getMyUnit());
    for (int i = 0; i < unit->getEnUnitNum(); i++)
        frameFirstSkil(unit->getEnUnit());
    updateDamage();         // ダメージ表示更新
    updateMyUnitState();    // 自軍ユニット状態更新
    updateEnUnitState();    // 敵軍ユニット状態更新
    unit->update();         // ユニット情報更新
    area->update();         // 領域情報更新
    //---- フレーム終わりスキル
    for (int i = 0; i < unit->getMyUnitNum(); i++)
        frameEndSkil(unit->getMyUnit());
    for (int i = 0; i < unit->getEnUnitNum(); i++)
        frameEndSkil(unit->getEnUnit());
}

//-----------------------------------------------------------
// 設定
//-----------------------------------------------------------
void BattleMapState::setMapData(MapData* data)
{
    map_data = data;
    area->setMapData(data);
}

//-----------------------------------------------------------
// 自軍ユニット生成
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
// 敵軍ユニット生成
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
// 自軍拠点生成
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
// 敵軍拠点生成
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
// 自軍ユニット状態更新
//-----------------------------------------------------------
void BattleMapState::updateMyUnitState()
{
    for (int i = 0; i < unit->getMyUnitNum(); i++) {
        BattleUnitState *state = unit->getMyUnit();
        if (state->getSurvivalTime() <= 60) continue;  // 召喚ウェイト
        int com = state->getNowCommand();
        //---- 施設
        if (state->getName() == "拠点") return;
        //---- 待機状態
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
// 敵軍ユニット状態更新
//-----------------------------------------------------------
void BattleMapState::updateEnUnitState()
{
    for (int i = 0; i < unit->getEnUnitNum(); i++) {
        BattleUnitState *state = unit->getEnUnit();
        if (state->getSurvivalTime() <= 60) continue;  // 召喚ウェイト
        int com = state->getNowCommand();
        //---- 施設
        if (state->getName() == "拠点") return;
        //---- 待機状態
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
// ユニットがいるか
// いる：true、いない：false
//-----------------------------------------------------------
bool BattleMapState::isUnit(int x, int y)
{
    BattleUnitState *state = unit->getUnit(x, y);
    if (state == NULL) return false;
    return true;
}

//-----------------------------------------------------------
// 指定座標に自軍ユニットがいるか
// いる：true、いない：false
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
// 周囲に移動できるマスがあるか
// いる：true、いない：false
//-----------------------------------------------------------
bool BattleMapState::isMobileSpaceAround(BattleUnitState* u, int x, int y)
{
    for (int dire = 0; dire < 4; dire++) {
        if (isMobileSpaceDire(u, dire, x, y)) return true;
    }
    return false;
}

//-----------------------------------------------------------
// 指定方向のマスに移動できるか
// できる：true、できない：false
//-----------------------------------------------------------
bool BattleMapState::isMobileSpaceDire(BattleUnitState* u, int x, int y)
{
    if (!unit->isSpaceDire(x, y)) return false; // 空なし
    if (!map_data->isFloor(x, y)) return false; // 床以外
    return true;
}
bool BattleMapState::isMobileSpaceDire(BattleUnitState* u, int dire, int x, int y)
{
    // 上
    if (dire == Define::DIRE_UP) {
        for (int i = 0; i < u->getSizeX(); i++) {
            if (!isMobileSpaceDire(u, x + i, y - 1))
                return false;
        }
    }
    // 右
    else if (dire == Define::DIRE_RIGHT) {
        for (int i = 0; i < u->getSizeY(); i++) {
            if (!isMobileSpaceDire(u, x + u->getSizeX(), y + i))
                return false;
        }
    }
    // 下
    else if (dire == Define::DIRE_DOWN) {
        for (int i = 0; i < u->getSizeX(); i++) {
            if (!isMobileSpaceDire(u, x + i, y + u->getSizeY()))
                return false;
        }
    }
    // 左
    else if (dire == Define::DIRE_LEFT) {
        for (int i = 0; i < u->getSizeY(); i++) {
            if (!isMobileSpaceDire(u, x - 1, y + i))
                return false;
        }
    }
    return true;
}

//-----------------------------------------------------------
// 指定方向に移動
//-----------------------------------------------------------
void BattleMapState::moveDire(BattleUnitState* state, int dire)
{
    int dx[] = { 0, 1, 0, -1 };
    int dy[] = { -1, 0, 1, 0 };
    int px = state->getX() + dx[dire];
    int py = state->getY() + dy[dire];

    unit->moveDire(state, dire);
    //---- 自軍ユニット
    if (state->getWhich() == state->UNIT_MY) {
        for (int i = px; i < px + state->getSizeX(); i++)
        for (int j = py; j < py + state->getSizeY(); j++) {
            area->addAreaMpMy(state->getMp(), i, j);
            area->subAreaMpEn(state->getMp(), i, j);
        }
    }
    //---- 敵軍ユニット
    if (state->getWhich() == state->UNIT_ENE) {
        for (int i = px; i < px + state->getSizeX(); i++)
        for (int j = py; j < py + state->getSizeY(); j++) {
            area->addAreaMpEn(state->getMp(), i, j);
            area->subAreaMpMy(state->getMp(), i, j);
        }
    }
}

//-----------------------------------------------------------
// 攻撃
// attがrecに攻撃
//-----------------------------------------------------------
void BattleMapState::attack(BattleUnitState* att, BattleUnitState* rec)
{
    // 値計算
    // att攻撃力 - rec守備力 * attの属性に対するrecの耐久力
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
// 向き取得
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
    // 上
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
    // 右
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
    // 下
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
    // 左
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
    // 右上
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
    // 右下
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
    // 左下
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
    // 左上
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
// ダメージ更新
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
// ユニット行動
//===========================================================
//-----------------------------------------------------------
// 待機モード時の行動
//-----------------------------------------------------------
void BattleMapState::actionWait(BattleUnitState* state)
{

}
//-----------------------------------------------------------
// 自由モード時の行動
//-----------------------------------------------------------
void BattleMapState::actionFree(BattleUnitState* state)
{
    /*
    ランダムで移動
    */
    int x = state->getX();
    int y = state->getY();
    BattleUnitState* u;

    //---- 攻撃範囲に敵がいれば攻撃
    u = unit->getAroundEnemy(state);
    if (u != NULL && u->isAlive()) {
        attack(state, u);
        return;
    }

    //---- 動ける場所がなければ待機
    if (!isMobileSpaceAround(state, x, y)) return;
    //---- 自由移動
    int dire;
    while (1) {
        dire = rand() % 4;
        if (isMobileSpaceDire(state, dire, x, y)) break;
    }
    moveDire(state, dire);
}

//-----------------------------------------------------------
// 攻撃モード時の行動
//-----------------------------------------------------------
void BattleMapState::actionAttack(BattleUnitState* state)
{
    /*
    敵軍ベースに向かって進軍
    索敵範囲内に敵がいれば向かっていき攻撃
    */
    int x = state->getX();
    int y = state->getY();
    int which = state->getWhich();
    int gx = (which == state->UNIT_MY) ? map_data->enemy_base_x : map_data->player_base_x;
    int gy = (which == state->UNIT_MY) ? map_data->enemy_base_y : map_data->player_base_y;
    int dire;
    BattleUnitState* u;


    //---- 攻撃範囲に敵がいれば攻撃
    u = unit->getAroundEnemy(state);
    if (u != NULL && u->isAlive()) {
        attack(state, u);
        return;
    }
    // 動ける場所がなければ待機
    if (!isMobileSpaceAround(state, x, y)) return;
    //---- 索敵
    u = unit->getSearchRangeEnemy(state);
    if (u != NULL) {
        dire = getDire(state, u);
        if (dire != -1) {
            moveDire(state, dire);
            return;
        }
    }
    //---- 進軍
    dire = getDire(state, gx, gy);
    if (dire != -1) {
        moveDire(state, dire);
        return;
    }
}
//-----------------------------------------------------------
// 守備モード時の行動
//-----------------------------------------------------------
void BattleMapState::actionDefense(BattleUnitState* state)
{
    /*
    自軍ベース付近を徘徊
    索敵範囲内に敵がいれば向かっていき攻撃
    */
    int x = state->getX();
    int y = state->getY();
    int which = state->getWhich();
    int gx = (which == state->UNIT_MY) ? map_data->player_base_x : map_data->enemy_base_x;
    int gy = (which == state->UNIT_MY) ? map_data->player_base_y : map_data->enemy_base_y;
    int dire;
    BattleUnitState* u;

    //---- 攻撃範囲に敵がいれば攻撃
    u = unit->getAroundEnemy(state);
    if (u != NULL && u->isAlive()) {
        attack(state, u);
        return;
    }
    // 動ける場所がなければ待機
    if (!isMobileSpaceAround(state, x, y)) {
        return;
    }
    //---- 索敵
    u = unit->getSearchRangeEnemy(state);
    if (u != NULL) {
        dire = getDire(state, u);
        if (dire != -1) {
            moveDire(state, dire);
            return;
        }
    }
    //---- 自軍に戻る
    dire = getDire(state, gx, gy);
    if (dire != -1) {
        moveDire(state, dire);
        return;
    }
}
//-----------------------------------------------------------
// 指定移動モード時の行動
//-----------------------------------------------------------
void BattleMapState::actionSpeMove(BattleUnitState* state)
{
    /*
    指定場所に移動
    指定場所についたら自由行動
    索敵範囲内に敵がいれば向かっていき攻撃
    */

    int x = state->getX();
    int y = state->getY();
    int which = state->getWhich();
    int gx = state->getMovePosX();
    int gy = state->getMovePosY();
    int dire;
    BattleUnitState* u;

    //---- すでに目的地
    if (x == gx && y == gy) {
        state->setNowCommand(BattleUnitState::COM_WAIT);
        return;
    }
    //---- 攻撃範囲に敵がいれば攻撃
    u = unit->getAroundEnemy(state);
    if (u != NULL && u->isAlive()) {
        attack(state, u);
        return;
    }
    //---- 動ける場所がなければ待機
    if (!isMobileSpaceAround(state, x, y)) {
        return;
    }
    /*
    //---- 索敵
    u = unit->getSearchRangeEnemy(state);
    if (u != NULL) {
        dire = getDire(state, u);
        if (dire != -1) {
            moveDire(state, dire);
            return;
        }
    }
    */
    //---- 指定場所に移動
    dire = getDire(state, gx, gy);
    if (dire != -1) {
        moveDire(state, dire);
        return;
    }
}
//-----------------------------------------------------------
// 指定攻撃モード時の行動
//-----------------------------------------------------------
void BattleMapState::actionSpeAttack(BattleUnitState* state)
{
    /*
    指定ユニットに攻撃
    指定ユニットが死亡していれば自由移動に切り替え
    索敵範囲内に敵がいれば向かっていき攻撃
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

    //---- 攻撃範囲に敵がいれば攻撃
    u = unit->getAroundEnemy(state);
    if (u != NULL && u->isAlive()) {
        attack(state, u);
        return;
    }
    //---- 動ける場所がなければ待機
    if (!isMobileSpaceAround(state, x, y)) {
        return;
    }
    /*
    //---- 索敵
    u = unit->getSearchRangeEnemy(state);
    if (u != NULL) {
        dire = getDire(state, u);
        if (dire != -1) {
            moveDire(state, dire);
            return;
        }
    }
    */
    //---- 指定ユニット近くに移動
    dire = getDire(state, gx, gy);
    if (dire != -1) {
        moveDire(state, dire);
        return;
    }
}
//-----------------------------------------------------------
// 指定防御モード時の行動
//-----------------------------------------------------------
void BattleMapState::actionSpeDefense(BattleUnitState* state)
{
    /*
    指定ユニットを護衛
    指定ユニットが死亡していれば自由移動に切り替え
    索敵範囲内に敵がいれば向かっていき攻撃
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

    //---- 攻撃範囲に敵がいれば攻撃
    u = unit->getAroundEnemy(state);
    if (u != NULL && u->isAlive()) {
        attack(state, u);
        return;
    }
    //---- 動ける場所がなければ待機
    if (!isMobileSpaceAround(state, x, y)) {
        return;
    }
    /*
    //---- 索敵
    u = unit->getSearchRangeEnemy(state);
    if (u != NULL) {
        dire = getDire(state, u);
        if (dire != -1) {
            moveDire(state, dire);
            return;
        }
    }
    */
    //---- 指定ユニット近くに移動
    dire = getDire(state, gx, gy);
    if (dire != -1) {
        moveDire(state, dire);
        return;
    }
}

//===========================================================
// スキル
//===========================================================
//-----------------------------------------------------------
// フレーム初めのスキル
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
// フレーム終わりのスキル
//-----------------------------------------------------------
void BattleMapState::frameEndSkil(BattleUnitState* u)
{
    u->initIncrementStatus();      // 上昇ステータス初期化
}

//-----------------------------------------------------------
// スキル1
//-----------------------------------------------------------
// 周囲１マス内の「スライム」と名の付くユニットの数ｘ１０だけ
// 攻撃力が上昇する
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
            // スライムと名の付くか
            if (strstr(m->getName().c_str(), "スライム") != NULL) {
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