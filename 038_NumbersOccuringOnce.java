// Coding Interviews: Questions, Analysis & Solutions
// Harry He


public class NumbersOccuringOnce {
    public class NumbersOccurringOnce {
        public int num1;
        public int num2;
    }
    
    public static void getOnce(int numbers[], NumbersOccurringOnce once){
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

        NumbersOccuringOnce numbersOnce = new NumbersOccuringOnce();
        NumbersOccurringOnce once = numbersOnce.new NumbersOccurringOnce();
        once.num1 = Integer.MIN_VALUE;
        once.num2 = Integer.MAX_VALUE;
        
        getOnce(numbers, once);
        
        if((once.num1 == expected.num1 && once.num2 == expected.num2) 
                || (once.num1 == expected.num2 && once.num2 == expected.num1))
            System.out.print("passed.\n");
        else
            System.out.print("FAILED.\n");
    }
    
    private static void test1() {
        int numbers[] = {2, 4, 3, 6, 3, 2, 5, 5};
        NumbersOccuringOnce numbersOnce = new NumbersOccuringOnce();
        NumbersOccurringOnce expected = numbersOnce.new NumbersOccurringOnce();
        expected.num1 = 4;
        expected.num2 = 6;
        
        test("test1", numbers, expected);
    }
    
    private static void test2() {
        int numbers[] = {4, 6};
        NumbersOccuringOnce numbersOnce = new NumbersOccuringOnce();
        NumbersOccurringOnce expected = numbersOnce.new NumbersOccurringOnce();
        expected.num1 = 4;
        expected.num2 = 6;
        
        test("test2", numbers, expected);
    }
    
    private static void test3() {
        int numbers[] = {4, 6, 1, 1, 1, 1};
        NumbersOccuringOnce numbersOnce = new NumbersOccuringOnce();
        NumbersOccurringOnce expected = numbersOnce.new NumbersOccurringOnce();
        expected.num1 = 4;
        expected.num2 = 6;
        
        test("test3", numbers, expected);
    }
    
    public static void main(String args[]) {
        test1();
        test2();
        test3();
    }
}
