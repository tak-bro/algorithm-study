#include <string>
#include <iostream>
#include <map>

using namespace std;

const string WIN_LEFT = "Left side wins!";
const string WIN_RIGHT = "Right side wins!";
const string DRAW = "Let's fight again!";

void checkBombs(string& fight) {
    for (int i = 0; i < fight.length(); i++) {
        if (fight[i] == '*') {
            if (i > 0 && fight[i-1] != '*')  fight[i-1] = '_';
            if (fight[i+1] != '*')           fight[i+1] = '_';
        }
    }
}

string alphabetWar(string fight)
{ 
    int result = 0;
    // Remove killed letters by bombs
    checkBombs(fight);
    map<char, int> power;
    map<char, int>::iterator it;
    //left
    power['w'] = 4;
    power['p'] = 3;
    power['b'] = 2;
    power['s'] = 1;
    //right
    power['m'] = -4;
    power['q'] = -3;
    power['d'] = -2;
    power['z'] = -1;
    
    for (int i = 0; i < fight.length(); i++) {
        it = power.find(fight[i]);
        
        if (it != power.end()) {
            result += it->second;
        }
    }
    
    if (result == 0) return DRAW;
    if (result > 0) return WIN_LEFT;
    if (result < 0) return WIN_RIGHT;
    
    return DRAW;
}


int main() {
    
    cout << alphabetWar("s*zz") << endl;           //=> Right side wins!
    cout << alphabetWar("*zd*qm*wp*bs*") << endl;  //=> Let's fight again!
    cout << alphabetWar("zzzz*s*") << endl;      //=> Right side wins!
    cout << alphabetWar("www*www****z") << endl; //=> Left side wins!
    
    return 0;
}
