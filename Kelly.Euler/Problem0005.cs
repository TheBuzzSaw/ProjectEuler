using System;

namespace Kelly.Euler
{
    class Problem0005 : ProblemEngine
    {
        private readonly int _number;

        public Problem0005(int number)
        {
            _number = number;
        }

        public override void SolveProblem()
        {
            int number = _number;
            var maxFactorCount = new short[number - 1];

            for (int i = 2; i <= number; ++i)
            {
                Span<short> factorCount = stackalloc short[maxFactorCount.Length];

                int remainder = i;
                for (int j = 2; 2 <= remainder; ++j)
                {
                    if ((remainder % j) == 0)
                    {
                        ++factorCount[j - 2];
                        remainder /= j;
                        j = 1;
                    }
                }

                for (int j = 0; j < maxFactorCount.Length; ++j)
                    maxFactorCount[j] = Math.Max(maxFactorCount[j], factorCount[j]);
            }

            int result = 1;

            for (int i = 0; i < maxFactorCount.Length; ++i)
            {
                int n = i + 2;
                for (int j = 0; j < maxFactorCount[i]; ++j)
                    result *= n;
            }

            Console.WriteLine($"The smallest multiple of {number} is {result}.");
        }
    }
}