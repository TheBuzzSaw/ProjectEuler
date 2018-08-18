using System;

namespace Kelly.Euler
{
    class Problem0007 : ProblemEngine
    {
        private readonly int _primeOrdinal;

        public Problem0007(int primeOrdinal)
        {
            _primeOrdinal = primeOrdinal;
        }

        public override void SolveProblem()
        {
            var cache = new PrimeCache();
            long prime = cache.Prime(_primeOrdinal - 1);
            Console.WriteLine($"Prime #{_primeOrdinal} is {prime}.");
        }
    }
}