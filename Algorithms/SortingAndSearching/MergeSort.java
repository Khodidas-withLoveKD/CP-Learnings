package Algorithms.SortingAndSearching;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class MergeSort {
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
    int n = sc.nextInt();
    int[] arr = new int[n];

    for (int i = 0; i < n; i++) {
      arr[i] = sc.nextInt();
    }
    System.out.println("BEFORE arr = " + Arrays.toString(arr));
    // two main functions - mergeSort and merge
    mergeSort(arr, 0, n - 1);
    System.out.println("AFTER arr = " + Arrays.toString(arr));
  }

  private static void mergeSort(int[] arr, int low, int high) {
    if (low < high) {
      int mid = low + (high - low)/2;

      mergeSort(arr, low, mid);
      mergeSort(arr, mid + 1, high);

      merge(arr, low, mid, high);
    }
  }

  private static void merge(int[] arr, int low, int mid, int high) {
    // arr[low...mid] and arr[mid + 1...high] are already sorted
    // take two pointers
    int first = low,
        second = mid + 1;
    // TODO: try to do it with arrays
    // * Arrays are faster than ArrayList -> So, use that
//    int[] tempArr = new int[high - low + 1];
    List<Integer> tempArr = new ArrayList<>();

    while (first <= mid && second <= high) {
      if (arr[first] <= arr[second]) {
        tempArr.add(arr[first++]);
      } else {
        tempArr.add(arr[second++]);
      }
    }
    while (first <= mid) tempArr.add(arr[first++]);
    while (second <= high) tempArr.add(arr[second++]);

    // copy tempArr to arr
    for (int i = low; i <= high; i++) {
      arr[i] = tempArr.remove(0);
    }
  }
}