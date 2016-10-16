// Coding Interviews: Questions, Analysis & Solutions
// Harry He

public class RemoveNumbers {
    public static int remove_solution1(int numbers[], int n) {
        int i = 0;
        for (int j = 0; j < numbers.length; j++) {
            if (numbers[j] != n) 
                numbers[i++] = numbers[j];
        }

        return i;
    }
    
    public static int remove_solution2(int numbers[], int n) {
        int p1 = 0;
        while(p1 < numbers.length && numbers[p1] != n)
            ++p1;

        int p2 = numbers.length - 1;
        while(p1 < p2){
            while(p1 < numbers.length && numbers[p1] != n)
                ++p1;
            while(p2 > 0 && numbers[p2] == n)
                --p2;

            if(p1 < p2){
                numbers[p1] = numbers[p2];
                numbers[p2] = n;
            }
        }

        return p1;        
    }
    
    //================= Test Code =================
    private static boolean checkRemoved(int numbers[], int n, int expected) {
        int i = 0;
        while(i < expected)
        {
            if(numbers[i] == n)
                break;
            
            ++i;
        }
        
        return (i == expected);
    }
    
    private static void test(String testName, int nums[], int n, int expected) {
        System.out.print(testName + " begins: ");
        
        int copy[] = new int[nums.length];
        for(int i = 0; i < nums.length; ++i)
            copy[i] = nums[i];
        
        int result1 = remove_solution1(nums, n);
        if((result1 == expected) && checkRemoved(nums, n, expected))
            System.out.print("Solution1 Passed; ");
        else
            System.out.print("Solution1 FAILED; ");
        
        int result2 = remove_solution2(copy, n);
        if((result2 == expected) && checkRemoved(copy, n, expected))
            System.out.print("Solution2 Passed.\n");
        else
            System.out.print("Solution2 FAILED.\n");
    }

    // multiple targets to be deleted
    private static void test1() {
        int numbers[] = {4, 3, 2, 1, 2, 3, 6};
        int n = 2;
        int expected = 5;

        test("Test1", numbers, n, expected);
    }

    // targets are the first and last elements
    private static void test2() {
        int numbers[] = {4, 3, 2, 1, 2, 3, 4};
        int n = 4;
        int expected = 5;

        test("Test2", numbers, n, expected);
    }

    // all elements are targets to be deleted
    private static void test3() {
        int numbers[] = {4, 4, 4, 4};
        int n = 4;
        int expected = 0;

        test("Test3", numbers, n, expected);
    }

    // no target to be deleted
    private static void test4() {
        int numbers[] = {4, 3, 2, 1, 2, 3, 6};
        int n = 5;
        int expected = 7;

        test("Test4", numbers, n, expected);
    }
    
    // the only number is the target
    private static void test5() {
        int numbers[] = {4};
        int n = 4;
        int expected = 0;

        test("Test5", numbers, n, expected);
    }
    
    // the only number is the target
    private static void test6() {
        int numbers[] = {4};
        int n = 5;
        int expected = 1;

        test("Test6", numbers, n, expected);
    }

    // all elements except one are targets to be deleted
    private static void test7() {
        int numbers[] = {4, 4, 3, 4};
        int n = 4;
        int expected = 1;

        test("Test7", numbers, n, expected);
    }
    
    public static void main(String args[]) {
        test1();
        test2();
        test3();
        test4();
        test5();
        test6();
        test7();
    }
}
