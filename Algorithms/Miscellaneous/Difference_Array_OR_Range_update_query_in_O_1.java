package Algorithms.Miscellaneous;

import java.io.IOException;
import java.util.Scanner;

public class Difference_Array_OR_Range_update_query_in_O_1 {
  static Scanner sc;
  public static void main(String[] args) throws IOException {
    long startTime = System.currentTimeMillis();
    int caseNo = 1;
    sc = new Scanner(System.in);
    int testCases = sc.nextInt();         // scan first-word
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
    Consider an array A[] of integers and following two types of queries.

    update(l, r, x) : Adds x to all values from A[l] to A[r] (both inclusive).
    printArray() : Prints the current modified array.
    Examples :

    Input : A [] { 10, 5, 20, 40 }
            update(0, 1, 10)
            printArray()
            update(1, 3, 20)
            update(2, 2, 30)
            printArray()
    Output : 20 15 20 40
             20 35 70 60
    Explanation : The query update(0, 1, 10)
    adds 10 to A[0] and A[1]. After update,
    A[] becomes {20, 15, 20, 40}
    Query update(1, 3, 20) adds 20 to A[1],
    A[2] and A[3]. After update, A[] becomes
    {20, 35, 40, 60}.
    Query update(2, 2, 30) adds 30 to A[2].
    After update, A[] becomes {20, 35, 70, 60}.
    ------------
    Input STYLE
    t testcases
    for each testcase
    n (no. of elements)
    [n0, n1, .... nn-1] elements
    q (queries)
    1 - update (followed by l, r, val) | 0 - printArray
    */
    // inputs
    int n = sc.nextInt();
//    List<Integer> list = new ArrayList<>();
    int[] arr = new int[n];
    int[] increment = new int[n];
    for (int i = 0; i < n; i++) {
      arr[i] = sc.nextInt();
    }
    int queries = sc.nextInt();

    while (queries > 0) {
      int queryChoice = sc.nextInt();
      if (queryChoice == 1) {
        updateArray(n, increment);
      } else {
        printUpdatedArray(n, arr, increment);
      }
      queries--;
    }
  }

  private static void printUpdatedArray(int n, int[] arr, int[] increment) {
    int overallSum = 0;
    for (int i = 0; i < n; i++) {
      overallSum += increment[i];
      System.out.print((arr[i] + overallSum) + " ");
    }
    System.out.println();
  }

  private static void updateArray(int n, int[] increment) {
    int l = sc.nextInt(),
        r = sc.nextInt(),
        val = sc.nextInt();
    increment[l] += val;
    if (r + 1 < n) {
      increment[r + 1] -= val;
    }
  }
}