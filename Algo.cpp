#include "Algo.h"

//-----------------------------------------------------------
// yà–¾z2‚Â‚ÌlŠpŒ`‚ªÚ‚·‚é‚©
// yˆø”zlŠpŒ`a‚Ì¶ã‚ÌÀ•Wax1,ay1,‰E‰º‚ÌÀ•Wax2,ay2
//         lŠpŒ`b‚Ì¶ã‚ÌÀ•Wbx1,by1,‰E‰º‚ÌÀ•Wbx2,bx2
// y•Ô’lzÚ‚·‚éFtrueAÚ‚³‚È‚¢Ffalse
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