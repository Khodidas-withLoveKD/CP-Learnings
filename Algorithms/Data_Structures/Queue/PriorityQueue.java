package Algorithms.Data_Structures.Queue;

import java.io.IOException;
import java.util.Iterator;
import java.util.*;

public class PriorityQueue {
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
    PriorityQueue Demo
    */
    java.util.PriorityQueue<Integer> pq = new java.util.PriorityQueue<>();
    pq.add(1);
    pq.add(8);
    pq.add(2);
    pq.add(4);
    pq.add(3);
    pq.add(7);
    pq.add(10);
    pq.add(1);

    System.out.println("pq = " + pq);
    System.out.println(pq.peek());
    System.out.println(pq.poll());
    System.out.println(pq.peek());
    System.out.println(pq.poll());
    System.out.println(pq.poll());
    System.out.println(pq.poll());

    printPQ(pq);
    Collections.reverse(pq);
  }
  private static void printPQ (java.util.PriorityQueue<Integer> pq) {
    for (Integer element : pq) {
      System.out.println(" elem = " + element);
    }
    Iterator it = pq.iterator();
    System.out.println("Via Iterator");
    while(it.hasNext()) {
      System.out.println(" it elem = " + it.next());
    }
  }
}