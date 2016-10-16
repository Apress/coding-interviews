// Coding Interviews: Questions, Analysis & Solutions
// Harry He

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

// ==================== Solution 1 ====================
void GetIntersection_solution1(const vector<int>& array1, 
                     const vector<int>& array2, 
                     vector<int>& intersection)
{
    vector<int>::const_iterator iter1 = array1.begin();
    vector<int>::const_iterator iter2 = array2.begin();

    intersection.clear();

    while(iter1 != array1.end() && iter2 != array2.end())
    {
        if(*iter1 == *iter2)
        {
            intersection.push_back(*iter1);
            ++ iter1;
            ++ iter2;
        }
        else if(*iter1 < *iter2)
            ++ iter1;
        else
            ++ iter2;
    }
}

// ==================== Solution 2 ====================
/* === Supposing array1 is much longer than array2 === */
void GetIntersection_solution2(const vector<int>& array1, 
                     const vector<int>& array2, 
                     vector<int>& intersection)
{
    intersection.clear();
    
    vector<int>::const_iterator iter1 = array1.begin();
    while(iter1 != array1.end())
    {
        if(binary_search(array2.begin(), array2.end(), *iter1))
            intersection.push_back(*iter1);
    }
}

// ==================== Test Code ====================
bool CheckIdenticalArray(const vector<int>& array1, 
          const vector<int>& array2)
{
    vector<int>::const_iterator iter1 = array1.begin();
    vector<int>::const_iterator iter2 = array2.begin();

    bool identical = true;
    while(iter1 != array1.end() && iter2 != array2.end())
    {
        if(*iter1 != *iter2)
        {
            identical = false;
            break;
        }

        ++ iter1;
        ++ iter2;
    }

    if(iter1 != array1.end() || iter2 != array2.end())
        identical = false;

    return identical;
}    

void Test(char* testName, 
          const vector<int>& array1, 
          const vector<int>& array2, 
          vector<int>& expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    vector<int> result1;
    GetIntersection_solution1(array1, array2, result1);
    if(CheckIdenticalArray(result1, expected))
        printf("solution1 passed; ");
    else
        printf("solution1 FAILED; ");

    vector<int> result2;
    GetIntersection_solution1(array1, array2, result2);
    if(CheckIdenticalArray(result2, expected))
        printf("solution2 passed.\n");
    else
        printf("solution2 FAILED.\n");
}

void Test1()
{
    int numbers1[] = {1, 4, 7, 10, 13, 16};
    vector<int> array1(numbers1, numbers1 + sizeof(numbers1) / sizeof(int));

    int numbers2[] = {1, 3, 5, 7, 9, 11};
    vector<int> array2(numbers2, numbers2 + sizeof(numbers2) / sizeof(int));

    int exp[] = {1, 7};
    vector<int> expected(exp, exp + sizeof(exp) / sizeof(int));

    Test("Test1", array1, array2, expected);
}

void Test2()
{
    int numbers1[] = {4, 7, 10, 13};
    vector<int> array1(numbers1, numbers1 + sizeof(numbers1) / sizeof(int));

    int numbers2[] = {1, 3, 5, 7, 9, 11, 13};
    vector<int> array2(numbers2, numbers2 + sizeof(numbers2) / sizeof(int));

    int exp[] = {7, 13};
    vector<int> expected(exp, exp + sizeof(exp) / sizeof(int));

    Test("Test2", array1, array2, expected);
}

// no intersection
void Test3()
{
    int numbers1[] = {1, 3, 5, 7};
    vector<int> array1(numbers1, numbers1 + sizeof(numbers1) / sizeof(int));

    int numbers2[] = {2, 4, 6, 8};
    vector<int> array2(numbers2, numbers2 + sizeof(numbers2) / sizeof(int));

    vector<int> expected;

    Test("Test3", array1, array2, expected);
}

// one array only has one element
void Test4()
{
    int numbers1[] = {-2, 1, 4, 7};
    vector<int> array1(numbers1, numbers1 + sizeof(numbers1) / sizeof(int));

    vector<int> array2;
    array2.push_back(1);

    vector<int> expected;
    expected.push_back(1);

    Test("Test4", array1, array2, expected);
}

// one array is empty
void Test5()
{
    int numbers1[] = {-2, 1, 4, 7};
    vector<int> array1(numbers1, numbers1 + sizeof(numbers1) / sizeof(int));

    vector<int> array2;

    vector<int> expected;

    Test("Test5", array1, array2, expected);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

	return 0;
}
