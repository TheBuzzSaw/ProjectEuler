using System;

namespace Kelly.Euler
{
    class Problem0002 : ProblemEngine
    {
        public int SolveProblem(int limit = 4_000_000)
        {
            int sum = 0;
            int a = 0;
            int b = 1;

            while (b < limit)
            {
                if ((b & 1) == 0)
                    sum += b;

                int c = a + b;
                a = b;
                b = c;
            }

            return sum;
        }
    }
}