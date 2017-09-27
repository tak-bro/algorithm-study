#include <iostream>
#include <string>

using namespace std;

void reverse(char *str) {
    char *end = str;
    char tmp;
    
    if (str) {
        while (*end) {
            ++end;
        } 
        --end; // go to last character
        // reverse
        while (str < end) {
            tmp = *str;
            *str++ = *end;
            *end-- = tmp;
        }
    }
}

bool isUniqueChars(string str) {
    bool *charSet = new bool[256];
    
    for (int i = 0; i < str.length(); i++) {
        int val = str[i];
        if (charSet[val]) 
            return false;
        charSet[val] = true;    
    }
    return true;
}

int main() {
    cout << isUniqueChars("aaaaa") << endl;
    cout << isUniqueChars("abcdefg") << endl;
    
    char a[256] = "123456";
    cout << a << endl;
    reverse(a);
    cout << a << endl;
    
    return 0;
}