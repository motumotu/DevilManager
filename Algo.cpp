#include "Algo.h"

//-----------------------------------------------------------
// �y�����z2�̎l�p�`���ڂ��邩
// �y�����z�l�p�`a�̍���̍��Wax1,ay1,�E���̍��Wax2,ay2
//         �l�p�`b�̍���̍��Wbx1,by1,�E���̍��Wbx2,bx2
// �y�Ԓl�z�ڂ���Ftrue�A�ڂ��Ȃ��Ffalse
//-----------------------------------------------------------
bool Algo::crossTwoSquare(
    int ax1, int ay1, int ax2, int ay2,
    int bx1, int by1, int bx2, int by2)
{
    if (ax1 > bx2 || bx1 > ax2 || ay1 > by2 || by1 > ay2) {
        return false;
    }
    return true;
}