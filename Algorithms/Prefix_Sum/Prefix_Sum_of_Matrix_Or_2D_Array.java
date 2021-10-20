package Algorithms.Prefix_Sum;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Prefix_Sum_of_Matrix_Or_2D_Array {
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
    Given a matrix (or 2D array) a[][] of integers, find prefix sum matrix for it.
    Let prefix sum matrix be psa[][]. The value of psa[i][j] contains sum of all values which are
    above it or on left of it.
    ------------
    Input STYLE
    t testcases
    for each testcase
    r c
    r --> r = no. of rows
    c --> c = no. of columns
    n = number
    array:
    [[ n00 n01 n02 .... n0c]
     [ n10 n11 .... n1c]
     .              .
     .              .
     [ nr0 ...... nrc]]
    */
    // inputs
    int r = sc.nextInt(),
        c = sc.nextInt(),
        prefixSum = 0;
    List<List<Integer>> al = new ArrayList<>();
    List<List<Integer>> ans = new ArrayList<>();
    List<Integer> li, ansList;
    // dummy row
    ansList = new ArrayList<>();
    for (int i=0; i < c; i++) {
      ansList.add(0);
    }
    ans.add(ansList);
    int num;
    for (int i=0; i<r; i++) {
      li = new ArrayList<>();
      ansList = new ArrayList<>();
      prefixSum = 0;

      for (int j=0; j < c; j++) {
        num = sc.nextInt();
        prefixSum += num;
        li.add(num);
        ansList.add(prefixSum + ans.get(i).get(j));
      }

      al.add(li);
      ans.add(ansList);
    }
    // remove first row in ans
    System.out.println("al = " + al);
    System.out.println("ans = " + ans);
  }
  static void getAns(ArrayList<Integer> al, int i) {
    System.out.println("ans = " + al.get(i - 1));
  }
}