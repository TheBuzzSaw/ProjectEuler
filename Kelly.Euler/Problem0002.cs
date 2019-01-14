using System;

namespace Kelly.Euler
{
    class Problem0002 : ProblemEngine
    {
        private readonly int _limit;

        public Problem0002(int limit)
        {
            _limit = limit;
        }

        public void SolveProblem()
        {
            int limit = _limit;
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

            Console.WriteLine("Total: " + sum);
        }
    }
}