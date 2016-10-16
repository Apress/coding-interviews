// Coding Interviews: Questions, Analysis & Solutions
// Harry He

public class GreatestSumOfSubarrays {
    public static int getGreatestSumOfSubArray(int[] numbers) {
        int curSum = 0;
        int greatestSum = Integer.MIN_VALUE;
        for(int i = 0; i < numbers.length; ++i) {
            if(curSum <= 0)
                curSum = numbers[i];
            else
                curSum += numbers[i];

            if(curSum > greatestSum)
                greatestSum = curSum;
        }

        return greatestSum;
    } 
    
    //================= Test Code =================
    
    private static void test(String testName, int[] numbers, int expected) {
        System.out.print(testName + " begins: ");

        if(getGreatestSumOfSubArray(numbers) == expected)
            System.out.print("passed.\n");
        else
            System.out.print("FAILED.\n");
    }
    
    private static void test1() {
        int[] numbers = {1, -2, 3, 10, -4, 7, 2, -5};
        int expected = 18;
        test("Test1", numbers, expected);
    }
    
    // all numbers are negative    
    private static void test2() {
        int[] numbers = {-2, -8, -1, -5, -9};
        int expected = -1;
        test("Test2", numbers, expected);
    }
    
    // all numbers are positive    
    private static void test3() {
        int[] numbers = {2, 8, 1, 5, 9};
        int expected = 25;
        test("Test3", numbers, expected);
    }
    
    // only one number    
    private static void test4() {
        int[] numbers = {2};
        int expected = 2;
        test("Test4", numbers, expected);
    }
    
    public static void main(String[] argv) {
        test1();
        test2();
        test3();
        test4();
    }
}
