package Algorithms.Data_Structures.Array;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class search_an_element_in_a_sorted_and_pivoted_array {
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

    // find pivot (using binary search!!!)
    int pivot = findPivot(list);
    System.out.println("pivot = " + pivot);
    // pivot is end of first half
    // do binary search in two halves
    int ans, len = 0;
    ans = binarySearch(list.subList(0, pivot), key);
    if (ans == -1) {
      ans = binarySearch(list.subList(pivot, list.size()), key);
      len = pivot;
    }
    if (ans == -1) {
      System.out.println("KEY not found");
    } else {
      System.out.println("Key found at index: " + (ans + len));
    }
  }
  private static int binarySearch(List<Integer> list, int key) {
    int left = 0,
          right = list.size() - 1,
          mid = right / 2;
    while (left <= right) {
      if (list.get(mid) == key) return mid;

      if (key > list.get(mid)) {
        // upper half
        left = mid + 1;
      } else {
        right = mid - 1;
      }
      mid = left + (right - left)/2;
    }
    return -1;
  }
  private static int findPivot(List<Integer> list) {
    int l = 0,
        r = list.size() - 1,
        m = r / 2;
    while (r - l > 1) {
      int left = list.get(l),
            right = list.get(r),
            mid = list.get(m);
      // all must be in ascending
      // So, if mid > right || mid < left
      if (left > mid) {
        // shift left
        r = m;
      } else if (mid > right) {
        // shift right
        l = m;
      }
      // pivot found
      if (list.get(l) < list.get(r)) break;

      m = l + (r - l)/2;
    }
    return r;
  }
}