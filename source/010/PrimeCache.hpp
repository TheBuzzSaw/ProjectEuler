#ifndef PrimeCacheHpp
#define PrimeCacheHpp

#include <set>
#include <cstdint>

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
    
private:
    std::set<int64_t> _primes;
};

#endif
