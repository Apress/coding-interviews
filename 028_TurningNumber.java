// Coding Interviews: Questions, Analysis & Solutions
// Harry He

public class TurningNumber {
    public static int getTurningIndex(int numbers[]) {
        if(numbers.length <= 2)
            return -1;

        int left = 0;
        int right = numbers.length - 1;
        while(right > left + 1) {
            int middle = (left + right) / 2;
            if(middle == 0 || middle == numbers.length - 1)
                return -1;

            if(numbers[middle] > numbers[middle - 1]
                && numbers[middle] > numbers[middle + 1])
                return middle;
            else if(numbers[middle] > numbers[middle - 1]
                && numbers[middle] < numbers[middle + 1])
                left = middle;
            else
                right = middle;
        }

        return -1;
    }
    
    //================= Test Code =================
    private static void test(String testName, int[] numbers, int expected) {
        System.out.print(testName + " begins: ");

        if(getTurningIndex(numbers) == expected)
            System.out.print("passed.\n");
        else
            System.out.print("FAILED.\n");
    }

    private static void test1() {
        int numbers[] = {1, 2, 3, 4, 5, 10, 9, 8, 7, 6};
        int expected = 5;
        test("test1", numbers, expected);
    }

    private static void test2() {
        int numbers[] = {1, 10, 9, 8, 7, 6, 5, 4, 3, 2};
        int expected = 1;
        test("test2", numbers, expected);
    }

    private static void test3() {
        int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 10, 9};
        int expected = 8;
        test("test3", numbers, expected);
    }

    private static void test4() {
        int numbers[] = {1, 2, 1};
        int expected = 1;
        test("test4", numbers, expected);
    }
    
    public static void main(String args[]) {
        test1();
        test2();
        test3();
        test4();
    }
}
