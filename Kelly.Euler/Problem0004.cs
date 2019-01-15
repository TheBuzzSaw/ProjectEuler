using System;

namespace Kelly.Euler
{
    class Problem0004 : ProblemEngine
    {
        private static bool IsPalindrome32Stack(int n)
        {
            Span<byte> buffer = stackalloc byte[12];

            int i = 0;
            while (n > 0)
            {
                int tenth = n / 10;
                buffer[i++] = (byte)(n - tenth * 10);
                n = tenth;
            }

            int max = i / 2;
            for (int j = 0; j < max; ++j)
            {
                if (buffer[j] != buffer[i - 1 - j])
                    return false;
            }

            return true;
        }

        private static bool IsPalindrome32(int n)
        {
            var text = n.ToString();
            int max = text.Length / 2;
            for (int i = 0; i < max; ++i)
            {
                if (text[i] != text[text.Length - 1 - i])
                    return false;
            }

            return true;
        }

        public void SolveProblem(int digitCount = 3)
        {
            int a = 0;
            int b = 0;
            int c = 0;

            int min = 1;

            for (int i = 1; i < digitCount; ++i)
                min *= 10;

            int max = min * 10;
            for (int i = min; i < max; ++i)
            {
                for (int j = i; j < max; ++j)
                {
                    int product = i * j;
                    if (product > c && IsPalindrome32Stack(product))
                    {
                        a = i;
                        b = j;
                        c = product;
                    }
                }
            }

            Console.WriteLine($"{a} * {b} = {c}");
        }
    }
}