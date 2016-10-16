// Coding Interviews: Questions, Analysis & Solutions
// Harry He

using System;
using System.Collections.Generic;

namespace _034_MinimalPresses
{
    class Program
    {
        public static int MinKeyPress(int keys, int[] frequencies)
        {
            Array.Sort(frequencies);

            int letters = frequencies.Length;
            int presses = 0;

            // The last element has the highest frequency in 
            // an increasingly sorted array
            for (int i = letters - 1; i >= 0; --i)
            {
                int j = letters - 1 - i;
                presses += frequencies[i] * (j / keys + 1);
            }

            return presses;
        }

        // ============================ test code ============================
        private static void Test(String testName, int keys, int[] frequencies, int expected)
        {
            Console.Write(testName + " begins: ");

            if (MinKeyPress(keys, frequencies) == expected)
                Console.Write("Passed.\n");
            else
                Console.Write("FAILED.\n");
        }

        private static void Test1()
        {
            int keys = 9;
            int[] frequences = { 1, 1, 1, 100, 100, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 10, 11, 11, 11, 11, 1, 1, 1, 100 };
            int expected = 397;

            Test("Test1", keys, frequences, expected);
        }

        private static void Test2()
        {
            int keys = 2;
            int[] frequences = { 8, 2, 5, 2, 4, 9 };
            int expected = 47;

            Test("Test2", keys, frequences, expected);
        }

        static void Main(string[] args)
        {
            Test1();
            Test2();
        }
    }
}
