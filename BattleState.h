//-----------------------------------------------------------
// BattleState.h
// �ΐ��ʂ̏��
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "BattleMapState.h"
#include "SystemData.h"
#include "BattleCardState.h"
#include "GameData.h"
#include "Algo.h"

class BattleState {
public:
    static const int PLAYER = 0;            // �v���C���[
    static const int ENEMY = 1;             // �G
    static const int TURN_READY = 0;        // �ΐ�J�n�O
    static const int TURN_CURD_SELECT = 1;  // �J�[�h�I��
    static const int TURN_CURD_USE = 2;     // �J�[�h�g�p
    static const int TURN_BATTLE = 3;       // �o�g����
    static const int TURN_END = 4;          // �����I��
    static const int TURN_TIME = 2000;      // 1�^�[���̎���
    static const int INIT_MP = 10;          // ��������
    static const int ONETURN_MP = 5;        // 1�^�[���̖���
    static const int BATTLE_SELECT_NORMAL = 0; // �ʏ�I�����[�h
    static const int BATTLE_SELECT_AREA = 1;   // �G���A�I�����[�h
    static const int BATTLE_SELECT_MYUNIT = 2; // ���R���j�b�g�I��
    static const int BATTLE_SELECT_ENUNIT = 3; // �G�R���j�b�g�I��
    // ���W
    static const int BUTTON_CANCEL_TOP_X = 675;
    static const int BUTTON_CANCEL_TOP_Y = 515;
    static const int BUTTON_CANCEL_SIZE_X = 112;
    static const int BUTTON_CANCEL_SIZE_Y = 35;
    static const int BUTTON_END_TOP_X = 675;
    static const int BUTTON_END_TOP_Y = 555;
    static const int BUTTON_END_SIZE_X = 112;
    static const int BUTTON_END_SIZE_Y = 35;

private:
    GameData* game_data;
    BattleMapState *map_state;   // �ΐ�}�b�v���
    BattleCardState *card_state; // �J�[�h���
    std::queue<BattleUnitState*> select_unit;  // �I���������j�b�g
    BattleUnitState* mouse_on_unit;  // �J�[�\��������Ă郆�j�b�g
    int left_click_now;          // ���N���b�N����
    int click_first_pos_x;       // �N���b�N�����ʒux
    int click_first_pos_y;       // �N���b�N�����ʒuy
    int click_now_pos_x;         // �N���b�N�I���ʒux
    int click_now_pos_y;         // �N���b�N�I���ʒuy
    int now_turn;                // ���݃^�[��
    int now_battle_select_mode;  // �ΐ�^�[���ł̑I�����[�h
    int select_unit_com;         // �I�����j�b�g�ɑ΂��閽��
    int player_pos_x;            // �v���C���[�̍��Wx
    int player_pos_y;            // �v���C���[�̍��Wy
    int shift_pos_x;             // �V�t�g���Wx
    int shift_pos_y;             // �V�t�g���Wy
    int time_cnt;                // �o�ߎ���
    int my_mp;                   // ��������
    int en_mp;                   // �G����
    int winner;                  // ������

public:
    BattleState(GameData*);      // �R���X�g���N�^
    ~BattleState();              // �f�X�g���N�^
    void init();                 // ������
    void battleInit();           // �ΐ��񏉊���
    void battleSetting();        // �ΐ�ݒ�
    void update();               // �X�V
    void changeCardSelectTurn(); // �J�[�h�g�p�^�[���Ɉڍs
    void updateMousePos(int, int); // �}�E�X���W�X�V
    void moveShiftPos(int, int); // �V�t�g���W�ړ�
    void setShiftPos(int, int);  // �V�t�g���W�ݒ�
    void setInitShiftPos();      // �V�t�g���W�������ʒu��
    int changeMousePosX(int);    // �}�E�X���W���}�b�v���W�ɕϊ�
    int changeMousePosY(int);    // �}�E�X���W���}�b�v���W�ɕϊ�
    void setMapData(MapData*);   // �}�b�v�f�[�^�ݒ�
    void selectCard(int);        // �J�[�h�I��
    void selectCancelButton();   // �L�����Z���{�^���I��
    void selectEndButton();      // �I���{�^���I��
    void putUnit();              // ���j�b�g�ݒu
    bool useMyMp(int);           // ���͎g�p
    bool useEnMp(int);           // ���͎g�p
    void firstLeftClick(int x, int y); // �ŏ��̍��N���b�N
    void nowLeftClick(int x, int y);   // ���N���b�N��
    void endLeftClick(int x, int y);   // ���N���b�N�̍Ō�
    void updateSelectUnit();      // �I�����j�b�g�X�V
    void deselectUnit();          // �I�𒆂̃��j�b�g����
    void commandSelectUnit(int);  // �I�𒆂̃��j�b�g�ɑ΂��Ė���
    void commandSelectUnit(int, int, int); // �I�𒆂̃��j�b�g�ɑ΂��Ė���
    void commandSelectUnit(int, BattleUnitState*); // �I�𒆂̃��j�b�g�ɑ΂��Ė���
    void changeSelectMode(int);   // �I�����[�h�ύX
    void setSelectUnitCom(int);   // ���j�b�g�ɑ΂��閽�߃Z�b�g
    bool isPutUnitMy(CardData*, int, int);  // ���̞e�Ƀ��j�b�g�u���邩
    bool isPutUnitMy(int, int);
    bool isPutUnitEn(CardData*, int, int);
    void createUnitMy(CardData*, int, int); // ���j�b�g����
    void createUnitEn(CardData*, int, int); // ���j�b�g����
    void updateMouseOnUnit(int, int);       // �J�[�\��������Ă郆�j�b�g�X�V
    void checkEnd();             // �I������

    //---- getter
    BattleMapState *getMapState();   // �}�b�v���擾
    BattleCardState *getCardState(); // �J�[�h���擾
    MapData *getMapData();       // �}�b�v�f�[�^�擾
    int getSelectUnitNum();      // �I�𒆂̃��j�b�g��
    BattleUnitState* getSelectUnit(); // �I�𒆂̃��j�b�g
    int getPlayerPosX();         // �v���C���[���Wx�擾
    int getPlayerPosY();         // �v���C���[���Wy�擾
    int getShiftPosX();          // �V�t�g���Wx�擾
    int getShiftPosY();          // �V�t�g���Wy�擾
    int getNowTurn();            // ���݃^�[���擾
    int getNowTimeCnt();         // ���ݎc�莞�Ԏ擾
    int getMyMp();               // ���R���͎擾
    int getEnMp();               // �G�R���͎擾
    bool isLeftClickNow();       // ���N���b�N����
    int getClickFirstPosX();     // �N���b�N�����ʒux
    int getClickFirstPosY();     // �N���b�N�����ʒuy
    int getClickNowPosX();       // �N���b�N�I���ʒux
    int getClickNowPosY();       // �N���b�N�I���ʒuy
    int getNowSelectMode();      // ���݂̑I�����[�h�擾
    int getSelectUnitCom();      // �I�����j�b�g�擾
    int getWinner();             // �����Ҏ擾
};