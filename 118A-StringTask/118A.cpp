#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>

using namespace std;

int main(){
    string input, output;
    char vowels[] = "aoeuiy";
    getline(cin, input);
    for(int i=0; i < input.length(); i++){
        input[i] = tolower(input[i]);
    }
    for(int i=0; i < 6; ++i){
        input.erase(remove(input.begin(), input.end(), vowels[i]), input.end());
    }
    for(int i=0; i < input.length(); i++){
        output += '.';
        output += input[i];
    }
    cout << output <<endl;
    return 0;
}



