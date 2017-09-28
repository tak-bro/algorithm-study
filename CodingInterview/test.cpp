#include <gtest/gtest.h>
#include "ArraysAndStrings.cpp"

TEST(UniqueCharsTest, TrueCase) { 
    ASSERT_EQ(true, isUniqueChars("ga"));
    ASSERT_EQ(true, isUniqueChars("abcdefghijk"));
}

TEST(UniqueCharsTest, Falsecase) { 
    ASSERT_EQ(false, isUniqueChars("aaaaa"));
    ASSERT_EQ(false, isUniqueChars("bvbbbdsfsafcdsvsa"));
}

TEST(AnagramTest, TrueCase) { 
    ASSERT_EQ(true, isAnagram("abcdef", "bacfed"));
    ASSERT_EQ(true, isAnagram("aaabbb", "ababab"));
    ASSERT_EQ(true, isAnagram2("abcdef", "bacfed"));
    ASSERT_EQ(true, isAnagram2("aaabbb", "ababab"));
}

TEST(AnagramTest, FalseCase) { 
    ASSERT_EQ(false, isAnagram("abcdefg", "bacfed"));
    ASSERT_EQ(false, isAnagram("aaabbb", "aaabab"));
    ASSERT_EQ(false, isAnagram2("abcdefg", "bacfed"));
    ASSERT_EQ(false, isAnagram2("aaabbb", "aaabab"));
}

TEST(AnagramTest2, UpperCase) { 
    ASSERT_EQ(true, isAnagram2("abcdef", "BACFED"));
    ASSERT_EQ(true, isAnagram2("aaabbb", "ABABAB"));
    ASSERT_EQ(false, isAnagram2("abcdefg", "BacFEd"));
    ASSERT_EQ(false, isAnagram2("aaabbb", "aaABAb"));
    ASSERT_EQ(false, isAnagram2("ab", "aaABAb"));
}


TEST(RotateTest, MatrixSize5) { 
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
            ASSERT_EQ(result[i][j], arr[i][j]);
        }
    }
}

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


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}