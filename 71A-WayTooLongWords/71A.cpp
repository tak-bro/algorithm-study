#include<iostream>
#include<string.h>

#define SIZE 120

using namespace std;

int main(){
    int n, length;
    char string[SIZE][SIZE] ;
    cin >> n;
    for(int i =0; i<n; i++){
        cin >> string[i];
    }

    for(int j=0; j<n ; j++){
        if((length = strlen(string[j])) > 10){
            cout << string[j][0] << length-2 << string[j][length-1] << endl;
        }
        else{
            cout << string[j] << endl;
        }
    }
    return 0;
}
