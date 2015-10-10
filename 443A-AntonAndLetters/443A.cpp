#include<iostream>
#include<string>
#include<map>
#include<ctype.h>

using namespace std;

int main(){
    map<char, int> hashMap;
    map<char, int>::iterator mapIter;

    string strInput;
    getline(cin, strInput);

    for(int i = 0; i < strInput.length(); i++){
        if(isalpha(strInput[i])){
            mapIter = hashMap.find(strInput[i]);
            if(mapIter == hashMap.end()){
                hashMap.insert( map<char, int>::value_type(strInput[i], 1));
            }
        }
    }

    int nOutput = hashMap.size(); 
    cout << nOutput << endl;

    return 0;
}

