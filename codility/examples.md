# https://gist.github.com/coded9/fab301766c3c5af601e4ef5cf2855e21

#[Tape Equilibrium](https://codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/)
```java
class Solution {
    public int solution(int[] A) {
        int i,left=0,right=0,sum=0,min=Integer.MAX_VALUE;
        for(i=0;i<A.length;i++){
    	 sum += A[i];
     }
     left = A[0];
     for(i=1;i<A.length;i++){
    	 right = sum - left;
    	 min = Math.min(min, Math.abs(right-left));
    	 left +=A[i];
     }
     return min;
    }
}
```
#[FrogJmp](https://codility.com/programmers/lessons/3-time_complexity/frog_jmp/)
```java
class Solution {
    public int solution(int X, int Y, int D) {
        // write your code in Java SE 8
        if(X>=Y) return 0;
        return (Y-X)%D==0?(Y-X)/D:(Y-X)/D +1;
    }
}
```
#[ PermMissingElem](https://codility.com/programmers/lessons/3-time_complexity/perm_missing_elem/)
```java
class Solution {
    public int solution(int[] A) {
         long N = A.length+1,sum=0;
        for(int i=0;i<A.length;i++){
            sum += A[i];
    }
    return (int)(N*(N+1)/2-sum);
    }
}
```

