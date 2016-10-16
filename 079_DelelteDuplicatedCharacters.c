// Coding Interviews: Questions, Analysis & Solutions
// Harry He

#include <stdio.h>
#include <string.h>

void DeletedDuplication(char* pString)
{
    int hashTable[256];
    char* pSlow = pString;
    char* pFast = pString;

    if(pString == NULL)
        return;

    memset(hashTable, 0, sizeof(hashTable));

    while (*pFast != '\0')
    {
        *pSlow = *pFast;
        
        if(hashTable[*pFast] == 0)
        {
            ++ pSlow;
            hashTable[*pFast] = 1;
        }
        
        ++pFast;
    }

    *pSlow = '\0';
}

// ==================== Test Code ====================
void Test(char* testName, char* pString, char* pExpected)
{
    if(NULL != testName)
        printf("%s begins: ", testName);

    DeletedDuplication(pString);
    if((pString == NULL && pExpected == NULL) || (0 == strcmp(pString, pExpected)))
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

void Test1()
{
    char pString[] = "google";
    char* pExpected = "gole";
    Test("Test1", pString, pExpected);
}

void Test2()
{
    char pString[] = "aaaaaaaaaaaaaaaaaaaaa";
    char* pExpected = "a";
    Test("Test2", pString, pExpected);
}

void Test3()
{
    char pString[] = "";
    char* pExpected = "";
    Test("Test3", pString, pExpected);
}

void Test4()
{
    char pString[] = "abcacbbacbcacabcba";
    char* pExpected = "abc";
    Test("Test4", pString, pExpected);
}

void Test5()
{
    char pString[] = "abcdefg";
    char* pExpected = "abcdefg";
    Test("Test5", pString, pExpected);
}

void Test6()
{
    char* pString = NULL;
    char* pExpected = NULL;
    Test("Test6", pString, pExpected);
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