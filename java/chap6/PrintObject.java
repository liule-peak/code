package javacode.chap6;

class Person {
    private String name;

    public Person(String name) {
        this.name = name;
    }

    public String toString() {
        return name;
    }
}

public class PrintObject {
    public static void main(String[] args) {
        Person p = new Person("liule");
        System.out.println(p);
    }
}