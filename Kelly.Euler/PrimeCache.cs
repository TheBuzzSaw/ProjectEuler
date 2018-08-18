using System;
using System.Collections.Generic;

namespace Kelly.Euler
{
    // TODO: Make this not suck.
    class PrimeCache
    {
        private readonly List<long> _primes = new List<long> { 2, 3, 5, 7 };
        private long _max = 9;

        public PrimeCache()
        {
        }

        public long Prime(int index)
        {
            while (_primes.Count <= index)
                IsPrime(_max + 101);
            
            return _primes[index];
        }

        public bool IsPrime(long n)
        {
            if (n > _max)
            {
                long oddN = n | 1;
                for (long i = _max + 2; i <= oddN; i += 2)
                {
                    bool isPrime = true;

                    foreach (long prime in _primes)
                    {
                        if ((i % prime) == 0)
                        {
                            isPrime = false;
                            break;
                        }
                        else if (i < (prime * prime))
                        {
                            break;
                        }
                    }

                    if (isPrime)
                        _primes.Add(i);
                }

                _max = oddN;

                return _primes[_primes.Count - 1] == n;
            }

            return _primes.BinarySearch(n) >= 0;
        }
    }
}