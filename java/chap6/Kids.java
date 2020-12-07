package javacode.chap6;

public class Kids extends Person1 {
    public Kids() {
        System.out.println("this constructor belongs to Kids");
    }

    public void say() {
        System.out.println("from kids");
        super.say();
    }
}