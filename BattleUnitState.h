//-----------------------------------------------------------
// BattleUnitState.h
// ユニットデータ情報
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "CardData.h"
#include "MapData.h"
#include "Define.h"
#include <string>
#include <vector>

class BattleUnitState {
public:
    static const int STATE_WAIT = 0;   // 待機状態
    static const int STATE_MOVE = 1;   // 移動状態
    static const int STATE_ATTACK = 2; // 攻撃状態
    static const int STATE_SKILL = 3;  // スキル中
    static const int STATE_DEATH_ANI = 4; // 死亡アニメーション
    static const int STATE_DEATH = 5;  // 死亡

    static const int UNIT_MY = 0;      // 自軍ユニット
    static const int UNIT_ENE = 1;     // 敵軍ユニット
    static const int COM_WAIT = 0;     // 命令_待機
    static const int COM_MOVE = 1;     // 命令_行動 自由
    static const int COM_ATTACK = 2;   // 命令_攻撃
    static const int COM_DEFENSE = 3;  // 命令_防御
    static const int COM_SPE_MOVE = 4; // 命令_指定移動
    static const int COM_SPE_ATTACK = 5;  // 命令_指定攻撃
    static const int COM_SPE_DEFENSE = 6; // 命令_指定防御

    static const int TIME_DEATH_ANI = 30; // 時間_死亡アニメーション
private:
    // ステータス
    int which;                  // どっちのユニットか
    int size_x;                 // 大きさx
    int size_y;                 // 大きさy
    int image_size_x;           // 画像の大きさx
    int image_size_y;           // 画像の大きさy
    int pos_x;                  // マス目の座標x
    int pos_y;                  // マス目の座標y
    int pixel_x;                // ピクセル座標x
    int pixel_y;                // ピクセル座標y
    int id;                     // 種族ID
    int individual_id;          // 個別ID
    std::string name;           // 名前
    int kind;                   // 種類
    int mp;                     // 必要魔力
    int max_hp;                 // 最大体力値
    int hp;                     // 現在の体力値
    int pow;                    // 攻撃力
    int def;                    // 防御力
    int mspeed;                 // 移動速度
    int aspeed;                 // 攻撃速度
    int attribute;              // 自分の属性
    int search_range;           // 索敵範囲
    int increment_hp;           // 増加体力量
    int increment_pow;          // 増加攻撃力量
    int increment_def;          // 増加防御力量
    int increment_mspeed;       // 増加移動速度量
    int increment_aspeed;       // 増加攻撃速度量
    int fire;                   // 火
    int water;                  // 水
    int ice;                    // 氷
    int elect;                  // 電
    int dark;                   // 闇
    int light;                  // 光
    int earth;                  // 地
    int poison;                 // 毒
    int wind;                   // 風
    std::vector<int> skil;      // スキル
    std::vector<int> equipment; // 装備
    // 状態
    int now_state;              // 現在の状態
    int now_dire;               // 現在の向き
    int now_command;            // 現在の命令
    int move_x;                 // x方向にどれだけ動いたか
    int move_y;                 // y方向にどれだけ動いたか
    int cnt_frame;              // 何フレーム経過したか
    int survival_time;          // 生存時間

    int move_pos_x;             // 目的地x
    int move_pos_y;             // 目的地y
    BattleUnitState* specified_unit; // 指定ユニット
public:
    BattleUnitState();          // コンストラクタ
    ~BattleUnitState();         // デストラクタ
    void init();                // 初期化
    void update();              // 更新
    void setState(CardData*, int, int,int,int);  // ユニットのステータスセット
    void moveDire(int);         // 指定方向に移動
    bool isAlive();             // 生きているか
    int getImage();             // 現在の画像取得
    void initIncrementStatus(); // 上昇能力初期化
    void incrementHp(int);      // 体力上昇
    void incrementPow(int);     // 攻撃力上昇
    void incrementDef(int);     // 守備力上昇
    void incrementMSpeed(int);  // 移動速度上昇
    void incrementASpeed(int);  // 攻撃速度上昇

    // コマンド
    void comAttackDire(int);     // 指定方向に攻撃
    void comMoveDire(int);       // 指定方向に移動
    void comReceivedDamage(int); // ダメージを受ける

    // setter
    void setNowCommand(int);               // コマンド設定
    void setMovePos(int, int);             // 移動先設定
    void setAttackUnit(BattleUnitState*);  // 攻撃対象ユニット指定
    void setDefenseUnit(BattleUnitState*); // 防御対象ユニット指定
    void setSpecifiedUnit(BattleUnitState*);
    // getter
    int getWhich();             // どちらのユニットか
    int getSizeX();             // 大きさx取得
    int getSizeY();             // 大きさy取得
    int getX();                 // 座標x取得
    int getY();                 // 座標y取得
    int getImageSizeX();        // 画像サイズx取得 
    int getImageSizeY();        // 画像サイズy取得
    int getPixelX();            // ピクセル座標x
    int getPixelY();            // ピクセル座標y
    int getId();                // ID取得
    std::string getName();      // 名前取得
    int getKind();              // カードの種類取得
    int getMp();                // MP取得
    int getMaxHp();             // 最大HP取得
    int getHp();                // HP取得
    int getPow();               // 攻撃力取得
    int getDef();               // 守備力取得
    int getMoveSpeed();         // 移動速度取得
    int getAttackSpeed();       // 攻撃速度取得
    int getAttribute();         // 自属性取得
    int getSearchRange();       // 索敵範囲取得
    int getIncremenattributetHp();       // 増加体力量取得
    int getIncrementHp();
    int getIncrementPow();      // 増加攻撃力量取得
    int getIncrementDef();      // 増加守備力量取得
    int getIncrementMoveSpeed();   // 増加移動速度量取得
    int getIncrementAttackSpeed(); // 増加攻撃速度量取得
    int getAttrDef(int);           // 属性守備力取得
    int getSkilNum();              // スキル数取得
    int getSkil(int);              // スキル取得
    std::vector<int> getSkil();    // スキル取得
    int getEquipmentNum();         // 装備数取得
    int getEquipment(int);         // 装備取得

    int getNowState();             // 現在の状態取得
    int getNowDire();              // 現在の向き取得
    int getNowCommand();           // 現在のコマンド取得
    BattleUnitState* getSpecifiedUnit();  // 指定ユニット取得
    int getMovePosX();           // 目的x取得
    int getMovePosY();           // 目的地y取得
    int getSurvivalTime();       // 生存時間取得
};