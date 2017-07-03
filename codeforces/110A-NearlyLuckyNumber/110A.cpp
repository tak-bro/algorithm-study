#include<iostream>
#include<string>

using namespace std;

int main(){
    string str;
    bool flag = true;
    int fourFlag = 0;
    int sevenFlag = 0;

    cin >> str;

    for(long i=0; i < str.size(); i++){
        if(str[i]=='4'){
            fourFlag++;
        }
        else if(str[i] == '7'){
            sevenFlag++;
        }
    }
    int sum = fourFlag + sevenFlag;

    if(sum == 4 || sum == 7){
        cout << "YES" <<endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

