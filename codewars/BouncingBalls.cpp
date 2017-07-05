#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
class Bouncingball
{
public:
    static int bouncingBall(double h, double bounce, double window);
};

int Bouncingball::bouncingBall(double h, double bounce, double window) {
    bool isHeightNonZero = (h > 0)? true:false;
    bool isBounceInRange = (bounce > 0 && bounce < 1)? true:false;
    bool isLowerWindow = (window < h)? true:false;
    int result = 1; // f h> window, Mom will see it once.
    
    // Check condition
    if (!isHeightNonZero || !isBounceInRange || !isLowerWindow) {
        return -1;
    }
    
    // Start at bottom
    h *= bounce;
    while (h > window) {
        result +=2;
        h *= bounce;
    }
    
    return result;
}


int main(void)
{
    Bouncingball a;
    int result = a.bouncingBall(30, 0.66, 1.5);
    cout << result <<endl;

    return 0;
}
