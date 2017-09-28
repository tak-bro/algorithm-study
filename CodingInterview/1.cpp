#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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
    vector<bool> charSet(256, false);
    
    for (int i = 0; i < str.length(); i++) {
        int val = str[i];
        if (charSet[val]) 
            return false;
        charSet[val] = true;    
    }
    return true;
}

bool isAnagram(string a, string b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    return (a == b);
}

bool isAnagram2(string a, string b) {
    int len = a.length();
    if (len != b.length()) 
        return false;
    vector<int> bit(256, 0);
    // to lower
    transform(a.begin(), a.end(), a.begin(), ::toupper);
    transform(b.begin(), b.end(), b.begin(), ::toupper);
    
    for (int i = 0; i < len; i++) {
        int valA = a[i];
        int valB = b[i];
        bit[valA]++;
        bit[valB]--;
    }
    
    for (vector<int>::iterator itr = bit.begin(); itr != bit.end(); ++itr) {
        if (*itr > 0) 
            return false;
    }
    
    return true;
}

string replaceFun(string str) {
    int len = str.length();
    int spaceCnt = 0;
    int newLength = 0;
    
    for (int i = 0; i < len; i++) {
        if (str[i] == ' ') spaceCnt++;
    }
    newLength = len + spaceCnt*2;
    
    for (int i = len; i > 0; i--) {
        if (str[i] == ' ') {
            str[newLength-1] = '0';
            str[newLength-2] = '2';
            str[newLength-3] = '%';
            newLength = newLength - 3;
        } else {
            str[newLength-1] = str[i];
            newLength = newLength - 1;
        }
    }
    return str;
}