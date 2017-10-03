#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> list, int value) {
    int low = 0;
    int high = list.size()-1;
    int mid, guess = 0;
    
    while (low <= high) {
        mid = (low + high) / 2;
        guess = list[mid];
        
        if (guess > value)
            high = mid - 1;
        if (guess < value)
            low = mid + 1;
        
        if (guess == value) 
            return mid;
    }
    
    return -1;
}

TEST_CASE( "Simple Binary Search", "[binary_search]" ) {
    vector<int> test = { 1, 3, 5, 7, 9 };
    
    int value = 3;
    REQUIRE( binarySearch(test, value) == 1 );
    
    value = 1;
    REQUIRE( binarySearch(test, value) == 0 );
    
    value = 9;
    REQUIRE( binarySearch(test, value) == 4 );
    
    value = -3;
    REQUIRE( binarySearch(test, value) == -1 );
}

