using System;
using System.Collections.Generic;

namespace Kelly.Euler
{
    class Program
    {
        static void Main(string[] args)
        {
            var problems = new SortedDictionary<int, ProblemEngine>
            {
                [1] = new Problem0001(1000),
                [2] = new Problem0002(4_000_000),
                [3] = new Problem0003(600_851_475_143),
                [4] = new Problem0004(100, 1000)
            };

            try
            {
                while (true)
                {
                    Console.Write("Choose a problem:");

                    foreach (int problem in problems.Keys)
                        Console.Write(" " + problem);
                    
                    Console.WriteLine();

                    string input = Console.ReadLine();

                    if (!int.TryParse(input, out int choice))
                        break;
                    
                    if (!problems.TryGetValue(choice, out ProblemEngine engine))
                    {
                        Console.WriteLine("Invalid choice. Try again.");
                        continue;
                    }

                    Console.WriteLine(engine.TimeSolution());
                }
            }
            catch (Exception exception)
            {
                for (var e = exception; e != null; e = e.InnerException)
                {
                    Console.WriteLine(e.GetType());
                    Console.WriteLine(e.Message);
                    Console.WriteLine(e.StackTrace);
                }

                Console.WriteLine("PRESS ENTER TO EXIT");
                Console.ReadLine();
            }
        }
    }
}
