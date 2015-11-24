//-----------------------------------------------------------
// BattleMapState.h
// �ΐ�}�b�v���
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "MapData.h"
#include "BattleAllUnitState.h"
#include "BattleAreaState.h"
#include "BattleDamageState.h"
#include <queue>
#include <ctime>
#include <cstring>

class BattleMapState {
private:
    GameData *game_data;
    MapData *map_data;         // �}�b�v���
    BattleAreaState *area;     // �G���A���
    BattleAllUnitState *unit;  // ���j�b�g���
    std::queue<BattleDamageState*> damage; // �_���[�W���

public:
    BattleMapState(GameData*);             // �R���X�g���N�^
    ~BattleMapState();                     // �f�X�g���N�^
    void init();                           // ������
    void battleInit();                     // �ΐ��񏉊���
    void battleSetting();                  // �ΐ�ݒ�
    void update();                         // �X�V
    void setMapData(MapData*);             // �}�b�v�f�[�^�ݒ�
    void createMyUnit(CardData*,int,int);  // ���R���j�b�g����
    void createEnUnit(CardData*,int,int);  // �G�R���j�b�g����
    void createMyBase(CardData*);          // ���R���_����
    void createEnBase(CardData*);          // �G�R���_����
    void updateMyUnitState();              // ���R���j�b�g��ԍX�V
    void updateEnUnitState();              // �G�R���j�b�g��ԍX�V
    void updateDamage();                   // �_���[�W�X�V
    bool isUnit(int, int);                 // ���j�b�g�����邩
    bool isMyUnit(int, int);               // �w����W�Ɏ��R���j�b�g�����邩
    bool isEnUnit(int, int);               // �w����W�ɓG�R���j�b�g�����邩
    bool isMobileSpaceAround(BattleUnitState*, int, int);    // ���͂Ɉړ��ł���}�X�����邩
    bool isMobileSpaceDire(BattleUnitState*, int, int);      // ���͂Ɉړ��ł���}�X�����邩
    bool isMobileSpaceDire(BattleUnitState*, int, int, int); // ���͂Ɉړ��ł���}�X�����邩
    void moveDire(BattleUnitState*, int);                    // �w������Ɉړ�
    void attack(BattleUnitState*, BattleUnitState*);         // �U��
    int getDirection(BattleUnitState*, BattleUnitState*);    // �����擾
    int getDire(BattleUnitState*, BattleUnitState*);         // �����擾
    int getDire(BattleUnitState*, int, int);                 // �����擾
    int getDire(BattleUnitState*, int, int, int, int);       // �����擾

    //---- �s��
    void actionWait(BattleUnitState*);        // �ҋ@���[�h���̍s��
    void actionFree(BattleUnitState*);        // ���R���[�h���̍s��
    void actionAttack(BattleUnitState*);      // �U�����[�h���̍s��
    void actionDefense(BattleUnitState*);     // ������[�h���̍s��
    void actionSpeMove(BattleUnitState*);     // �w��ړ����[�h���̍s��
    void actionSpeAttack(BattleUnitState*);   // �w��U�����[�h���̍s��
    void actionSpeDefense(BattleUnitState*);  // �w��h�䃂�[�h���̍s��

    //---- �X�L��
    void frameFirstSkil(BattleUnitState*); // �t���[���n�߃X�L��
    void frameEndSkil(BattleUnitState*);   // �t���[���I���X�L��
    void skil1(BattleUnitState*);          // �X�L��1
    
    //---- getter
    MapData *getMapData();                 // �}�b�v�f�[�^�擾
    BattleAreaState *getAreaState();       // �G���A���擾
    BattleAllUnitState *getUnitState();    // ���j�b�g���擾
    int getDamageStateNum();               // �_���[�W�I�u�W�F�N�g���\��
    BattleDamageState* getDamageState();   // �_���[�W�I�u�W�F�N�g�擾
};