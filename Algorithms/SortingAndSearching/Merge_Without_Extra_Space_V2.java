import java.io.IOException;
import java.util.*;
import java.lang.*;

public class solve {
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

    // The goal is to place elements at their correct places
    // So, by observation the if the element in arr1 is larger than arr2's element
    // then it has to be replaced with the current largest element of arr1
    int index1 = 0,
        index2 = 0,
        greatestElementIndex = n - 1;
    while (index1 <= greatestElementIndex && index2 < m) {
      // if below condition the elem is in its correct array
      if (arr1[index1] < arr2[index2]) index1++;
      else {
        // place the element in its correct array
        int temp = arr1[greatestElementIndex];
        arr1[greatestElementIndex] = arr2[index2];
        arr2[index2] = temp;
        greatestElementIndex--;
        index2++;
      }
    }
    // the elem will be in their correct arrays but unsorted
    // so
    System.out.println("------- BEFORE SORT ----\narr1 = " + Arrays.toString(arr1));
    System.out.println("arr2 = " + Arrays.toString(arr2));
    Arrays.sort(arr1);
    Arrays.sort(arr2);
  }
}