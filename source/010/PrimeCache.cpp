#include "PrimeCache.hpp"
#include <algorithm>

PrimeCache::PrimeCache()
    : _lastCheck(3)
    , _primes{2, 3}
{
}

PrimeCache::PrimeCache(PrimeCache&& other)
    : PrimeCache()
{
    std::swap(_primes, other._primes);
    std::swap(_lastCheck, other._lastCheck);
}

PrimeCache& PrimeCache::operator=(PrimeCache&& other)
{
    if (this != &other)
    {
        std::swap(_primes, other._primes);
        std::swap(_lastCheck, other._lastCheck);
    }

    return *this;
}

void PrimeCache::FillCache(int64_t value)
{
    if (!(value & 1)) ++value; // Ensure odd value.
    
    for (int64_t i = _lastCheck + 2; i <= value; i += 2)
    {
        bool isPrime = true;
        
        for (auto j : _primes)
        {
            if (!(i % j))
            {
                isPrime = false;
                break;
            }
            else if (j * j > i)
            {
                break;
            }
        }
        
        if (isPrime) _primes.push_back(i);
    }
    
    if (_lastCheck < value) _lastCheck = value;
}

bool PrimeCache::IsPrime(int64_t value)
{
    FillCache(value);
    
    return std::binary_search(
        _primes.begin(),
        _primes.end(),
        value);
}
