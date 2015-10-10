#include<iostream>
#include<string>

using namespace std;

int main(){
    string strInput, strInput2, strOutput;
    cin >> strInput >> strInput2 ;

    for(int i = 0; i <strInput.length(); i++){
        if(strInput[i] != strInput2[i])
            strOutput.append("1");
        else 
            strOutput.append("0");
    }
    cout << strOutput << endl;

    return 0;
}
