#include "Algo.h"

//-----------------------------------------------------------
// 【説明】2つの四角形が接するか
// 【引数】四角形aの左上の座標ax1,ay1,右下の座標ax2,ay2
//         四角形bの左上の座標bx1,by1,右下の座標bx2,bx2
// 【返値】接する：true、接さない：false
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