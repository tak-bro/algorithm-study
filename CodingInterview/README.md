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

- Write a method to replace all spaces in a string with ‘%20’.
```
```
--------





