#include<iostream>

using namespace std;

int main(){
    int n, k, cnt=0;
    cin >> n >> k;
    int arr[n];
    for(int i = 0 ; i<n; i++){
        cin >> arr[i];
        if(arr[i] >= k)
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}

