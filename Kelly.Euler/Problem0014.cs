using System;
using System.Linq;

namespace Kelly.Euler
{
    class Problem0014 : ProblemEngine
    {
        private readonly int _limit;

        public static long NextCollatz64(long n)
        {
            return (n & 1) == 1 ? n * 3 + 1 : n / 2;
        }

        public static int CollatzLength(long n)
        {
            int count = 1;

            while (n != 1)
            {
                n = NextCollatz64(n);
                ++count;
            }

            return count;
        }

        public Problem0014(int limit)
        {
            _limit = limit;
        }

        public override void SolveProblem()
        {
            int limit = _limit;
            int longestStart = 0;
            int longestChain = 0;

            for (int i = 1; i < limit; ++i)
            {
                int length = CollatzLength(i);

                if (length > longestChain)
                {
                    longestChain = length;
                    longestStart = i;
                }
            }

            Console.WriteLine($"The longest chain starting under {limit} starts at {longestStart} and is {longestChain} long.");
        }
    }
}