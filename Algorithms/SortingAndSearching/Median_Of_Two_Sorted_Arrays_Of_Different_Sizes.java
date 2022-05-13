package Algorithms.SortingAndSearching;

import java.util.Scanner;

public class Median_Of_Two_Sorted_Arrays_Of_Different_Sizesa {
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

  private static float findMedianOfTwoSortedArrays(int[] arr1, int[] arr2, int n, int m) {
    /*
      Corner cases:
      1. Size of small array = 0
      -> Med = Med(larger arr)
      =======

      2. Size of small arr = 1
        2.1 Large Arr size  = 1
        --> Med = med(both)

        2.2 Large Arr size = even
        --> Med = med of three elem --> (m/2) - 1, m/2 and sm elem

        2.3 LAS = odd
        --> sm elem effects if only it lies between m/2 + 1 and m/2 - 1
        --> if present Med = MO4/ 2
      ==========

      3. sm size = 2
        3.1 lm size = 2
        --> MO4

        3.2 lm size odd
        --> MO3 (la mid, max (m/2 - 1, sm first), min (m/2 + 1, sm second)

        3.4 lm size even
        --> MO4 (la m/2 - 1, m/2, max(m/2 - 2, first sm), min (m/2 + 1, sec sm))
      ========

      The array size will reduce to min 2
      Let's code!!
    */
    int median = -1;

    int l1 = 0, h1 = n - 1,
            l2 = 0, h2 = m - 1;

    while (h1 - l1 > 2 && h2 - l2 > 2) {
      int size1 = h1 - l1 + 1;
      int size2 = h2 - l2 + 1;
      float m1 = getMedian(arr1, l1, h1, size1);
      float m2 = getMedian(arr2, l2, h2, size2);

      int medianIndex1 = size1/2 - 1;
      int medianIndex2 = size2/2 - 1;
      // if m1 < m2
      if (m1 < m2) {
        // discared firt half of arr1
        l1 = l1 + medianIndex1;
        // discard second half of arr2
        h2 = (size2 % 2 == 0) ? l2 + medianIndex2 + 1 : l2 + medianIndex2;
      } else {
        // discard the first half of arr2
        l2 = l2 + medianIndex2;
        h1 = (size1 % 2 == 0) ? l1 + medianIndex1 + 1 : l1 + medianIndex1;
      }
    }
    // breaks when one / both arr <= 2

    // case 1: sm = 0, l = ?
    int l, h;

    if (h1 - l1 == 0 || h2 - l2 == 0) {
      // med = median of large arr
      if (h1 - l1 != 0) {
        int size1 = h1 - l1 + 1;
        median = (size1 % 2 == 0) ?
                (arr1[size1/2 - 1] + arr1[size1/2])
                : arr1[size1/2];
      } else {
        int size2 = h2 - l2 + 1;
        median = (size2 % 2 == 0) ?
                (arr1[size2/2 - 1] + arr1[size2/2])
                : arr1[size2/2];
      }
    }

    // case 2: sm = 1
    // 2.1 l = 1
    if (h1 - l1 == 1 && h2 - l2 == 1) {
      // med of both
      median = (arr1[0] + arr2[0]) / 2;
    }
    // 2.2 l = even
    return median;
  }

  private static float getMedian(int[] arr, int low, int high, int size) {
    // check for size
    float median;
    if (size % 2 == 0) {
      median = (float)((arr[size - 1] + arr[size])/2.0);
    } else {
      median = (float)(arr[size/2]);
    }
    return median;
  }

}