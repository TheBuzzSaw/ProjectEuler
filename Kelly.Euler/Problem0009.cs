using System;

namespace Kelly.Euler
{
    class Problem0009 : ProblemEngine
    {
        private readonly int _targetSum;

        public Problem0009(int targetSum)
        {
            _targetSum = targetSum;
        }

        public void SolveProblem()
        {
            int targetSum = _targetSum;
            int product = 0;

            for (int a = 1; product == 0 && a < targetSum; ++a)
            {
                int max = (targetSum - a) / 2 + a;

                for (int b = a + 1; product == 0 && b < max; ++b)
                {
                    int c = targetSum - b - a;
                    int left = a * a + b * b;
                    int right = c * c;

                    if (left == right)
                        product = a * b * c;
                }
            }

            Console.WriteLine($"abc == {product}");
        }
    }
}