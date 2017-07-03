#include<iostream>
#include<string>

using namespace std;

int main(){
    bool flag = true;
    string s, t;

    cin >> s >> t;
    int nSize = t.length() - 1;

    for(int i = 0, j = nSize; i < s.length(); i++, j--){
        if(s[i] != t[j]){
            flag = false ;
        }
    }

    if(flag){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

