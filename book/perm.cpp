#include <iostream>
#include <vector>

using namespace std;

// swap
void swap(vector<int> &arr, int i, int j) 
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

// nPr
void perm(vector<int> &arr, int depth, int n, int k) 
{
    if (depth == k) { // 한번 depth가 k로 도달하면 사이클이 돌았음.
        // print
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for (int i = depth; i < n; i++) {
        swap(arr, i, depth);
        perm(arr, depth+1, n, k);
        swap(arr, i, depth);
    }
}

int main() {
    vector<int> arr = { 1, 2, 3, 4 };
    perm(arr, 0, 4, 4);
    
    return 0;
}