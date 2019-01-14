using System;
using System.Collections;

namespace Kelly.Euler
{
    class Problem0010 : ProblemEngine
    {
        private readonly int _primeLimit;

        public Problem0010(int primeLimit)
        {
            _primeLimit = primeLimit;
        }

        public void SolveProblem()
        {
            int primeLimit = _primeLimit;
            long sum = 2;
            var primes = new BitArray(primeLimit, true);
            primes[0] = false;
            primes[1] = false;

            for (int i = 4; i < primeLimit; i += 2)
                primes[i] = false;
            
            for (long i = 3; i < primeLimit; i += 2)
            {
                if (primes[(int)i])
                {
                    sum += i;

                    var ii = i + i;

                    for (long j = i * i; j < primeLimit; j += ii)
                        primes[(int)j] = false;
                }
            }

            Console.WriteLine($"Sum of all primes below {primeLimit} is {sum}.");
        }
    }
}