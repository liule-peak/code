package javacode.chap6;

public class Interview {
    public static void main(String[] args) {
        Base q = new Sub();
        Sub b = (Sub) q;
        b.add(1,2,3);
    }
}

class Base {
    public void add(int a, int... b) {
        System.out.println("Base");
    }
}

class Sub extends Base {
    public void add(int a, int[] b) {
        System.out.println("Sub1");
    }

    public void add(int a, int b,int c) {
        System.out.println("Sub2");
    }
}