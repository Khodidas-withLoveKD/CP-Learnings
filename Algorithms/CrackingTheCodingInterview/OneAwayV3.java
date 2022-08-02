import java.util.*;
import java.lang.*;

public class solve {
  static Scanner sc;
  public static void main (String[] args) {
    long startTime = System.currentTimeMillis();
    int caseNo = 1;
    sc = new Scanner(System.in);
    int testCases = sc.nextInt();
    sc.nextLine();
    while (testCases > 0) {
      System.out.println("Testcase: " + caseNo++ + "\n-------------");
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

  private static boolean isOneAway(String a, String b) {
    // check for diff
    if (Math.abs(a.length() - b.length()) > 1) return false;

    String shorter, longer;
    if (a.length() < b.length()) {
      shorter = a;
      longer = b;
    } else {
      shorter = b;
      longer = a;
    }

    boolean foundOneDifference = false;
    int shortIndex = 0,
        longIndex = 0;

    while (shortIndex < shorter.length() && longIndex < longer.length()) {
      if (shorter.charAt(shortIndex) != longer.charAt(longIndex)) {
        if (foundOneDifference) return false;
        foundOneDifference = true;
        if (longIndex + 1 < longer.length()
            && shorter.charAt(shortIndex) == longer.charAt(longIndex + 1)) {
          longIndex++;
        } else {
          shortIndex++;
          longIndex++;
        }
      } else {
        longIndex++;
        shortIndex++;
      }
    }

    return longIndex - shortIndex <= 1;
  }
}
