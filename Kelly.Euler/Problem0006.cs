using System;

namespace Kelly.Euler
{
    class Problem0006 : ProblemEngine
    {
        public void SolveProblem(int naturalNumberCount = 100)
        {
            int sum = 0;
            int squareSum = 0;

            for (int i = 1; i <= naturalNumberCount; ++i)
            {
                sum += i;
                squareSum += i * i;
            }

            int difference = sum * sum - squareSum;

            Console.WriteLine($"The difference is {difference}.");
        }
    }
}