//-----------------------------------------------------------
// SkillData.cpp
// �X�L�����
// ����� 2015.03.14
// ����� motumotu
//-----------------------------------------------------------
#include "SkillData.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
SkillData::SkillData()
{
    text[1] = "���͂P�}�X���́u�X���C���v�Ɩ��̕t�����j�b�g�̐����P�O�����U���͂��㏸����";
    text[2] = "���̃��j�b�g�̎��S���A�X���C�����Q�̐��ݏo��";
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
SkillData::~SkillData()
{

}

//-----------------------------------------------------------
// �擾
//-----------------------------------------------------------
std::string SkillData::getSkillText1(int n)
{
    if (text[n].length() >= LINE_TEXT_NUM * 2) {
        return text[n].substr(0, LINE_TEXT_NUM * 2);
    }
    else {
        return text[n].substr(0, text[n].length());
    }
}
std::string SkillData::getSkillText2(int n)
{
    if (text[n].length() < LINE_TEXT_NUM * 2) {
        return "";
    }
    else {
        return text[n].substr(LINE_TEXT_NUM * 2, text[n].length());
    }
}