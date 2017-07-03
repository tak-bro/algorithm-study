#include<iostream>
#include<string>

using namespace std;

int main(){
    int line, output = 0;
    string input;
    cin >> line;
    for(int i=0; i <= line; i++){
        getline(cin, input);
        if(input == "X++"){
            output++;
        }else if(input == "++X"){
            ++output;
        } else if(input == "X--"){
            output--;
        } else if(input == "--X"){
            --output;
        }
    }
    cout << output <<endl;
    return 0;
}


