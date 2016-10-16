// Coding Interviews: Questions, Analysis & Solutions
// Harry He

#include <stdio.h>
#include <math.h>
#include <cerrno>

bool Equal(double num1, double num2);
double PowerWithUnsignedExponent(double base, unsigned int exponent);
 
double Power(double base, int exponent)
{
    errno = 0;
 
    if(Equal(base, 0.0) && exponent < 0)
    {
        errno = EDOM;
        return 0.0;
    }
 
    unsigned int absExponent = (unsigned int)(exponent);
    if(exponent < 0)
        absExponent = (unsigned int)(-exponent);
 
    double result = PowerWithUnsignedExponent(base, absExponent);
    if(exponent < 0)
        result = 1.0 / result;
 
    return result;
}
 
/*
double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
    double result = 1.0;
    
    for(int i = 1; i <= exponent; ++i)
        result *= base;
 
    return result;
}
*/
double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
    if(exponent == 0)
        return 1;
    if(exponent == 1)
        return base;

    double result = PowerWithUnsignedExponent(base, exponent >> 1);
    result *= result;
    if((exponent & 0x1) == 1)
        result *= base;

    return result;
}

bool Equal(double num1, double num2)
{
    if((num1 - num2 > -0.0000001)
        && (num1 - num2 < 0.0000001))
        return true;
    else
        return false;
}

// ==================== Test Code ====================
void Test(char* testName, double base, int exponent, double expectedResult, int expectedFlag)
{
    if(testName != NULL)
        printf("%s begins: ", testName);
    
    double result = Power(base, exponent);
    if(abs(result - expectedResult) < 0.00000001 && errno == expectedFlag)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

int main(int argc, char* argv[])
{
    Test("Test1", 2, 3, 8, 0);

    Test("Test2", -2, 3, -8, 0);

    Test("Test3", 2, -3, 0.125, 0);

    Test("Test4", 2, 0, 1, 0);

    Test("Test5", 0, 0, 1, 0);

    Test("Test6", 0, 4, 0, 0);

    Test("Test7", 0, -4, 0, EDOM);

    return 0;
}
