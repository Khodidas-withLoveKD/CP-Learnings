package Algorithms.Data_Structures.Array;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class improved_sorted_rotated_array_find_if_has_sum_x {
  static Scanner sc;
  public static void main(String[] args) throws IOException {
    long startTime = System.currentTimeMillis();
    int caseNo = 1;
    sc = new Scanner(System.in);
    int testCases = sc.nextInt();
    while (testCases > 0) {
      System.out.println("Testcase: " + caseNo++);
      justDoIt();
      testCases--;
      System.out.println("-------------");
    }
    long endTime = System.currentTimeMillis();
    long elapsedTime = (endTime - startTime);
    System.out.println("Execution Time: " + elapsedTime + "ms");
  }

  static void justDoIt() {
     /*
    Given an array that is sorted and then rotated around an unknown point.
    Find if the array has a pair with a given sum x.
    It may be assumed that all elements in the array are distinct.

    Examples :
    Input: arr[] = {11, 15, 6, 8, 9, 10}, x = 16
    Output: true
    There is a pair (6, 10) with sum 16

    Input: arr[] = {11, 15, 26, 38, 9, 10}, x = 35
    Output: true
    There is a pair (26, 9) with sum 35

    Input: arr[] = {11, 15, 26, 38, 9, 10}, x = 45
    Output: false
    There is no pair with sum 45.
    ------------
    Input STYLE
    t testcases
    for each testcase
    n (no. of elements)
    [n0, n1, .... nn-1] elements
    sun
    */
    // inputs
    int n = sc.nextInt();
    List<Integer> list = new ArrayList<>(n);
    for (int i = 0; i < n; i++) {
      list.add(sc.nextInt());
    }
    int sum = sc.nextInt();

    // ===== APPROACH ======
    /*
    - Find Pivot
    - Use two pointer technique
   */
    // find pivot
    // max element will be the pivot (let's make that a pivot)
    int pivot = list.indexOf(Collections.max(list));

    int[] ans;
    ans = findAns(list, sum, pivot);
    if (ans[0] == -1) {
      System.out.println("KEY not found");
    } else {
      System.out.println("Pair found at index: " + ans[0] + " and " + ans[1]);
    }
  }
  private static int[] findAns(List<Integer> list, int sum, int pivot) {
    int [] ans = new int[2];
    ans[0] = -1;

    // use two pointer technique as array is sorted
    // the pivot will be the largest element
    int l = pivot + 1,
        r = pivot,
        currSum;

    while (l != r) {
      currSum = list.get(l) + list.get(r);
      if (currSum == sum) {
        ans[0] = l;
        ans[1] = r;
        break;
      }
      // if the sum of two is less than required, move pointer to right
      if (currSum < sum) {
        l = (l == list.size() - 1) ? 0 : l + 1;
      } else {
        r = (r == 0) ? list.size() - 1 : r - 1;
      }
    }

    return ans;
  }
}