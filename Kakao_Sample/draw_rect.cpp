#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<vector<int> > v) {
    vector<int> ans;
    int x[3] = { v[0][0], v[1][0], v[2][0] };
    int y[3] = { v[0][1], v[1][1], v[2][1] };

    // xor 연산은 두 비트가 같으면 0 다르면 1을 반환한다.
    // a와 b가 같으면 a^b=0, 다르면 0이 아닌 값
    // 세 좌표의 x값과 y값들을 각각 xor 연산하면 마지막엔 결국 구하려는 좌표값이 계산된다.  
    ans.push_back(x[0]^x[1]^x[2]);
    ans.push_back(y[0]^y[1]^y[2]);

    return ans;
}
