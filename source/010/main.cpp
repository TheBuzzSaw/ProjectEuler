#include <iostream>
#include "PrimeCache.hpp"
using namespace std;

PrimeCache cache;

int64_t SumOfPrimesBelow(int64_t n)
{
    int64_t sum = 0;
    
    if (n > 2)
    {
        sum = 2;
        
        for (int64_t i = 3; i < n; i += 2)
        {
            if (cache.IsPrime(i)) sum += i;
        }
    }
    
    return sum;
}

int main(int argc, char** argv)
{
    cout << "Sum of primes below 10: "
        << SumOfPrimesBelow(10) << endl;
        
    cout << "Sum of primes below 2,000,000: "
        << SumOfPrimesBelow(2000000) << endl;

    return 0;
}
