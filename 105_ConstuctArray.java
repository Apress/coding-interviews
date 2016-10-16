// Coding Interviews: Questions, Analysis & Solutions
// Harry He

public class ConstuctArray {
    public static void multiply(double array1[], double array2[]){
        if(array1.length == array2.length && array1.length > 0){
            array2[0] = 1;
            for(int i = 1; i < array1.length; ++i){
                array2[i] = array2[i - 1] * array1[i - 1];
            }
            
            int temp = 1;
            for(int i = array1.length - 2; i >= 0; --i){
                temp *= array1[i + 1];
                array2[i] *= temp;
            }
        }
    }
    
    //================= Test Code =================
    private static boolean equalArrays(double array1[], double array2[]){
        if(array1.length != array2.length)
            return false;
        
        for(int i = 0; i < array1.length; ++i){
            if(abs(array1[i] - array2[i]) > 0.0000001)
                return false;
        }
        
        return true;
    }
    
    private static double abs(double d) {
        return (d > 0) ? d : -d;
    }

    private static void test(String testName, double array1[], double array2[], double expected[]){
        System.out.print(testName + " Begins: ");
        
        multiply(array1, array2);
        if(equalArrays(array2, expected))
            System.out.println("Passed.");
        else
            System.out.println("FAILED.");
    }
    
    private static void test1(){
        double array1[] = {1, 2, 3, 4, 5};
        double array2[] = new double[5];
        double expected[] = {120, 60, 40, 30, 24};
        
        test("Test1", array1, array2, expected);
    }
    
    private static void test2(){
        double array1[] = {1, 2, 0, 4, 5};
        double array2[] = new double[5];
        double expected[] = {0, 0, 40, 0, 0};
        
        test("Test2", array1, array2, expected);
    }
    
    private static void test3(){
        double array1[] = {1, 2, 0, 4, 0};
        double array2[] = new double[5];
        double expected[] = {0, 0, 0, 0, 0};
        
        test("Test3", array1, array2, expected);
    }
    
    private static void test4(){
        double array1[] = {1, -2, 3, -4, 5};
        double array2[] = new double[5];
        double expected[] = {120, -60, 40, -30, 24};
        
        test("Test4", array1, array2, expected);
    }
    
    public static void main(String[] args){
        test1();
        test2();
        test3();
        test4();
    }
}
