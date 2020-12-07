package javacode.chap6;


public class KidsTest extends Kids {
    private int a;

    public KidsTest() {
        super();
        this.a = 7;
        System.out.println(a);
        System.out.println("this constructor belongs to KidsTest");
    }
    public void say() {
        
        System.out.println("from KidsTest");
    }

    public void get() {
        
        super.say();
    }

    public static void main(String[] args) {
        
        KidsTest obj1 = new KidsTest();
        obj1.say();
        obj1.get();
    }
    
}