//=======================================================
// �w�b�_�[�C���N���[�h
//=======================================================
#include "DxLib.h"
#include "SystemData.h"
#include "Game.h"

//=======================================================
// WinMain�֐�
//=======================================================
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    SystemData::loadSystemData();
    ChangeWindowMode(TRUE);                   // �E�B���h�E���[�h�ŋN������
    SetGraphMode(                             // �E�B���h�E�ݒ�
        SystemData::getWindowWidth(),         // ��ʕ�
        SystemData::getWindowHeight(),        // ��ʍ���
        SystemData::getWindowColor());        // �g�p�J���[
    SetWindowText("�����X�^�[�}�l�[�W���[");  // �^�C�g����
    if (DxLib_Init() == -1) { return -1; }    // DX���C�u����������
    if (SetDrawScreen(DX_SCREEN_BACK) != 0) { return -1; }  // �`���𗠉�ʂ�
    
    //---- �f�o�b�O�p�R���\�[��
    AllocConsole();
    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);
    freopen_s(&fp, "CONIN$", "r", stdin);
    //---- �t�H���g
    LPCSTR font_path1 = "dat\\PixelMplus12-Regular.ttf";
    if (!(AddFontResourceEx(font_path1, FR_PRIVATE, NULL) > 0))
        MessageBox(NULL, "�t�H���g�f�[�^�Ǎ����s", "", MB_OK);
    LPCSTR font_path2 = "dat\\PixelMplus10-Regular.ttf";
    if (!(AddFontResourceEx(font_path2, FR_PRIVATE, NULL) > 0))
        MessageBox(NULL, "�t�H���g�f�[�^�Ǎ����s", "", MB_OK);

    // �Q�[������
    Game *game = new Game();
    game->init();
    game->mainLoop();
    delete(game);

    //---- �I������
    if (!RemoveFontResourceEx(font_path1, FR_PRIVATE, NULL))
        MessageBox(NULL, "remove failure", "", MB_OK);
    if (!RemoveFontResourceEx(font_path2, FR_PRIVATE, NULL))
        MessageBox(NULL, "remove failure", "", MB_OK);
    DxLib_End();
    return 0;
}