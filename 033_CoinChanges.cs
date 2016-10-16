// Coding Interviews: Questions, Analysis & Solutions
// Harry He

using System;
using System.Collections.Generic;

namespace _033_CoinChanges
{
    class Program
    {
        public static int GetMinCount(int total, int[] coins)
        {
            int[] counts = new int[total + 1];
            counts[0] = 0;

            const int MAX = Int32.MaxValue;

            for (int i = 1; i <= total; ++i)
            {
                int count = MAX;
                for (int j = 0; j < coins.Length; ++j)
                {
                    if (i - coins[j] >= 0 && count > counts[i - coins[j]])
                        count = counts[i - coins[j]];
                }

                if (count < MAX)
                    counts[i] = count + 1;
                else
                    counts[i] = MAX;
            }

            return counts[total];
        }

        // ============================ test code ============================
        private static void Test(String testName, int total, int[] coins, int expected)
        {
            Console.Write(testName + " begins: ");

            if (GetMinCount(total, coins) == expected)
                Console.Write("Passed.\n");
            else
                Console.Write("FAILED.\n");
        }

        private static void Test1()
        {
            int[] coins = { 1, 5, 10, 20, 25 };
            int total = 40;
            int expected = 2;

            Test("test1", total, coins, expected);
        }

        private static void Test2()
        {
            int[] coins = { 1, 3, 9, 10 };
            int total = 15;
            int expected = 3;

            Test("test2", total, coins, expected);
        }

        private static void Test3()
        {
            int[] coins = { 1, 2, 5, 21, 25 };
            int total = 63;
            int expected = 3;

            Test("test3", total, coins, expected);
        }

        // Impossible to make changes
        private static void Test4()
        {
            int[] coins = { 2, 4, 8, 16 };
            int total = 63;
            int expected = Int32.MaxValue;

            Test("test4", total, coins, expected);
        }

        // Total value is in the array for coins
        private static void Test5()
        {
            int[] coins = { 1, 3, 9, 10 };
            int total = 9;
            int expected = 1;

            Test("test5", total, coins, expected);
        }

        static void Main(string[] args)
        {
            Test1();
            Test2();
            Test3();
            Test4();
            Test5();
        }
    }
}
