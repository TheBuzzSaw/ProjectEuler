#include <iostream>
#include <cstdint>
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

int64_t GetPrime(int64_t n)
{
    int64_t primeValue = 2;
    int64_t primeCount = 1;
    
    while (primeCount < n)
    {
        while (!IsPrime(++primeValue));
        
        ++primeCount;
    }
    
    return primeValue;
}

int main(int argc, char** argv)
{
    cout << GetPrime(10001) << endl;
    
    return 0;
}
