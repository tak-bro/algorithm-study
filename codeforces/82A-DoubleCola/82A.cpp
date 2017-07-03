#include<iostream>
#include<string>

using namespace std;

int main(){
    int n;
    string strList[5] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
    cin >> n;
    if(n < 6){
        cout << strList[n-1] <<endl;
        goto end;
    }
    switch(n%6){
        case 0:
            cout << strList[0] << endl;
            break;
        case 1:
            cout << strList[1] << endl;
            break;
        case 2:
            cout << strList[2] << endl;
            break;
        case 3:
            cout << strList[3] << endl;
            break;
        case 4:
            cout << strList[4] << endl;
            break;
    }
end:
    return 0;
}

