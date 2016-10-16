// Coding Interviews: Questions, Analysis & Solutions
// Harry He

#include <stdio.h>
#include <string.h>

/*capacity is total capacity of a string, which is longer than its actual length*/
void ReplaceBlank(char string[], int capacity)
{
    int originalLength, numberOfBlank, newLength;
    int i, indexOfOriginal, indexOfNew;
    
    if(string == NULL || capacity <= 0)
        return;

    /*originalLength is the actual length of string*/ 
    originalLength = numberOfBlank = i = 0;
    while(string[i] != '\0')
    {
        ++ originalLength;

        if(string[i] == ' ')
            ++ numberOfBlank;

        ++ i;
    }

    /*newLength is the length of the replaced string*/
    newLength = originalLength + numberOfBlank * 2;
    if(newLength > capacity)
        return;

    indexOfOriginal = originalLength;
    indexOfNew = newLength;
    while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
    {
        if(string[indexOfOriginal] == ' ')
        {
            string[indexOfNew --] = '0';
            string[indexOfNew --] = '2';
            string[indexOfNew --] = '%';
        }
        else
        {
            string[indexOfNew --] = string[indexOfOriginal];
        }

        -- indexOfOriginal;
    }
}

void Test(char* testName, char string[], int length, char expected[])
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    ReplaceBlank(string, length);

    if(expected == NULL && string == NULL)
        printf("passed.\n");
    else if(expected == NULL && string != NULL)
        printf("failed.\n");
    else if(strcmp(string, expected) == 0)
        printf("passed.\n");
    else
        printf("failed.\n");
}

#define LENGTH 100

// A blank is inside a sentence
void Test1()
{
    char string[LENGTH] = "hello world";
    Test("Test1", string, LENGTH, "hello%20world");
}

// A blank is at the beginning of a sentence
void Test2()
{
    char string[LENGTH] = " helloworld";
    Test("Test2", string, LENGTH, "%20helloworld");
}

// A blank is at the end of a sentence
void Test3()
{
    char string[LENGTH] = "helloworld ";
    Test("Test3", string, LENGTH, "helloworld%20");
}

// Two adjcent blanks
void Test4()
{
    char string[LENGTH] = "hello  world";
    Test("Test4", string, LENGTH, "hello%20%20world");
}

// NULL
void Test5()
{
    Test("Test5", NULL, 0, NULL);
}

// Empty string
void Test6()
{
    char string[LENGTH] = "";
    Test("Test6", string, LENGTH, "");
}

// Input string only has a blank
void Test7()
{
    char string[LENGTH] = " ";
    Test("Test7", string, LENGTH, "%20");
}

// No blanks in the input
void Test8()
{
    char string[LENGTH] = "helloworld";
    Test("Test8", string, LENGTH, "helloworld");
}

// Input string only has blanks
void Test9()
{
    char string[LENGTH] = "   ";
    Test("Test9", string, LENGTH, "%20%20%20");
}

// Multiple blanks among words
void Test10()
{
    char string[LENGTH] = "Multiple blanks among words";
    Test("Test10", string, LENGTH, "Multiple%20blanks%20among%20words");
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    Test10();

    return 0;
}
