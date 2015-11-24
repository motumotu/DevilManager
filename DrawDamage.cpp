//-----------------------------------------------------------
// DrawDamage.cpp
// ダメージの描画
// 制作日 2015.03.04
// 制作者 motumotu
//-----------------------------------------------------------
#include "DrawDamage.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
DrawDamage::DrawDamage(GameData* data, BattleState* state)
{
    game_data = data;
    battle_state = state;
    init();
    loadImage();          // 画像読み込み
    color_white = GetColor(255, 255, 255);
    color_red = GetColor(207, 0, 0);
    font = CreateFontToHandle("PixelMplus12", 12, -1, DX_FONTTYPE_ANTIALIASING_EDGE);
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
DrawDamage::~DrawDamage()
{

}

//-----------------------------------------------------------
// 初期処理
//-----------------------------------------------------------
void DrawDamage::init()
{
}

//-----------------------------------------------------------
// 更新処理
//-----------------------------------------------------------
void DrawDamage::update()
{

}

//-----------------------------------------------------------
// 画像読み込み
//-----------------------------------------------------------
void DrawDamage::loadImage()
{
}

//-----------------------------------------------------------
// 描画
//-----------------------------------------------------------
void DrawDamage::draw()
{
    BattleMapState* map_state = battle_state->getMapState();
    for (int i = 0; i < map_state->getDamageStateNum(); i++) {
        BattleDamageState* damage = map_state->getDamageState();
        int px = damage->getX() + battle_state->getShiftPosX();
        px -= damage->getDamageDigits() * 5;
        int py = damage->getY() + battle_state->getShiftPosY() - 10;
        int color = (damage->getWhich()) ? color_white : color_red;
        DrawFormatStringToHandle(px, py - damage->getCntFrame() / 2,
            color, font, "%d", damage->getDamage());
    }
}