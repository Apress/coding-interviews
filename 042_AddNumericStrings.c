// Coding Interviews: Questions, Analysis & Solutions
// Harry He

#include <stdio.h>
#include <string.h>

int checkInvalidInput(char* num1, char* num2, char* sum);
void reverse(char* str);

/* It returns -1 if the input invalid, otherwise returns 0. */
int add(char* num1, char* num2, char* sum)
{
    int index1, index2, indexSum;
    int sumDigit, carry, digit1, digit2;
    
    if(checkInvalidInput(num1, num2, sum))
        return -1;
    
    reverse(num1);
    reverse(num2);
    
    index1 = index2 = indexSum = 0;
    carry = 0;
    while(num1[index1] != '\0' || num2[index2] != '\0')
    {
         digit1 = (num1[index1] == '\0') ? 0 : num1[index1] - '0';
         digit2 = (num2[index2] == '\0') ? 0 : num2[index2] - '0';
         
         sumDigit = digit1 + digit2 + carry;
         carry = (sumDigit >= 10) ? 1 : 0;
         sumDigit = (sumDigit >= 10) ? sumDigit - 10 : sumDigit;
         
         sum[indexSum++] = sumDigit + '0';
         
         if(num1[index1] != '\0')
            ++index1;
         if(num2[index2] != '\0')
            ++index2;
    }
    
    if(carry != 0)
        sum[indexSum++] = carry + '0';
    
    sum[indexSum] = '\0';    
    reverse(sum);
    
    return 0;
}

int checkInvalidInput(char* num1, char* num2, char* sum)
{
    int length1, length2, i;
    
    if(num1 == NULL || num2 == NULL || sum == NULL)
        return -1;
    
    length1 = strlen(num1);
    for(i = 0; i < length1; ++i)
    {
        if(num1[i] < '0' || num1[i] > '9')
            return -1;
    }
    
    length2 = strlen(num2);
    for(i = 0; i < length2; ++i)
    {
        if(num2[i] < '0' || num2[i] > '9')
            return -1;
    }
    
    return 0;
}

void reverse(char* str)
{
    int i, length;
    char temp;
    
    length = strlen(str);
    for(i = 0; i < length / 2; ++i)
    {
        temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}

// ==================== Test Code ====================
void test(char* testName, char* num1, char* num2, char* sum, char* expected, int valid)
{
    int result;
    
    if(testName != NULL)
        printf("%s begins: ", testName);

    result = add(num1, num2, sum);
    if((result == -1 && valid == -1) || (valid == 0 && strcmp(sum, expected) == 0))
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void test1()
{
    char num1[] = "999";
    char num2[] = "3";
    char sum[20];
    char* expected = "1002";
    test("Test1", num1, num2, sum, expected, 0);
}

void test2()
{
    char num1[] = "33";
    char num2[] = "9999";
    char sum[20];
    char* expected = "10032";
    test("Test2", num1, num2, sum, expected, 0);
}

void test3()
{
    char num1[] = "3333333";
    char num2[] = "222";
    char sum[20];
    char* expected = "3333555";
    test("Test3", num1, num2, sum, expected, 0);
}

void test4()
{
    char num1[] = "33abc33";
    char num2[] = "222";
    char sum[20];
    char* expected = "";
    test("Test4", num1, num2, sum, expected, -1);
}

void test5()
{
    test("Test5", NULL, NULL, NULL, NULL, -1);
}

void test6()
{
    char num1[] = "3333333344445555";
    char num2[] = "222222222222222";
    char sum[20];
    char* expected = "3555555566667777";
    test("Test6", num1, num2, sum, expected, 0);
}

int main(int argc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    
    return 0;
}
