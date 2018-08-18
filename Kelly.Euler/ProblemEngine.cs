using System;

namespace Kelly.Euler
{
    abstract class ProblemEngine
    {
        public abstract void SolveProblem();

        public TimeSpan TimeSolution()
        {
            var stopwatch = System.Diagnostics.Stopwatch.StartNew();
            SolveProblem();
            return stopwatch.Elapsed;
        }
    }
}