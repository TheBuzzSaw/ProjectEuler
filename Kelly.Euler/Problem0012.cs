using System;

namespace Kelly.Euler
{
    class Problem0012 : ProblemEngine
    {
        private readonly int _minFactorCount;

        public Problem0012(int minFactorCount)
        {
            _minFactorCount = minFactorCount;
        }

        public override void SolveProblem()
        {
            int minFactorCount = _minFactorCount;
            int factorCount = 0;
            int naturalNumber = 0;
            long total = 0;

            while (factorCount <= minFactorCount)
            {
                total += ++naturalNumber;
                factorCount = CountFactors(total);
            }

            Console.WriteLine($"Triangle number #{naturalNumber} is {total} and has {factorCount} factors.");
        }

        private static int CountFactors(long number)
        {
            if (number < 2)
                return 1;
            
            int result = 2;

            for (long i = 2; i < number; ++i)
            {
                if ((number % i) == 0)
                {
                    ++result;

                    if (number / i == i)
                        break;
                    else
                        ++result;
                }
                else if (i * i > number)
                {
                    break;
                }
            }

            return result;
        }
    }
}