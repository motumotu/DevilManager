//-----------------------------------------------------------
// BattleManager.cpp
// 対戦画面の制御
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#include "BattleManager.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
BattleManager::BattleManager(GameData *data, GameState *state)
{
    enemy_manager = new BattleEnemyManager(data, state);
    game_data = data;
    game_state = state;
    battle_state = state->getSceneState()->getBattleState();
    map_state = battle_state->getMapState();
    card_state = battle_state->getCardState();
    input_state = state->getInputState();
    init();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
BattleManager::~BattleManager()
{
    delete(enemy_manager);
}

//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void BattleManager::init()
{
    
}

//-----------------------------------------------------------
// 更新
//-----------------------------------------------------------
void BattleManager::update()
{
    clickProcess();                  // プレイヤー
    enemy_manager->updateCommand();  // 敵
}

//-----------------------------------------------------------
// クリック処理
//-----------------------------------------------------------
void BattleManager::clickProcess()
{
    int x = input_state->getPointX();
    int y = input_state->getPointY();
    //---- マウス座標
    battle_state->updateMousePos(x, y);
    battle_state->updateMouseOnUnit(x, y);
    if (x <= 0) {
        battle_state->moveShiftPos(Define::DIRE_LEFT, 3);
    }
    if (x >= SystemData::getWindowWidth()) {
        battle_state->moveShiftPos(Define::DIRE_RIGHT, 3);
    }
    if (y <= 0) {
        battle_state->moveShiftPos(Define::DIRE_UP, 3);
    }
    if (y >= SystemData::getWindowHeight()) {
        battle_state->moveShiftPos(Define::DIRE_DOWN, 3);
    }
    //---- マウスクリック処理
    // 左クリックされた瞬間
    if (input_state->getClick(MOUSE_INPUT_LEFT) == 1) {
        leftClickProcess();
    }
    // 右クリックされた瞬間
    if (input_state->getClick(MOUSE_INPUT_RIGHT) == 1) {
        rightClickProcess();
    }
    // 左クリック中
    if (input_state->getClick(MOUSE_INPUT_LEFT) > 1) {
        if (battle_state->getNowTurn() == BattleState::TURN_BATTLE) {
            battle_state->nowLeftClick(x, y);
        }
    }
    // 左クリック終了
    if (battle_state->isLeftClickNow() && input_state->getClick(MOUSE_INPUT_LEFT) == 0) {
        if (battle_state->getNowTurn() == BattleState::TURN_BATTLE) {
            battle_state->endLeftClick(x, y);
        }
    }

    //---- キー入力
    // 上
    if (input_state->getKeyState(KEY_INPUT_W) >= 1) {
        battle_state->moveShiftPos(Define::DIRE_UP, 5);
    }
    // 右
    if (input_state->getKeyState(KEY_INPUT_D) >= 1) {
        battle_state->moveShiftPos(Define::DIRE_RIGHT, 5);
    }
    // 下
    if (input_state->getKeyState(KEY_INPUT_S) >= 1) {
        battle_state->moveShiftPos(Define::DIRE_DOWN, 5);
    }
    // 左
    if (input_state->getKeyState(KEY_INPUT_A) >= 1) {
        battle_state->moveShiftPos(Define::DIRE_LEFT, 5);
    }
}

//-----------------------------------------------------------
// 自軍ユニット生成
//-----------------------------------------------------------
void BattleManager::createMyUnit(int id)
{
    createMyUnit(id,
        battle_state->getPlayerPosX(),
        battle_state->getPlayerPosY());
}
void BattleManager::createMyUnit(int id, int x, int y)
{
    if (battle_state->getMapState()->getMapData()->outCheck(x, y)) return;
    battle_state->getMapState()->createMyUnit(
        game_data->getAllCardData()->getCardData(id), x, y);
}

//-----------------------------------------------------------
// 敵軍ユニット生成
//-----------------------------------------------------------
void BattleManager::createEnUnit(int id, int x, int y)
{
    if (battle_state->getMapState()->getMapData()->outCheck(x, y)) return;
    battle_state->getMapState()->createEnUnit(
        game_data->getAllCardData()->getCardData(id), x, y);

}

//-----------------------------------------------------------
// 右クリック処理
//-----------------------------------------------------------
void BattleManager::rightClickProcess()
{

}

//-----------------------------------------------------------
// 左クリック処理
//-----------------------------------------------------------
void BattleManager::leftClickProcess()
{
    int mx = input_state->getPointX();
    int my = input_state->getPointY();
    int px = battle_state->changeMousePosX(mx);
    int py = battle_state->changeMousePosY(my);

    //---- 対戦中の処理
    if (battle_state->getNowTurn() == BattleState::TURN_BATTLE) {
        // マップ部分
        if (my < SystemData::getWindowHeight() - 90) {
            battle_state->firstLeftClick(mx, my);
        }
        // UI部分
        if (my >= SystemData::getWindowHeight() - 90) {
            for (int i = 0; i < 7; i++) {
                if (mx >= i * 70 + 21 && mx <= i * 70 + 81 && my >= 535 && my <= 595) {
                    battle_state->setSelectUnitCom(i);
                }
            }
        }
    }
    //---- カード選択中の処理
    else if (battle_state->getNowTurn() == BattleState::TURN_CURD_SELECT) {
        // キャンセルボタン
        if (mx >= BattleState::BUTTON_CANCEL_TOP_X &&
            mx <= BattleState::BUTTON_CANCEL_TOP_X + BattleState::BUTTON_CANCEL_SIZE_X &&
            my >= BattleState::BUTTON_CANCEL_TOP_Y &&
            my <= BattleState::BUTTON_CANCEL_TOP_Y + BattleState::BUTTON_CANCEL_SIZE_Y) {
            battle_state->selectCancelButton();
        }
        // 終了ボタン
        if (mx >= BattleState::BUTTON_END_TOP_X &&
            mx <= BattleState::BUTTON_END_TOP_X + BattleState::BUTTON_END_SIZE_X &&
            my >= BattleState::BUTTON_END_TOP_Y &&
            my <= BattleState::BUTTON_END_TOP_Y + BattleState::BUTTON_END_SIZE_Y) {
            enemy_manager->useCard();
            battle_state->selectEndButton();
        }
        // カード選択
        for (int i = 0; i < card_state->getMyHandNum(); i++) {
            if (mx >= 21 + i * 70 && mx <= 21 + i * 70 + 60 &&
                my >= 510 && my <= 595) {
                battle_state->selectCard(i);
            }
        }
    }
    //---- カード使用中の処理
    else if (battle_state->getNowTurn() == BattleState::TURN_CURD_USE) {
        int id = card_state->getSelectCard();
        if (!battle_state->isPutUnitMy(game_data->getAllCardData()->getCardData(id), px, py)) return;
        createMyUnit(id, px, py);
        battle_state->putUnit();
        battle_state->useMyMp(game_data->getAllCardData()->getCardData(id)->mp);
    }
    //---- 対戦終了時
    else if (battle_state->getNowTurn() == BattleState::TURN_END) {
        // 結果をBattleResultStateに格納後リザルト画面に画面遷移
        game_state->getSceneState()->changeScene(SceneState::SCENE_BATTLE_RESULT);
    }
}

//===========================================================
// getter
//===========================================================

