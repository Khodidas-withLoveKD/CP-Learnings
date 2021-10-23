package Algorithms.Java_Specific;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Reverse_Sort_and_Lambda_expression {
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
    1. Sorting a collection in descending order
    2. Lambda functions
    ------------
    Input STYLE
    t testcases
    for each testcase
    n (no. of elements)
    [n0, n1, .... nn-1] elements
    */
    // inputs
    int n = sc.nextInt();
    List<Integer> list = new ArrayList<>();
    List<Integer> temp, lambdaSort;

    for (int i = 0; i < n; i++) {
      list.add(sc.nextInt());
    }
    temp = new ArrayList<>(list);
    lambdaSort  = new ArrayList<>(list);
    // sort ascending
    Collections.sort(temp);
    System.out.println("Ascending list = " + temp);

    // sort descending
    list.sort(Collections.reverseOrder()); // OR Collections.sort(list, Collections.reverseOrder())
    System.out.println("Descending list = " + list);

    // ===== Lambda Expressions ======
    System.out.println("Printing list via lambda");
    list.forEach(num -> System.out.println(num));

    // sorting list via lambda
    Collections.sort(lambdaSort,
            (n1, n2) -> { return n1.compareTo(n2);} );
    System.out.println("lambdaSort = " + lambdaSort);
  }
}