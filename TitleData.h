//-----------------------------------------------------------
// TitleData.h
// �^�C�g����ʂ̃f�[�^
// ����� 2015.03.17
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "SystemData.h"

class TitleData {
public:
    static const int BUTTON_SIZE_X = 200;   // �{�^���̑傫��x
    static const int BUTTON_SIZE_Y = 40;    // �{�^���̑傫��y
private:
public:
    TitleData();                  // �R���X�g���N�^
    ~TitleData();                 // �f�X�g���N�^
    int getPosButtonNewgameX();   // �{�^���u�͂��߂���v�̈ʒux
    int getPosButtonNewgameY();   // �{�^���u�͂��߂���v�̈ʒuy
    int getPosButtonContinueX();  // �{�^���u�Â�����v�̈ʒux
    int getPosButtonContinueY();  // �{�^���u�Â�����v�̈ʒuy
    int getPosButtonSettingX();   // �{�^���u�V�X�e���ݒ�v�̈ʒux
    int getPosButtonSettingY();   // �{�^���u�V�X�e���ݒ�v�̈ʒuy
    int getPosButtonSiteX();      // �{�^���u�����T�C�g�v�̈ʒux
    int getPosButtonSiteY();      // �{�^���u�����T�C�g�v�̈ʒuy
    int getPosButtonEndX();       // �{�^���u�Q�[���I���v�̈ʒux
    int getPosButtonEndY();       // �{�^���u�Q�[���I���v�̈ʒuy
};