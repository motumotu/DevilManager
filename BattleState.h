//-----------------------------------------------------------
// BattleState.h
// 対戦画面の状態
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "BattleMapState.h"
#include "SystemData.h"
#include "BattleCardState.h"
#include "GameData.h"
#include "Algo.h"

class BattleState {
public:
    static const int PLAYER = 0;            // プレイヤー
    static const int ENEMY = 1;             // 敵
    static const int TURN_READY = 0;        // 対戦開始前
    static const int TURN_CURD_SELECT = 1;  // カード選択
    static const int TURN_CURD_USE = 2;     // カード使用
    static const int TURN_BATTLE = 3;       // バトル中
    static const int TURN_END = 4;          // 試合終了
    static const int TURN_TIME = 2000;      // 1ターンの時間
    static const int INIT_MP = 10;          // 初期魔力
    static const int ONETURN_MP = 5;        // 1ターンの魔力
    static const int BATTLE_SELECT_NORMAL = 0; // 通常選択モード
    static const int BATTLE_SELECT_AREA = 1;   // エリア選択モード
    static const int BATTLE_SELECT_MYUNIT = 2; // 自軍ユニット選択
    static const int BATTLE_SELECT_ENUNIT = 3; // 敵軍ユニット選択
    // 座標
    static const int BUTTON_CANCEL_TOP_X = 675;
    static const int BUTTON_CANCEL_TOP_Y = 515;
    static const int BUTTON_CANCEL_SIZE_X = 112;
    static const int BUTTON_CANCEL_SIZE_Y = 35;
    static const int BUTTON_END_TOP_X = 675;
    static const int BUTTON_END_TOP_Y = 555;
    static const int BUTTON_END_SIZE_X = 112;
    static const int BUTTON_END_SIZE_Y = 35;

private:
    GameData* game_data;
    BattleMapState *map_state;   // 対戦マップ情報
    BattleCardState *card_state; // カード情報
    std::queue<BattleUnitState*> select_unit;  // 選択したユニット
    BattleUnitState* mouse_on_unit;  // カーソルが乗ってるユニット
    int left_click_now;          // 左クリック中か
    int click_first_pos_x;       // クリック初期位置x
    int click_first_pos_y;       // クリック初期位置y
    int click_now_pos_x;         // クリック終了位置x
    int click_now_pos_y;         // クリック終了位置y
    int now_turn;                // 現在ターン
    int now_battle_select_mode;  // 対戦ターンでの選択モード
    int select_unit_com;         // 選択ユニットに対する命令
    int player_pos_x;            // プレイヤーの座標x
    int player_pos_y;            // プレイヤーの座標y
    int shift_pos_x;             // シフト座標x
    int shift_pos_y;             // シフト座標y
    int time_cnt;                // 経過時間
    int my_mp;                   // 自分魔力
    int en_mp;                   // 敵魔力
    int winner;                  // 勝利者

public:
    BattleState(GameData*);      // コンストラクタ
    ~BattleState();              // デストラクタ
    void init();                 // 初期化
    void battleInit();           // 対戦情報初期化
    void battleSetting();        // 対戦設定
    void update();               // 更新
    void changeCardSelectTurn(); // カード使用ターンに移行
    void updateMousePos(int, int); // マウス座標更新
    void moveShiftPos(int, int); // シフト座標移動
    void setShiftPos(int, int);  // シフト座標設定
    void setInitShiftPos();      // シフト座標を初期位置に
    int changeMousePosX(int);    // マウス座標をマップ座標に変換
    int changeMousePosY(int);    // マウス座標をマップ座標に変換
    void setMapData(MapData*);   // マップデータ設定
    void selectCard(int);        // カード選択
    void selectCancelButton();   // キャンセルボタン選択
    void selectEndButton();      // 終了ボタン選択
    void putUnit();              // ユニット設置
    bool useMyMp(int);           // 魔力使用
    bool useEnMp(int);           // 魔力使用
    void firstLeftClick(int x, int y); // 最初の左クリック
    void nowLeftClick(int x, int y);   // 左クリック中
    void endLeftClick(int x, int y);   // 左クリックの最後
    void updateSelectUnit();      // 選択ユニット更新
    void deselectUnit();          // 選択中のユニット解除
    void commandSelectUnit(int);  // 選択中のユニットに対して命令
    void commandSelectUnit(int, int, int); // 選択中のユニットに対して命令
    void commandSelectUnit(int, BattleUnitState*); // 選択中のユニットに対して命令
    void changeSelectMode(int);   // 選択モード変更
    void setSelectUnitCom(int);   // ユニットに対する命令セット
    bool isPutUnitMy(CardData*, int, int);  // その枡にユニット置けるか
    bool isPutUnitMy(int, int);
    bool isPutUnitEn(CardData*, int, int);
    void createUnitMy(CardData*, int, int); // ユニット生成
    void createUnitEn(CardData*, int, int); // ユニット生成
    void updateMouseOnUnit(int, int);       // カーソルが乗ってるユニット更新
    void checkEnd();             // 終了判定

    //---- getter
    BattleMapState *getMapState();   // マップ情報取得
    BattleCardState *getCardState(); // カード情報取得
    MapData *getMapData();       // マップデータ取得
    int getSelectUnitNum();      // 選択中のユニット数
    BattleUnitState* getSelectUnit(); // 選択中のユニット
    int getPlayerPosX();         // プレイヤー座標x取得
    int getPlayerPosY();         // プレイヤー座標y取得
    int getShiftPosX();          // シフト座標x取得
    int getShiftPosY();          // シフト座標y取得
    int getNowTurn();            // 現在ターン取得
    int getNowTimeCnt();         // 現在残り時間取得
    int getMyMp();               // 自軍魔力取得
    int getEnMp();               // 敵軍魔力取得
    bool isLeftClickNow();       // 左クリック中か
    int getClickFirstPosX();     // クリック初期位置x
    int getClickFirstPosY();     // クリック初期位置y
    int getClickNowPosX();       // クリック終了位置x
    int getClickNowPosY();       // クリック終了位置y
    int getNowSelectMode();      // 現在の選択モード取得
    int getSelectUnitCom();      // 選択ユニット取得
    int getWinner();             // 勝利者取得
};