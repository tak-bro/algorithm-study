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

void rotate(int n, vector<vector<int>> &matrix) {
    for (int layer = 0; layer < n/2; ++layer) {
        int first = layer;
        int last = n-1-layer;
        
        for (int i = first; i < last; ++i) {
            int offset = i - first;
            int top = matrix[first][i]; // save top
            
            // left -> top
            matrix[first][i] = matrix[last-offset][first];
            
            // bottom -> left
            matrix[last-offset][first] = matrix[last][last-offset];
            
            // right -> bottom
            matrix[last][last-offset] = matrix[i][last];
            
            // top -> right
            matrix[i][last] = top; // right
        }
    }
}

void setZeros(int n, int m, vector<vector<int>> &matrix) {
    vector<int> row(n, 0);
    vector<int> column(m, 0);
    
    // store the index
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                row[i] = 1;
                column[j] = 1;
            }
        }
    }
    
    // set matrix[i][j] to zero
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row[i] == 1 || column[j] == 1) {
                matrix[i][j] = 0;
            }
        }
    }
}