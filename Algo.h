#pragma once
#include <stdio.h>
class Algo {
public:
    // 2つの四角形が接するか
    static bool crossTwoSquare(
        int ax1, int ay1, int ax2, int ay2,
        int bx1, int by1, int bx2, int by2);
};