#include <string>
#include <map>
#include <algorithm>

using namespace std;

char getMapValue(char c) 
{
    map<char, char> nokia;
    nokia['a'] = '2'; nokia['b'] = '2'; nokia['c'] = '2';
    nokia['d'] = '3'; nokia['e'] = '3'; nokia['f'] = '3';
    nokia['g'] = '4'; nokia['h'] = '4'; nokia['i'] = '4'; 
    nokia['j'] = '5'; nokia['k'] = '5'; nokia['l'] = '5';
    nokia['m'] = '6'; nokia['n'] = '6'; nokia['o'] = '6';
    nokia['p'] = '7'; nokia['q'] = '7'; nokia['r'] = '7'; nokia['s'] = '7';
    nokia['t'] = '8'; nokia['u'] = '8'; nokia['v'] = '8';
    nokia['w'] = '9'; nokia['x'] = '9'; nokia['y'] = '9'; nokia['z'] = '9';
    
    return nokia[c];
}

string unlock (string str)
{ 
    string strResult;
    for_each(str.begin(), str.end(), [&](char c){
        strResult.push_back(getMapValue(tolower(c)));
    });
    
    
    return strResult;
}