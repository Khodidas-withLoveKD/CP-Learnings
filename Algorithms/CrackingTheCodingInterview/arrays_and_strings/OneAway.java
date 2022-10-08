package Algorithms.CrackingTheCodingInterview;

import java.util.Scanner;

public class OneAway {
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
    if (Math.abs(a.length() - b.length()) > 1) return false;

    if (a.equals(b)) return true;

    int[] mapA = new int[26];
    int[] mapB = new int[26];
    for (char c : a.toCharArray()) mapA[c - 'a']++;
    for (char c : b.toCharArray()) mapB[c - 'a']++;

    int diffA = 0, diffB = 0;
    for (int i = 0; i < 26; i++) {
      diffA += Math.max(mapA[i] - mapB[i], 0);
      diffB += Math.max(mapB[i] - mapA[i], 0);
    }
    return diffA + diffB <= 2;
  }
}
