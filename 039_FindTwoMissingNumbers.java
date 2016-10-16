
// Coding Interviews: Questions, Analysis & Solutions
// Harry He

public class FindTwoMissingNumbers {
    public class NumbersOccurringOnce {
        public int num1;
        public int num2;
    }

    //================= Solution 1 =================
    public static void findMissing_solution1(int numbers[], NumbersOccurringOnce missing){
        int sum1 = 0;
        int product1 = 1;
        for(int i = 0; i < numbers.length; ++i){
            sum1 += numbers[i];
            product1 *= numbers[i];
        }
        
        int sum2 = 0;
        int product2 = 1;
        for(int i = 1; i <= numbers.length + 2; ++i){
            sum2 += i;
            product2 *= i;
        }
        
        int s = sum2 - sum1;
        int p = product2 / product1;
        
        missing.num1 = (s + (int)(Math.sqrt(s * s - 4 * p))) / 2;
        missing.num2 = s - missing.num1;
    }
    
    //================= Solution 2 =================
    public static void findMissing_solution2(int numbers[], NumbersOccurringOnce missing){
        int originalLength = numbers.length;
        int extendedLength = originalLength * 2 + 2;
        int extention[] = new int[extendedLength];
        for(int i = 0; i < originalLength; ++i)
            extention[i] = numbers[i];
        for(int i = originalLength; i < extendedLength; ++i)
            extention[i] = i - originalLength + 1;
        
        getOnce(extention, missing);
    }
    
    private static void getOnce(int numbers[], NumbersOccurringOnce once){
        if (numbers.length < 2)
            return;
     
        int resultExclusiveOR = 0;
        for (int i = 0; i < numbers.length; ++ i)
            resultExclusiveOR ^= numbers[i];
     
        int indexOf1 = findFirstBitIs1(resultExclusiveOR);    

        once.num1 = once.num2 = 0;
        for (int j = 0; j < numbers.length; ++ j) {
            if(isBit1(numbers[j], indexOf1))
                once.num1 ^= numbers[j];
            else
                once.num2 ^= numbers[j];
        }
    }
     
    // The first 1 bit from the rightmost
    private static int findFirstBitIs1(int num){
        int indexBit = 0;
        while (((num & 1) == 0) && (indexBit < 32)) {
            num = num >> 1;
            ++ indexBit;
        }
     
        return indexBit;
    }

    // check whether the bit with index indexBit is 1
    private static boolean isBit1(int num, int indexBit) {
        num = num >> indexBit;
        return (num & 1) == 1;
    }
    
    //================= Test Code =================
    private static void test(String testName, int[] numbers, NumbersOccurringOnce expected) {
        System.out.print(testName + " begins: ");

        FindTwoMissingNumbers missingNumbers = new FindTwoMissingNumbers();
        NumbersOccurringOnce missing = missingNumbers.new NumbersOccurringOnce();
        missing.num1 = Integer.MIN_VALUE;
        missing.num2 = Integer.MAX_VALUE;
        
        findMissing_solution1(numbers, missing);
        
        if((missing.num1 == expected.num1 && missing.num2 == expected.num2) 
                || (missing.num1 == expected.num2 && missing.num2 == expected.num1))
            System.out.print("Solution1 passed; ");
        else
            System.out.print("Solution1 FAILED; ");
        
        findMissing_solution2(numbers, missing);
        
        if((missing.num1 == expected.num1 && missing.num2 == expected.num2) 
                || (missing.num1 == expected.num2 && missing.num2 == expected.num1))
            System.out.print("Solution2 passed.\n");
        else
            System.out.print("Solution2 FAILED.\n");
    }
    
    private static void test1() {
        int numbers[] = {1, 3, 5, 6, 4, 7};
        FindTwoMissingNumbers missingNumbers = new FindTwoMissingNumbers();
        NumbersOccurringOnce expected = missingNumbers.new NumbersOccurringOnce();
        expected.num1 = 2;
        expected.num2 = 8;
        
        test("test1", numbers, expected);
    }
    
    private static void test2() {
        int numbers[] = {1};
        FindTwoMissingNumbers missingNumbers = new FindTwoMissingNumbers();
        NumbersOccurringOnce expected = missingNumbers.new NumbersOccurringOnce();
        expected.num1 = 2;
        expected.num2 = 3;
        
        test("test2", numbers, expected);
    }
    
    private static void test3() {
        int numbers[] = {3, 4};
        FindTwoMissingNumbers missingNumbers = new FindTwoMissingNumbers();
        NumbersOccurringOnce expected = missingNumbers.new NumbersOccurringOnce();
        expected.num1 = 1;
        expected.num2 = 2;
        
        test("test3", numbers, expected);
    }
    
    public static void main(String args[]) {
        test1();
        test2();
        test3();
    }
}
