#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "ArraysAndStrings.cpp"

vector<int> bag(100, 1);

unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? number : Factorial(number-1)*number;
}

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );
}

TEST_CASE("UniqueCharsTest", "[isUniqueChars]") {
    // true case
    REQUIRE(isUniqueChars("ga") == true);
    REQUIRE(isUniqueChars("abcdefghy") == true);
    // false case
    REQUIRE(isUniqueChars("aaaaa") == false);
    REQUIRE(isUniqueChars("bvbbbdsfsafcdsvsa") == false);
}

TEST_CASE("AnagramTest First", "[isAnagram]") {
    // true case
    REQUIRE(isAnagram("abcdef", "bacfed") == true);
    REQUIRE(isAnagram("aaabbb", "ababab") == true);
    REQUIRE(isAnagram("asdasdasdasd", "dsadsadsadsa") == true);
    // false case
    REQUIRE(isAnagram("abcdefg", "bacfed") == false);
    REQUIRE(isAnagram("aaabbb", "aaabab") == false);
}

TEST_CASE("AnagramTest Second", "[isAnagram2]") {
    // true case
    REQUIRE(isAnagram2("abcdef", "bacfed") == true);
    REQUIRE(isAnagram2("aaabbb", "ababab") == true);
    REQUIRE(isAnagram2("asdasdasdasd", "dsadsadsadsa") == true);
    REQUIRE(isAnagram2("abcdef", "BACFED") == true);
    REQUIRE(isAnagram2("aaabbb", "ABABAB") == true);
    // false case
    REQUIRE(isAnagram2("abcdefg", "bacfed") == false);
    REQUIRE(isAnagram2("aaabbb", "aaabab") == false);
    REQUIRE(isAnagram2("abcdefg", "BacFEd") == false);
    REQUIRE(isAnagram2("aaabbb", "AAABab") == false);
    REQUIRE(isAnagram2("ab", "aaABAb") == false);
}

TEST_CASE("RotateTest", "[rotate]") {
    vector<vector<int>> arr = 
    { 
        { 1, 0, 0, 0, 1 }, 
        { 1, 0, 1, 0, 1 }, 
        { 1, 0, 0, 0, 1 }, 
        { 1, 0, 1, 0, 1 },
        { 1, 0, 0, 0, 1 },
    };
    vector<vector<int>> result =
    {
        { 1, 1, 1, 1, 1 },
        { 0, 0, 0, 0, 0 },
        { 0, 1, 0, 1, 0 },
        { 0, 0, 0, 0, 0 },
        { 1, 1, 1, 1, 1 },
    };

    rotate(5, arr); // rotate arr matrix to 90 degrees
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            REQUIRE(result[i][j] == arr[i][j]);
        }
    }
}

/*
TEST(RotateTest, MatrixSize3) { 
    vector<vector<int>> arr2 = 
    { 
        { 1, 0, 0 }, 
        { 1, 0, 1 },
        { 1, 0, 0 }, 
    };
    vector<vector<int>> result2 =
    {
        { 1, 1, 1 }, 
        { 0, 0, 0 },
        { 0, 1, 0 }, 
    };
    
    rotate(3, arr2); // rotate arr matrix to 90 degrees
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ASSERT_EQ(result2[i][j], arr2[i][j]);
        }
    }
}

TEST(SetZeroTest, MatrixSize3) { 
    vector<vector<int>> arr = 
    { 
        { 1, 1, 1 }, 
        { 1, 0, 1 },
        { 1, 1, 1 }, 
    };
    vector<vector<int>> result =
    {
        { 1, 0, 1 }, 
        { 0, 0, 0 },
        { 1, 0, 1 }, 
    };
    
    setZeros(3, 3, arr); 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ASSERT_EQ(result[i][j], arr[i][j]);
        }
    }
}

TEST(SetZeroTest, MatrixSize5) { 
    vector<vector<int>> arr = 
    { 
        { 1, 1, 1, 1 }, 
        { 1, 0, 1, 1 },
        { 1, 1, 0, 1 }, 
    };
    vector<vector<int>> result =
    {
        { 1, 0, 0, 1 }, 
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 }, 
    };
    
    setZeros(3, 4, arr); 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            ASSERT_EQ(result[i][j], arr[i][j]);
        }
    }
}

*/