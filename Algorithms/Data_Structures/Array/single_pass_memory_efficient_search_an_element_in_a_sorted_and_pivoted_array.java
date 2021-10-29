package Algorithms.Data_Structures.Array;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class single_pass_memory_efficient_search_an_element_in_a_sorted_and_pivoted_array {
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
    Search an element in a sorted and rotated array
    An element in a sorted array can be found in O(log n) time via binary search.
    But suppose we rotate an ascending order sorted array at some pivot unknown to you beforehand.
    So for instance, 1 2 3 4 5 might become 3 4 5 1 2.
    Devise a way to find an element in the rotated array in O(log n) time.

    Example:
    Input  : arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
             key = 3
    Output : Found at index 8

    Input  : arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
             key = 30
    Output : Not found

    Input : arr[] = {30, 40, 50, 10, 20}
            key = 10
    Output : Found at index 3
    ------------
    Input STYLE
    t testcases
    for each testcase
    n (no. of elements)
    [n0, n1, .... nn-1] elements
    key
    */
    // inputs
    int n = sc.nextInt();
    List<Integer> list = new ArrayList<>(n);
    for (int i = 0; i < n; i++) {
      list.add(sc.nextInt());
    }
    int key = sc.nextInt();

    // pivot is end of first half
    int ans, len = 0;
    ans = binarySearch(list, 0, list.size() - 1, key);
    if (ans == -1) {
      System.out.println("KEY not found");
    } else {
      System.out.println("Key found at index: " + (ans + len));
    }
  }
  // passing list everyTime will create a memory overhead. So, passing l and r as well
  private static int binarySearch(List<Integer> list, int l, int r, int key) {
    // termination
    if (r == l && list.get(l) != key) return -1;

    int m = l + (r - l)/ 2;
    System.out.println("l = " + l + " | r = " + r + " | m = " + m);
    int left = list.get(l),
        right = list.get(r),
        mid = list.get(m);
    // if mid is the key
    if (mid == key) return m;

    // ===== IDEA BEHIND THIS =======
    // check which half is sorted
    // Because at any given time at least one of them will always be sorted
    // then if sorted check for key in range
    // else partition (using binarySearch) till array is not sorted

    // if arr[l...mid] is sorted
    if (left < mid) {
      // if key lies in the first half
      if (left <= key && key < mid) {
        // do binary search in this half
        return binarySearch(list, l, m, key);
      } else {
        // key can lie in the second half
        return binarySearch(list, m + 1, r, key);
      }
    } else {
      // the other half must be sorted
      // if key lies in the first half
      if (mid < key && key <= right) {
        return binarySearch(list, m + 1, r, key);
      } else {
        // check in the other half
        return binarySearch(list, l, m, key);
      }
    }
  }
}