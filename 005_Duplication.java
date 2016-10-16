// Coding Interviews: Questions, Analysis & Solutions
// Harry He


public class Duplication {
    public static int duplicate(int numbers[]) {
        int length = numbers.length;
        
        int sum1 = 0;
        for(int i = 0; i < length; ++i) {
            if(numbers[i] < 0 || numbers[i] > length - 2)
                throw new IllegalArgumentException("Invalid numbers.");
            
            sum1 += numbers[i];
        }
        
        int sum2 = ((length - 1) * (length - 2)) >> 1;
        
        return sum1 - sum2;
    }
    
    //================= Test Code =================
    private static void test(String testName, int numbers[], int expected, boolean invalidArgument){
        System.out.print(testName + " begins: ");
        
        try {
            int duplication = duplicate(numbers);
            
            if(!invalidArgument && duplication == expected)
                System.out.print("Passed.\n");
            else
                System.out.print("FAILED.\n");
        }
        catch(IllegalArgumentException e){
            if(invalidArgument)
                System.out.print("Passed.\n");
            else
                System.out.print("FAILED.\n");
        }
    }
    
    private static void test1(){
        int numbers[] = {2, 1, 3, 1, 0};
        test("Test1", numbers, 1, false);
    }
    
    private static void test2(){
        int numbers[] = {2, 0, 3, 1, 0};
        test("Test2", numbers, 0, false);
    }
    
    private static void test3(){
        int numbers[] = {2, 0, 4, 3, 1, 4};
        test("Test3", numbers, 4, false);
    }
    
    private static void test4(){
        int numbers[] = {2, 1, 3, 0, 4};
        test("Test4", numbers, 0, true);
    }
    
    private static void test5(){
        int numbers[] = {2, 1, 3, 0, -1};
        test("Test5", numbers, 0, true);
    }
    
    private static void test6(){
        int numbers[] = {0};
        test("Test6", numbers, 0, true);
    }
    
    public static void main(String[] args) {
        test1();
        test2();
        test3();
        test4();
        test5();
        test6();
    }
}
