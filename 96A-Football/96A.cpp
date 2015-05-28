#include<iostream>
#include<string>

using namespace std;

int main(){
    string str;
    int isStanding=0;
    bool isDangerous = false;
    cin >> str;
    for(int i = 0 ; i < str.size(); i++){
        if(str[i] == str[i+1]){
            isStanding++;
            if(isStanding > 5){
                isDangerous = true;
                break;
            }
        }
        else
            isStanding = 0;
    }

    if(isDangerous)
        cout << "YES" <<endl;
    else
        cout << "NO" <<endl;

    return 0;
}

