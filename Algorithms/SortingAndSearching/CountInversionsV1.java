package Algorithms.SortingAndSearching;

import java.util.Scanner;

public class CountInversionsV1 {
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
    int k = sc.nextInt();
    int[] arr = new int[k];

    for (int i = 0; i < k; i++)
        arr[i] = sc.nextInt();

    System.out.println("Inversion Count = " + countInversions(arr, k));
  }

  private static int countInversions(int[] arr, int n) {
    // Use modified version of merge sort to get the thing done

    // Let's mergesort!!
    return mergeSort(0, n-1, arr, 0);
  }

  private static int mergeSort(int l, int h, int[] arr, int invCount) {
    if (l < h) {
      int mid = l + (h - l)/2;

      invCount = mergeSort(l, mid, arr, invCount);
      System.out.println("mergeSort LEFY invCount = " + invCount);
      invCount = mergeSort(mid + 1, h, arr, invCount);
      System.out.println("mergeSort RIGHT invCount = " + invCount);
      invCount = merge(l, mid + 1, h, arr, invCount);
      System.out.println("merge invCount = " + invCount);
//      return invCount;
    }
//    return 0;
    return invCount;
  }

  private static int merge(int l, int mid, int h, int[] arr, int invCount) {
    // case: 7    6
    int i = l, j = mid, k = 0;
    int[] tempArr = new int[h - l + 1];

    while (i < mid && j <= h) {
      if (arr[i] <= arr[j])  tempArr[k++] = arr[i++];
      else {
        tempArr[k++] = arr[j++];
        invCount += mid - i;
      }
    }
    while (i < mid) tempArr[k++] = arr[i++];
    while (j <= h) {
      tempArr[k++] = arr[j++];
      invCount += mid - i;
    }
    return invCount;
  }
}
