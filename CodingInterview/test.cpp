#include <gtest/gtest.h>
#include "1.cpp"

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

TEST(ReplaceFunTest, TrueCase) { 
    ASSERT_EQ("ab%20", replaceFun("ab "));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}