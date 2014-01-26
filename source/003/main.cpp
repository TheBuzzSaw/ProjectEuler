#include <iostream>
#include <cstdint>
#include <cmath>
using namespace std;

bool IsPrime(int64_t n)
{
    bool result = false;
    
    if (n > 1)
    {
        result = true;
        
        for (int64_t i = 2; i < n; ++i)
        {
            if (!(n % i))
            {
                result = false;
                break;
            }
        }
    }
    
    return result;
}

int64_t FindLargestPrimeFactor(int64_t n)
{
    int64_t result = 1;
    
    if (n > 1)
    {
        int64_t max = (int64_t)sqrt(n);
        
        for (int64_t i = 2; i < max; ++i)
        {
            if (!(n % i) && IsPrime(i))
            {
                result = i;
            }
        }
    }
    
    return result;
}

int main(int argc, char** argv)
{
    cout << FindLargestPrimeFactor(600851475143) << endl;
    return 0;
}