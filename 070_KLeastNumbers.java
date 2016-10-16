// Coding Interviews: Questions, Analysis & Solutions
// Harry He

import java.util.Arrays;
import java.util.Iterator;
import java.util.PriorityQueue;
import java.util.Random;
import java.util.Comparator;

public class KLeastNumbers {
    
    //================= Solution 1 =================
    public class ReversedComparator implements Comparator<Integer> {
        public int compare(Integer int1, Integer int2){
            int num1 = int1.intValue();
            int num2 = int2.intValue();
            
            if(num1 < num2)
                return 1;
            else if (num1 == num2)
                return 0;
            else
                return -1;
        }
    }

    public static void getLeastNumbers_1(int[] input, int[] output) {
        KLeastNumbers leastNumbers = new KLeastNumbers();
        ReversedComparator comparator = leastNumbers.new ReversedComparator();
        PriorityQueue<Integer> maxQueue = null;
        maxQueue = new PriorityQueue<Integer>(1, comparator);
        
        getLeastNumbers(input, maxQueue, output.length);
        
        Iterator<Integer> iter = maxQueue.iterator();
        for(int i = 0; i < output.length; ++i) {
            output[i] = iter.next();
        }
    }
    
    private static void getLeastNumbers(int[] input, PriorityQueue<Integer> output, int k) {
        output.clear();
        
        for(int i = 0; i < input.length; ++i) {
            if(output.size() < k) 
                output.add(new Integer(input[i]));
            else {
                Integer max = output.peek();
                Integer number = new Integer(input[i]);
                if(output.comparator().compare(number, max) > 0) {
                    output.poll();
                    output.add(number);
                }
            }
        }
    }

    //================= Solution 2 =================
    public static void getLeastNumbers_2(int[] input, int[] output) {
        int start = 0;
        int end = input.length - 1;
        int k = output.length;
        int index = partition(input, start, end);
        while(index != k - 1) {
            if(index > k - 1) {
                end = index - 1;
                index = partition(input, start, end);
            }
            else {
                start = index + 1;
                index = partition(input, start, end);
            }
        }
        
        for(int i = 0; i < k; ++i)
            output[i] = input[i];
    }
    
    private static int partition(int[] numbers, int start, int end) {
        int index = randomInRange(start, end);
        swap(numbers, index, end);
        
        int small = start - 1;
        for(index = start; index < end; ++index) {
            if(numbers[index] < numbers[end]){
                ++small;
                if(small != index)
                    swap(numbers, index, small);
            }
        }
        
        ++small;
        swap(numbers, small, end);
        
        return small;
    }
    
    private static int randomInRange(int start, int end){
        Random random = new Random();
        return random.nextInt(end - start + 1) + start;
    }
    
    private static void swap(int[] numbers, int index1, int index2){
        int temp = numbers[index1];
        numbers[index1] = numbers[index2];
        numbers[index2] = temp;
    }
    
    //================= Test Code =================
    
    private static boolean equals(int[] array1, int[] array2) {
        if(array1.length != array2.length)
            return false;
        
        Arrays.sort(array1);
        Arrays.sort(array2);
        
        int i = 0;
        for(; i < array1.length; ++i) {
            if(array1[i] != array2[i])
                break;
        }
        
        return (i == array1.length);
    }
    
    private static void test(String testName, int[] numbers, int[] expected) {
        System.out.print(testName + " begins: ");
        
        int[] output1 = new int[expected.length];
        getLeastNumbers_1(numbers, output1);
        if(equals(output1, expected))
            System.out.print("Solution1 Passed; ");
        else
            System.out.print("Solution1 FAILED; ");
        
        int[] output2 = new int[expected.length];
        getLeastNumbers_2(numbers, output2);
        if(equals(output2, expected))
            System.out.print("Solution2 Passed.\n");
        else
            System.out.print("Solution2 FAILED.\n");
    }
    
    private static void test1() {
        int[] numbers = {4, 5, 1, 6, 2, 7, 3, 8};
        int[] expected = {1, 2, 3, 4};

        test("Test1", numbers, expected);
    }
    
    private static void test2() {
        int[] numbers = {4, 5, 1, 6, 2, 7, 3, 8};
        int[] expected = {1, 2, 3, 4, 5, 6, 7, 8};

        test("Test2", numbers, expected);
    }
    
    private static void test3() {
        int[] numbers = {4, 5, 1, 6, 2, 7, 3, 8};
        int[] expected = {1};

        test("Test3", numbers, expected);
    }
    
    // duplicated numbers in the array
    private static void test4() {
        int[] numbers = {4, 5, 1, 6, 2, 7, 2, 8};
        int[] expected = {1, 2};

        test("Test4", numbers, expected);
    }
    
    public static void main(String[] argv) {
        test1();
        test2();
        test3();
        test4();
    }
}
