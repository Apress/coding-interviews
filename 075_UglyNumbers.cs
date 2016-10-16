// Coding Interviews: Questions, Analysis & Solutions
// Harry He

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _075_UglyNumbers
{
    class Program
    {
        // ================== Solution 1 ==================
        private static bool IsUgly(int number)
        {
            while (number % 2 == 0)
                number /= 2;
            while (number % 3 == 0)
                number /= 3;
            while (number % 5 == 0)
                number /= 5;

            return (number == 1) ? true : false;
        }

        public static int GetUglyNumber_Solution1(int index)
        {
            if (index <= 0)
                return 0;

            int number = 0;
            int uglyFound = 0;
            while (uglyFound < index)
            {
                ++number;

                if (IsUgly(number))
                {
                    ++uglyFound;
                }
            }

            return number;
        }

        // ================== Solution 2 ==================
        public static int GetUglyNumber_Solution2(int index)
        {
            if (index <= 0)
                return 0;

            int[] uglyNums = new int[index];
            uglyNums[0] = 1;
            int nextUglyIndex = 1;

            int index2 = 0;
            int index3 = 0;
            int index5 = 0;

            while (nextUglyIndex < index)
            {
                int min = Math.Min(uglyNums[index2] * 2, uglyNums[index3] * 3);
                min = Math.Min(min, uglyNums[index5] * 5);

                uglyNums[nextUglyIndex] = min;

                while (uglyNums[index2] * 2 <= uglyNums[nextUglyIndex])
                    ++index2;
                while (uglyNums[index3] * 3 <= uglyNums[nextUglyIndex])
                    ++index3;
                while (uglyNums[index5] * 5 <= uglyNums[nextUglyIndex])
                    ++index5;

                ++nextUglyIndex;
            }

            int ugly = uglyNums[nextUglyIndex - 1];
            return ugly;
        }

        // ==================== Test Code ====================
        static void Test(int index, int expected)
        {
            Console.WriteLine("Test for index " + index.ToString() + " begins: ");

            if (GetUglyNumber_Solution1(index) == expected)
                Console.Write("solution1 passed; ");
            else
                Console.Write("solution1 FAILD; ");

            if (GetUglyNumber_Solution2(index) == expected)
                Console.WriteLine("solution2 passed.");
            else
                Console.WriteLine("solution2 FAILED.");
        }


        static void Main(string[] args)
        {
            Test(1, 1);

            Test(2, 2);
            Test(3, 3);
            Test(4, 4);
            Test(5, 5);
            Test(6, 6);
            Test(7, 8);
            Test(8, 9);
            Test(9, 10);
            Test(10, 12);
            Test(11, 15);

            Test(1500, 859963392);

            Test(0, 0);
        }
    }
}
