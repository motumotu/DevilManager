//-----------------------------------------------------------
// TitleData.cpp
// �^�C�g����ʂ̃f�[�^
// ����� 2015.03.17
// ����� motumotu
//-----------------------------------------------------------
#include "TitleData.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
TitleData::TitleData()
{

}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
TitleData::~TitleData()
{

}

//-----------------------------------------------------------
// �{�^���ʒu�擾
//-----------------------------------------------------------
int TitleData::getPosButtonNewgameX() {
    return SystemData::getWindowWidth() / 2 - BUTTON_SIZE_X / 2;
}
int TitleData::getPosButtonNewgameY() {
    return SystemData::getWindowHeight() - 240;
}
int TitleData::getPosButtonContinueX() {
    return SystemData::getWindowWidth() / 2 - BUTTON_SIZE_X / 2;
}
int TitleData::getPosButtonContinueY() {
    return SystemData::getWindowHeight() - 200;
}
int TitleData::getPosButtonSettingX() {
    return SystemData::getWindowWidth() / 2 - BUTTON_SIZE_X / 2;
}
int TitleData::getPosButtonSettingY() {
    return SystemData::getWindowHeight() - 160;
}
int TitleData::getPosButtonSiteX() {
    return SystemData::getWindowWidth() / 2 - BUTTON_SIZE_X / 2;
}
int TitleData::getPosButtonSiteY() {
    return SystemData::getWindowHeight() - 120;
}
int TitleData::getPosButtonEndX() {
    return SystemData::getWindowWidth() / 2 - BUTTON_SIZE_X / 2;
}
int TitleData::getPosButtonEndY() {
    return SystemData::getWindowHeight() - 80;
}