#include <iostream>
#include <sstream>
#include <cstdint>
using namespace std;

int64_t CountDivisors(int64_t value)
{
    int64_t result = 2;
    
    for (int i = 2; i < value; ++i)
    {
        if (!(value % i))
        {
            ++result;
            
            if (value / i == i)
                break;
            else
                ++result;
        }
        else if (i * i > value)
        {
            break;
        }
    }
    
    return result;
}

void FindTriangleNumber(int64_t minDivisorCount)
{
    int64_t count = 0;
    int64_t total = 0;
    int64_t naturalNumber = 0;
    
    while (count < minDivisorCount)
    {
        total += ++naturalNumber;
        count = CountDivisors(total);
    }
    
    cout
        << "triangle number "
        << naturalNumber
        << " ("
        << total
        << ") has "
        << count
        << " divisors\n";
}

int main(int argc, char** argv)
{
    for (int i = 1; i < argc; ++i)
    {
        stringstream ss;
        ss << argv[i];
        
        int64_t minDivisorCount;
        
        if (ss >> minDivisorCount)
            FindTriangleNumber(minDivisorCount);
        else
            cerr << "invalid input: " << argv[i] << '\n';
    }
    
    return 0;
}
