import javafx.util.Pair;

import java.util.*;
import java.lang.*;

public class solve {
  static Scanner sc;
  public static void main (String[] args) {
    long startTime = System.currentTimeMillis();
    int caseNo = 1;
    sc = new Scanner(System.in);
    int testCases = sc.nextInt();
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
      Given a string, we need to print all possible palindromes that can be
      generated using letters of that string. Examples:

      Input:  str = "aabcb"
      Output: abcba bacab

      Input:  str = "aabbcadad"
      Output: aabdcdbaa aadbcbdaa abadcdaba
              abdacadba adabcbada adbacabda
              baadcdaab badacadab bdaacaadb
              daabcbaad dabacabad dbaacaabd
    */
    all_palindromes("hey");
  }
    private static List<String> all_palindromes(String s)
    {
    // Code here
    int[] charMap = new int[26];
    if (isPalindrome(s.toCharArray(), charMap)) {
      return generateAllPermutations(charMap, s.length() % 2 == 1);
    }

    return new ArrayList<String>();
  }

  private static boolean isPalindrome(char[] charArray, int[] map) {
    for (char c : charArray) {
      map[c - 'a']++;
    }

    boolean hasMid = charArray.length % 2 == 1;
    boolean midFound = false;

    for (int occ : map) {
      if (occ % 2 == 1) {
        if (hasMid) {
          if (!midFound) {
            midFound = true;
          } else {
            return false;
          }
        } else {
          return false;
        }
      }
    }

    return true;
  }

  private static List<String> generateAllPermutations(int[] map, boolean hasMidChar) {
    char midChar = hasMidChar ? getMidChar(map) : Character.MIN_VALUE;

    List<String> permutations = generateAllNormalPermutations(
            getStringForPermutation(map));

    List<String> ans = new ArrayList<String>();
    for (String str : permutations) {
      ans.add(str + midChar + getMirrorString(str));
    }

    return ans;
  }

  private static String getMirrorString(String str) {
    return new StringBuilder(str).reverse().toString();

  }

  private static List<String> generateAllNormalPermutations (String str) {
    return new ArrayList<String>(
            new TreeSet<String>(
                    permute(str, "")
            )
    );
  }

  private static List<String> permute (String str, String prefix) {
    if (str.length() == 0) {
      return new ArrayList<String>() {{
        add(prefix);
      }};
    }

    List<String> ans = new ArrayList<String>();

    for (int i = 0; i < str.length(); i++) {
      String rem = str.substring(0, i) + str.substring(i + 1);
      ans.addAll(permute(rem, prefix + str.charAt(i)));
    }

    return ans;
  }

  private static String getStringForPermutation (int[] map) {
    StringBuilder sb = new StringBuilder();

    for (int i = 0; i < 26; i++) {
      map[i] /= 2;
      while (map[i]-- > 0) sb.append((char)(i + 'a'));
    }

    return sb.toString();
  }

  private static char getMidChar (int[] map) {
    for (int i = 0; i < 26; i++) {
      if (map[i] % 2 == 1) return (char)(i + 'a');
    }
    return 'z';
  }
}
