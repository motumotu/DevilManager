//-----------------------------------------------------------
// BattleAllUnitState.h
// �S���j�b�g�f�[�^���
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "BattleUnitState.h"
#include "CardData.h"
#include "Define.h"
#include "GameData.h"
#include <queue>

class BattleAllUnitState {
private:
    std::queue<BattleUnitState*> my_unit;   // ���R���j�b�g
    std::queue<BattleUnitState*> en_unit;   // �G�R���j�b�g
    int all_unit_num;                       // �Œ�ID�p
    BattleUnitState *map_unit[MapData::MAP_SIZE_MAX][MapData::MAP_SIZE_MAX];
    GameData *game_data;
    AllCardData *card_data;
public:
    BattleAllUnitState(GameData*);           // �R���X�g���N�^
    ~BattleAllUnitState();          // �f�X�g���N�^
    void init();                    // ������
    void battleInit();              // �ΐ��񏉊���
    void update();                  // �X�V
    void createMyUnit(CardData*, int, int);  // ���R���j�b�g����
    void createEnUnit(CardData*, int, int);  // �G�R���j�b�g����
    BattleUnitState* getAroundEnemyMy(BattleUnitState*);// ����4�}�X�̓G���擾
    BattleUnitState* getAroundEnemyEn(BattleUnitState*);// ����4�}�X�̓G���擾
    BattleUnitState* getAroundEnemy(BattleUnitState*);  // ����4�}�X�̓G���擾
    BattleUnitState* getSearchRangeEnemy(BattleUnitState*); // ���G�͈͓��̓G���擾
    bool isSpaceAround(int, int);    // ���͂ɋ󂫂܂������邩
    bool isSpaceDire(int, int);      // �w��������󂫂܂���
    void moveDire(BattleUnitState*, int);    // �w������Ɉړ�
    BattleUnitState *popMyUnit();      // ���R�擪���j�b�g���o��
    void pushMyUnit(BattleUnitState*); // ���R���j�b�g������
    BattleUnitState *popEnUnit();      // �G�R�擪���j�b�g���o��
    void pushEnUnit(BattleUnitState*); // �G�R���j�b�g������
    void deleteUnit(BattleUnitState*); // ���j�b�g�폜

    //---- ���j�b�g�X�L��
    void deathSkil(BattleUnitState*);  // ���S���X�L������

    //---- getter
    BattleUnitState *getUnit(int, int); // �w����W�̃��j�b�g�擾
    int getMyUnitNum();             // ���R���j�b�g���擾
    int getEnUnitNum();             // �G�R���j�b�g���擾
    BattleUnitState *getMyUnit();   // ���R���j�b�g���擾
    BattleUnitState *getEnUnit();   // �G�R���j�b�g���擾
};