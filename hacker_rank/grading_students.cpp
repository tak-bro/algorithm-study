#include <bits/stdc++.h>

using namespace std;

int roundUp(int n) {
    if (n < 38)
        return n;
    
    switch (n%5) {
        case 3:
            n += 2;
            break;
        case 4:
            n += 1;
            break;
        default:
            break;
    }
    return n;
}

vector < int > solve(vector < int > grades){
    // Complete this function
    vector<int> result;
    
    for(vector<int>::iterator it = grades.begin(); it != grades.end(); it++) {
          result.push_back(roundUp(*it));
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> grades(n);
    for(int grades_i = 0; grades_i < n; grades_i++){
       cin >> grades[grades_i];
    }
    vector < int > result = solve(grades);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? "\n" : "");
    }
    cout << endl;
    

    return 0;
}
