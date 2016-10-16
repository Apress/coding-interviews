// Coding Interviews: Questions, Analysis & Solutions
// Harry He

#include <stdio.h>
#include <math.h>

void PrintProbability(int number)
{
    if(number < 1)
        return;

    const int maxValue = 6;
    int* pProbabilities[2];
    pProbabilities[0] = new int[maxValue * number + 1];
    pProbabilities[1] = new int[maxValue * number + 1];
    for(int i = 0; i < maxValue * number + 1; ++i)
    {
        pProbabilities[0][i] = 0;
        pProbabilities[1][i] = 0;
    }
 
    int flag = 0;
    for (int i = 1; i <= maxValue; ++i) 
        pProbabilities[flag][i] = 1; 
    
    for (int k = 2; k <= number; ++k) 
    {
        for(int i = 0; i < k; ++i)
            pProbabilities[1 - flag][i] = 0;

        for (int i = k; i <= maxValue * k; ++i) 
        {
            pProbabilities[1 - flag][i] = 0;
            for(int j = 1; j <= i && j <= maxValue; ++j) 
                pProbabilities[1 - flag][i] += pProbabilities[flag][i - j];
        }
 
        flag = 1 - flag;
    }
 
    double total = pow((double)maxValue, number);
    for(int i = number; i <= maxValue * number; ++i)
    {
        double ratio = (double)pProbabilities[flag][i] / total;
        printf("%d: %e\n", i, ratio);
    }
 
    delete[] pProbabilities[0];
    delete[] pProbabilities[1];
}

// ==================== Test Code ====================
void Test(int n)
{
    printf("Test for %d begins:\n", n);

    PrintProbability(n);

    printf("\n");
}

int main(int argc, char* argv[])
{
    Test(1);
    Test(2);
    Test(3);
    Test(4);
    
    Test(11);

    Test(0);

    return 0;
}
