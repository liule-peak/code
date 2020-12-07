package javacode.chap5;

class BaseClass {
    public int book = 6;

    public void base() {
        System.out.println("父类的普通方法");
    }

    public void test() {
        System.out.println("父类被覆盖的方法");
    }
}

public class SubClass extends BaseClass {
    public String book = "Java EE";

    
    public void test() {
        System.out.println("subclass over ride baseclass");
    }

    public void sub() {
        System.out.println("subclass simple method");
    }

    public static void main(String[] aStrings) {
        BaseClass bc = new BaseClass();
        System.out.println(bc.book);
        bc.base();
        bc.test();

        SubClass sc = new SubClass();
        System.out.println(sc.book);
        sc.base();
        sc.test();

        BaseClass polymophicBc = new SubClass();
        System.out.println(polymophicBc);

        polymophicBc.base();
        polymophicBc.test();
    }
    
}