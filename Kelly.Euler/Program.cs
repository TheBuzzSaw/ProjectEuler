﻿using System;
using System.Collections.Generic;

namespace Kelly.Euler
{
    class Program
    {
        static void Main(string[] args)
        {
            var problems = new SortedDictionary<int, ProblemEngine>
            {
                [1] = new Problem0001(),
                [2] = new Problem0002(),
                [3] = new Problem0003(),
                [4] = new Problem0004(),
                [5] = new Problem0005(),
                [6] = new Problem0006(),
                [7] = new Problem0007(),
                [8] = new Problem0008(),
                [9] = new Problem0009(1000),
                [10] = new Problem0010(2_000_000),
                [11] = new Problem0011(4),
                [12] = new Problem0012(500),
                [13] = new Problem0013(10),
                [14] = new Problem0014(1_000_000),
                [15] = new Problem0015(),
                [27] = new Problem0027()
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

                    engine.Run();
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
