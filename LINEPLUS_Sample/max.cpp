#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(const vector<int>& data) {
	// TODO implement your solution to here.
	vector<int> tmp = data;
	std::sort(tmp.begin(), tmp.end());
			
	return tmp.back();
}

int main() {
	int N, temp;
	vector<int> data;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		data.push_back(temp);
	}
	cout << solve(data) << endl;
	return 0;
}
