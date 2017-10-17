#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Description :
 * Time complexity :
 * Space complexity :
 */
int calc(vector<int> &list) {
    int size = list.size();
    if (size== 1)   return 1;
	
	// sort
    int first, second, third = 0;
    for (int i = 0; i < size-2; i+=2) {
        first = list[i];
        second = list[i+1];
        third = list[i+2];
        
        if (first > second && first > third) {
            list[i+1] = first;
            list[i] = second;
        }
        else if (third> first && third > second) {
            list[i+1] = third;
            list[i+2] = second;
        }
    }
	// check
	int n=0;
	for (int i = 0; i < list.size(); i++) {
		if (is_sorted(list.rbegin(), list.rend()-i)) {
		    cout << "i: " << i << endl;
			n++;
		}	
	}
	cout << n << endl;
	
	for (int i = 0; i < size; i++) {
	    cout << list[i] << ' ';
	}
	cout << '\n';
	int result = size - n;
    return result;

}

int main(int argc, const char* argv[]) {
    int n = 0;

    vector<int> numbers = { 2, 3, 1, 5, 8, 9, 10, 11, 13, 24, 56, 68, 69, 50, 54, 55, 56, 58, 205, 115, 505, 415, 213 };
    cout << calc(numbers) << endl;
    
    return 0;
}
