#include "PrimeCache.hpp"

PrimeCache::PrimeCache()
{
    _primes.insert(2);
}

PrimeCache::PrimeCache(PrimeCache&& other)
    : _primes(std::move(other._primes))
{
}

PrimeCache::PrimeCache(const PrimeCache& other)
    : _primes(other._primes)
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
    }

    return *this;
}

PrimeCache& PrimeCache::operator=(const PrimeCache& other)
{
    if (this != &other)
    {
        _primes = other._primes;
    }
    
    return *this;
}

bool PrimeCache::IsPrime(int64_t value)
{
    int64_t highestPrime = *_primes.rbegin();
    
    for (int64_t i = highestPrime + 1; i <= value; ++i)
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
    
    return _primes.count(value) > 0;
}
