// Coding Interviews: Questions, Analysis & Solutions
// Harry He

#include <stdio.h>

int bitsToModify(int number1, int number2)
{
    int temp = number1 ^ number2;
    
    // the number of 1 bits in temp
    int bits = 0;
    while(temp != 0) {
        ++bits;
        temp = (temp - 1) & temp;
    }
    
    return bits;
}

// ======== Test Code ========
void test(char* testName, int number1, int number2, int expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);
    
    if(bitsToModify(number1, number2) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

void test1()
{
    int number1 = 0;
    int number2 = 13;
    int expected = 3;
    
    test("Test1", number1, number2, expected);
}

void test2()
{
    int number1 = 0;
    int number2 = 15;
    int expected = 4;
    
    test("Test2", number1, number2, expected);
}

void test3()
{
    int number1 = 7;
    int number2 = 0;
    int expected = 3;
    
    test("Test3", number1, number2, expected);
}

void test4()
{
    int number1 = 7;
    int number2 = 7;
    int expected = 0;
    
    test("Test4", number1, number2, expected);
}


void test5()
{
    int number1 = 7;
    int number2 = 15;
    int expected = 1;
    
    test("Test5", number1, number2, expected);
}

int main(int argc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();
}