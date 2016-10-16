// Coding Interviews: Questions, Analysis & Solutions
// Harry He

#include <stdio.h>
#include <string.h>

void Reverse(char *pBegin, char *pEnd) 
{
    if(pBegin == NULL || pEnd == NULL)
        return;

    while(pBegin < pEnd) 
    {
        char temp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = temp;

        pBegin ++, pEnd --;
    }
}	

char* LeftRotateString(char* pStr, int n)
{
    if(pStr != NULL)
    {
        int nLength = static_cast<int>(strlen(pStr));
        if(nLength > 0 && n > 0 && n < nLength)
        {
            char* pFirstStart = pStr;
            char* pFirstEnd = pStr + n - 1;
            char* pSecondStart = pStr + n;
            char* pSecondEnd = pStr + nLength - 1;

            // Reverse the n leading characters
            Reverse(pFirstStart, pFirstEnd);
            // Reverse other characters
            Reverse(pSecondStart, pSecondEnd);
            // Reverse the whole string
            Reverse(pFirstStart, pSecondEnd);
        }
    }

    return pStr;
}

// ==================== Test Code ====================
void Test(char* testName, char* input, int num, char* expectedResult)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    char* result = LeftRotateString(input, num);

    if((input == NULL && expectedResult == NULL)
        || (input != NULL && strcmp(result, expectedResult) == 0))
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

void Test1()
{
    char input[] = "abcdefg";
    char expected[] = "cdefgab";

    Test("Test1", input, 2, expected);
}

void Test2()
{
    char input[] = "abcdefg";
    char expected[] = "bcdefga";

    Test("Test2", input, 1, expected);
}

void Test3()
{
    char input[] = "abcdefg";
    char expected[] = "gabcdef";

    Test("Test3", input, 6, expected);
}

void Test4()
{
    Test("Test4", NULL, 6, NULL);
}

void Test5()
{
    char input[] = "abcdefg";
    char expected[] = "abcdefg";

    Test("Test5", input, 0, expected);
}

void Test6()
{
    char input[] = "abcdefg";
    char expected[] = "abcdefg";

    Test("Test6", input, 7, expected);
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

