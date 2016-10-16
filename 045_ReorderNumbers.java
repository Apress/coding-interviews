// Coding Interviews: Questions, Analysis & Solutions
// Harry He

public class ReorderNumbers {
    //================= Solution 1 =================
   public static void reorderOddEven_solution1(int nums[]) {
        int begin = 0;
        int end = nums.length - 1;
        while(begin < end) {
            // Move begin forwards until it meets an even number
            while(begin < end && (nums[begin] & 0x1) != 0)
                begin++;
            
            // Move end backwards until it meets an odd number
            while(begin < end && (nums[end] & 0x1) == 0)
                end--;
            
            if(begin < end) {
                int temp = nums[begin];
                nums[begin] = nums[end];
                nums[end] = temp;
            }
        }
    }
    
   //================= Solution 2 =================
    public static void reorderOddEven_solution2(int nums[]) {
        Criterion isEven = new Criterion() {
            public boolean check(int num) {
                if((num & 0x1) == 0)
                    return true;
               
                return false;
            }
        };
       
        reorder(nums, isEven);
    }
   
    public interface Criterion{
        boolean check(int num);
    }

    private static void reorder(int nums[], Criterion criterion) {
        int begin = 0;
        int end = nums.length - 1;
        while(begin < end) {
            while(begin < end && !criterion.check(nums[begin]))
                begin++;
            
            while(begin < end && criterion.check(nums[end]))
                end--;
            
            if(begin < end) {
                int temp = nums[begin];
                nums[begin] = nums[end];
                nums[end] = temp;
            }
        }
    }
    
    //================= Test Code =================
    private static void test(String testName, int nums[]) {
        System.out.print(testName + " begins: ");
        
        int copy[] = new int[nums.length];
        for(int i = 0; i < nums.length; ++i)
            copy[i] = nums[i];
        
        reorderOddEven_solution1(nums);
        if(checkOddBeforeEven(nums))
            System.out.print("Solution1 Passed; ");
        else
            System.out.print("Solution1 FAILED; ");
        
        reorderOddEven_solution2(copy);
        if(checkOddBeforeEven(copy))
            System.out.print("Solution2 Passed.\n");
        else
            System.out.print("Solution2 FAILED.\n");
    }
    
    private static boolean checkOddBeforeEven(int nums[]) {
        int i = 0;
        while(i < nums.length) {
            if((nums[i] & 0x01) == 0)
                break;
            
            ++i;
        }
        
        while(i < nums.length) {
            if((nums[i] & 0x01) == 1)
                break;
            
            ++i;
        }
        
        return (i == nums.length);
    }
    
    private static void test1() {
        int nums[] = {1, 2, 3, 4, 5, 6, 7};
        test("Test1", nums);
    }
    
    private static void test2() {
        int nums[] = {2, 4, 6, 1, 3, 5, 7};
        test("Test2", nums);
    }
    
    private static void test3() {
        int nums[] = {1, 3, 5, 7, 2, 4, 6};
        test("Test3", nums);
    }
    
    private static void test4() {
        int nums[] = {1};
        test("Test4", nums);
    }
    
    private static void test5() {
        int nums[] = {2};
        test("Test5", nums);
    }
    
    public static void main(String args[]) {
        test1();
        test2();
        test3();
        test4();
        test5();
    }
}
