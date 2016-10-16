// Coding Interviews: Questions, Analysis & Solutions
// Harry He

public class Minimum {
    public static int getMin(int numbers[]) {
        int index1 = 0;
        int index2 = numbers.length - 1;
        int indexMid = index1;
        
        while(numbers[index1] >= numbers[index2]) {
            if(index2 - index1 == 1) {
                indexMid = index2;
                break;
            }
            
            indexMid = (index1 + index2) / 2;
            
            // if numbers with indexes index1, index2, indexMid
            // are equal, search sequentially
            if(numbers[index1] == numbers[index2]
                    && numbers[indexMid] == numbers[index1])
                return getMinSequentially(numbers, index1, index2);
            
            if(numbers[indexMid] >= numbers[index1])
                index1 = indexMid;
            else if(numbers[indexMid] <= numbers[index2])
                index2 = indexMid;
        
        }
        
        return numbers[indexMid];
    }
    
    private static int getMinSequentially(int numbers[], int index1, int index2) {
        int result = numbers[index1];
        for(int i = index1 + 1; i <= index2; ++i) {
            if(result > numbers[i])
            result = numbers[i];
        }
        
        return result;
    }
    
    
    //================= Test Code =================
    private static void test(String testName, int[] numbers, int expected) {
        System.out.print(testName + " begins: ");

        if(getMin(numbers) == expected)
            System.out.print("passed.\n");
        else
            System.out.print("FAILED.\n");
    }

    public static void main(String argv[]) {
        // typical input, a rotation of a increasingly sorted array
        int array1[] = {3, 4, 5, 1, 2};
        test("Test1", array1, 1);

        // duplicated number is the minimal
        int array2[] = {3, 4, 5, 1, 1, 2};
        test("Test2", array2, 1);

        // duplicated number is not in both beginning and end
        int array3[] = {3, 4, 5, 1, 2, 2};
        test("Test3", array3, 1);

        // duplicated number is in both beginning and end
        int array4[] = {1, 0, 1, 1, 1};
        test("Test4", array4, 0);

        // rotate 0 numbers in an array
        int array5[] = {1, 2, 3, 4, 5};
        test("Test5", array5, 1);

        // only one number in an array
        int array6[] = {2};
        test("Test6", array6, 2);
    }
}
