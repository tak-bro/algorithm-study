#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include"../catch.hpp"
#include <math.h>

class VolTank
{
public:
  static int tankVol(int h, int d, int vt)
  {
    float r = d / 2.0f;
    float r2 = r * r;
    float oa = r - h;
    float theta = acos(oa / r);
    float ab = r * sin(theta);
    float k = vt / M_PI / r2;
    float sTheta = theta * r2 / 2.0f;
    float sOab = ab * oa / 2.0f;
    float s = 2.0f * (sTheta - sOab);
    return s * k;
  }
};


TEST_CASE( "Tank vol calculated", "[tankvol]" ) {
    VolTank object = VolTank();
    REQUIRE( object.tankVol(5, 7, 3848) == 2940 );
    REQUIRE( object.tankVol(2, 7, 3848) == 907 );
    REQUIRE( object.tankVol(2, 8, 5026) == 982 );
    REQUIRE( object.tankVol(4, 9, 6361) == 2731 );
}
