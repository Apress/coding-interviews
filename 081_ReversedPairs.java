// Coding Interviews: Questions, Analysis & Solutions
// Harry He

public class ReversedPairs {
    public static int countReversedPairs(int[] numbers) {
        int[] buffer = new int[numbers.length];
        return countReversedPairs(numbers, buffer, 0, numbers.length - 1);
    }
    
    private static int countReversedPairs(int[] numbers, int[] buffer, int start, int end) {
        if(start >= end)
            return 0;
        
        int middle = start + (end - start) / 2;
        
        int left = countReversedPairs(numbers, buffer, start, middle);
        int right = countReversedPairs(numbers, buffer, middle + 1, end);
        int between = merge(numbers, buffer, start, middle, end);
        
        return left + right + between; 
    }
    
    private static int merge(int[] numbers, int[] buffer, int start, int middle, int end) {
        int i = middle; // the end of the first sub-array
        int j = end;    // the end of the second sub-array
        int k = end;    // the end of the merged array
        int count = 0;
        while(i >= start && j >= middle + 1) {
            if(numbers[i] > numbers[j]) {
                buffer[k--] = numbers[i--];
                count += (j - middle);
            }
            else {
                buffer[k--] = numbers[j--];
            }   
        }
        
        while(i >= start) {
            buffer[k--] = numbers[i--];
        }
        
        while(j >= middle + 1) {
            buffer[k--] = numbers[j--];
        }
        
        // copy elements from buffer[] to numbers[]
        for(i = start; i <= end; ++i) {
            numbers[i] = buffer[i];
        }
        
        return count;       
    }

    //================= Test Code =================
    
    private static void test(String testName, int[] numbers, int expected) {
        System.out.print(testName + " begins: ");

        if(countReversedPairs(numbers) == expected)
            System.out.print("passed.\n");
        else
            System.out.print("FAILED.\n");
    }
    
    private static void test1() {
        int[] numbers = {1, 2, 3, 4, 7, 6, 5};
        int expected = 3;
        test("Test1", numbers, expected);
    }
    
    // decreasingly sorted array
    private static void test2() {
        int[] numbers = {6, 5, 4, 3, 2, 1};
        int expected = 15;
        test("Test2", numbers, expected);
    }
    
    // increasingly sorted array
    private static void test3() {
        int[] numbers = {1, 2, 3, 4, 5, 6};
        int expected = 0;
        test("Test3", numbers, expected);
    }
    
    // only one number
    private static void test4() {
        int[] numbers = {1};
        int expected = 0;
        test("Test4", numbers, expected);
    }
    
    // two numbers
    private static void test5() {
        int[] numbers = {1, 2};
        int expected = 0;
        test("Test5", numbers, expected);
    }
    
    // two numbers
    private static void test6() {
        int[] numbers = {2, 1};
        int expected = 1;
        test("Test5", numbers, expected);
    }
    
    // duplicated numbers
    private static void test7() {
        int[] numbers = {1, 2, 1, 2, 1};
        int expected = 3;
        test("Test7", numbers, expected);
    }
    
    // duplicated numbers
    private static void test8() {
        int[] numbers = {7, 5, 4, 5, 3, 5, 6, 5};
        int expected = 12;
        test("Test8", numbers, expected);
    }
    
    public static void main(String[] argv) {
        test1();
        test2();
        test3();
        test4();
        test5();
        test6();
        test7();
        test8();
    }
}
