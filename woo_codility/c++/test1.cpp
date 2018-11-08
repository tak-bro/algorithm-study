#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include"../catch.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iterator> // for ostream_iterator

using namespace std;

// x = wrap(x, 0, 10): 0~9내부를 랩 어라운드
int wrap(int x, int low, int high)
{
    if (low < high) {
        cout << "error!" << endl;
        return -1;
    }

    const int n = (x - low) % (high - low);
    return (n >= 0) ? (n + low) : (n + high);
}

// sort greator
// std::sort(odd.begin(), odd.end(), _greator());
struct _greater
{
    template<class T>
    bool operator()(T const &a, T const &b) const { return a > b; }
};

// sort less
// std::sort(odd.begin(), odd.end(), _less());
struct _less
{
    template<class T>
    bool operator()(T const &a, T const &b) const { return a < b; }
};

// int to string
string int2string(int n) {
    stringstream ss;
    ss << n;
    return ss.str();
}

// char to int 
// only use when character is digit
int char2int(char n) {
    return n - '0';
}

// string to int
int string2int(string n) {
    istringstream buffer(n);
    int result;
    buffer >> result;
    return result;
}

// vector<string> to string
string vector2string(const std::vector<std::string>& elements, const char* const separator)
{
    switch (elements.size())
    {
        case 0:
            return "";
        case 1:
            return elements[0];
        default:
            std::ostringstream os; 
            std::copy(elements.begin(), elements.end()-1, std::ostream_iterator<std::string>(os, separator));
            os << *elements.rbegin();
            return os.str();
    }
}

// vector<string> vecSplit = split("ab cd ef", " ")
// vecSplit = { "ab", "cd", "ef" }
vector<string> split(string& stringToSplit, string& delimiter)
{
    vector<string> result;
    size_t pos = 0, lastPos = 0;
    while ((pos = stringToSplit.find_first_of(delimiter, lastPos)) != string::npos)
    {
        result.push_back(stringToSplit.substr(lastPos, pos-lastPos+1));
        lastPos = pos+1;
    }
    result.push_back(stringToSplit.substr(lastPos));
    
    return result;
}

// return max
int max(int a, int b)
{
    return a > b ? a : b;
}

// return min
int min(int a, int b)
{
    return a > b ? b : a;
}

/* **********************************************************************************************************************************************************
 * start soluiton
 * **********************************************************************************************************************************************************/

int solution(int n)
{
    return n;
}

TEST_CASE( "codility test1", "[solution]" ) {
    REQUIRE( solution(10) == 10 );
    REQUIRE( solution(10) == 10 );
}