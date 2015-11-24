//-----------------------------------------------------------
// ImageData.h
// �摜�f�[�^
// ����� 2015.03.17
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "DxLib.h"

class ImageData {
public:
    static const int MINICARD_SIZE_X = 33;
    static const int MINICARD_SIZE_Y = 46;
    static const int CARD_SIZE_X = 60;
    static const int CARD_SIZE_Y = 85;
private:
    int handl_card[100];        // ���ʂ̃J�[�h
    int handl_card_mini[100];   // �������J�[�h
    int handl_monster[100][52]; // �����X�^�[
public:
    ImageData();                // �R���X�g���N�^
    ~ImageData();               // �f�X�g���N�^

    int getCard(int);           // ���ʂ̃J�[�h
    int getCardMini(int);       // �������J�[�h
    int getMonster(int, int);   // �����X�^�[
};