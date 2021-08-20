package Algorithms.Data_Structures.Set.Implementation;

import java.util.Iterator;
import java.util.Scanner;
import java.util.SortedSet;

public class TreeSet {
  static Scanner sc;

  public static void main(String[] args) {
    sc = new Scanner(System.in);
    int testCases = Integer.parseInt(sc.nextLine());         // scan first-word
    while (testCases > 0) {
      justDoIt();
      testCases--;
    }
  }

  static void justDoIt() {
    /*
    Implement SortedSet via TreeSet
    */
    // =============== SOLVE ==============
    // =========== My try ============
    SortedSet<String> ts = new java.util.TreeSet<>();
    // add elements
    ts.add("KD");
    ts.add("Loves");
    ts.add("Himself");
    ts.add("Maybe you");
    // insertion order not maintained, sorted in ascending order
    System.out.println("TreeSet = " + ts);
    // inserting duplicate
    ts.add("KD");
    ts.add("KD2");
    System.out.println("TreeSet:\n" + ts);
    ts.remove("Maybe you");
    // Iterate
    Iterator<String> it = ts.iterator();
    while (it.hasNext()) {
      System.out.println(it.next());
    }
    // check if a value exist
    System.out.println("Ts has A ? --> " + ts.contains("A"));
    System.out.println("Ts has KD ? --> " + ts.contains("KD"));
    // first and last element
    System.out.println("First = " + ts.first());
    System.out.println("Last = " + ts.last());
    // iterating through enhanced for loop
    for (String val : ts) {
      System.out.println("val = " + val);
    }
  }
}