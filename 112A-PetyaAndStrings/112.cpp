#include<iostream>
#include<string>

using namespace std;

int main(){
    string str1, str2;
    cin >> str1 >> str2;
    int test[str1.size()];
    int tmp;
    for(int i=0; i < str1.size(); i++){
        str1[i] = tolower(str1[i]);
        str2[i] = tolower(str2[i]);
    }

    for(int i=0; i< str1.size(); i++){
        if(str1[i] == str2[i])
            test[i] = 0;
        else if(str1[i] < str2[i])
            test[i] = -1;
        else
            test[i] = 1;
    }

    if(test[str1.size()-1] == 0)
        tmp = 0;
    for(int i = 0; i < str1.size(); i++){
        if(test[i] != 0){
            tmp = test[i];
            break;
        }
    }

    cout << tmp << endl;
    return 0;
}


