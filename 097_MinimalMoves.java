// Coding Interviews: Questions, Analysis & Solutions
// Harry He

public class MinimalMoves {
    // ==================== Solution 1 ====================
    public static int minMoveCount_solution1(int[] seq) {
        return seq.length - longestIncreasingLength_solution1(seq);
    }
    
    private static int longestIncreasingLength_solution1(int[] seq){
        int len = seq.length;
        int[] lookup = new int[len];
        
        for(int i = 0; i < len; ++i) {
            int longestSoFar = 0;
            for(int j= 0; j < i; ++j) {
                if(seq[i] > seq[j] && lookup[j] > longestSoFar)
                    longestSoFar = lookup[j];
            }
            lookup[i] = longestSoFar + 1;
        }
        
        int longestLength = 0;
        for(int i = 0; i < len; ++i) {
            if(lookup[i] > longestLength)
                longestLength = lookup[i];
        }
        
        return longestLength;
    }
    
    // ==================== Solution 2 ====================
    public static int minMoveCount_solution2(int[] seq) {
        return seq.length - longestIncreasingLength_solution2(seq);
    }
    
    private static int longestIncreasingLength_solution2(int[] seq){
        int len = seq.length;
        int[] lookup = new int[len];
        
        lookup[0] = seq[0];
        int longestLength = 1;
        for(int i = 1; i < len; ++i) {
            if(seq[i] > lookup[longestLength - 1]) {
                longestLength++;
                lookup[longestLength - 1] = seq[i];
            }
            else {
                int low = 0;
                int high = longestLength - 1;
                while(low != high) {
                    int mid = (low + high) / 2;
                    if(lookup[mid] < seq[i]) {
                        low = mid + 1;
                    }
                    else {
                        high = mid;
                    }
                }
                
                lookup[low] = seq[i];
            }
        }

        return longestLength;
    }
    
    // ==================== Test Code ====================
    private static void test(String testName, int cards[], int expected){
        System.out.print(testName + " begins: ");
        if(minMoveCount_solution1(cards) == expected)
            System.out.print("Passed; ");
        else
            System.out.print("FAILED; ");
        
        if(minMoveCount_solution2(cards) == expected)
            System.out.println("Passed.");
        else
            System.out.println("FAILED.");
    }
    
    private static void test1(){
        int cards[] = {2, 4, 1, 5, 6, 3};
        test("Test1", cards, 2);
    }
    
    private static void test2(){
        int cards[] = {1, 2, 5, 3, 4, 7, 6};
        test("Test2", cards, 2);
    }
    
    private static void test3(){
        int cards[] = {7, 2, 3, 1, 4, 5, 8, 9, 6};
        test("Test3", cards, 3);
    }
    
    private static void test4(){
        int cards[] = {8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7};
        test("Test4", cards, 10);
    }
    
    private static void test5(){
        int cards[] = {1, 2, 3, 4, 5, 6, 7};
        test("Test5", cards, 0);
    }
    
    private static void test6(){
        int cards[] = {7, 6, 5, 4, 3, 2, 1};
        test("Test6", cards, 6);
    }
    
    private static void test7(){
        int cards[] = {7};
        test("Test7", cards, 0);
    }
    
    public static void main(String[] args) {
        test1();
        test2();
        test3();
        test4();
        test5();
        test6();
        test7();
    }
}