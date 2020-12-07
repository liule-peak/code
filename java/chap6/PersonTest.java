package javacode.chap6;

public class PersonTest {
    public static void main(String[] args) {
        PersonU p1 = new PersonU();
        p1.eat();

        Man man = new Man();
        man.eat();
        man.age = 25;
        man.walk();
        man.earnMoney();

        System.out.println("---------------");
        PersonU p2 = new Man();
        p2.eat();
        p2.walk();
    }
    
}