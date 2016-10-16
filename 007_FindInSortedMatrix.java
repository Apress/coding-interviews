// Coding Interviews: Questions, Analysis & Solutions
// Harry He


public class FindInMatrix {

    public static boolean find(int matrix[][], int value){
        int rows = matrix.length;
        int cols = matrix[0].length;
        int start = 0;
        int end = rows * cols - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            int row = mid / cols;
            int col = mid % cols;
            int v = matrix[row][col];
            
            if (v == value) 
                return true;

            if (v > value)
                end = mid - 1;
            else
                start = mid + 1;
        }
        
        return false;
    }
    
    private static void test(String testName, int matrix[][], int value, boolean expected){
        System.out.print(testName + " begins: ");

        if(find(matrix, value) == expected)
            System.out.print("passed.\n");
        else
            System.out.print("FAILED.\n");
    }
    
    //  1   3   5
    //  7   9   11
    //  13  15  17
    // The value to be found, 7, is in the matrix;
    private static void test1(){
        int matrix[][] = {{1, 3, 5}, {7, 9, 11}, {13, 15, 17}};
        test("Test1", matrix, 7, true);
    }
    
    //  1   3   5
    //  7   9   11
    //  13  15  17
    // The value to be found, 1, is in the matrix;
    private static void test2(){
        int matrix[][] = {{1, 3, 5}, {7, 9, 11}, {13, 15, 17}};
        test("Test2", matrix, 1, true);
    }
    
    //  1   3   5
    //  7   9   11
    //  13  15  17
    // The value to be found, 17, is in the matrix;
    private static void test3(){
        int matrix[][] = {{1, 3, 5}, {7, 9, 11}, {13, 15, 17}};
        test("Test3", matrix, 17, true);
    }
    
    //  1   3   5
    //  7   9   11
    //  13  15  17
    // The value to be found, 6, is not in the matrix;
    private static void test4(){
        int matrix[][] = {{1, 3, 5}, {7, 9, 11}, {13, 15, 17}};
        test("Test4", matrix, 6, false);
    }
    
    //  1   3   5
    //  7   9   11
    //  13  15  17
    // The value to be found, 0, is not in the matrix;
    private static void test5(){
        int matrix[][] = {{1, 3, 5}, {7, 9, 11}, {13, 15, 17}};
        test("Test5", matrix, 0, false);
    }
    
    //  1   3   5
    //  7   9   11
    //  13  15  17
    // The value to be found, 18, is not in the matrix;
    private static void test6(){
        int matrix[][] = {{1, 3, 5}, {7, 9, 11}, {13, 15, 17}};
        test("Test6", matrix, 18, false);
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
