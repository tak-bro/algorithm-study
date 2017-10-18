import java.util.Comparator;
import java.util.Vector;
import java.util.Collections;
import java.util.Arrays;

public class Example
{
    public static String int2String(int from) {
        return Integer.toString(from);
    }
    
    public static int string2Int(String from) {
        return Integer.parseInt(from);
    }
    
    // Sort Vector
    public static void sortVector(Vector<Integer> tmp) {
         Collections.sort(tmp);
    }
    // Sort Vector Reverse
    public static void sortVectorReverse(Vector<Integer> tmp) {
         Collections.sort(tmp, Collections.reverseOrder());
    }
    
    // String to Vector (Split)
    public static Vector<String> splitString(String tmp, String delimeter) {
        String[] strArray = tmp.split(delimeter);
        Vector vec = new Vector();
        vec.addAll(Arrays.asList(strArray));
        return vec;
    }
    
    public static void main(String args[])
    {
        Vector<String> test = splitString("1,2,3,4,5,", ",");
        for (int i = 0; i < test.size(); i++) {
            System.out.println(test.get(i));
        }
        
        // compare string
        int a = 3;
        String b = "3";
        if (b.equals(int2String(a))) {
            System.out.println("Pass");
        } else {
            System.out.println("test");
        }
        
        // Sort vector
        // Create a Vector
        Vector<Integer> vector = new Vector<Integer>();
        vector.add(121);         
        vector.add(4);         
        vector.add(43);
        // sort
        sortVectorReverse(vector);
        //sortVector(vector);
        for (int i = 0; i < vector.size(); i++) {
            System.out.println(vector.get(i));
        }
        
    }
    
}