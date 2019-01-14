using System;

namespace Kelly.Euler
{
    class Problem0027 : ProblemEngine
    {
        public Problem0027()
        {
        }

        public void SolveProblem()
        {
            var cache = new PrimeCache();
            int index = 0;
            int maxLength = 0;
            long a = 0;
            long b = 0;

            while (true)
            {
                long prime = cache.Prime(index++);

                if (prime >= 1000)
                    break;
                
                for (long coefficient = -999; coefficient <= 999; ++coefficient)
                {
                    int length = 0;
                    long n = 0;

                    while (true)
                    {
                        long value = n * n + coefficient * n + prime;

                        if (!cache.IsPrime(value))
                            break;
                            
                        ++length;
                        ++n;
                    }

                    if (length > maxLength)
                    {
                        maxLength = length;
                        a = coefficient;
                        b = prime;
                    }
                }
            }

            Console.WriteLine($"{a} and {b}: {a * b}");
        }
    }
}