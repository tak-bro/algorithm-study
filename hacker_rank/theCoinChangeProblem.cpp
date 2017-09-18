#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 
// https://www.hackerrank.com/challenges/coin-change
//

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    // get Input
    int n, m;
    cin >> n;
    cin >> m;
    int *coin = new int[m];
    vector<long> change(n+1, 0);
    for (int i = 0; i < m; i++) {
        cin >> coin[i];
    }
    
    change[0] = 1; // 0을 만들수 있는 방법은 1이다. 
    
    for (int i=0; i < m; i++) {
        for (int j=coin[i]; j<=n; j++) {
            change[j] += change[j-coin[i]];
        }
    }
    // print result
    cout << change[n];
    
    return 0;
}