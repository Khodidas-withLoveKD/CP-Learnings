package Algorithms.Strings;

import java.util.BitSet;
import java.util.Scanner;

public class IsPalindromeUsingBitVector {
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
      Check if a string is Palindrome using bitVector
    */

    char[] charArr = sc.nextLine().toCharArray();
    BitSet bs = new BitSet(26); // assuming string has lowercase alphabets only

    // for a string to be palindrome -> at most one odd
    // we will flip the bit representing the char
    // then count the bit
    for (char c : charArr) {
      bs.flip(c - 'a');
    }

    System.out.println(bs.cardinality() <= 1 ? "YES" : "NO");
  }
}
