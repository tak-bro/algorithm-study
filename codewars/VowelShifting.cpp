#include <algorithm>

bool isVowel(char c) {
    switch(tolower(c)) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    default:
        return false;
    }
}

static void rotateString(std::string& s, int n)
{
    if(s.empty())
        return;
        
    if(n < 0)
    {
        n = (-n) % s.size();
        auto it = s.begin() + n;
        std::rotate(s.begin(), it, s.end());
    }
    else if(n > 0)
    {
        n = n % s.size();
        auto it = s.begin() + (s.size() - n);
        std::rotate(s.begin(), it, s.end());
    }
}

std::string vowelShift(std::string text, int n)
{
    std::string tmp;
    
    // find vowels
    for (int i = 0; i < text.size(); i++) {
        if (isVowel(text[i])) {
            tmp.push_back(text[i]);
        }
    }
    
    // rotate vowels
    rotateString(tmp, n);
    
    // rotate string
    for (int i = 0, j = 0; i < text.size(); i++) {
        if (isVowel(text[i])) {
            text[i] = tmp[j];
            j++;
        }
    }  
     
    return text;
}