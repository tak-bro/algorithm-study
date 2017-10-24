#include <iostream>
#include <vector>

using namespace std;

void combination(vector<int> &arr, int index, int n, int r, int target)
{
    // print
    if (r == 0) {
        for (int i = 0; i < index; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    } else if (target == n) {
        return;
    } else {
        arr[index] = target;
        combination(arr, index+1, n, r-1, target+1);
        combination(arr, index, n, r, target+1);
    }
}

int main() {
    vector<int> arr = { 0, 1, 2, 3, 4 };
    combination(arr, 0, 5, 3, 0);
    
    return 0;
}