/*
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iterator> // for ostream_iterator
#include <cstring>

using namespace std;

struct _greater
{
    template<class T>
    bool operator()(T const &a, T const &b) const { return a > b; }
};

// string to vector<string>
vector<string> string2vector(string s, string token){
    std::vector<std::string> v;

    size_t posLast = 0, pos = 0;
    while((pos = s.find(token, pos)) != std::string::npos) {
        if(s[pos] != s[posLast])
            v.push_back(s.substr(posLast, pos - posLast));
        posLast = ++pos;
    }
    if(s[posLast] != 0)  // If there is no terminating token found
        v.push_back(s.substr(posLast));

    return v;
}

const char* sortTheInnerContent(const char* words, int length) {
    vector<string> tokenized = string2vector(string(words), " ");
    string result;
    
    for_each(tokenized.begin(), tokenized.end(), [&result] (string word) {
        std::sort(word.begin()+1, word.end()-1, _greater());
        result.append(word);
        result.append(" ");
    });
    result.pop_back(); // for last string
    
    // string to char*
    return strndup(result.data(), result.size());
}
*/


// above is my solution but is not working properly
#include <cstring>
#include <algorithm>
#include <iostream>

void SortWord(char* begin, char* end)
{
  if (end - begin > 3)
  {
    std::sort(begin + 1, end - 1, [](char a, char b) { return a > b; });
  }
}

char* sortTheInnerContent(const char* words, int length) {
  char* result = new char[length + 1]; 
  strncpy(result, words, length);
  result[length] = '\0';
  char* begin = result;
  char* end = strchr(begin, ' ');
  while (end != nullptr)
  {
    SortWord(begin, end);
    begin = end + 1;
    end = strchr(begin, ' ');
  }
  end = strchr(begin, '\0');
  SortWord(begin, end); 
  return result;
}

int main() {
    char const *expected = sortTheInnerContent("sort the inner content in descending order", 43);
    std::cout << expected << std::endl;
      
    return 0;
}
