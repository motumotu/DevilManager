//-----------------------------------------------------------
// SaveData.h
// �Z�[�u�f�[�^
// ����� 2015.03.18
// ����� motumotu
//-----------------------------------------------------------
#include "SaveData.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
SaveData::SaveData()
{
    have_card = new HaveCardData();
    loadSaveData();
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
SaveData::~SaveData()
{
    saveSaveData();
    delete(have_card);
}

//-----------------------------------------------------------
// �Z�[�u�f�[�^�ǂݍ���
//-----------------------------------------------------------
void SaveData::loadSaveData()
{
    std::string str;
    std::ifstream ifs("savedata/savedata001.dat");
    if (ifs.fail()) {
        std::cout << "�Z�[�u�f�[�^�̓ǂݍ��݂Ɏ��s���܂����B" << std::endl;
        return;
    }
    //---- �v���C���[��
    getline(ifs, str);
    player_name = str;

    //---- �Z�[�u�f�[�^�쐬��
    getline(ifs, str);
    create_savedata_day = atoi(str.c_str());

    //---- �v���C����
    getline(ifs, str);
    player_time = atoi(str.c_str());

    //---- �f�b�L���
    // �f�b�L����
    getline(ifs, str);
    deck_num = atoi(str.c_str());
    for (int i = 1; i <= deck_num; i++) {
        DeckData *deck = new DeckData();
        // ���O
        getline(ifs, str);
        deck->setDeckName(str);
        // �J�[�h
        getline(ifs, str);
        std::stringstream ss(str);
        while (ss >> str) {
            int n = atoi(str.c_str());
            deck->addCard(n);
        }
        deck_data[i] = deck;
    }
    
    //---- �����J�[�h���
    // �����J�[�h����
    getline(ifs, str);
    have_card_num = atoi(str.c_str());
    // �J�[�h���
    getline(ifs, str);
    std::stringstream ss(str);
    while (ss >> str) {
        int n = atoi(str.c_str());
        have_card->addCard(n);
    }
}

//-----------------------------------------------------------
// �Z�[�u�f�[�^�ۑ�
//-----------------------------------------------------------
void SaveData::saveSaveData()
{

}

//===========================================================
// getter
//===========================================================
int SaveData::getDeckNum() { return deck_num; }
DeckData *SaveData::getDeckData(int n) { return deck_data[n]; }
int SaveData::getHaveCardNum() { return have_card->getAllCardNum(); }
HaveCardData *SaveData::getHaveCardData() { return have_card; }