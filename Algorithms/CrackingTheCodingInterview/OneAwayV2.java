package Algorithms.CrackingTheCodingInterview;

import java.util.Scanner;

public class OneAwayV2 {
  static Scanner sc;
  public static void main (String[] args) {
    long startTime = System.currentTimeMillis();
    int caseNo = 1;
    sc = new Scanner(System.in);
    int testCases = sc.nextInt();
    sc.nextLine();
    while (testCases > 0) {
      System.out.println("Testcase: " + caseNo++ + "\n----------");
      justDoIt();
      testCases--;
      System.out.println("-------------");
    }
    long endTime = System.currentTimeMillis();
    long elapsedTime = (endTime - startTime);
    System.out.println("Execution Time: " + elapsedTime + "ms");
  }
  // ==== SOLVE ==============
  static void justDoIt () {
    /*
    One Away: There are three types of edits that can be performed on strings:
    insert a character, remove a character, or replace a character.
    Given two strings, write a function to check if they are one edit (or zero edits) away.

    EXAMPLE
    pale, ple -> true
    pales, pale -> true
    pale, bale -> true
    pale, bake -> false
     */

    String a = sc.nextLine(),
            b = sc.nextLine();
    System.out.println("Strings = " + a + " | " + b);
    System.out.println(isOneAway(a,b) ? "YES" : "NO");
  }

  private static boolean isOneAway (String a, String b) {
    if (a.length() == b.length()) return isOneEditAway(a, b);
    else if (a.length() - 1 == b.length()) return isOneInsertionAway(b, a);
    else if (a.length() + 1 == b.length()) return isOneInsertionAway(a, b);

    return false;
  }

  private static boolean isOneEditAway(String a, String b) {
    boolean foundOneDifference = false;
    for (int i = 0; i < a.length(); i++) {
      if (a.charAt(i) != b.charAt(i)) {
        if (foundOneDifference) return false;
        foundOneDifference = true;
      }
    }
    return true;
  }

  private static boolean isOneInsertionAway(String shortStr, String longStr) {

    int shortIndex = 0,
        longIndex = 0;
    while (shortIndex < shortStr.length() && longIndex < longStr.length()) {
      if (shortStr.charAt(shortIndex) != longStr.charAt(longIndex)) {
        longIndex++;
        if (longIndex - shortIndex > 1) return false;
      } else {
        longIndex++;
        shortIndex++;
      }
    }
    return true;
  }
}
