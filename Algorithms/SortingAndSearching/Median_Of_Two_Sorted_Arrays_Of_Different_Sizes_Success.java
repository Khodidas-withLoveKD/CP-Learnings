package Algorithms.SortingAndSearching;

import java.util.Scanner;

public class Median_Of_Two_Sorted_Arrays_Of_Different_Sizes_Success {
  static Scanner sc;
  public static void main (String[] args) {
    sc = new Scanner(System.in);
    // testCases
    int testCases = sc.nextInt();
    while (testCases > 0) {
      justDoIt();
      testCases--;
    }
  }
  // ==== SOLVE ==============
  static void justDoIt () {
    int n = sc.nextInt(),
            m = sc.nextInt();
    int[] arr1 = new int[n];
    int[] arr2 = new int[m];

    for (int i = 0; i < n; i++) arr1[i] = sc.nextInt();
    for (int j = 0; j < m; j++) arr2[j] = sc.nextInt();

    System.out.println("Median = " + findMedianOfTwoSortedArrays(arr1, arr2, n , m));
  }

  private static double findMedianOfTwoSortedArrays(int[] arr1, int[] arr2, int n, int m) {
    double median = -1;
    // if n > m => replace
    // as n should be less
    // because we do py = (n + m + 1)/2 - px
    // py can go -ve
    if (n > m) {
      return findMedianOfTwoSortedArrays(arr2, arr1, m, n);
    }
    // few vars that we will require
    int start = 0, end = n;

    // as arrays are sorted we can apply binary search
    while (start <= end) {
      // the index at which x will be partitioned
      int px = (start + end) / 2;
      int py = (n + m + 1)/2 - px;

      int maxLeftX = (px == 0) ? Integer.MIN_VALUE : arr1[px - 1];
      int maxLeftY = (py == 0) ? Integer.MIN_VALUE : arr2[py - 1];

      int minRightX = (px == n) ? Integer.MAX_VALUE : arr1[px];
      int minRightY = (py == m) ? Integer.MAX_VALUE : arr2[py];

      // check conditions
      if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
        if ((n + m) % 2 == 1) {
          median = Math.max(maxLeftX, maxLeftY);
        } else {
          median = (Math.max(maxLeftX, maxLeftY) + Math.min(minRightX, minRightY))/2.0;
        }
        break;
      } else {
        if (maxLeftX > minRightY) end = px - 1;
        else start = px + 1;
      }
    }
    return median;
  }

}