#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<string> getInput(ssize_t sizeLimit)
{
    vector<string> tokenVector;
    string line;
    getline(cin, line);
    istringstream iss(line);
    string token;
    while (getline(iss, token, ' ')) {
        tokenVector.push_back(token);
        if (tokenVector.size() >= sizeLimit) {
            break;
        }
    }
    return tokenVector;
}


int main(void)
{
     //   표준 입력으로부터 최대 10개의 문자열 토큰을 벡터 형태로 반환받음
    vector<string> words = getInput(10);

    // 다음과 같은 방식으로  words와 word 문자열 변수로 사용할 수 있음
    /*
       for_each(words.begin(), words.end(), [] (string word) {
           cout << "word=" << word << endl;
       });
       cout << words[0] << endl;
    */

    // write your code here
    int nSum = 0;

    for(vector<string>::iterator it = words.begin(); it != words.end(); ++it) {
        nSum += it->length();
    }
    cout << nSum << endl;

    return 0;
}
