// Coding Interviews: Questions, Analysis & Solutions
// Harry He

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ==================== Solution 1 ====================
int NumberOf1(unsigned int n);

int NumberOf1Between1AndN_Solution1(unsigned int n)
{
    int number = 0;
    unsigned int i;

    for(i = 0; i <= n; ++ i)
        number += NumberOf1(i);

    return number;
}

int NumberOf1(unsigned int n)
{
    int number = 0;
    while(n)
    {
        if(n % 10 == 1)
            number ++;

        n = n / 10;
    }

    return number;
}

// ==================== Solution 2 ====================
int NumberOf1InString(const char* strN);
int PowerBase10(unsigned int n);

int NumberOf1Between1AndN_Solution2(int n)
{
    char strN[50];

    if(n <= 0)
        return 0;

    sprintf(strN, "%d", n);
    return NumberOf1InString(strN);
}

int NumberOf1InString(const char* strN)
{
    int first, length;
    int numOtherDigits, numRecursive, numFirstDigit;
    
    if(!strN || *strN < '0' || *strN > '9' || *strN == '\0')
        return 0;

    first = *strN - '0';
    length = (unsigned int)(strlen(strN));

    if(length == 1 && first == 0)
        return 0;

    if(length == 1 && first > 0)
        return 1;

    // If strN is 21345, numFirstDigit is the number of digit 1 
    // in the most signification digit in numbers from 10000 to 19999
    numFirstDigit = 0;
    if(first > 1)
        numFirstDigit = PowerBase10(length - 1);
    else if(first == 1)
        numFirstDigit = atoi(strN + 1) + 1;

    // numOtherDigits is the number of digit 1 in digits except
    // the most significant digit in numbers from 01346 to 21345
    numOtherDigits = first * (length - 1) * PowerBase10(length - 2);
    // numRecursive is the number of digit 1 in numbers from 1 to 1345    
    numRecursive = NumberOf1InString(strN + 1);

    return numFirstDigit + numOtherDigits + numRecursive;
}

int PowerBase10(unsigned int n)
{
    int i, result = 1;
    for(i = 0; i < n; ++ i)
        result *= 10;

    return result;
}

// ==================== Test Code ====================
void Test(char* testName, int n, int expected)
{
    if(testName != NULL)
        printf("%s begins: \n", testName);
    
    if(NumberOf1Between1AndN_Solution1(n) == expected)
        printf("Solution1 passed.\n");
    else
        printf("Solution1 failed.\n"); 
    
    if(NumberOf1Between1AndN_Solution2(n) == expected)
        printf("Solution2 passed.\n");
    else
        printf("Solution2 failed.\n"); 

    printf("\n");
}

int main(int argc, char* argv[])
{
    Test("Test1", 1, 1);
    Test("Test2", 5, 1);
    Test("Test3", 10, 2);
    Test("Test4", 55, 16);
    Test("Test5", 99, 20);
    Test("Test6", 10000, 4001);
    Test("Test7", 21345, 18821);
    Test("Test8", 0, 0);

    return 0;
}

