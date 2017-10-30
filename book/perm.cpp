#include <iostream>
#include <vector>

using namespace std;
//  http://gorakgarak.tistory.com/522


// swap
void swap(vector<int> &arr, int i, int j) 
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

// nPr
// arr: 데이터 array
// depth: 현재 트리구조에서 어떤 깊이에서 교환작업을 할지
// n: 배열의 갯수
// k: 몇개를 뽑아서 순열을 만들것인지.
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
        swap(arr, i, depth);    // i와 depth를 교환
        perm(arr, depth+1, n, k); // a[depth+1],... a[k]
        swap(arr, i, depth);    // 원래상태로 되돌리기위해
    }
}

int main() {
    vector<int> arr = { 1, 2, 3, 4 };
    perm(arr, 0, 4, 4);
    
    return 0;
}