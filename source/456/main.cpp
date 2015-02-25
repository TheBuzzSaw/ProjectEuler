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
    int64_t x = 1;
    int64_t y = 1;
    
    cout << "P = {";
    
    for (int i = 0; i < 8; ++i)
    {
        x = (x * 1248) % 32323;
        y = (y * 8421) % 30103;
        
        if (i > 0) cout << ", ";
        
        cout << "(" << (x - 16161) << ", " << (y - 15051) << ")";
    }
    
    cout << "}" << endl;
    
    return 0;
}