package Algorithms.Prefix_Sum;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.TreeSet;

public class Largest_subarray_sum_modulo_m {
  static BufferedReader br;

  public static void main(String[] args) throws IOException {
    int caseNo = 1;
    br = new BufferedReader(new InputStreamReader(System.in));
    int testCases = Integer.parseInt(br.readLine());         // scan first-word
    while (testCases > 0) {
      System.out.println("Testcase: " + caseNo++);
      justDoIt();
      testCases--;
      System.out.println("-------------");
    }
  }

  static void justDoIt() throws IOException {
     /*
    Given an array of n elements and an integer m. The task is to find the maximum
    value of the sum of its subarray modulo m i.e find the sum of each
    subarray mod m and print the maximum value of this modulo operation.
    Examples:

    Input : arr[] = { 3, 3, 9, 9, 5 }
            m = 7
    Output : 6
    All sub-arrays and their value:
    { 9 } => 9%7 = 2
    { 3 } => 3%7 = 3
    { 5 } => 5%7 = 5
    { 9, 5 } => 14%7 = 2
    { 9, 9 } => 18%7 = 4
    { 3, 9 } => 12%7 = 5
    { 3, 3 } => 6%7 =
    { 3, 9, 9 } => 21%7 = 0
    { 3, 3, 9 } => 15%7 = 1
    { 9, 9, 5 } => 23%7 = 2
    { 3, 3, 9, 9 } => 24%7 = 3
    { 3, 9, 9, 5 } => 26%7 = 5
    { 3, 3, 9, 9, 5 } => 29%7 = 1

    Input : arr[] = {10, 7, 18}
            m = 13
    Output : 12
    The subarray {7, 18} has maximum sub-array
    sum modulo 13.
    */
    // =============== SOLVE ==============
    // =========== My try ============
    int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer :: parseInt).toArray();
    int prefixSum = 0,
            m = Integer.parseInt(br.readLine()),
            ans = 0;
    /*
      prefixSumArr is as the name suggest
      first thing,
      (a + m) % m = a % m
      because (a + m) % m = a % m + m % m = a % m + 0
      Also, it is very evident that the ans is when
      a given range has sum such that, sum % m = m - 1 or closer to it
      --------
      Let's say the ans lies in tha range i to j
      so, (prefixSumArr[j] - prefixSumArr[i]) % m = ans
      but as prefixSumArr[i] > prefixSumArr[j] the ans can be negative.
      But as we know the diff cannot be greater than m - 1
      So, (prefixSumArr[j] - prefixSumArr[i] + m) % m = ans
      --------
      Now, it is quite evident that (prefixSumArr[j] - prefixSumArr[i] + m) % m must be m - 1 or closer to it
      OR
      prefixSumArr[j] - prefixSumArr[i] + m should be maximum
      OR
      prefixSumArr[j] - prefixSumArr[i] should be <= -1,
      the closer the better
      So, prefixSumArr[i] (should be) > prefixSumArr[j] and diff should be as small as possible
    */
    // a DS to implement above condition
    TreeSet<Integer> ts = new TreeSet<>(); // Hashset can also be used, but is difficult to get the just higher element
    Integer elem = 0;
    // get prefixSum
    for (int num : arr) {
      prefixSum += num;
      prefixSum %= m;
      ts.add(prefixSum);
      // get the closest element greater than prefixSum
      elem = ts.higher(prefixSum);
      // if not found, range is 0 to i
      if (elem == null) {
        elem = 0;
      }
      // (prefixSumArr[j] - prefixSumArr[i] + m) % m
      elem = (prefixSum - elem + m) % m;
      ans = Integer.max(elem, ans);
      // sum can never be larger than m - 1
      // so if found it
      if (ans == m-1) break;
    }
    System.out.println("Max sum is " + ans);
  }
}