#include <string>
using namespace std;

string encodeOrDecode(string str, string key)
{
    std::map<char, char> map;
    for (int i = 0; i < key.length(); i += 2)
    {
        map[key[i]] = key[i + 1];
        map[toupper(key[i])] = toupper(key[i + 1]);
        map[key[i + 1]] = key[i];
        map[toupper(key[i + 1])] = toupper(key[i]);
    }
    
    std::for_each(str.begin(), str.end(), [&](char& c)
    {
        auto find = map.find(c);
        if (find != map.end())
          c = find->second;
    });
    return str;
}

string encode (string str, string key)
{
    return encodeOrDecode(str, key);
}

string decode (string str, string key)
{
    return encodeOrDecode(str, key);
}