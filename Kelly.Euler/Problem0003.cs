using System;

namespace Kelly.Euler
{
    class Problem0003 : ProblemEngine
    {
        private readonly long _number;

        public Problem0003(long number)
        {
            _number = number;
        }

        public static bool IsPrime(long n)
        {
            for (long i = 3; (i * i) < n; ++i)
            {
                if ((n % i) == 0)
                    return false;
            }

            return true;
        }

        public void SolveProblem()
        {
            long number = _number;
            long result = 0;

            for (long i = 3; (i * i) < number; i += 2)
            {
                if ((number % i) == 0 && IsPrime(i))
                    result = i;
            }

            Console.WriteLine($"Largest prime factor of {number} is {result}.");
        }
    }
}