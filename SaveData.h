//-----------------------------------------------------------
// SaveData.h
// �Z�[�u�f�[�^
// ����� 2015.03.18
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "DeckData.h"
#include "HaveCardData.h"

class SaveData {
private:
    std::string player_name;    // �v���C���[��
    int create_savedata_day;    // �Z�[�u�f�[�^�쐬��
    int player_time;            // �v���C����
    int deck_num;               // �f�b�L��
    DeckData *deck_data[100];   // �f�b�L�f�[�^
    int have_card_num;          // �����J�[�h��
    HaveCardData *have_card;    // �����J�[�h�f�[�^
    // �N���A�X�g�[���[���
    // �N���A�o�g�����
    // �V�X�e���f�[�^
public:
    SaveData();       // �R���X�g���N�^
    ~SaveData();      // �f�X�g���N�^
    void loadSaveData();  // �Z�[�u�f�[�^�ǂݍ���
    void saveSaveData();  // �Z�[�u�f�[�^�ۑ�
    bool isSaveData();    // �Z�[�u�f�[�^�����邩
    //---- getter
    int getDeckNum();                // �f�b�L���擾
    DeckData *getDeckData(int);      // �f�b�L�f�[�^�擾
    int getHaveCardNum();            // �����J�[�h�����擾
    HaveCardData *getHaveCardData(); // �����J�[�h�f�[�^�擾
};