// Coding Interviews: Questions, Analysis & Solutions
// Harry He

#include <stdio.h>

// Supposing there is enough memory at the end of array1,
// in order to accommodate numbers in array2
void merge(int* array1, int length1, int* array2, int length2) 
{
    int index1, index2, indexMerged;

    if(array1 == NULL || array2 == NULL)
        return;

    index1 = length1 - 1;
    index2 = length2 - 1;
    indexMerged = length1 + length2 - 1;
    
    while(index1 >= 0 && index2 >= 0) 
    {
        if(array1[index1] >= array2[index2])
            array1[indexMerged--] = array1[index1--];
        else
            array1[indexMerged--] = array2[index2--];
    }

    while(index2 >= 0)
        array1[indexMerged--] = array2[index2--];
}

// ==================== Test Code ====================

void Test(char* testName, int* array1, int length1, int* array2, int length2, int* expected)
{
    int i;
    
    if(testName != NULL)
        printf("%s begins: ", testName);

    merge(array1, length1, array2, length2);
    
    if(expected != NULL && array1 != NULL && array2 != NULL)
    {
        for(i = 0; i < length1 + length2; ++i)
        {
            if(array1[i] != expected[i])
                break;
        }
    }
    
    if((expected == NULL && (array1 == NULL || array2 == NULL)) || (i == length1 + length2))
        printf("passed.\n");
    else
        printf("FAILED.\n");    
}

// no duplicated numbers
void Test1()
{
    int array1[20] = {1, 3, 5, 7, 9};
    int array2[] = {2, 4, 6, 8, 10};
    
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    Test("Test1", array1, 5, array2, 5, expected);
}

// no duplicated numbers
void Test2()
{
    int array1[20] = {2, 4, 6, 8, 10};
    int array2[] = {1, 3, 5, 7, 9};
    
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    Test("Test2", array1, 5, array2, 5, expected);
}

// duplicated arrays
void Test3()
{
    int array1[20] = {2, 4, 6, 8, 10};
    int array2[] = {2, 4, 6, 8, 10};
    
    int expected[] = {2, 2, 4, 4, 6, 6, 8, 8, 10, 10};
    
    Test("Test3", array1, 5, array2, 5, expected);
}

// numbers in array1 are less than numbers in array2
void Test4()
{
    int array1[20] = {1, 2, 3, 4, 5};
    int array2[] = {6, 7, 8, 9, 10};
    
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    Test("Test4", array1, 5, array2, 5, expected);
}

// numbers in array1 are greater than numbers in array2
void Test5()
{
    int array1[20] = {6, 7, 8, 9, 10};
    int array2[] = {1, 2, 3, 4, 5};
    
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    Test("Test5", array1, 5, array2, 5, expected);
}

// numbers in array1 are greater than numbers in array2
void Test6()
{
    Test("Test6", NULL, 0, NULL, 0, NULL);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
}
