package javacode.chap6;

public class Primitive2String {
    public static void main(String[] args) {
        String intStr = "123";
        int it1 = Integer.parseInt(intStr);
        System.out.println(it1);
        int it2 = Integer.valueOf(intStr);
        System.out.println(it2);
        String floatStr = "4.56";
        float ft1 = Float.parseFloat(floatStr);
        System.out.println(ft1);
        float ft2 = Float.valueOf(floatStr);
        System.out.println(ft2);

        String ftStr = String.valueOf(2.345f);
        System.out.println(ftStr);
        String dbStr = String.valueOf(3.344);
        System.out.println(dbStr);

        String boolStr = String.valueOf(true);
        System.out.println(boolStr.toUpperCase()); 

    }
    
}