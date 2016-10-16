// Coding Interviews: Questions, Analysis & Solutions
// Harry He

public class ContinousSequenceWithSum {
    public static void findContinuousSequence(int sum) {
        if(sum < 3)
            return;

        int small = 1; 
        int big = 2;
        int middle = (1 + sum) / 2;
        int curSum = small + big;

        while(small < middle) {
            if(curSum == sum)
                printContinuousSequence(small, big);

            while(curSum > sum && small < middle) {
                curSum -= small;
                ++small;

                if(curSum == sum)
                    printContinuousSequence(small, big);
            }

            ++big;
            curSum += big;
        }
    }
    
    private static void printContinuousSequence(int small, int big){
        for(int i = small; i <= big; ++i)
            System.out.print(String.valueOf(i) + " ");
        System.out.println("");
    }
    
    // ==================== test code ====================
    private static void test(String testName, int sum) {
        System.out.println(testName + " for " + String.valueOf(sum) + " begins: ");
        
        findContinuousSequence(sum);
    }
    
    public static void main(String[] args) {
        test("test1", 1);
        test("test2", 3);
        test("test3", 4);
        test("test4", 9);
        test("test5", 15);
        test("test6", 100);
    }
}
