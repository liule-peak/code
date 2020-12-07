package javacode.chap6;

public class MainTest {
    public static void main(String[] args) {
        Main.main(new String[100]);
    }
}

class Main {
    public static void main(String[] args) {
        for (int i = 0; i < args.length; i++) {
            System.out.println("args_"+i);
        }
    }
}