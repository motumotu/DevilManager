//=======================================================
// ヘッダーインクルード
//=======================================================
#include "DxLib.h"
#include "SystemData.h"
#include "Game.h"

//=======================================================
// WinMain関数
//=======================================================
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    SystemData::loadSystemData();
    ChangeWindowMode(TRUE);                   // ウィンドウモードで起動する
    SetGraphMode(                             // ウィンドウ設定
        SystemData::getWindowWidth(),         // 画面幅
        SystemData::getWindowHeight(),        // 画面高さ
        SystemData::getWindowColor());        // 使用カラー
    SetWindowText("モンスターマネージャー");  // タイトル名
    if (DxLib_Init() == -1) { return -1; }    // DXライブラリ初期化
    if (SetDrawScreen(DX_SCREEN_BACK) != 0) { return -1; }  // 描画先を裏画面に
    
    //---- デバッグ用コンソール
    AllocConsole();
    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);
    freopen_s(&fp, "CONIN$", "r", stdin);
    //---- フォント
    LPCSTR font_path1 = "dat\\PixelMplus12-Regular.ttf";
    if (!(AddFontResourceEx(font_path1, FR_PRIVATE, NULL) > 0))
        MessageBox(NULL, "フォントデータ読込失敗", "", MB_OK);
    LPCSTR font_path2 = "dat\\PixelMplus10-Regular.ttf";
    if (!(AddFontResourceEx(font_path2, FR_PRIVATE, NULL) > 0))
        MessageBox(NULL, "フォントデータ読込失敗", "", MB_OK);

    // ゲーム処理
    Game *game = new Game();
    game->init();
    game->mainLoop();
    delete(game);

    //---- 終了処理
    if (!RemoveFontResourceEx(font_path1, FR_PRIVATE, NULL))
        MessageBox(NULL, "remove failure", "", MB_OK);
    if (!RemoveFontResourceEx(font_path2, FR_PRIVATE, NULL))
        MessageBox(NULL, "remove failure", "", MB_OK);
    DxLib_End();
    return 0;
}