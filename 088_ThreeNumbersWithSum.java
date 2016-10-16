// Coding Interviews: Questions, Analysis & Solutions
// Harry He

import java.util.Arrays;

public class ThreeNumbersWithSum {
    public static boolean hasTripleWithSum0(int numbers[]) {
        boolean found = false;
        if(numbers.length < 3)
            return found;

        Arrays.sort(numbers);

        for(int i = 0; i < numbers.length; ++i) {
            int sum = -numbers[i];
            found = hasPairWithSum(numbers, sum, i);

            if(found)
                break;
        }

        return found;
    }

    private static boolean hasPairWithSum(int numbers[], int sum, int excludeIndex) {
        boolean found = false;
    
        int ahead = numbers.length - 1;
        int behind = 0;
    
        while(ahead > behind) {
            if(ahead == excludeIndex)
                ahead--;
            if(behind == excludeIndex)
                behind++;
            
            int curSum = numbers[ahead] + numbers[behind];
        
            if(curSum == sum) {
                found = true;
                break;
            }
            else if(curSum > sum)
                ahead --;
            else
                behind ++;
        }
    
        return found;
    }
    
    //================= Test Code =================
    private static void test(String testName, int numbers[], boolean expected) {
        System.out.print(testName + " Begins: ");
        
        if(hasTripleWithSum0(numbers) == expected)
            System.out.println("Passed.");
        else
            System.out.println("FAILED.");
    }
    
    // The array has three numbers with the sum 0
    private static void test1() {
        int numbers[] = {1, 2, -4, 7, 11, 3};
        test("test1", numbers, true);
    }
    
    // The array does not have three numbers with the sum 0
    private static void test2() {
        int numbers[] = {1, 2, 4, 7, 11, 5};
        test("test2", numbers, false);
    }    
    
    // The array with three numbers,
    // and the sum of three numbers is 0
    private static void test3() {
        int numbers[] = {1, 2, -3};
        test("test3", numbers, true);
    }
    
    // The array with three numbers,
    // and the sum of three numbers is not 0
    private static void test4() {
        int numbers[] = {1, 2, 3};
        test("test4", numbers, false);
    }
    
    // The length of the array is less than 3,
    private static void test5() {
        int numbers[] = {1, 2};
        test("test5", numbers, false);
    }
    
    public static void main(String[] args) {
        test1();
        test2();
        test3();
        test4();
        test5();
    }
}
