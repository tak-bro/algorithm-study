#include<iostream>
#include<math.h>

using namespace std;

int main(){
    unsigned long long n, m, a;
    unsigned long long answer;
    cin >> n >> m >> a;
    answer = ceil((n*1.0)/a) * ceil((m*1.0)/a);
    cout << answer<< endl;
    return 0;
}

