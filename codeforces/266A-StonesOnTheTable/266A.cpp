#include<iostream>
#include<string>

using namespace std;

int main(){
    int nSize, nCnt = 0;
    int test=0;
    string str;
    cin >> nSize >> str;
    char tmp = str[0];

    for(int i = 0; i < nSize; i++){
        tmp = str[i];
        if(tmp == str[i+1])
            nCnt++;
        else{
            if(test < nCnt){
                test = nCnt;
            }
        }
    }
    cout << nCnt << endl;
    return 0;
}

