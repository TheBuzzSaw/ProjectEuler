#include "PrimeCache.hpp"

PrimeCache::PrimeCache()
    : _lastCheck(2)
{
    _primes.insert(2);
}

PrimeCache::PrimeCache(PrimeCache&& other)
    : _primes(std::move(other._primes))
    , _lastCheck(other._lastCheck)
{
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
        _primes = std::move(other._primes);
        _lastCheck = other._lastCheck;
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
        
        if (isPrime) _primes.insert(i);
    }
    
    if (_lastCheck < value) _lastCheck = value;
    
    return _primes.count(value) > 0;
}
