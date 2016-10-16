// Coding Interviews: Questions, Analysis & Solutions
// Harry He

import java.util.HashMap;
import java.util.Map;


public class Anagram {
    public static boolean areAnagrams(String str1, String str2){
        if(str1.length() != str2.length())
            return false;
        
        Map<Character, Integer> times = new HashMap<Character, Integer>();
        for(int i = 0; i < str1.length(); ++i){
            Character ch = str1.charAt(i);
            if(times.containsKey(ch))
                times.put(ch, times.get(ch) + 1);
            else
                times.put(ch, 1);
        }
        
        for(int i = 0; i < str2.length(); ++i){
            Character ch = str2.charAt(i);
            if(!times.containsKey(ch))
                return false;
            
            if(times.get(ch) == 0)
                return false;
            
            times.put(ch, times.get(ch) - 1);
        }
        
        // If two strings with same length and containing
        // same set of characters are not anagrams,
        // it returns false before, because values of some
        // characters reach 0 in the second for loop above.
        // Therefore, it is safe to return true here.
        return true;
    }

    //================= Test Code =================
    private static void test(String testName, String str1, String str2, boolean expected){
        System.out.print(testName + " begins: ");

        if(areAnagrams(str1, str2) == expected)
            System.out.print("passed.\n");
        else
            System.out.print("FAILED.\n");
    }
    
    private static void test1(){
        test("Test1", "silent", "listen", true);
    }
    
    private static void test2(){
        test("Test2", "evil", "live", true);
    }
    
    private static void test3(){
        test("Test3", "eleven plus two", "twelve plus one", true);
    }
    
    private static void test4(){
        test("Test4", "there", "their", false);
    }
    
    private static void test5(){
        test("Test5", "an", "and", false);
    }
    
    static public void main(String[] args) {
        test1();
        test2();
        test3();
        test4();
        test5();
    }
}
