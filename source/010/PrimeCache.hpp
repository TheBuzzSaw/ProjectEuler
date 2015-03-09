#ifndef PrimeCacheHpp
#define PrimeCacheHpp

#include <cstdint>
#include <vector>

class PrimeCache
{
public:
    PrimeCache();
    PrimeCache(PrimeCache&& other);
    PrimeCache(const PrimeCache& other);
    ~PrimeCache();
    
    PrimeCache& operator=(PrimeCache&& other);
    PrimeCache& operator=(const PrimeCache& other);
    
    bool IsPrime(int64_t value);
    
    std::vector<int64_t>::const_iterator begin() const
    {
        return _primes.cbegin();
    }
    
    std::vector<int64_t>::const_iterator end() const
    {
        return _primes.cend();
    }
    
private:
    std::vector<int64_t> _primes;
    int64_t _lastCheck;
};

#endif
