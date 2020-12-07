package javacode.chap6;

public class EqualTest {
    public static void main(String[] args) {
        int it = 65;
        float f1 = 65.0f;
        System.out.println("Is Equal between 65 and 65.0f?" + (it == f1));
        
        char ch = 'A';
        System.out.println("Is Equal between 65 and 'A'?"+(it == ch));
    }
    
}