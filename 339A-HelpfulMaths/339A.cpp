#include<iostream>
#include<string>
#include<cctype>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    string str, out;
    vector<int> vTmp;
    cin >> str;

    for(int i = 0; i < str.size(); i++){
        if(isdigit(str[i]))
            vTmp.push_back(str[i]);
    }
    sort(vTmp.begin(), vTmp.end());

    for(int i=0; i < vTmp.size(); i++){
        out += vTmp[i];
        if(i==vTmp.size()-1) break;
        out += '+';
    }
    cout << out <<endl;

    return 0;
}

