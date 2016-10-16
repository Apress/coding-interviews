// Coding Interviews: Questions, Analysis & Solutions
// Harry He

public class TwoNumbersWithSum {
    public static boolean hasPairWithSum(int numbers[], int sum) {
        boolean found = false;
    
        int ahead = numbers.length - 1;
        int behind = 0;
    
        while(ahead > behind) {
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
    private static void test(String testName, int numbers[], int sum, boolean expected) {
        System.out.print(testName + " Begins: ");
        
        if(hasPairWithSum(numbers, sum) == expected)
            System.out.println("Passed.");
        else
            System.out.println("FAILED.");
    }
    
    // The array has two numbers with the given sum,
    // and two numbers are inside the array
    private static void test1() {
        int numbers[] = {1, 2, 4, 7, 11, 15};
        test("test1", numbers, 15, true);
    }

    // The array has two numbers with the given sum,
    // and two numbers are the first and last elements
    private static void test2() {
        int numbers[] = {1, 2, 4, 7, 11, 16};
        test("test2", numbers, 17, true);
    }

    // The array does not have two numbers with the given sum
    private static void test3() {
        int numbers[] = {1, 2, 4, 7, 11, 16};
        test("test3", numbers, 10, false);
    }

    // There is only one number in the array
    private static void test4() {
        int numbers[] = {2};
        test("test4", numbers, 2, false);
    }
    
    public static void main(String[] args) {
        test1();
        test2();
        test3();
        test4();
    }

}
