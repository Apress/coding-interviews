// Coding Interviews: Questions, Analysis & Solutions
// Harry He

#include <stdio.h>

// ==================== Solution 1 ====================
int MaxDiffCore(int* start, int* end, int* max, int* min);

int MaxDiff_Solution1(int numbers[], unsigned length)
{
    if(numbers == NULL && length < 2)
        return 0;

    int max, min;
    return MaxDiffCore(numbers, numbers + length - 1, &max, &min);
}

int MaxDiffCore(int* start, int* end, int* max, int* min)
{
    if(end == start)
    {
        *max = *min = *start;
        return 0x80000000;
    }

    int* middle = start + (end - start) / 2;

    int maxLeft, minLeft;
    int leftDiff = MaxDiffCore(start, middle, &maxLeft, &minLeft);

    int maxRight, minRight;
    int rightDiff = MaxDiffCore(middle + 1, end, &maxRight, &minRight);

    int crossDiff = maxRight - minLeft;

    *max = (maxLeft > maxRight) ? maxLeft : maxRight;
    *min = (minLeft < minRight) ? minLeft : minRight;

    int maxDiff = (leftDiff > rightDiff) ? leftDiff : rightDiff;
    maxDiff = (maxDiff > crossDiff) ? maxDiff : crossDiff;
    return maxDiff;
}

// ==================== Solution 2 ====================
int MaxDiff_Solution2(int numbers[], unsigned length)
{
    if(numbers == NULL && length < 2)
        return 0;

    int min = numbers[0];
    int maxDiff =  numbers[1] - min;

    for(int i = 2; i < length; ++i)
    {
        if(numbers[i - 1] < min)
            min = numbers[i - 1];

        int currentDiff = numbers[i] - min;
        if(currentDiff > maxDiff)
            maxDiff = currentDiff;
    }

    return maxDiff;
}

// ==================== Test Code ====================
void Test(char* testName, int* numbers, unsigned int length, int expected)
{
    if(testName != NULL)
        printf("====%s begins: ==== \n", testName);

    if(MaxDiff_Solution1(numbers, length) == expected)
        printf("Solution 1 Passed.\n");
    else
        printf("Solution 1 FAILED.\n");

    if(MaxDiff_Solution2(numbers, length) == expected)
        printf("Solution 2 Passed.\n");
    else
        printf("Solution 2 FAILED.\n");
}

void Test1()
{
    int numbers[] = {4, 1, 3, 2, 5};
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), 4);
}

void Test2()
{
    int numbers[] = {1, 2, 4, 7, 11, 16};
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), 15);
}

void Test3()
{
    int numbers[] = {16, 11, 7, 4, 2, 1};
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), -1);
}

void Test4()
{
    int numbers[] = {9, 11, 5, 7, 16, 1, 4, 2};
    Test("Test4", numbers, sizeof(numbers) / sizeof(int), 11);
}

void Test5()
{
    int numbers[] = {2, 4};
    Test("Test5", numbers, sizeof(numbers) / sizeof(int), 2);
}

void Test6()
{
    int numbers[] = {4, 2};
    Test("Test6", numbers, sizeof(numbers) / sizeof(int), -2);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

	return 0;
}

