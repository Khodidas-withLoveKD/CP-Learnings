package Algorithms.SortingAndSearching;

import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class Merge_Without_Extra_Space_V3 {
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
    Merge sort Algorithm
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

    merge(arr1, arr2, n1, n2);

    System.out.println("------\nAFTWer arr1 = " + Arrays.toString(arr1));
    System.out.println("AFTER arr2 = " + Arrays.toString(arr2));
  }
  public static void merge(int[] arr1, int[] arr2, int n, int m) {
    // code here
      /*
          The goal is to use O(1) space
          so, this can be done by keeping the arrs sorted everytime
          using the observation that.... (joi le niche)
      */

    // The idea here is that if the smallest elem in arr2 is greater than any of the elem
    // in arr1, place it at its correct arr

    // do this while
    for (int index1 = 0; index1 < n; index1++) {
      if (arr1[index1] > arr2[0]) {
        // swap them
        int temp = arr2[0];
        arr2[0] = arr1[index1];
        arr1[index1] = temp;
        // and sort arr2 in order to make sure arr2[0] is the smallest element
        Arrays.sort(arr2);
      }
    }
  }
}