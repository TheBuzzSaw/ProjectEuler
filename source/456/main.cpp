#include <iostream>
#include <vector>
#include <cstdint>
#include <cmath>
using namespace std;

template<typename T>
constexpr T Pi() { return 3.1415926535897932384626433832795; }

template<typename T>
constexpr T Tau() { return Pi<T>() * T(2); }

template<typename T>
constexpr T DegreesPerRadian() { return T(180) / Pi<T>(); }

template<typename T>
constexpr T ToDegrees(T radians) { return radians * DegreesPerRadian<T>(); }

template<typename T>
T GetRadians(int64_t x, int64_t y)
{
    if (x == 0)
    {
        if (y > 0)
            return Pi<T>() / T(2);
        else
            return Pi<T>() / T(-2);
    }
    
    if (y == 0)
    {
        if (x > 0)
            return 0;
        else
            return -Pi<T>();
    }
    
    auto angle = atan(T(y) / T(x));
    
    if (x > 0)
    {
        return angle;
    }
    else
    {
        if (y > 0)
            return Pi<T>() + angle;
        else
            return -Pi<T>() + angle;
    }
}

void TestGet(int x, int y)
{
    auto radians = GetRadians<double>(x, y);
    auto degrees = ToDegrees(radians);
    
    cout << x << ", " << y << " -- " << degrees << endl;
}

int64_t FindC(int64_t count)
{
    int64_t x = 1;
    int64_t y = 1;
    
    int64_t originCount = 0;
    vector<double> angles;
    angles.reserve(count);
    
    for (int i = 0; i < count; ++i)
    {
        x = (x * 1248) % 32323;
        y = (y * 8421) % 30103;
        
        int64_t px = x - 16161;
        int64_t py = y - 15051;
        
        if (px == 0 || py == 0)
            cout << px << ", " << py << endl;
        
        if (px == 0 && py == 0)
            ++originCount;
        else
            angles.push_back(GetRadians<double>(px, py));
    }
    
    cout << "origin count: " << originCount << endl;
    cout << "angle count: " << angles.size() << endl;
    
    return 0;
}

void TestGets()
{
    TestGet(-1, 50);
    TestGet(0, 50);
    TestGet(1, 50);
    
    TestGet(50, 1);
    TestGet(50, 0);
    TestGet(50, -1);
    
    TestGet(1, -50);
    TestGet(0, -50);
    TestGet(-1, -50);
    
    TestGet(-50, -1);
    TestGet(-50, 0);
    TestGet(-50, 1);
}

int main(int argc, char** argv)
{
    FindC(2000000);
    
    return 0;
}