#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
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
    ofstream fout("dump.txt", ofstream::binary);
    int64_t x = 1;
    int64_t y = 1;
    
    cout << "[" << count << "] Generating...";
    cout.flush();
    
    int64_t originCount = 0;
    vector<double> angles;
    angles.reserve(count);
    
    for (int i = 0; i < count; ++i)
    {
        x = (x * 1248) % 32323;
        y = (y * 8421) % 30103;
        
        int64_t px = x - 16161;
        int64_t py = y - 15051;
        
        fout << "(" << px << ", " << py << ") angle " << ToDegrees(GetRadians<double>(px, py)) << "\n";
        
        if (px == 0 && py == 0)
            ++originCount;
        else
            angles.push_back(GetRadians<double>(px, py));
    }
    
    fout << '\n';
    
    if (originCount > 0)
        cout << originCount << " origins\n";
    
    cout << "Sorting...";
    cout.flush();
    
    sort(angles.begin(), angles.end());
    
    cout << "Counting...";
    cout.flush();
    
    fout << "Sorted Angles:";
    for (size_t i = 0; i < angles.size(); ++i)
        fout << " (" << i << ") " << ToDegrees(angles[i]);
    
    fout << '\n';
    
    int64_t result = 0;
    
    for (size_t i = 0; i < angles.size(); ++i)
    {
        auto low = angles[i] + Pi<double>();
        
        for (size_t j = i + 1; j < angles.size() && angles[j] <= low; ++j)
        {
            auto high = angles[j] + Pi<double>();
            
            fout
                << "("
                << i
                << ") "
                << ToDegrees(angles[i])
                << " to ("
                << j
                << ") "
                << ToDegrees(angles[j])
                << " -> shadow "
                << ToDegrees(low)
                << " to "
                << ToDegrees(high)
                << ":";
                
            size_t k = j + 1;
            while (k < angles.size() && angles[k] < low) ++k;
            
            while (k < angles.size() && angles[k] <= high)
            {
                fout << " (" << k << ") " << ToDegrees(angles[k]);
                ++result;
                ++k;
            }
            
            fout << '\n';
            
            //while (k != angles.end() && *k <= high) ++batch, ++k;
            
            //result += batch;
        }
    }
    
    fout.close();
    
    return result;
}

void TestGets()
{
    cout << "TOP\n";
    for (int i = 0; i < 10; ++i)
        TestGet(-50 + 10 * i, 50);
    
    cout << "RIGHT\n";
    for (int i = 0; i < 10; ++i)
        TestGet(50, 50 - 10 * i);
    
    cout << "BOTTOM\n";
    for (int i = 0; i < 10; ++i)
        TestGet(50 - 10 * i, -50);
    
    cout << "LEFT\n";
    for (int i = 0; i < 10; ++i)
        TestGet(-50, -50 + 10 * i);
}

int main(int argc, char** argv)
{
    if (argc < 2) TestGets();
    
    for (int i = 1; i < argc; ++i)
    {
        int64_t n;
        stringstream ss;
        ss << argv[i];
        
        if (ss >> n && n > 0)
        {
            auto result = FindC(n);
            cout << "Result: " << result << endl;
        }
        else
        {
            cerr << "invalid input: " << argv[i] << '\n';
        }
    }
    
    return 0;
}
