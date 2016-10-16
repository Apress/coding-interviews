// Coding Interviews: Questions, Analysis & Solutions
// Harry He

public class ArithmeticOperations {

    public static int add(int num1, int num2) {
        int sum, carry;
        do {
            sum = num1 ^ num2;
            carry = (num1 & num2) << 1;
            num1 = sum;
            num2 = carry;
        } while (num2 != 0);

        return num1;
    }

    public static int subtract(int num1, int num2) {
        num2 = add(~num2, 1);
        return add(num1, num2);
    }

    public static int multiply(int num1, int num2) {
        boolean minus = false;
        if ((num1 < 0 && num2 > 0) || (num1 > 0 && num2 < 0))
            minus = true;

        if (num1 < 0)
            num1 = add(~num1, 1);
        if (num2 < 0)
            num2 = add(~num2, 1);

        int result = 0;
        while (num1 > 0) {
            if ((num1 & 0x1) != 0) {
                result = add(result, num2);
            }

            num2 = num2 << 1;
            num1 = num1 >> 1;
        }

        if (minus)
            result = add(~result, 1);

        return result;
    }

    public static int divide(int num1, int num2) {
        if (num2 == 0)
            throw new ArithmeticException("num2 is zero.");

        boolean minus = false;
        if ((num1 < 0 && num2 > 0) || (num1 > 0 && num2 < 0))
            minus = true;

        if (num1 < 0)
            num1 = add(~num1, 1);
        if (num2 < 0)
            num2 = add(~num2, 1);

        int result = 0;
        for (int i = 0; i < 32; i=add(i, 1)) {
            result = result << 1;
            if ((num1 >> (31 - i)) >= num2) {
                num1 = subtract(num1, num2 << (31 - i));
                result = add(result, 1);
            }
        }

        if (minus)
            result = add(~result, 1);

        return result;
    }

    public static void test(String testName, int num1, int num2, int res1,
            int res2, int res3, int res4) {
        System.out.print(testName + " begins: ");

        if (add(num1, num2) == res1)
            System.out.print("add passed, ");
        else
            System.out.print("add FAILED, ");

        if (subtract(num1, num2) == res2)
            System.out.print("subtract passed, ");
        else
            System.out.print("subtract FAILED, ");

        if (multiply(num1, num2) == res3)
            System.out.print("multiply passed, ");
        else
            System.out.print("multiply FAILED, ");

        try {
            int result = divide(num1, num2);
            if (num2 != 0 && result == res4)
                System.out.print("divide passed.");
            else
                System.out.print("divide FAILED.");
        } catch (ArithmeticException e) {
            if (num2 == 0)
                System.out.print("divide passed.");
            else
                System.out.print("divide FAILED.");
        }

        System.out.print("\n");
    }

    public static void main(String[] args) {
        test("Test1", 3, 2, 5, 1, 6, 1);
        test("Test2", -3, 2, -1, -5, -6, -1);
        test("Test3", -3, -2, -5, -1, 6, 1);
        test("Test4", -3, 0, -3, -3, 0, 0);
        test("Test5", 100, -5, 95, 105, -500, -20);
        test("Test6", 98, 5, 103, 93, 490, 19);
        test("Test7", 6, 12, 18, -6, 72, 0);
    }
}
