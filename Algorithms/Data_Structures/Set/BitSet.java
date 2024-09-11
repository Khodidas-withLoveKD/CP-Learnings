package Algorithms.Data_Structures;

import java.util.Scanner;

public class BitSet {
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
    /*
      Bitset
    */

    java.util.BitSet bs1 = new java.util.BitSet();
    java.util.BitSet bs2 = new java.util.BitSet();

    bs1.set(3);
    System.out.println(bs1.get(5));
    System.out.println(bs1.cardinality());
    System.out.println("bs1.length() = " + bs1.length());

    bs2.set(2);
    System.out.println("BEFORE use of XOR bs2 = = " + bs2);

    bs2.xor(bs1);
    System.out.println("After use of XOR bs2 = = " + bs2);

    bs1.set(7);
    bs1.set(1);
    bs1.set(2);
    bs1.set(4);
    bs1.set(3);
    bs1.set(6);

    // assign values to bs2
    bs2.set(4);
    bs2.set(6);
    bs2.set(3);
    bs2.set(9);
    bs2.set(2);

    java.util.BitSet bs3 = (java.util.BitSet) bs1.clone();
    System.out.println("\n====\nNEW bs1 = " + bs1);
    System.out.println("NEW bs2 = " + bs2);
    System.out.println("Before AND bs1 = " + bs1);
    bs1.and(bs2);
    System.out.println("AFTER AND bs1 = " + bs1);

    System.out.println("====\nBefore NAND bs1 = " + bs3);
    bs3.andNot(bs2);
    System.out.println("AFTER NAND bs1 = " + bs3);

    System.out.println("====\nUse of get on b2 = " + bs2.get(1,7));
    System.out.println("====\nUse of get on b2 = " + bs2.get(1));
    System.out.println("====\nUse of get on b2 = " + bs2.get(4));

    System.out.println("====\nBEFORE FLIP b2 = " + bs2);
    bs2.flip(1,7);
    System.out.println("AFTER FLIP b2 = " + bs2);

    System.out.println("====\nBEFORE INTERSECT b2 = " + bs2);
    System.out.println("BEFORE INTERSECT bs1 = " + bs1);
    System.out.println("bs1.intersects(bs2) = " + bs1.intersects(bs2));

    System.out.println("BEFORE INTERSECT bs1 = " + bs1);
    java.util.BitSet bs4 = new java.util.BitSet();
    bs4.set(1);
    bs4.set(3);
    bs4.set(5);
    System.out.println("bs1.intersects(bs4) = " + bs1.intersects(bs4));
    System.out.println("bs4.intersects(bs1) = " + bs4.intersects(bs1));

    System.out.println("===\nbs4.equals(bs1) = " + bs4.equals(bs1));
    java.util.BitSet bs5 = (java.util.BitSet) bs4.clone();
    System.out.println("===\nbs4.equals(bs5) = " + bs4.equals(bs5));

  }
}
