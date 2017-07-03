#include<iostream>

using namespace std;

int main(){
    int n, cnt=0;

    cin >> n;
    int p[n];
    int q[n];

    for(int i = 0; i < n; i++){
        cin >> p[i] >> q[i] ;
        if(q[i] - p[i] >= 2){
            cnt++;
        }
    }
    cout << cnt <<endl;
    return 0;
}

