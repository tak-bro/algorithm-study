/*
// 숫자 골라내기
input
1
4
2 5 3 3

output
Case #1
7
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

	
vector<int> getInput(int sizeLimit) 
{
    vector<int> tokenVector;
    string line;
    getline(cin, line);
    istringstream iss(line);
    string token;
    while (getline(iss, token, ' ')) {
        try {
            tokenVector.push_back(stoi(token));
        } catch (exception& e) {
            continue;
        }
        if (tokenVector.size() >= sizeLimit) {
            break;
        }
    }
    return tokenVector;
}

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++) {
        int Answer=0;
		// get inputs
	    string line;
		int n = 0;
		cin >> n; 
  	    getline(cin, line);
  	    vector<int> inputs = getInput(n);
  	    for (int i = 0; i < inputs.size(); i++) {
  	        Answer = Answer ^ inputs[i];
  	    }
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}