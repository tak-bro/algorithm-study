#include<iostream>

using namespace std;

int main(){
    int m, h1, a1, x1, y1, h2, a2, x2, y2;
    cin >> m >> h1 >> a1 >> x1 >> y1 >> h2 >> a2 >> x2 >> y2 ;
    int xaniar, abol;
    int test=1;
    bool flag = true;

    cout << m << h1 << a1 << x1 << y1 << h2 << a2 << x2 << y2 ;
    xaniar = (x1*h1+y1) % m;
    abol = (x2*h2+y2) % m;
    while(xaniar >= a1 && abol >= a2){
        test++;
        xaniar *= test;
        abol *= test;
        if(xaniar >=m || abol >= m){
            flag = false;
            break;
        }

    }
    cout << flag << endl;

    cout << test<<endl;


    return 0;
}

