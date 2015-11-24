//-----------------------------------------------------------
// AllCardData.cpp
// �Q�[���̃f�[�^��
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#include "AllCardData.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
AllCardData::AllCardData()
{
    readCardData();             // �J�[�h�f�[�^�ǂݍ���
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
AllCardData::~AllCardData()
{

}

//-----------------------------------------------------------
// ������
//-----------------------------------------------------------
void AllCardData::init()
{

}

//-----------------------------------------------------------
// �X�V
//-----------------------------------------------------------
void AllCardData::update()
{

}

//-----------------------------------------------------------
// �J�[�h�f�[�^�ǂݍ���
//-----------------------------------------------------------
// �y�����z �S�J�[�h�f�[�^��ǂݍ���
// �y�����z �Ȃ�
// �y�Ԓl�z �����Ftrue�A���s�Ffalse
//-----------------------------------------------------------
bool AllCardData::readCardData()
{
    //---- �t�@�C�����J��
    std::string str;
    std::ifstream ifs("dat/card_data.dat");
    if (ifs.fail()) {
        puts("card_data.dat�̓ǂݍ��݂Ɏ��s���܂����B");
        return false;
    }
    puts("card_data.dat�ǂݍ��ݐ���");
    //---- �J�[�h�f�[�^�ǂݍ���
    while (getline(ifs, str)) {
        std::stringstream ss(str);
        // ID
        ss >> str;
        int id = atoi(str.c_str());
        card[id].id = id;
        // ���O
        ss >> str;
        card[id].name = str;
        // ����
        ss >> str;
        card[id].mp = atoi(str.c_str());
        // �̗�
        ss >> str;
        card[id].hp = atoi(str.c_str());
        // �U����
        ss >> str;
        card[id].pow = atoi(str.c_str());
        // �h���
        ss >> str;
        card[id].def = atoi(str.c_str());
        // �ړ����x
        ss >> str;
        card[id].move_speed = atoi(str.c_str());
        // �U�����x
        ss >> str;
        card[id].attack_speed = atoi(str.c_str());
        // �Αϐ�
        ss >> str;
        card[id].fire = atoi(str.c_str());
        // ���ϐ�
        ss >> str;
        card[id].water = atoi(str.c_str());
        // �X�ϐ�
        ss >> str;
        card[id].ice = atoi(str.c_str());
        // �d�ϐ�
        ss >> str;
        card[id].elect = atoi(str.c_str());
        // �őϐ�
        ss >> str;
        card[id].dark = atoi(str.c_str());
        // ���ϐ�
        ss >> str;
        card[id].light = atoi(str.c_str());
        // �n�ϐ�
        ss >> str;
        card[id].earth = atoi(str.c_str());
        // �őϐ�
        ss >> str;
        card[id].poison = atoi(str.c_str());
        // ���ϐ�
        ss >> str;
        card[id].wind = atoi(str.c_str());
        // ����
        ss >> str;
        if (str == "��") card[id].attribute = CardData::ATTR_FIRE;
        else if (str == "��") card[id].attribute = CardData::ATTR_WATER;
        else if (str == "�X") card[id].attribute = CardData::ATTR_ICE;
        else if (str == "�d") card[id].attribute = CardData::ATTR_ELECT;
        else if (str == "��") card[id].attribute = CardData::ATTR_DARK;
        else if (str == "��") card[id].attribute = CardData::ATTR_LIGHT;
        else if (str == "�n") card[id].attribute = CardData::ATTR_EARTH;
        else if (str == "��") card[id].attribute = CardData::ATTR_POISON;
        else if (str == "��") card[id].attribute = CardData::ATTR_WIND;
        // ���G�͈�
        ss >> str;
        card[id].search_range = atoi(str.c_str());
        // �摜�傫��x
        ss >> str;
        card[id].image_size_x = atoi(str.c_str());
        // �摜�傫��y
        ss >> str;
        card[id].image_size_y = atoi(str.c_str());
        // �傫��x
        ss >> str;
        card[id].size_x = atoi(str.c_str());
        // �傫��y
        ss >> str;
        card[id].size_y = atoi(str.c_str());
        // �X�L��
        ss >> str;
        int n = atoi(str.c_str());
        for (int i = 0; i < n; i++) {
            ss >> str;
            card[id].skil.push_back(atoi(str.c_str()));
        }
    }
    return true;
}

//===========================================================
// getter
//===========================================================
CardData *AllCardData::getCardData(int id) { return &card[id]; }