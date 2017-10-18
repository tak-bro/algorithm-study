//////////////////////////////////
/*
This is a demo task.

Write a function:

class Solution { public int solution(int[] A); }

that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.
For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Assume that:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].
Complexity:

expected worst-case time complexity is O(N);
expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
Elements of input arrays can be modified.
*/
////////////////////////////////////////

// you can also use imports, for example:
import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class CodilityTest {
     public static int solution(int[] A) {
        // write your code in Java SE 8
        
        // Sort array
        Arrays.sort(A);
        
        // Delete negative integers
        int[] positives = Arrays.stream(A).filter(x -> (x > 0)).toArray();
        if (positives.length == 0) {
            return 1;
        }
        
        // Delete duplicate elements
        int b=0;
        positives[b] = positives[0];
        for (int i=0; i < positives.length;i++) {
            if (positives[b] != positives[i]) {
                b++;
                positives[b] = positives[i];
            }
        }
         
        boolean allChecked = true;
        for (int i = 0; i < positives.length; i++) {
            if ((i+1) != positives[i]) {
                allChecked = false;
                return i+1;
            }
        }
        
        if (allChecked) {
            return positives.length+1;
        }
        return 1;
    }
    
    public static void main(String args[])
    {   
        int[] first = { 1, 3, 6, 4, 1, 2 };
        int result = solution(first);
        System.out.println("First result is 5");
        System.out.println("Result value by solution function is " + result);
        
        
        int[] second = { 1, 2, 3 };
        result = solution(second);
        System.out.println("Second result is 4");
        System.out.println("Result value by solution function is " + result);
        
        int[] third = { -1, -3 };
        result = solution(third);
        System.out.println("First result is 1");
        System.out.println("Result value by solution function is " + result);
    }
}