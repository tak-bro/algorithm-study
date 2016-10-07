#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<int> getInput(ssize_t sizeLimit) 
{
    vector<int> tokenVector;
    string line;
    getline(cin, line);
    istringstream iss(line);
    string token;
    while (getline(iss, token, ' ')) {
        try {
            tokenVector.push_back(stoi(token));
        } catch (exception& e) {
            continue;
        }
        if (tokenVector.size() >= sizeLimit) {
            break;
        }
    }
    return tokenVector;
}


int main(void)
{
    // 표준 입력으로부터 최대 10개의 자연수를 벡터 형태로 읽어들임
    vector<int> numbers = getInput(10);

    //다음과 같은 방식으로 numbers 벡터와 number 변수를 사용할 수 있음
    /*
    for_each(numbers.begin(), numbers.end(), [] (int number) {
            cout << "number=" << number << endl;
            });
    cout << numbers[0] << endl;
    */

    //   write your code here
    float fSum = 0;

    for(vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        fSum += *it;
    }
    float fAverage = fSum / numbers.size();
    cout.setf(ios::fixed);
    cout.precision(1); 
    cout << fAverage << endl;

    return 0;
}
