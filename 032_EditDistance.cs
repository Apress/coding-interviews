// Coding Interviews: Questions, Analysis & Solutions
// Harry He

using System;
using System.Collections.Generic;

namespace _032_EditDistance
{
    class Program
    {
        static int GetEditDistance(String str1, String str2)
        {
            int len1 = str1.Length; ;
            int len2 = str2.Length;

            int[,] distances = new int[len2 + 1, len1 + 1];

            int editDistance = GetEditDistance(str1, str2, distances, len1, len2);

            return editDistance;
        }

        static int GetEditDistance(String str1, String str2, int[,] distances, int len1, int len2)
        {
            for (int i = 0; i < len2 + 1; ++i)
                distances[i, 0] = i;
            for (int j = 0; j < len1 + 1; ++j)
                distances[0, j] = j;

            for (int i = 1; i < len2 + 1; ++i)
            {
                for (int j = 1; j < len1 + 1; ++j)
                {
                    if (str1[j - 1] == str2[i - 1])
                        distances[i, j] = distances[i - 1, j - 1];
                    else
                    {
                        int deletion = distances[i, j - 1] + 1;
                        int insertion = distances[i - 1, j] + 1;
                        int substitution = distances[i - 1, j - 1] + 1;
                        distances[i, j] = Min(deletion, insertion, substitution);
                    }
                }
            }

            return distances[len2, len1];
        }

        static int Min(int num1, int num2, int num3)
        {
            int less = (num1 < num2) ? num1 : num2;
            return (less < num3) ? less : num3;
        }

        // ================================ test code ================================
        static void Test(String testName, String str1, String str2, int expected)
        {
            Console.Write(testName + " begins: ");

            if (GetEditDistance(str1, str2) == expected)
                Console.Write("Passed.\n");
            else
                Console.Write("FAILED.\n");
        }

        static void Test1()
        {
            Test("Test1", "kitten", "kitten", 0);
        }

        static void Test2()
        {
            Test("Test2", "kitten", "sitting", 3);
        }

        static void Test3()
        {
            Test("Test3", "Saturday", "Sunday", 3);
        }

        static void Test4()
        {
            Test("Test4", "ant", "parent", 3);
        }

        static void Test5()
        {
            Test("Test5", "parent", "ant", 3);
        }

        static void Test6()
        {
            Test("Test6", "parent", "", 6);
        }

        static void Test7()
        {
            Test("Test7", "", "parent", 6);
        }

        static void Main(string[] args)
        {
            Test1();
            Test2();
            Test3();
            Test4();
            Test5();
            Test6();
            Test7();
        }
    }
}
