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
                [1] = new Problem0001(1000)
            };

            try
            {
                Console.Write("Choose a problem:");

                foreach (int problem in problems.Keys)
                    Console.Write(" " + problem);
                
                Console.WriteLine();

                while (true)
                {
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
