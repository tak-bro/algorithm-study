#include<iostream>
#include<string>

using namespace std;

int main(){
    string str;
    size_t found;
    char test[] = "HQ9";
    bool flag = false;

    cin >> str;
    for(int i = 0; i<4; i++){
        found = str.find(test[i]);
        if(found != string::npos){
            flag = true;
            break;
        }
    }

    if(flag)
        cout << "YES" <<endl;
    else
        cout << "NO" <<endl;

    return 0;
}

