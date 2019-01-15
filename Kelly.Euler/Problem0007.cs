using System;

namespace Kelly.Euler
{
    class Problem0007 : ProblemEngine
    {
        public void SolveProblem(int primeOrdinal = 10_001)
        {
            var cache = new PrimeCache();
            long prime = cache.Prime(primeOrdinal - 1);
            Console.WriteLine($"Prime #{primeOrdinal} is {prime}.");
        }
    }
}