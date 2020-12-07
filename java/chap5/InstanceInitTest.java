package javacode.chap5;

class Base {
    {
        int b = 10;
        System.out.println(b);
    }
    int b = 20;

    {
        System.out.println(b);
        System.out.println("Hi from B");
    }

    public void hi() {
        System.out.println("hi");
    }

    public Base() {
        System.out.println("constructor method");
    }

}

public class InstanceInitTest {

    int a = 9;
    {
        a = 6;
        System.out.println(a);
    }

    {
        System.out.println(a);
    }
    Base alpha = new Base();

    public InstanceInitTest() {
        System.out.println("from InstanceInitTest");
    }

    public static void main(String[] aStrings) {
        new InstanceInitTest();
    }

}