package Algorithms.SortingAndSearching;

import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class Median_Of_Two_Sorted_Arrays_Of_Same_Size {
  static Scanner sc;
  public static void main(String[] args) throws IOException {
    long startTime = System.currentTimeMillis();
    int caseNo = 1;
    sc = new Scanner(System.in);
    int testCases = sc.nextInt();
//    int testCases = 1;
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
    Median of two sorted arrays of same size
   */
    // input
    int n1 = sc.nextInt();
    int n2 = sc.nextInt();
    int[] arr1 = new int[n1];

    for (int i = 0; i < n1; i++) {
      arr1[i] = sc.nextInt();
    }
    int[] arr2 = new int[n2];

    for (int i = 0; i < n2; i++) {
      arr2[i] = sc.nextInt();
    }
    System.out.println("AFTWer arr1 = " + Arrays.toString(arr1));
    System.out.println("AFTER arr2 = " + Arrays.toString(arr2));

    System.out.println("median = " + findMedian(arr1, arr2, n1, n2));

//    System.out.println("------\nAFTWer arr1 = " + Arrays.toString(arr1));
//    System.out.println("AFTER arr2 = " + Arrays.toString(arr2));
  }
  public static int findMedian(int[] arr1, int[] arr2, int n, int m) {
    // code here
      /*
          The goal here is find solution in log(n) time
      */
    // find medians of both individual arrays
    int m1 = findIndividualMedian(arr1, 0, n - 1);
    int m2 = findIndividualMedian(arr2, 0, m - 1);

    // now if m1 != m2 then median lie between this nums
    if (m1 == m2) return m1;

    int l1 = 0, h1 = n - 1, l2 = 0, h2 = m - 1;
    int size = h1 - l1 + 1;
    while (size > 2) {
      if (m1 < m2) {
        // then med must lie between arr1[0....n/2] & arr2[n/2 .... n-1]
        if (size % 2 == 0) {
          h2 = l2 + (size / 2);
          l1 = l1 + (size / 2) - 1;
        } else {
          h2 = l2 + (size/2);
          l1 = l1 + (size / 2);
        }
      } else {
        // then med must lie between arr1[n/2...n-1] && arr2[0 ... n/2]
        if (size % 2 == 0) {
          h1 = l1 + (size/2);
          l2 = l2 + (size/2) - 1;
        } else {
          h1 = l1 + (size/2);
          l2 = l2 + (size/2);
        }
      }
      m1 = findIndividualMedian(arr1, l1, h1);
      m2 = findIndividualMedian(arr2, l2, h2);
      size = h1 - l1 + 1;
    }
    return (Math.max(arr1[l1], arr2[l2]) + Math.min(arr1[h1], arr2[h2]))/2;
  }
  private static int findIndividualMedian(int[] arr, int low, int high) {
    int n = high - low + 1;
    return (n % 2 == 0) ? (arr[low + (n-1)/2] + arr[low + (n/2)])/2 : arr[low + (n/2)];
  }
}