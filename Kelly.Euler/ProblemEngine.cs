using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Reflection;

namespace Kelly.Euler
{
    abstract class ProblemEngine
    {
        private static readonly Dictionary<Type, Func<string, object>> _parserByType =
            new Dictionary<Type, Func<string, object>>
            {
                [typeof(sbyte)] = s => sbyte.Parse(s),
                [typeof(short)] = s => short.Parse(s),
                [typeof(int)] = s => int.Parse(s),
                [typeof(long)] = s => long.Parse(s),

                [typeof(BigInteger)] = s => BigInteger.Parse(s),

                [typeof(string)] = s => s
            };
        
        private readonly MethodInfo _solveProblemMethod;

        protected ProblemEngine()
        {
            _solveProblemMethod = GetType().GetMethods().Single(m => m.Name == "SolveProblem");
        }

        public void Run()
        {
            var parameters = _solveProblemMethod.GetParameters();
            var arguments = new object[parameters.Length];

            for (int i = 0; i < parameters.Length; ++i)
            {
                var parameter = parameters[i];
                var defaultValue = parameter.DefaultValue;

                if (DBNull.Value.Equals(defaultValue))
                {
                    if (parameter.ParameterType.IsValueType)
                        defaultValue = Activator.CreateInstance(parameter.ParameterType);
                    else
                        defaultValue = null;
                }

                Console.Write($"{parameter.Name} (default [{defaultValue}]): ");
                var input = Console.ReadLine();

                arguments[i] =
                    string.IsNullOrWhiteSpace(input) ?
                    defaultValue :
                    _parserByType[parameter.ParameterType](input);
            }

            var stopwatch = System.Diagnostics.Stopwatch.StartNew();
            var result = _solveProblemMethod.Invoke(this, arguments);
            var elapsed = stopwatch.Elapsed;
            Console.WriteLine($"result [{result}]");
            Console.WriteLine(elapsed);
        }
    }
}