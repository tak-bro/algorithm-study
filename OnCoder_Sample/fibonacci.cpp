#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include"../catch.hpp"
#include <vector>

std::vector<long long> fibonacci(80, 0);

class Solution {
public:
    long long solution(int N) {
         if (N < 2) 
            return N;

        if (fibonacci[N] != 0) 
            return fibonacci[N];
        
        return fibonacci[N] = solution(N-1) + solution(N-2);
    }
};

TEST_CASE( "Fibonacci are computed", "[Fibonacci]" ) {
    Fibonacci object = Fibonacci();
    REQUIRE( object.solution(0) == 0 );
    REQUIRE( object.solution(1) == 1 );
    REQUIRE( object.solution(2) == 1 );
    REQUIRE( object.solution(4) == 3 );
    REQUIRE( object.solution(5) == 5 );
    REQUIRE( object.solution(6) == 8 );
    REQUIRE( object.solution(7) == 13 );
    REQUIRE( object.solution(8) == 21 );
    REQUIRE( object.solution(9) == 34 );
    REQUIRE( object.solution(10) == 55 );
}
