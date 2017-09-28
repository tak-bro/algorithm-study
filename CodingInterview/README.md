# Cracking the Coding Interview, 4th Edition

## Table of Contents
- [Chapter1. Arrays and Strings](#arrays-and-strings)

--------

#### Arrays and Strings

- Implement an algorithm to determine if a string has all unique characters. What if you can not use additional data structures?
```c
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

```

- Write code to reverse a C-Style String. (C-String means that “abcd” is represented as five characters, including the null character.)
```c
void reverse(char *str) {
    char *end = str;
    char tmp;
    
    if (str) {
        while (*end) {
            ++end;
        }
        --end;
        while (str < end) {
            tmp = *str;
            *str++ = *end;
            *end-- = tmp;
        }
    }
}
```

- Write a method to decide if two strings are anagrams or not.
```c
bool isAnagram(string a, string b) {
    if (a.length() != b.length()) return false;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return (a == b);
}
```

- Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in place?
```c
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
```

- Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column is set to 0.
```c

```


--------





