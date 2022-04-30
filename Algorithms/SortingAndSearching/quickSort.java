package Algorithms.SortingAndSearching;

import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class quickSort {
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
    Quick sort Algorithm
   */
    int [] arr = new int[]{10, 80, 90, 30, 40, 100, 70};
    System.out.println("BEOFRE arr = " + Arrays.toString(arr));
    // two main functions - partition and quickSort
    quickSort(arr, 0, arr.length - 1);
    System.out.println("AFTER arr = " + Arrays.toString(arr));
  }

  private static void quickSort(int[] arr, int low, int high) {
    if (low < high) {
      int pivotIndex = partition(arr, low, high);
      System.out.println("pivotIndex = " + pivotIndex);
      quickSort(arr, low, pivotIndex - 1);
      quickSort(arr, pivotIndex + 1, high);
    }
  }
  private static int partition(int[] arr, int low, int high) {
    int i = low - 1, // smallestNumIndex
            j = low, pivot = arr[high];
    // check for partitioning from low to high - 1
    System.out.println("-----\n BEFORE arr = \n" + Arrays.toString(arr));
    for (; j < high; j++) {
      // TODO: think what will happen if we take only arr[j] < pivot
      if (arr[j] <= pivot) {
        i++;
        System.out.println("arr[" + i + "] = " + arr[i] + " |  arr[" + j + "] = " + arr[j]);
        // swap them
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
    // swap pivot with i + 1 because arr[i] will be the last element in the arr who is <= pivot
    arr[high] = arr[i + 1];
    arr[i + 1] = pivot;
    System.out.println("-----\n AFTER arr = \n" + Arrays.toString(arr));

    return i + 1;
  }
}