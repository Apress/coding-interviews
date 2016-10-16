// Coding Interviews: Questions, Analysis & Solutions
// Harry He

#include <stdio.h>
#include <string.h>

void PermutationCore(char* pStr, char* pBegin);

void Permutation(char* pStr)
{
    if(pStr == NULL)
        return;

    PermutationCore(pStr, pStr);
}

void PermutationCore(char* pStr, char* pBegin)
{
    char *pCh = NULL;
    char temp;
    
    if(*pBegin == '\0')
    {
        printf("%s\n", pStr);
    }
    else
    {
        for(pCh = pBegin; *pCh != '\0'; ++ pCh)
        {
            temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;

            PermutationCore(pStr, pBegin + 1);

            temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;
        }
    }
}

// ==================== Test Code ====================
void Test(char* pStr)
{
    if(pStr == NULL)
        printf("Test for NULL begins:\n");
    else
        printf("Test for %s begins:\n", pStr);

    Permutation(pStr);

    printf("\n");
}

int main(int argc, char* argv[])
{
    char string1[64];
    char string2[64];
    char string3[64];
    char string4[64];

    Test(NULL);

    string1[0] = '\0';
    Test(string1);

    sprintf(string2, "%s", "a");
    Test(string2);

    sprintf(string3, "%s", "ab");
    Test(string3);

    sprintf(string4, "%s", "abc");
    Test(string4);

    return 0;
}

