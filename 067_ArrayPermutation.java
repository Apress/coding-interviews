// Coding Interviews: Questions, Analysis & Solutions
// Harry He

import java.util.*;

public class ArrayPermutation {
    static public void permute(ArrayList<int[]> arrays){
        Stack<Integer> permutation = new Stack<Integer>();
        permuteCore(arrays, permutation);
    }
    
    static private void permuteCore(ArrayList<int[]> arrays, Stack<Integer> permutation){
        if(permutation.size() == arrays.size()){
            System.out.println(permutation);
            return;
        }
        
        int[] array = arrays.get(permutation.size());
        for(int i = 0; i < array.length; ++i){
            permutation.push(array[i]);
            permuteCore(arrays, permutation);
            permutation.pop();
        }
    }
    
    //================= Test Code =================
    static private void test(String testName, ArrayList<int[]> arrays){
        System.out.println(testName + " begins: ");
        
        permute(arrays);
    }
    
    static private void test1(){
        ArrayList<int[]> arrays = new ArrayList<int[]>();
        
        int[] array1 = {1, 2};
        int[] array2 = {3, 4};
        int[] array3 = {5, 6};
        
        arrays.add(array1);
        arrays.add(array2);
        arrays.add(array3);
        
        test("Test1", arrays);
    }
    
    static private void test2(){
        ArrayList<int[]> arrays = new ArrayList<int[]>();
        
        int[] array1 = {1, 2};
        int[] array2 = {3, 4, 5};
        int[] array3 = {6};
        
        arrays.add(array1);
        arrays.add(array2);
        arrays.add(array3);
        
        test("Test2", arrays);
    }
    
    static private void test3(){
        ArrayList<int[]> arrays = new ArrayList<int[]>();
        
        int[] array1 = {1, 2, 3};
        int[] array2 = {4, 5, 6};
        int[] array3 = {7, 8};
        
        arrays.add(array1);
        arrays.add(array2);
        arrays.add(array3);
        
        test("Test3", arrays);
    }
    
    static private void test4(){
        ArrayList<int[]> arrays = new ArrayList<int[]>();
        
        int[] array1 = {1, 2, 3, 4, 5};
        
        arrays.add(array1);
        
        test("Test4", arrays);
    }
    
    static private void test5(){
        ArrayList<int[]> arrays = new ArrayList<int[]>();
        
        int[] array1 = {6};
        int[] array2 = {7};
        int[] array3 = {8};
        int[] array4 = {9};
        
        arrays.add(array1);
        arrays.add(array2);
        arrays.add(array3);
        arrays.add(array4);
        
        test("Test4", arrays);
    }
    
    public static void main(String[] args) {
        test1();
        test2();
        test3();
        test4();
        test5();
    }
}
