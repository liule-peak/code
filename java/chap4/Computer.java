package javacode.chap4;

import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;

public class Computer {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String str = input.nextLine();

        String[] inOrderArrays = strToArrays(str);
        System.out.println(Arrays.toString(inOrderArrays));
        String[] postOrderArrays = toPostOrder(inOrderArrays);
        System.out.println(Arrays.toString(inOrderArrays));
        Double result = toCompute(postOrderArrays);
        System.out.printf("%.3f", result);
        input.close();
    }

    public static String[] strToArrays(String str) {
        int strLength = str.length();
        int beginIndex = 0;
        int endIndex = 0;
        String[] Arrays = new String[strLength];
        int arraysIndex = 0;

        for (int i = 0; i < strLength; i++) {
            if (str.charAt(i) == '*' || str.charAt(i) == '/' || str.charAt(i) == '+' || str.charAt(i) == '-'
                    || str.charAt(i) == '(' || str.charAt(i) == ')') {
                endIndex = i - 1;
                if (beginIndex <= endIndex) {
                    Arrays[arraysIndex] = str.substring(beginIndex, endIndex + 1);
                    Arrays[arraysIndex + 1] = String.valueOf(str.charAt(i));
                    arraysIndex += 2;
                    beginIndex = i + 1;
                } else {
                    Arrays[arraysIndex] = String.valueOf(str.charAt(i));
                    arraysIndex += 1;
                    beginIndex = i + 1;
                }
            }
        }

        if(!isOper(String.valueOf(str.charAt(strLength - 1)))){
            Arrays[arraysIndex] = str.substring(beginIndex,strLength);
            arraysIndex += 1;
        }
        String[] Arrays2 = new String[arraysIndex];
        for(int i = 0; i < arraysIndex; i++) {
            Arrays2[i] = Arrays[i];
        }
        System.out.println(arraysIndex);
        return Arrays2;
    }


    public static String[] toPostOrder(String[] arrays) {
        Stack<String> operStack = new Stack<String>();
        int arraysLength = arrays.length;
        String[] arrays2 = new String[arraysLength];
        int tempIndex = 0;

        for (int i = 0; i < arraysLength; i++) {
            if (isOper(arrays[i])) {
                if (operStack.isEmpty()) {
                    operStack.push(arrays[i]);
                } else {
                    if (arrays[i].equals("(")) {
                        operStack.push(arrays[i]);
                    } else if (arrays[i].equals(")")) {
                        while (operStack.peek().equals("(") == false) {
                            arrays2[tempIndex] = operStack.pop();
                            tempIndex += 1;
                        }
                        operStack.pop();
                    } else {
                        if (operStack.peek().equals("(")) {
                            operStack.push(arrays[i]);
                        } else {
                            if (getPriority(arrays[i].charAt(0)) > getPriority(operStack.peek().charAt(0))
                                    && operStack.isEmpty() == false) {
                                operStack.push(arrays[i]);
                            } else {
                                while (getPriority(arrays[i].charAt(0)) <= getPriority(operStack.peek().charAt(0))
                                        && operStack.isEmpty() == false) {
                                    arrays[tempIndex] = operStack.pop();
                                    tempIndex += 1;
                                    if (operStack.isEmpty()) {
                                        operStack.push(arrays[i]);
                                        break;
                                    }
                                }
                                if (getPriority(arrays[i].charAt(0)) > getPriority(operStack.peek().charAt(0))) {
                                    operStack.push(arrays[i]);
                                }
                            }

                        }
                    }
                }
            } else if (isNum(arrays[i])) {
                arrays2[tempIndex] = arrays[i];
                tempIndex += 1;
            } else {

            }
        }
        while (!operStack.isEmpty()) {
            arrays2[tempIndex] = operStack.pop();
            tempIndex += 1;
        }
        String[] arrays3 = new String[tempIndex];
        for (int i = 0; i < tempIndex; i++) {
            arrays3[i] = arrays2[i];
        }
        return arrays3;
    }

    public static int getPriority(char c) {
        if (c == '*' || c == '/') {
            return 2;
        } else if (c == '+' || c == '-') {
            return 1;
        } else {
            return 999;
        }
    }

    public static double toCompute(String[] arrays) {
        Stack<String> numStack = new Stack<String> ();
        int arraysLength = arrays.length;
        for (int i = 0; i < arraysLength; i++) {
            if (isNum(arrays[i])) {
                numStack.push(arrays[i]);
            } else if (isOper(arrays[i])) {
                Double num2 = Double.parseDouble(numStack.pop());
                Double num1 = Double.parseDouble(numStack.pop());
                if (arrays[i].equals("+")) {
                    Double result = num1 + num2;
                    numStack.push(result.toString());
                } else if (arrays[i].equals("-")) {
                    Double result = num1 - num2;
                    numStack.push(result.toString());
                } else if (arrays[i].equals("*")) {
                    Double result = num1 * num2;
                    numStack.push(result.toString());
                } else if (arrays[i].equals("/")) {
                    Double result = num1 / num2;
                    numStack.push(result.toString());
                } else {

                }
            } else {

            }
        }
        Double result = Double.parseDouble(numStack.pop());
        return result;
    }

    public static boolean isOper(String str) {
        if (str.equals("*") || str.equals("/") || str.equals("+") || str.equals("-") || str.equals("(")
                || str.equals(")")) {
            return true;
        } else {
            return false;
        }
    }

    public static boolean isNum(String str) {
        if (str.equals("*") || str.equals("/") || str.equals("+") || str.equals("-") || str.equals("(")
                || str.equals(")")) {
            return false;
        } else {
            return true;
        }
    }
}

