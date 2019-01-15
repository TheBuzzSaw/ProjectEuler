using System;

namespace Kelly.Euler
{
    class Problem0005 : ProblemEngine
    {
        public void SolveProblem(int number = 20)
        {
            var maxFactorCounts = new short[number - 1];

            for (int i = 2; i <= number; ++i)
            {
                Span<short> factorCounts = stackalloc short[maxFactorCounts.Length];

                int remainder = i;
                for (int j = 2; 2 <= remainder; ++j)
                {
                    if ((remainder % j) == 0)
                    {
                        ++factorCounts[j - 2];
                        remainder /= j;
                        j = 1;
                    }
                }

                for (int j = 0; j < maxFactorCounts.Length; ++j)
                    maxFactorCounts[j] = Math.Max(maxFactorCounts[j], factorCounts[j]);
            }

            int result = 1;

            for (int i = 0; i < maxFactorCounts.Length; ++i)
            {
                int n = i + 2;

                for (short j = 0; j < maxFactorCounts[i]; ++j)
                    result *= n;
            }

            Console.WriteLine($"The smallest multiple of {number} is {result}.");
        }
    }
}