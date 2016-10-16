// Coding Interviews: Questions, Analysis & Solutions
// Harry He

#include <stdio.h>
#include <memory>

void PrintNumber(char* number);
bool Increment(char* number, int length);
void Print1ToMaxOfNDigitsCore(char* number, int length, int index);

// ==================== Solution 1====================
void Print1ToMaxOfNDigits_1(int n)
{
    if(n <= 0)
        return;
 
    char *number = new char[n + 1];
    memset(number, '0', n);
    number[n] = '\0';
 
    while(!Increment(number, n))
    {
        PrintNumber(number);
    }
 
    delete []number;
}
 
bool Increment(char* number, int length)
{
    bool isOverflow = false;
    int carry = 0;
 
    for(int i = length - 1; i >= 0; i --)
    {
        int sum = number[i] - '0' + carry;
        if(i == length - 1)
            sum ++;
 
        if(sum >= 10)
        {
            if(i == 0)
                isOverflow = true;
            else
            {
                sum -= 10;
                carry = 1;
                number[i] = '0' + sum;
            }
        }
        else
        {
            number[i] = '0' + sum;
            break;
        }
    }
 
    return isOverflow;
}

// ==================== Solution 2 ====================
void Print1ToMaxOfNDigits_2(int n)
{
    if(n <= 0)
        return;
 
    char* number = new char[n + 1];
    number[n] = '\0';
    Print1ToMaxOfNDigitsCore(number, n, -1);
 
    delete[] number;
}
 
void Print1ToMaxOfNDigitsCore(char* number, int length, int index)
{
    if(index == length - 1)
    {
        PrintNumber(number);
        return;
    }
 
    for(int i = 0; i < 10; ++i)
    {
        number[index + 1] = i + '0';
        Print1ToMaxOfNDigitsCore(number, length, index + 1);
    }
}

// ==================== Common Function ====================
void PrintNumber(char* number)
{
    char* pChar = number;
    while(*pChar == '0')
        ++pChar;
 
    if(*pChar != '\0')
        printf("%s\t", pChar);
}

// ==================== Test Code ====================
void Test(int n)
{
    printf("Test for %d begins:\n", n);

    Print1ToMaxOfNDigits_1(n);
    printf("\n");
    
    Print1ToMaxOfNDigits_2(n);
    printf("\n");

    printf("Test for %d ends.\n", n);
}

int main(int argc, char* argv[])
{
    Test(1);
    Test(2);
    Test(3);
    Test(0);
    Test(-1);

    return 0;
}
