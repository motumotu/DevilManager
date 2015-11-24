//-----------------------------------------------------------
// BattleMapState.h
// 対戦マップ情報
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "MapData.h"
#include "BattleAllUnitState.h"
#include "BattleAreaState.h"
#include "BattleDamageState.h"
#include <queue>
#include <ctime>
#include <cstring>

class BattleMapState {
private:
    GameData *game_data;
    MapData *map_data;         // マップ情報
    BattleAreaState *area;     // エリア情報
    BattleAllUnitState *unit;  // ユニット情報
    std::queue<BattleDamageState*> damage; // ダメージ情報

public:
    BattleMapState(GameData*);             // コンストラクタ
    ~BattleMapState();                     // デストラクタ
    void init();                           // 初期化
    void battleInit();                     // 対戦情報初期化
    void battleSetting();                  // 対戦設定
    void update();                         // 更新
    void setMapData(MapData*);             // マップデータ設定
    void createMyUnit(CardData*,int,int);  // 自軍ユニット生成
    void createEnUnit(CardData*,int,int);  // 敵軍ユニット生成
    void createMyBase(CardData*);          // 自軍拠点生成
    void createEnBase(CardData*);          // 敵軍拠点生成
    void updateMyUnitState();              // 自軍ユニット状態更新
    void updateEnUnitState();              // 敵軍ユニット状態更新
    void updateDamage();                   // ダメージ更新
    bool isUnit(int, int);                 // ユニットがいるか
    bool isMyUnit(int, int);               // 指定座標に自軍ユニットがいるか
    bool isEnUnit(int, int);               // 指定座標に敵軍ユニットがいるか
    bool isMobileSpaceAround(BattleUnitState*, int, int);    // 周囲に移動できるマスがあるか
    bool isMobileSpaceDire(BattleUnitState*, int, int);      // 周囲に移動できるマスがあるか
    bool isMobileSpaceDire(BattleUnitState*, int, int, int); // 周囲に移動できるマスがあるか
    void moveDire(BattleUnitState*, int);                    // 指定方向に移動
    void attack(BattleUnitState*, BattleUnitState*);         // 攻撃
    int getDirection(BattleUnitState*, BattleUnitState*);    // 向き取得
    int getDire(BattleUnitState*, BattleUnitState*);         // 向き取得
    int getDire(BattleUnitState*, int, int);                 // 向き取得
    int getDire(BattleUnitState*, int, int, int, int);       // 向き取得

    //---- 行動
    void actionWait(BattleUnitState*);        // 待機モード時の行動
    void actionFree(BattleUnitState*);        // 自由モード時の行動
    void actionAttack(BattleUnitState*);      // 攻撃モード時の行動
    void actionDefense(BattleUnitState*);     // 守備モード時の行動
    void actionSpeMove(BattleUnitState*);     // 指定移動モード時の行動
    void actionSpeAttack(BattleUnitState*);   // 指定攻撃モード時の行動
    void actionSpeDefense(BattleUnitState*);  // 指定防御モード時の行動

    //---- スキル
    void frameFirstSkil(BattleUnitState*); // フレーム始めスキル
    void frameEndSkil(BattleUnitState*);   // フレーム終わりスキル
    void skil1(BattleUnitState*);          // スキル1
    
    //---- getter
    MapData *getMapData();                 // マップデータ取得
    BattleAreaState *getAreaState();       // エリア情報取得
    BattleAllUnitState *getUnitState();    // ユニット情報取得
    int getDamageStateNum();               // ダメージオブジェクト数表示
    BattleDamageState* getDamageState();   // ダメージオブジェクト取得
};