#include<iostream>
#include<string>
#include<cctype>

#define MAX_SIZE 100

using namespace std;

int main(){
    string str;
    bool change = false;
    int upper=0, lower=0;
    cin >> str;

    for(int i = 0; i < str.size(); i++){
        if(islower(str[i]))
            lower++;
        else
            upper++;
    }

    if(islower(str[0]) && upper == (str.size()-1) || (upper == str.size()))
        change = true;

    if(change){
        for(int j=0; j < str.size(); j++){
            if(islower(str[j]))
                str[j] = toupper(str[j]);
            else if(isupper(str[j]))
                str[j] = tolower(str[j]);
        }
    }

    cout << str <<endl;
    return 0;
}

