//-----------------------------------------------------------
// BattleAllUnitState.h
// 全ユニットデータ情報
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "BattleUnitState.h"
#include "CardData.h"
#include "Define.h"
#include "GameData.h"
#include <queue>

class BattleAllUnitState {
private:
    std::queue<BattleUnitState*> my_unit;   // 自軍ユニット
    std::queue<BattleUnitState*> en_unit;   // 敵軍ユニット
    int all_unit_num;                       // 固定ID用
    BattleUnitState *map_unit[MapData::MAP_SIZE_MAX][MapData::MAP_SIZE_MAX];
    GameData *game_data;
    AllCardData *card_data;
public:
    BattleAllUnitState(GameData*);           // コンストラクタ
    ~BattleAllUnitState();          // デストラクタ
    void init();                    // 初期化
    void battleInit();              // 対戦情報初期化
    void update();                  // 更新
    void createMyUnit(CardData*, int, int);  // 自軍ユニット生成
    void createEnUnit(CardData*, int, int);  // 敵軍ユニット生成
    BattleUnitState* getAroundEnemyMy(BattleUnitState*);// 周囲4マスの敵を取得
    BattleUnitState* getAroundEnemyEn(BattleUnitState*);// 周囲4マスの敵を取得
    BattleUnitState* getAroundEnemy(BattleUnitState*);  // 周囲4マスの敵を取得
    BattleUnitState* getSearchRangeEnemy(BattleUnitState*); // 索敵範囲内の敵を取得
    bool isSpaceAround(int, int);    // 周囲に空きますがあるか
    bool isSpaceDire(int, int);      // 指定方向が空きますか
    void moveDire(BattleUnitState*, int);    // 指定方向に移動
    BattleUnitState *popMyUnit();      // 自軍先頭ユニット取り出し
    void pushMyUnit(BattleUnitState*); // 自軍ユニットを入れる
    BattleUnitState *popEnUnit();      // 敵軍先頭ユニット取り出し
    void pushEnUnit(BattleUnitState*); // 敵軍ユニットを入れる
    void deleteUnit(BattleUnitState*); // ユニット削除

    //---- ユニットスキル
    void deathSkil(BattleUnitState*);  // 死亡時スキル発動

    //---- getter
    BattleUnitState *getUnit(int, int); // 指定座標のユニット取得
    int getMyUnitNum();             // 自軍ユニット数取得
    int getEnUnitNum();             // 敵軍ユニット数取得
    BattleUnitState *getMyUnit();   // 自軍ユニット情報取得
    BattleUnitState *getEnUnit();   // 敵軍ユニット情報取得
};