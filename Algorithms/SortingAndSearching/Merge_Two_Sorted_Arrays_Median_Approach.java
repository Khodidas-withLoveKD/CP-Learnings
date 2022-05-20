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
      System.out.println("Testcase: " + caseNo++);
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
    int n = sc.nextInt(),
            m = sc.nextInt();
    int[] arr1 = new int[n];
    int[] arr2 = new int[m];

    for (int i = 0; i < n; i++) arr1[i] = sc.nextInt();
    for (int j = 0; j < m; j++) arr2[j] = sc.nextInt();

    mergeTwoSortedArrays(arr1, arr2, n, m);
  }

  private static void mergeTwoSortedArrays(int[] arr1, int[] arr2, int n, int m) {
    // find the median index first
    int medianIndex = findMedianOfTwoSortedArrays(arr1, arr2, n, m);
    System.out.println("medianIndex = " + medianIndex);
    // when index found replace those arrays and sort them
    // replace arr1.length - mI nums
    for (int i = n - medianIndex, j = 0; i < n; i++, j++) {
      // swap nums
      int temp = arr1[i];
      arr1[i] = arr2[j];
      arr2[j] = temp;
    }
    System.out.println("arr1 = " + Arrays.toString(arr1));
    System.out.println("arr2 = " + Arrays.toString(arr2));

    // sort them
    Arrays.sort(arr1);
    Arrays.sort(arr2);
    System.out.println("After SORT ==== \n");
    System.out.println("arr1 = " + Arrays.toString(arr1));
    System.out.println("arr2 = " + Arrays.toString(arr2));
    // now we need to check if the arrays was swaped in findMedianOfTwoSortedArrays
    // so we compare the last and first nums of arrs
    if (arr1[n - 1] > arr2[0]) {
      // arrays were swaped
      // swap till the condition is true
      for (int i = n - 1, j = 0;
           i >= 0 && j < m && arr1[i] > arr2[j]; i--, j++) {
        int temp = arr1[i];
        arr1[i] = arr2[j];
        arr2[j] = temp;
      }
    }
    System.out.println("After SWAPPING ==== \n");
    System.out.println("arr1 = " + Arrays.toString(arr1));
    System.out.println("arr2 = " + Arrays.toString(arr2));
    // sort them
    Arrays.sort(arr1);
    Arrays.sort(arr2);
    System.out.println("After Last ==== \n");
    System.out.println("arr1 = " + Arrays.toString(arr1));
    System.out.println("arr2 = " + Arrays.toString(arr2));
  }

  private static int findMedianOfTwoSortedArrays(int[] arr1, int[] arr2, int n, int m) {
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
        // return the index
        return px;
      }
      if (maxLeftX > minRightY) {
        end = px - 1;
      } else {
        start = px + 1;
      }
    }
    return -1;
  }

}