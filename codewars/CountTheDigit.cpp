#include <iostream>
#include <string>
#include <algorithm>

class CountDig
{
public:
    static int nbDig(int n, int d);
};

int CountDig::nbDig(int n, int d)
{
    std::string strDigits;
    
    for (int k = 0; k <= n; ++k) {
      strDigits += std::to_string(k * k);
    }
  
    return std::count(strDigits.begin(), strDigits.end(), std::to_string(d)[0]);
}

int main() {
    int n, d = 0;
    int result = 0;
    CountDig *test;
    
    std::cout << "input n: ";
    std::cin >> n;
    std::cout << "input d: ";
    std::cin >> d;
    
    result = test->nbDig(n, d);
    
    std::cout << "Digits: "<< result << std::endl;
   
    return 0;
}
