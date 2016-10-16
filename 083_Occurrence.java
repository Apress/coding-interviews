// Coding Interviews: Questions, Analysis & Solutions
// Harry He

public class Occurrence {
    static public int countOccurrence(int[] numbers, int k) {
        int first = getFirst(numbers, 0, numbers.length - 1, k);
        int last = getLast(numbers, 0, numbers.length - 1, k);
        
        int occurrence = 0;
        if(first > -1 && last > -1)
            occurrence = last - first + 1;
        
        return occurrence;
    }
    
    // Get the index of the first k. It returns -1 if no k exists.
    static private int getFirst(int[] numbers, int start, int end, int k) {
        if(start > end)
            return -1;
        
        int middle = start + (end - start) / 2;
        if(numbers[middle] == k) {
            if((middle > 0 && numbers[middle - 1] != k)
                    || (middle == 0))
                return middle;
            
            end = middle - 1;
        }
        else if(numbers[middle] > k){
            end = middle - 1;
        }
        else {
            start = middle + 1;
        }
        
        return getFirst(numbers, start, end, k);
    }
    
    // Get the index of the last k. It returns -1 if no k exists.
    static private int getLast(int[] numbers, int start, int end, int k) {
        if(start > end)
            return -1;
        
        int middle = start + (end - start) / 2;
        if(numbers[middle] == k) {
            if((middle < numbers.length - 1 && numbers[middle + 1] != k)
                    || (middle == numbers.length - 1))
                return middle;
            
            start = middle + 1;
        }
        else if(numbers[middle] > k){
            end = middle - 1;
        }
        else {
            start = middle + 1;
        }
        
        return getLast(numbers, start, end, k);
    }
    
    //================= Test Code =================
    
    private static void test(String testName, int[] numbers, int k, int expected) {
        System.out.print(testName + " begins: ");

        if(countOccurrence(numbers, k) == expected)
            System.out.print("passed.\n");
        else
            System.out.print("FAILED.\n");
    }
    
    // target is in the array
    private static void test1()
    {
        int[] data = {1, 2, 3, 3, 3, 3, 4, 5};
        int k = 3;
        int expected = 4;
        test("Test1", data, k, expected);
    }

    // target is at the beginning of the array
    private static void test2()
    {
        int[] data = {3, 3, 3, 3, 4, 5};
        int k = 3;
        int expected = 4;
        test("Test2", data, k, expected);
    }
    
    // target is at the end of the array
    private static void test3()
    {
        int[] data = {1, 2, 3, 3, 3, 3};
        int k = 3;
        int expected = 4;
        test("Test2", data, k, expected);
    }   
    
    // target does not exist in the array
    private static void test4()
    {
        int[] data = {1, 3, 3, 3, 3, 4, 5};
        int k = 2;
        int expected = 0;
        test("Test4", data, k, expected);
    }
    
    // target is less than the first element in the array
    private static void test5()
    {
        int[] data = {1, 3, 3, 3, 3, 4, 5};
        int k = 0;
        int expected = 0;
        test("Test5", data, k, expected);
    }
    
    // target is greater than the first element in the array
    private static void test6()
    {
        int[] data = {1, 3, 3, 3, 3, 4, 5};
        int k = 6;
        int expected = 0;
        test("Test6", data, k, expected);
    }
    
    // all numbers are duplicated, and target is in the array
    private static void test7()
    {
        int[] data = {3, 3, 3, 3};
        int k = 3;
        int expected = 4;
        test("Test7", data, k, expected);
    }
    
    // all numbers are duplicated, and target is not in the array
    private static void test8()
    {
        int[] data = {3, 3, 3, 3};
        int k = 4;
        int expected = 0;
        test("Test8", data, k, expected);
    }
    
    // only one number exists in the array, and target is in the array
    private static void test9()
    {
        int[] data = {3};
        int k = 3;
        int expected = 1;
        test("Test9", data, k, expected);
    }
        
    // only one number exists in the array, and target is not in the array
    private static void test10()
    {
        int[] data = {3};
        int k = 4;
        int expected = 0;
        test("Test10", data, k, expected);
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
        test9();
        test10();
    }
}
