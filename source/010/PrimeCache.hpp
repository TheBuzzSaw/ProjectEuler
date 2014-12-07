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
    
private:
    std::vector<int64_t> _primes;
    int64_t _lastCheck;
};

#endif
