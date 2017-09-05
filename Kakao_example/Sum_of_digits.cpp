#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string int2string(int n) {
    stringstream ss;
    ss << n;
    return ss.str();
}

// single char
int char2int(char n) {
    return n - '0';
}

int string2int(string n) {
    istringstream buffer(n);
    int result;
    buffer >> result;
    return result;
}

int solution(int n)
{
    int answer = 0;
    string tmp = int2string(n);
    
    for (std::string::iterator itr = tmp.begin(); itr != tmp.end(); ++itr) {
        answer += char2int(*itr);
    }

    return answer;
}

// build command: clang++ Sum_of_digits.cpp -std=c++11 -O2 -Wno-unused-result
int main() {
    int input = 123213213;
    int result = solution(input);
    
    std::cout << result << endl;
}