//-----------------------------------------------------------
// BattleUnitState.h
// ���j�b�g�f�[�^���
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "CardData.h"
#include "MapData.h"
#include "Define.h"
#include <string>
#include <vector>

class BattleUnitState {
public:
    static const int STATE_WAIT = 0;   // �ҋ@���
    static const int STATE_MOVE = 1;   // �ړ����
    static const int STATE_ATTACK = 2; // �U�����
    static const int STATE_SKILL = 3;  // �X�L����
    static const int STATE_DEATH_ANI = 4; // ���S�A�j���[�V����
    static const int STATE_DEATH = 5;  // ���S

    static const int UNIT_MY = 0;      // ���R���j�b�g
    static const int UNIT_ENE = 1;     // �G�R���j�b�g
    static const int COM_WAIT = 0;     // ����_�ҋ@
    static const int COM_MOVE = 1;     // ����_�s�� ���R
    static const int COM_ATTACK = 2;   // ����_�U��
    static const int COM_DEFENSE = 3;  // ����_�h��
    static const int COM_SPE_MOVE = 4; // ����_�w��ړ�
    static const int COM_SPE_ATTACK = 5;  // ����_�w��U��
    static const int COM_SPE_DEFENSE = 6; // ����_�w��h��

    static const int TIME_DEATH_ANI = 30; // ����_���S�A�j���[�V����
private:
    // �X�e�[�^�X
    int which;                  // �ǂ����̃��j�b�g��
    int size_x;                 // �傫��x
    int size_y;                 // �傫��y
    int image_size_x;           // �摜�̑傫��x
    int image_size_y;           // �摜�̑傫��y
    int pos_x;                  // �}�X�ڂ̍��Wx
    int pos_y;                  // �}�X�ڂ̍��Wy
    int pixel_x;                // �s�N�Z�����Wx
    int pixel_y;                // �s�N�Z�����Wy
    int id;                     // �푰ID
    int individual_id;          // ��ID
    std::string name;           // ���O
    int kind;                   // ���
    int mp;                     // �K�v����
    int max_hp;                 // �ő�̗͒l
    int hp;                     // ���݂̗̑͒l
    int pow;                    // �U����
    int def;                    // �h���
    int mspeed;                 // �ړ����x
    int aspeed;                 // �U�����x
    int attribute;              // �����̑���
    int search_range;           // ���G�͈�
    int increment_hp;           // �����̗͗�
    int increment_pow;          // �����U���͗�
    int increment_def;          // �����h��͗�
    int increment_mspeed;       // �����ړ����x��
    int increment_aspeed;       // �����U�����x��
    int fire;                   // ��
    int water;                  // ��
    int ice;                    // �X
    int elect;                  // �d
    int dark;                   // ��
    int light;                  // ��
    int earth;                  // �n
    int poison;                 // ��
    int wind;                   // ��
    std::vector<int> skil;      // �X�L��
    std::vector<int> equipment; // ����
    // ���
    int now_state;              // ���݂̏��
    int now_dire;               // ���݂̌���
    int now_command;            // ���݂̖���
    int move_x;                 // x�����ɂǂꂾ����������
    int move_y;                 // y�����ɂǂꂾ����������
    int cnt_frame;              // ���t���[���o�߂�����
    int survival_time;          // ��������

    int move_pos_x;             // �ړI�nx
    int move_pos_y;             // �ړI�ny
    BattleUnitState* specified_unit; // �w�胆�j�b�g
public:
    BattleUnitState();          // �R���X�g���N�^
    ~BattleUnitState();         // �f�X�g���N�^
    void init();                // ������
    void update();              // �X�V
    void setState(CardData*, int, int,int,int);  // ���j�b�g�̃X�e�[�^�X�Z�b�g
    void moveDire(int);         // �w������Ɉړ�
    bool isAlive();             // �����Ă��邩
    int getImage();             // ���݂̉摜�擾
    void initIncrementStatus(); // �㏸�\�͏�����
    void incrementHp(int);      // �̗͏㏸
    void incrementPow(int);     // �U���͏㏸
    void incrementDef(int);     // ����͏㏸
    void incrementMSpeed(int);  // �ړ����x�㏸
    void incrementASpeed(int);  // �U�����x�㏸

    // �R�}���h
    void comAttackDire(int);     // �w������ɍU��
    void comMoveDire(int);       // �w������Ɉړ�
    void comReceivedDamage(int); // �_���[�W���󂯂�

    // setter
    void setNowCommand(int);               // �R�}���h�ݒ�
    void setMovePos(int, int);             // �ړ���ݒ�
    void setAttackUnit(BattleUnitState*);  // �U���Ώۃ��j�b�g�w��
    void setDefenseUnit(BattleUnitState*); // �h��Ώۃ��j�b�g�w��
    void setSpecifiedUnit(BattleUnitState*);
    // getter
    int getWhich();             // �ǂ���̃��j�b�g��
    int getSizeX();             // �傫��x�擾
    int getSizeY();             // �傫��y�擾
    int getX();                 // ���Wx�擾
    int getY();                 // ���Wy�擾
    int getImageSizeX();        // �摜�T�C�Yx�擾 
    int getImageSizeY();        // �摜�T�C�Yy�擾
    int getPixelX();            // �s�N�Z�����Wx
    int getPixelY();            // �s�N�Z�����Wy
    int getId();                // ID�擾
    std::string getName();      // ���O�擾
    int getKind();              // �J�[�h�̎�ގ擾
    int getMp();                // MP�擾
    int getMaxHp();             // �ő�HP�擾
    int getHp();                // HP�擾
    int getPow();               // �U���͎擾
    int getDef();               // ����͎擾
    int getMoveSpeed();         // �ړ����x�擾
    int getAttackSpeed();       // �U�����x�擾
    int getAttribute();         // �������擾
    int getSearchRange();       // ���G�͈͎擾
    int getIncremenattributetHp();       // �����̗͗ʎ擾
    int getIncrementHp();
    int getIncrementPow();      // �����U���͗ʎ擾
    int getIncrementDef();      // ��������͗ʎ擾
    int getIncrementMoveSpeed();   // �����ړ����x�ʎ擾
    int getIncrementAttackSpeed(); // �����U�����x�ʎ擾
    int getAttrDef(int);           // ��������͎擾
    int getSkilNum();              // �X�L�����擾
    int getSkil(int);              // �X�L���擾
    std::vector<int> getSkil();    // �X�L���擾
    int getEquipmentNum();         // �������擾
    int getEquipment(int);         // �����擾

    int getNowState();             // ���݂̏�Ԏ擾
    int getNowDire();              // ���݂̌����擾
    int getNowCommand();           // ���݂̃R�}���h�擾
    BattleUnitState* getSpecifiedUnit();  // �w�胆�j�b�g�擾
    int getMovePosX();           // �ړIx�擾
    int getMovePosY();           // �ړI�ny�擾
    int getSurvivalTime();       // �������Ԏ擾
};