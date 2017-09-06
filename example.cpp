#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

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

int main() {
    cout << 2e9 << endl;
      
     return 0;
}
