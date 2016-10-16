// Coding Interviews: Questions, Analysis & Solutions
// Harry He

#include <stdio.h>
#include <string>

char FirstNotRepeatingChar(char* pString)
{
    if(pString == NULL)
        return '\0';

    const int tableSize = 256;
    unsigned int hashTable[tableSize];
    for(unsigned int i = 0; i<tableSize; ++ i)
        hashTable[i] = 0;

    char* pHashKey = pString;
    while(*(pHashKey) != '\0')
        hashTable[*(pHashKey++)] ++;

    pHashKey = pString;
    while(*pHashKey != '\0')
    {
        if(hashTable[*pHashKey] == 1)
            return *pHashKey;

        pHashKey++;
    }

    return '\0';
} 

// ==================== Test Code ====================
void Test(char* testName, char* pString, char expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);
    
    if(FirstNotRepeatingChar(pString) == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

int main(int argc, char* argv[])
{
    // There is a character appearing once
    Test("Test1", "google", 'l');

    // There is not a character appearing once
    Test("Test2", "aabccdbd", '\0');

    // All characters appear only once
    Test("Test3", "abcdefg", 'a');

    // NULL
    Test("Test4", NULL, '\0');
    
    // Empty string
    Test("Test5", "", '\0');

    return 0;
}
