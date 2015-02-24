#include <iostream>
#include <cstdint>
#include <cmath>
using namespace std;

struct Point
{
    int16_t x;
    int16_t y;
};

template<typename T>
constexpr T Pi() { return 3.1415926535897932384626433832795; }

template<typename T>
constexpr T DegreesPerRadian() { return T(180) / Pi<T>(); }

template<typename T>
constexpr T ToDegrees(T radians) { return radians * DegreesPerRadian<T>(); }

template<typename T>
T GetRadians(int x, int y)
{
    return atan(T(y) / T(x));
}

void TestGet(int x, int y)
{
    auto radians = GetRadians<double>(x, y);
    auto degrees = ToDegrees(radians);
    
    cout << x << ", " << y << " -- " << degrees << endl;
}

int main(int argc, char** argv)
{
    TestGet(50, 50);
    TestGet(50, 0);
    TestGet(50, -50);
    TestGet(0, -50);
    TestGet(-50, -50);
    
    return 0;
}