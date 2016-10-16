// Coding Interviews: Questions, Analysis & Solutions
// Harry He

import java.util.Arrays;
import java.util.Comparator;

public class SortArrayForMinNumber {    
    public static void PrintMinNumber(int numbers[]) {
        String strNumbers[] = new String[numbers.length];
        for(int i = 0; i < numbers.length; ++i) {
            strNumbers[i] = String.valueOf(numbers[i]);
        }
     
        Arrays.sort(strNumbers, (new SortArrayForMinNumber()).new NumericComparator());
     
        for(int i = 0; i < numbers.length; ++i)
            System.out.print(strNumbers[i]);
        System.out.print("\n");
    }

    public class NumericComparator implements Comparator<String>{
        public int compare(String num1, String num2) {
            String str1 = num1 + num2;
            String str2 = num2 + num1;
            return str1.compareTo(str2);
        }
    }
    
     // ====================Test code====================
    private static void Test(String testName, int numbers[], String expectedResult)
    {
        System.out.println(testName + " begins:");

        System.out.println("Expected result is: \t" + expectedResult);

        System.out.print("Actual result is: \t");
        PrintMinNumber(numbers);

        System.out.print("\n");
    }

    private static void Test1() {
        int numbers[] = {3, 5, 1, 4, 2};
        Test("Test1", numbers, "12345");
    }

    private static void Test2() {
        int numbers[] = {3, 32, 321};
        Test("Test2", numbers, "321323");
    }

    private static void Test3() {
        int numbers[] = {3, 323, 32123};
        Test("Test3", numbers, "321233233");
    }

    private static void Test4() {
        int numbers[] = {1, 11, 111};
        Test("Test4", numbers, "111111");
    }

    // There is only one element in an array
    private static void Test5(){
        int numbers[] = {321};
        Test("Test5", numbers, "321");
    }
    
    public static void main(String[] args) {
        Test1();
        Test2();
        Test3();
        Test4();
        Test5();
    }
}
