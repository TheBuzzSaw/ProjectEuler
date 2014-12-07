#include "PrimeCache.hpp"
#include <algorithm>

PrimeCache::PrimeCache()
    : _lastCheck(2)
    , _primes{2}
{
}

PrimeCache::PrimeCache(PrimeCache&& other)
    : PrimeCache()
{
    std::swap(_primes, other._primes);
    std::swap(_lastCheck, other._lastCheck);
}

PrimeCache::PrimeCache(const PrimeCache& other)
    : _primes(other._primes)
    , _lastCheck(other._lastCheck)
{
}

PrimeCache::~PrimeCache()
{
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

PrimeCache& PrimeCache::operator=(const PrimeCache& other)
{
    if (this != &other)
    {
        _primes = other._primes;
        _lastCheck = other._lastCheck;
    }
    
    return *this;
}

bool PrimeCache::IsPrime(int64_t value)
{
    for (int64_t i = _lastCheck + 1; i <= value; ++i)
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
    
    return std::binary_search(
        _primes.begin(),
        _primes.end(),
        value);
}
