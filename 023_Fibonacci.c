// Coding Interviews: Questions, Analysis & Solutions
// Harry He

#include <stdio.h>

// ==================== Solution 1 ====================
long long Fibonacci_Solution1(unsigned int n)
{
    if(n <= 0)
        return 0;

    if(n == 1)
        return 1;

    return Fibonacci_Solution1(n - 1) + Fibonacci_Solution1(n - 2);
}

// ==================== Solution 2 ====================
long long Fibonacci_Solution2(unsigned int n)
{
    int result[2] = {0, 1};
    long long  fibNMinusOne = 1;
    long long  fibNMinusTwo = 0;
    long long  fibN = 0;
    unsigned int i;

    if(n < 2)
        return result[n];

    for(i = 2; i <= n; ++ i)
    {
        fibN = fibNMinusOne + fibNMinusTwo;

        fibNMinusTwo = fibNMinusOne;
        fibNMinusOne = fibN;
    }

     return fibN;
}

// ==================== Solution 3 ====================
#include <assert.h>

struct Matrix2By2
{
    long long m_00;
    long long m_01;
    long long m_10;
    long long m_11;
};

struct Matrix2By2 MatrixMultiply
(
    const struct Matrix2By2* matrix1, 
    const struct Matrix2By2* matrix2
)
{
    struct Matrix2By2 result;
    result.m_00 = matrix1->m_00 * matrix2->m_00 + matrix1->m_01 * matrix2->m_10;
    result.m_01 = matrix1->m_00 * matrix2->m_01 + matrix1->m_01 * matrix2->m_11;
    result.m_10 = matrix1->m_10 * matrix2->m_00 + matrix1->m_11 * matrix2->m_10;
    result.m_11 = matrix1->m_10 * matrix2->m_01 + matrix1->m_11 * matrix2->m_11;
    
    return result;
}

struct Matrix2By2 MatrixPower(unsigned int n)
{
    struct Matrix2By2 result;
    struct Matrix2By2 unit = {1, 1, 1, 0};

    assert(n > 0);
    if(n == 1)
    {
        result = unit;
    }
    else if(n % 2 == 0)
    {
        result = MatrixPower(n / 2);
        result = MatrixMultiply(&result, &result);
    }
    else if(n % 2 == 1)
    {
        result = MatrixPower((n - 1) / 2);
        result = MatrixMultiply(&result, &result);
        result = MatrixMultiply(&result, &unit);
    }

    return result;
}

long long Fibonacci_Solution3(unsigned int n)
{
    struct Matrix2By2 PowerNMinus2;
    int result[2] = {0, 1};
    
    if(n < 2)
        return result[n];

    PowerNMinus2 = MatrixPower(n - 1);
    return PowerNMinus2.m_00;
}

// ==================== Test Code ====================
void Test(int n, int expected)
{
    if(Fibonacci_Solution1(n) == expected)
        printf("Test for %d in solution1 passed.\n", n);
    else
        printf("Test for %d in solution1 failed.\n", n);

    if(Fibonacci_Solution2(n) == expected)
        printf("Test for %d in solution2 passed.\n", n);
    else
        printf("Test for %d in solution2 failed.\n", n);

    if(Fibonacci_Solution3(n) == expected)
        printf("Test for %d in solution3 passed.\n", n);
    else
        printf("Test for %d in solution3 failed.\n", n);
}

int main(int argc, char* argv[])
{
    Test(0, 0);
    Test(1, 1);
    Test(2, 1);
    Test(3, 2);
    Test(4, 3);
    Test(5, 5);
    Test(6, 8);
    Test(7, 13);
    Test(8, 21);
    Test(9, 34);
    Test(10, 55);

    Test(40, 102334155);

    return 0;
}
