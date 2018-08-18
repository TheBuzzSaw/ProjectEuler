using System;

namespace Kelly.Euler
{
    class Problem0001 : ProblemEngine
    {
        private readonly int _limit;

        public Problem0001(int limit)
        {
            _limit = limit;
        }

        public override void SolveProblem()
        {
            int limit = _limit;
            int sum = 0;

            for (int i = 3; i < limit; ++i)
            {
                if ((i % 3) == 0 || (i % 5) == 0)
                    sum += i;
            }

            Console.WriteLine("Total: " + sum);
        }
    }
}