#include <iostream>
#include <sstream>
#include <vector>
#include <cstdint>
using namespace std;

int64_t SumOfDivisors(int64_t value)
{
    int64_t result = 1;
    
    for (int64_t i = 2; i < value; ++i)
    {
        int64_t n = value / i;
        
        if (i * n == value)
        {
            result += i;
            
            if (i == n)
                break;
            else
                result += n;
        }
        else if (i > n)
        {
            break;
        }
    }
    
    return result;
}

int64_t SumOfAmicableNumbers(int64_t limit)
{
    int64_t result = 0;
    
    for (int64_t i = 2; i < limit; ++i)
    {
        int64_t a = SumOfDivisors(i);
        
        if (a > i)
        {
            int64_t b = SumOfDivisors(a);
            
            if (b == i)
            {
                result += a + b;
            }
        }
    }
    
    return result;
}

int main(int argc, char** argv)
{
    if (argc > 1)
    {
        for (int i = 1; i < argc; ++i)
        {
            stringstream ss;
            ss << argv[i];
            
            int64_t value;
            
            if (ss >> value && value > 0)
            {
                cout
                    << "sum of amicable numbers under "
                    << value
                    << " == "
                    << SumOfAmicableNumbers(value)
                    << endl;
            }
            else
            {
                cerr << "invalid: " << argv[i] << '\n';
            }
        }
    }
    else
    {
        cerr << "requires positive value\n";
    }
    
    return 0;
}
