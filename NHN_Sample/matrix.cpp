#include <iostream>
#include <sstream>
#include <vector>
#include <string>

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


int main() {
	int n = 0;
	string line;
	
	cin >> n;
  	getline(cin, line);
	
	vector< vector<int> > input(n, vector<int>(n, 0));
	
	// get input NxN matrix
	for (int i = 0; i < n; i++) {
	    input[i] = getInput(n);
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
		    if (j == n-1) {
			    cout << input[j][i];
		    } else {
			    cout << input[j][i] << " ";
		    }
		}
		cout << endl;
	}

    	return 0;
}
