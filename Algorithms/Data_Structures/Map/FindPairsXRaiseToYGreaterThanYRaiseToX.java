package Algorithms.Data_Structures.Map;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class FindPairsXRaiseToYGreaterThanYRaiseToX {
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
    int xL = sc.nextInt();
    int[] X = new int[xL];
    for (int i = 0; i < xL; i++) X[i] = sc.nextInt();

    int yL = sc.nextInt();
    int[] Y = new int[yL];
    for (int i = 0; i < yL; i++) Y[i] = sc.nextInt();


    System.out.println("pairs = " + countPairs(X, Y));
  }
  static long countPairs(int[] X, int[] Y) {
    // code here
    long ans = 0;
    // algo
    // if (x < y => cond satisfied) with some exceptions
    // exceptions
    // 1, (any num)
    // 2, 3 && 2, 4
    // 4, 5 && 4 ,6
//    int[] noOfExp = new int[4];
//    for (int x : X) {
//      if (x < 5) noOfExp[x - 1]++;
//    }
    // first sort y
    Arrays.sort(Y);

    Map<Integer, Integer> counts = new HashMap<>();

    for (int num : Y) {
      counts.put(num, counts.getOrDefault(num, 0) + 1);
    }
    System.out.println("counts = " + counts);
    System.out.println("Y = " + Arrays.toString(Y));
    System.out.println("-------------");
    // for each num in x
    for (int num : X) {
      ans += findPairsForNum(num, Y, counts);
    }

    return ans;
  }

  private static long findPairsForNum(int num, int[] arr, Map<Integer, Integer> counts) {
    System.out.println("========\nnum = " + num);
    if (num == 1) return 0;
    // find the index
    if (num >= arr[arr.length - 1]) {
      return counts.getOrDefault(1, 0);
    }
    int index = binarySearch(num, arr);
    System.out.println("BEFORE index = " + index);

    // this will give index of any of the upper_bound num in all poss
    // dups
    // go till last
    int minIndex = index, maxIndex = index;

//    while (minIndex - 1 > -1 && arr[minIndex - 1] >= num) minIndex--;
    // minIndex++
    System.out.println("minIndex = " + minIndex);

    while (maxIndex + 1 < arr.length && arr[maxIndex] == num) maxIndex++;
    System.out.println("maxIndex = " + maxIndex);

    index = Math.max(minIndex, maxIndex);

    System.out.println("AFTER index = " + index);
    // now we have a proper index;
    // for all no. of nums
    long ans = arr.length - index;

    System.out.println("FIRSt ans = " + ans);
    // negating exceptions
    if (num == 2) ans -= (counts.getOrDefault(3, 0) + counts.getOrDefault(4, 0));
    else if (num == 3) ans += counts.getOrDefault(2, 0);
//    else if (num == 4) ans -= counts.getOrDefault(5, 0);
    if (num > 1) ans += counts.getOrDefault(1, 0);

    System.out.println("second ans = " + ans);

    System.out.println("ans = " + ans);
    return ans;
  }

  private static int binarySearch(int num, int[] arr) {
    int l = 0, h = arr.length - 1,
            mid;

    // bs to get upperBound
    while (l < h) {
      System.out.println("l = " + l);
      System.out.println("h = " + h);
      mid = (l + h)/2;
      System.out.println("mid = " + mid);
      // if (arr[mid] == num && mid - 1 >= 0 && arr[mid - 1] > num) return mid;

      if (arr[mid] < num) l = mid + 1;
      else h = mid;
    }
    mid = (l + h) /2;
    return l + (arr[mid] > num ? 0 : 1);
  }
}
