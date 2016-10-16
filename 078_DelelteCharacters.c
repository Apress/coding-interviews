// Coding Interviews: Questions, Analysis & Solutions
// Harry He

#include <stdio.h>
#include <string.h>

void DeleteCharacters(char* pString, char* pCharsToBeDeleted)
{
    int hashTable[256];
    const char* pTemp = pCharsToBeDeleted;
    char* pSlow = pString;
    char* pFast = pString;

    if(pString == NULL || pCharsToBeDeleted == NULL)
        return;

    memset(hashTable, 0, sizeof(hashTable));
    while (*pTemp != '\0')
    {
        hashTable[*pTemp] = 1;
        ++ pTemp;
    }

    while (*pFast != '\0')
    {
        if(hashTable[*pFast] != 1)
        {
            *pSlow = *pFast;
            ++ pSlow;
        }
        ++pFast;
    }

    *pSlow = '\0';
}

// ==================== Test Code ====================
void Test(char* testName, char* pString, char* pCharsToBeDeleted, char* pExpected)
{
    if(NULL != testName)
        printf("%s begins: ", testName);

    DeleteCharacters(pString, pCharsToBeDeleted);
    if((pString == NULL && pExpected == NULL) || (0 == strcmp(pString, pExpected)))
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

void Test1()
{
    char pString[] = "We are students";
    char* pCharsToBeDeleted = "aeiou";
    char* pExpected = "W r stdnts";
    Test("Test1", pString, pCharsToBeDeleted, pExpected);
}

void Test2()
{
    char pString[] = "We are students";
    char* pCharsToBeDeleted = "wxyz";
    char* pExpected = "We are students";
    Test("Test2", pString, pCharsToBeDeleted, pExpected);
}

void Test3()
{
    char pString[] = "8613761352066";
    char* pCharsToBeDeleted = "1234567890";
    char* pExpected = "";
    Test("Test3", pString, pCharsToBeDeleted, pExpected);
}

void Test4()
{
    char pString[] = "119911";
    char* pCharsToBeDeleted = "";
    char* pExpected = "119911";
    Test("Test4", pString, pCharsToBeDeleted, pExpected);
}

void Test5()
{
    char pString[] = "119911";
    char* pCharsToBeDeleted = "aeiou";
    char* pExpected = "119911";
    Test("Test5", pString, pCharsToBeDeleted, pExpected);
}

void Test6()
{
    char pString[] = "";
    char* pCharsToBeDeleted = "aeiou";
    char* pExpected = "";
    Test("Test6", pString, pCharsToBeDeleted, pExpected);
}

void Test7()
{
    char* pString = NULL;
    char* pCharsToBeDeleted = "aeiou";
    char* pExpected = NULL;
    Test("Test7", pString, pCharsToBeDeleted, pExpected);
}

void Test8()
{
    char pString[] = "abcdefg";
    char* pCharsToBeDeleted = NULL;
    char* pExpected = "abcdefg";
    Test("Test8", pString, pCharsToBeDeleted, pExpected);
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
}