// Coding Interviews: Questions, Analysis & Solutions
// Harry He

import java.util.BitSet;


public class SubsetWithSum {
    public static boolean hasSubsetWithSum0(int numbers[]) {
        BitSet bits = new BitSet(numbers.length);
        while(increment(bits, numbers.length)) {
            int sum = 0;
            boolean oneBitAtLeast = false;
            for(int i = 0; i < numbers.length; ++i) {
                if(bits.get(i)) {
                    if(!oneBitAtLeast)
                        oneBitAtLeast = true;
                    
                    sum += numbers[i];
                }
            }
            
            if(oneBitAtLeast && sum == 0)
                return true;
        }
        
        return false;
    }
    
    private static boolean increment(BitSet bits, int length) {
        int index = length - 1;
        
        while(index >= 0 && bits.get(index)) {
            bits.clear(index);
            --index;
        }
        
        if(index < 0)
            return false;
        
        bits.set(index);
        return true;
    }

    // ==================== test code ====================
    private static void test(String testName, int numbers[], boolean expected) {
        System.out.print(testName + " Begins: ");
        
        if(hasSubsetWithSum0(numbers) == expected)
            System.out.println("Passed.");
        else
            System.out.println("FAILED.");
    }
    // The array has a zero
    private static void test1() {
        int numbers[] = {1, 2, 4, 0, 11, 15};
        test("test1", numbers, true);
    }
    
    // The array has two numbers whose sum is 0,
    private static void test2() {
        int numbers[] = {1, 2, -11, 7, 11, 15};
        test("test2", numbers, true);
    }
    
    // The array has three numbers whose sum is 0,
    private static void test3() {
        int numbers[] = {1, 2, -11, 7, 11, 15};
        test("test3", numbers, true);
    }
    
    // The array has four numbers whose sum is 0,
    private static void test4() {
        int numbers[] = {1, 2, -11, 7, 8, 15};
        test("test4", numbers, true);
    }
    
    // The array has five numbers whose sum is 0,
    private static void test5() {
        int numbers[] = {1, 2, -11, 4, 5, 15};
        test("test5", numbers, true);
    }
    
    // The array has six numbers whose sum is 0,
    private static void test6() {
        int numbers[] = {1, 3, 5, 4, 7, -20};
        test("test6", numbers, true);
    }
    
    // The array does not have a subset with sum is 0,
    private static void test7() {
        int numbers[] = {1, -3, 5, 4, 7, -20};
        test("test7", numbers, false);
    }
    
    public static void main(String[] args) {
        test1();
        test2();
        test3();
        test4();
        test5();
        test6();
        test7();
    }
}
