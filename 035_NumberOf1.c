// Coding Interviews: Questions, Analysis & Solutions
// Harry He

#include <stdio.h>

int NumberOf1_Solution1(int n)
{
    int count = 0;
    unsigned int flag = 1;
    while(flag)
    {
        if(n & flag)
            count ++;

        flag = flag << 1;
    }

    return count;
}

int NumberOf1_Solution2(int n)
{
    int count = 0;

    while (n)
    {
        ++ count;
        n = (n - 1) & n;
    }

    return count;
}

// ==================== Test Code ====================
void Test(int number, unsigned int expected)
{
    int actual = NumberOf1_Solution1(number);
    if(actual == expected)
        printf("Solution1: Test for %p passed.\n", number);
    else
        printf("Solution1: Test for %p failed.\n", number);

    actual = NumberOf1_Solution2(number);
    if(actual == expected)
        printf("Solution2: Test for %p passed.\n", number);
    else
        printf("Solution2: Test for %p failed.\n", number);

    printf("\n");
}

int main(int argc, char* argv[])
{
    // input 0, expected output is 0
    Test(0, 0);

    // input 1, expected output is 1
    Test(1, 1);

    // input 10, expected output is 2
    Test(10, 2);

    // input 0x7FFFFFFF, expected output is 31
    Test(0x7FFFFFFF, 31);

    // input 0xFFFFFFFF (negative), expected output is 32
    Test(0xFFFFFFFF, 32);

    // input 0x80000000 (negative), expected output is 1
    Test(0x80000000, 1);

    return 0;
}
