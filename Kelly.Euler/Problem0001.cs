using System;

namespace Kelly.Euler
{
    class Problem0001 : ProblemEngine
    {
        public int SolveProblem(int limit = 1000)
        {
            int sum = 0;

            for (int i = 3; i < limit; ++i)
            {
                if ((i % 3) == 0 || (i % 5) == 0)
                    sum += i;
            }

            return sum;
        }
    }
}