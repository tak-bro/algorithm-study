#include<iostream>
#include<stack>

using namespace std;

int main(){
    int nGroups, input;
    cin >> nGroups;
    stack<int> one, two, three;
    int output=0;

    for(int i = 0; i < nGroups; i++){
        cin >> input;
        if(input == 4)
            output++;
        else if(input == 3)
            three.push(3);
        else if(input == 2)
            two.push(2);
        else
            one.push(1);
    }

    while(!three.empty()){
        if(one.size() < 1){
            output += three.size();
            break;
        }
        else {
            three.pop();
            one.pop();
            output++;
        }
    }
    while(!two.empty()){
        if(one.size() < 1){
            if(two.size() != 1){
                two.pop();
                two.pop();
                output++;
            } else {
                output += two.size();
                break;
            }
        }
        else if(one.size() == 1){
            one.pop();
            two.pop();
            output++;
        }
        else {
            two.pop();
            one.pop();
            one.pop();
            output++;
        }
    }
    while(!one.empty()){
        if(one.size() > 3){
            one.pop();
            one.pop();
            one.pop();
            one.pop();
            output++;
        }
        else if(one.size() <= 3){
            for (int i = 0; i<one.size(); i++){
                one.pop();
            }
            output++;
            break;
        }
    }
    cout << output  << endl;
    return 0;
}


