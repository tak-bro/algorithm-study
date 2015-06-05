#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main(){
    string str;
    vector<char> test;
    int cnt=0;

    cin >> str;
    sort(str.begin(), str.end());
    for(int i = 0; i < str.size(); i++){
        if(str[i] != str[i+1]){
            cnt++;
        }
    }

    if(cnt %2 == 0){
        cout << "CHAT WITH HER!" <<endl;
    } else {
        cout << "IGNORE HIM!" <<endl;
    }

    return 0;
}

