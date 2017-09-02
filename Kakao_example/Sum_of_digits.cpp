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

    for (std::string::iterator itr = tmp.begin(); itr != tmp.end(); ++itr) {
        answer += char2int(*itr);
    }

    return answer;
}
