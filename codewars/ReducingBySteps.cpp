#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include"../catch.hpp"
#include <vector>

#include <vector>

class Operarray
{
public:
    static long long gcdi(long long x, long long y);
    static long long lcmu(long long a, long long b);
    static long long som(long long a, long long b);
    static long long maxi(long long a, long long b);
    static long long mini(long long a, long long b);
    template<typename Func>
    static long long oper(Func func, long long a, long long b);
    template<typename Func>
    static std::vector<long long> operArray(Func func, std::vector<long long> &arr, long long init);
};

long long Operarray::gcdi(long long x, long long y)
{
    x = std::abs(x); y = std::abs(y);
    while (y != 0)
    {
        long long tmp = x; x = y; y = tmp % y;
    }
    return x;
}
long long Operarray::lcmu(long long a, long long b)
{
    return std::abs(a * b) / gcdi(a, b);
}
long long Operarray::som(long long a, long long b)
{
    return a + b;
}
long long Operarray::maxi(long long a, long long b)
{
    return std::max(a, b);
}
long long Operarray::mini(long long a, long long b)
{
    return std::min(a, b);
}
template<typename Func>
long long Operarray::oper(Func func, long long a, long long b)
{
    return func(a, b);
}
template<typename Func>
std::vector<long long> Operarray::operArray(Func func, std::vector<long long> &arr, long long init)
{
    long long c = init;
    std::vector<long long> res(arr.size());
    for (unsigned int i = 0; i < arr.size(); i++)
    {
        c = oper(func, c, arr[i]);
        res[i] = c;
    }
    return res;
}


TEST_CASE( "Reductin By steps", "[Operarray]" ) {
    std::vector<long long> dta = { 18, 69, -90, -78, 65, 40 };
    std::vector<long long> sol = { 18, 3, 3, 3, 1, 1 };
    
    REQUIRE( Operarray::(2, 8, 5026) == 982 );
    dotest(Operarray::gcdi, dta, dta[0], sol);
    sol = { 18, 414, 2070, 26910, 26910, 107640 };
    dotest(Operarray::lcmu, dta, dta[0], sol);
    sol = { 18, 69, 69, 69, 69, 69 };
    dotest(Operarray::maxi, dta, dta[0], sol);
    sol = { 18, 18, -90, -90, -90, -90 };
    dotest(Operarray::mini, dta, dta[0], sol);
    sol = { 18, 87, -3, -81, -16, 24 };
    dotest(Operarray::som, dta, 0, sol);
}