#[PermCheck](https://codility.com/programmers/lessons/4-counting_elements/perm_check/)
```java
import java.util.*;
class Solution {
    public int solution(int[] A) {
        // write your code in Java SE 8
           long N = A.length,sum=0;
        Set<Integer> set = new HashSet();
        for(int i=0;i<A.length;i++){
    	 if(!set.contains(A[i])) {set.add(A[i]);sum += A[i];}
     }
     if(N*(N+1)/2==sum) return 1;
    return 0;
    }
}
```
#[MissingInteger](https://codility.com/programmers/lessons/4-counting_elements/missing_integer/)
```java
// you can also use imports, for example:
import java.util.*;
class Solution {
    public int solution(int[] A) {
        // write your code in Java SE 8
         int b=0;
        Set<Integer> set = new LinkedHashSet();
        for(int i=1;i<=A.length;i++){
           set.add(i);
        }
        for(int i=0;i<A.length;i++){
           
    	 if(set.contains(A[i])) {set.remove(A[i]);}
     }
     for(Integer a: set){ b = a; break;}
     return b==0?A.length+1:b;
    }
}
```
#[FrogRiverOne](https://codility.com/programmers/lessons/4-counting_elements/frog_river_one/)
```java
import java.util.*;
class Solution {
    public int solution(int X, int[] A) {
        // write your code in Java SE 8
        Set<Integer> set = new LinkedHashSet();
        int i;
        for(i=1;i<=X;i++){
            set.add(i);
    }
    for(i=0;i<A.length;i++){
        if(set.contains(A[i])) set.remove(A[i]);
        if(set.size()==0) break;
}
 return set.size()==0?i:-1;
}
}
```
#[CountDiv]
```java
class Solution {
    public int solution(int A, int B, int K) {
        // write your code in Java SE 8
        int count = 0;
        count = B/K - A/K;
        if(A%K==0)count++;
        return count; 
    }
}
```
#[Distinct](https://codility.com/programmers/lessons/6-sorting/distinct/)
```
import java.util.*;
class Solution {
    public int solution(int[] A) {
        // write your code in Java SE 8
        Set<Integer> set = new HashSet();
        for(int i=0;i<A.length;i++){
            set.add(A[i]);
    }
    return set.size();
}
}
```
#[MaxProductOfThree](https://codility.com/programmers/lessons/6-sorting/max_product_of_three/)
```
import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class Solution {
    public int solution(int[] A) {
        // write your code in Java SE 8
        int N = A.length;
        Arrays.sort(A);
    return Math.max(A[0]*A[1]*A[N-1],A[N-1]*A[N-2]*A[N-3]);
}
}
```
#[Triangle](https://codility.com/programmers/lessons/6-sorting/triangle/)
```
import java.util.*;
class Solution {
    public int solution(int[] A) {
        // write your code in Java SE 8
        Arrays.sort(A);
        int N = A.length,i;
        for(i=0;i<N-2;i++){
            long a,b,c;
            a = A[i]+A[i+1];
            b = A[i+2]+A[i+1];
            c = A[i]+A[i+2];
            if(a>A[i+2] && b >A[i] && c>A[i+1]) return 1;
    }
    return 0;
}
}
```
#[Brackets](https://codility.com/programmers/lessons/7-stacks_and_queues/brackets/)
```
import java.util.*;
class Solution {
    public int solution(String S) {
        // write your code in Java SE 8
      Stack<Character> st = new Stack();
      int i;
      char ch;
      for(i=0;i<S.length();i++){
          ch = S.charAt(i);
          if(ch=='('||ch=='['||ch=='{'||ch=='V') st.push(ch);
          else if(ch==')'||ch==']'||ch=='}' ||ch=='W'){
              if(st.isEmpty()|| (ch==')'&& st.peek()!='(')||(ch==']'&&st.peek()!='[') 
              || (ch=='}' && st.peek()!='{') || (ch=='W' && st.peek()!='V')) return 0;
              st.pop();
                 
              }
    }
      return st.isEmpty()?1:0;  
}
}
```
#[Dominator](https://codility.com/programmers/lessons/8-leader/dominator/)
```
import java.util.*;
class Solution {
    public int solution(int[] A) {
        // write your code in Java SE 8
        HashMap<Integer,Integer> map = new HashMap();
        int i,dominator=0,count=0;
        for(i=0;i<A.length;i++){
            if(map.containsKey(A[i])){
                map.put(A[i],map.get(A[i])+1);
            }else{
                map.put(A[i],1);
            }
        }    
    for(Integer a:map.keySet()){
    
        if(map.get(a)>count){
        count = map.get(a);
        dominator = a;
        }
    }
    for(i=0;i<A.length;i++){
        if(dominator==A[i]&&count>A.length/2) return i;
    }
    return -1;
}
}
```
#[Nesting](https://codility.com/programmers/lessons/7-stacks_and_queues/nesting/)
```
import java.util.*;
class Solution {
    public int solution(String S) {
        // write your code in Java SE 8
      Stack<Character> st = new Stack();
      int i;
      char ch;
      for(i=0;i<S.length();i++){
          ch = S.charAt(i);
          if(ch=='('||ch=='V') st.push(ch);
          else if(ch==')'||ch=='W'){
              if(st.isEmpty()|| (ch==')'&& st.peek()!='(') || (ch=='W' && st.peek()!='V')) return 0;
              st.pop();

              }
    }
      return st.isEmpty()?1:0;  
}
}
```
#[CountFactors](https://codility.com/programmers/lessons/10-prime_and_composite_numbers/count_factors/)
```
class Solution {
    public int solution(int N) {
        int count = 0;
       for(int i=1;i<(int)((Math.ceil(Math.sqrt(N))));i++){
           if(N%i==0) count++;
       }
       return count*2+((int)((Math.ceil(Math.sqrt(N))))==(int)(Math.sqrt(N))?1:0);
    }
}
```
#[MinPerimeterRectangle](https://codility.com/programmers/lessons/10-prime_and_composite_numbers/min_perimeter_rectangle/)
```
class Solution {
    public int solution(int N) {
        int min = Integer.MAX_VALUE;
        for(int i=1;i<=(int)(Math.ceil(Math.sqrt(N)));i++){
            if(N%i==0){
                min = Math.min(min,2*(N/i+i));
            }
        }
        return min;
    }
}
```
#[CountSemiPrimes]() Pending
```
import java.util.*;
class Solution {
    public int[] solution(int N, int[] P, int[] Q) {
       boolean arr[] = new boolean[N+1],flag;
       int i,j,k,count=0;
       if(N>1) arr[0] = arr[1] = true;
       for(i=2;i<=(int)Math.sqrt(arr.length-1);i++){
       if(!arr[i]){
           for(j=i*i;j<=arr.length-1;j+=i){
               arr[j] = true;
           }
       }
    }
    int[] res = new int[P.length];
    for(i=0;i<P.length;i++){
        count = 0;
        for(j=P[i];j<=Q[i];j++){
            flag = false;
            if(arr[j]&&j>2){
            for(k=2;k<=(int)Math.sqrt(j);k++){
                if(!arr[k] && j%k==0&&!arr[j/k]) {flag = true;break;} 
                    }
                    if(flag) count++;
                }
                res[i] = count;
        }
    }
        return res;
    }
}
```
#[CountNonDivisible]
```
class Solution {
    public int[] solution(int[] A) {
       int i,j,count;
       int[] B = new int[A.length]; 
       for(i=0;i<A.length;i++){
           count = 0;
           for(j=0;j<A.length;j++){
               if(A[i]%A[j]!=0) count++;
           }
           B[i] = count;
       }
       return B;
    }
}
```