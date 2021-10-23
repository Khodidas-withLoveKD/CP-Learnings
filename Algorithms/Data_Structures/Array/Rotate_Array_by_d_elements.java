package Algorithms.Data_Structures.Array;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Rotate_Array_by_d_elements {
  static Scanner sc;
  public static void main(String[] args) throws IOException {
    long startTime = System.currentTimeMillis();
    int caseNo = 1;
    sc = new Scanner(System.in);
    int testCases = sc.nextInt();
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
    Write a function rotate(ar[], d, n) that rotates arr[] of size n by d elements.
    arr = [1, 2, 3, 4, 5, 6] , d = 2
    ans: arr = [3, 4, 5, 6, 1, 2]
    Challenge: Do it with O(1) space
    ------------
    Input STYLE
    t testcases
    for each testcase
    n (no. of elements)
    [n0, n1, .... nn-1] elements
    d
    */
    // inputs
    int n = sc.nextInt();
    List<Integer> list = new ArrayList<>(n);
    for (int i = 0; i < n; i++) {
      list.add(sc.nextInt());
    }
    int d = sc.nextInt();

    // I can directly use Collections.reverse though by breaking the list. --> Takes O(n) space then
    // reverse the array till d elements
    reverse(0, d, list);
    System.out.println("list = " + list);
    // reverse the rest
    reverse(d, n, list);
    System.out.println("list = " + list);
    // reverse the entire list to get the ans
    reverse(0, n, list);
    System.out.println("list = " + list);
  }
  private static void reverse(int l, int r, List<Integer> list) {
    System.out.println("l = " + l);
    // swap elements from l to r - 1
    for (int i = l; i < ((r - l)/2) + l; i++) {
      int temp = list.get(i);
      int secondIndex = (r - 1) - i + l;
      list.set(i, list.get(secondIndex));
      list.set(secondIndex, temp);
    }
  }
}