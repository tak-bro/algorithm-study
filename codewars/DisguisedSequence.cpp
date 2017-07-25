#include<iostream>

class HiddenSeq
{
    public:
    static unsigned long long fcn(int n) {
        return std::pow(2.0, n);
    }
}

/*
    Sequence: 1,2,X
    (6 * u0 * u1) - (5 * u0 * u2) + (u1 * u2) = 0
    (6 * 1  * 2 ) - (5 * 1  * X ) + (2  * X ) = 0
    12 - 5X + 2X = 0
    12 = 3X
    X = 4
    Sequence: 1,2,4,X
    (6 * u1 * u2) - (5 * u1 * u3) + (u2 * u3) = 0
    (6 * 2  * 4 ) - (5 * 2  * X ) + (4  * X ) = 0
    48 - 10X + 4X = 0
    48 = 6X
    X = 8
    Sequence: 1,2,4,8,X
    And so on...
    It is clear to see that the sequence matches perfectly with the function un = 2^n.
*/
