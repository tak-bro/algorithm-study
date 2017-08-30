#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string input;
    cin >> input;
    int result = 1;
    
    for (int i = 0; i < input.length(); i++) {
        if(isupper(input[i]))
           result++;
    }

    cout << result;
    return 0;
}
