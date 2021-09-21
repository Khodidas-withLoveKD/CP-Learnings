package Algorithms.Prefix_Sum;

import java.io.IOException;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class Maximum_occurred_integer_in_n_ranges {
//  static BufferedReader br;
  static Scanner sc;
  public static void main(String[] args) throws IOException {
    int caseNo = 1;
//    br = new BufferedReader(new InputStreamReader(System.in));
    sc = new Scanner(System.in);
    int testCases = sc.nextInt();         // scan first-word
    while (testCases > 0) {
      System.out.println("Testcase: " + caseNo++);
      justDoIt();
      testCases--;
      System.out.println("-------------");
    }
  }

  static void justDoIt() throws IOException {
     /*
    Given n ranges of the form L and R, the task is to find the maximum occurred integer in all the ranges.
    If more than one such integer exists, print the smallest one.
    0 <= Li, Ri < 1000000.
    Examples :


    Input : L1 = 1 R1 = 15
            L2 = 4 R2 = 8
            L3 = 3 R3 = 5
            L3 = 1 R3 = 4
    Output : 4

    Input : L1 = 1 R1 = 15
            L2 = 5 R2 = 8
            L3 = 9 R3 = 12
            L4 = 13 R4 = 20
            L5 = 21 R5 = 30
    Output : 5
    Numbers having maximum occurrence i.e 2  are 5, 6,
    7, 8, 9, 10, 11, 12, 13, 14, 15. The smallest number
    among all are 5.
    */
    // =============== SOLVE ==============
    // =========== My try ============
    // Similar to a problem solved earlier
    // increase the height only of the limits, middle will be auto updated

    // inputs
    int n = sc.nextInt(),
            l, r, ans = 0;
    // DS to use my logic
    TreeMap<Integer, Integer> tm = new TreeMap<>();
    while (n > 0) {
      l = sc.nextInt();
      r = sc.nextInt();
      modifyTreeMap(tm, l ,r);
      n--;
    }
    System.out.println("tm = " + tm);
    // traverse TreeMap
    int maxNum = 0, currentNum = 0;
    for (Map.Entry mapElement : tm.entrySet()) {
      currentNum += (Integer)mapElement.getValue();
      if (currentNum > maxNum) {
        maxNum = currentNum;
        ans = (Integer)mapElement.getKey();
      }
    }
    System.out.println("maxNum = " + ans);
    /*
    Time Complexity: O(n)
    */
  }
  static void modifyTreeMap( TreeMap<Integer, Integer> tm, int l, int r) {
    if (tm.containsKey(l)) {
      tm.put(l, tm.get(l) + 1);
    } else {
      tm.put(l, 1);
    }
    if (tm.containsKey(r+1)) {
      tm.put(r+1, tm.get(r+1) - 1);
    } else {
      tm.put(r+1, -1);
    }
  }
}