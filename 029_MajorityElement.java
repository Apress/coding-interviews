// Coding Interviews: Questions, Analysis & Solutions
// Harry He

import java.util.Random;

public class MajorityElement {
    //================= Solution 1 =================
    public static int getMajority_1(int[] numbers){
        int length = numbers.length;
        int middle = length >> 1;
        int start = 0;
        int end = length - 1;
        
        int index = partition(numbers, start, end);
        while(index != middle){
            if(index > middle){
                end = index - 1;
                index = partition(numbers, start, end);
            }
            else{
                start = index + 1;
                index = partition(numbers, start, end);
            }
        }
        
        int result = numbers[middle];
        if(!checkMajorityExistence(numbers, result))
            throw new IllegalArgumentException("No majority exisits.");
        
        return result;
    }
    
    private static int partition(int[] numbers, int start, int end){
        int index = randomInRange(start, end);
        swap(numbers, index, end);
        
        int small = start - 1;
        for(index = start; index < end; ++index){
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
    
    //================= Solution 2 =================
    public static int getMajority_2(int[] numbers){
        int result = numbers[0];
        int times = 1;
        for(int i = 1; i < numbers.length; ++i){
            if(times == 0){
                result = numbers[i];
                times = 1;
            }
            else if(numbers[i] == result)
                times++;
            else
                times--;
        }
        
        if(!checkMajorityExistence(numbers, result))
            throw new IllegalArgumentException("No majority exisits.");
        
        return result;
    }
    
    //================= Common methods =================
    private static boolean checkMajorityExistence(int[] numbers, int number){
        int times = 0;
        for(int i = 0; i < numbers.length; ++i){
            if(numbers[i] == number)
                times++;
        }
        
        return (times * 2 > numbers.length);
    }
    
    //================= Test Code =================
    
    private static void test(String testName, int[] numbers, int expected, boolean invalidArgument){
        System.out.print(testName + " begins: ");
        
        try {
            int majority = getMajority_1(numbers);
            
            if(!invalidArgument && majority == expected)
                System.out.print("Solution1 Passed; ");
            else
                System.out.print("Solution1 FAILED; ");
        }
        catch(IllegalArgumentException e){
            if(invalidArgument)
                System.out.print("Solution1 Passed; ");
            else
                System.out.print("Solution1 FAILED; ");
        }
        
        try {
            int majority = getMajority_2(numbers);
            
            if(!invalidArgument && majority == expected)
                System.out.print("Solution2 Passed.\n");
            else
                System.out.print("Solution2 FAILED.\n");
        }
        catch(IllegalArgumentException e){
            if(invalidArgument)
                System.out.print("Solution2 Passed.\n");
            else
                System.out.print("Solution2 FAILED.\n");
        }
    }
    
    private static void test1(){
        int[] numbers = {1, 2, 3, 2, 2, 2, 5, 4, 2};
        test("Test1", numbers, 2, false); 
    }
    
    private static void test2(){
        int[] numbers = {1, 2, 3, 2, 4, 2, 5, 2, 3};
        test("test2", numbers, 0, true); 
    }
    
    private static void test3(){
        int[] numbers = {2, 2, 2, 2, 2, 1, 3, 4, 5};
        test("test3", numbers, 2, false); 
    }
    
    private static void test4(){
        int[] numbers = {1, 3, 4, 5, 2, 2, 2, 2, 2};
        test("test4", numbers, 2, false); 
    }
    
    private static void test5(){
        int[] numbers = {1};
        test("test4", numbers, 1, false); 
    }
   
    public static void main(String[] argv){
        test1();
        test2();
        test3();
        test4();
        test5();
    }
}
