import java.util.*;
import java.lang.*;

public class Largest_subarray_sum_modulo_m {
  static Scanner sc;
  public static void main (String[] args) {
    sc = new Scanner(System.in);
    int testCases = Integer.parseInt(sc.nextLine());         // scan first-word
    while (testCases > 0) {
      justDoIt();
      testCases--;
    }
  }
  static void justDoIt () {
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
    int n = Integer.parseInt(sc.nextLine()),
    temp = n;
    if (n == 1) {
      System.out.println(0);
      return;
    }
    ArrayList<Integer> list= new ArrayList<>(n);
    while (temp-- > 0)
      list.add(sc.nextInt());
    System.out.println(list);
    // two pointer method
    // first pointer
    System.out.println(printList(list));
  }

  static Boolean printList (ArrayList<Integer> list) {
    for (int i: list) {
      System.out.print(i + " ");
    }
    return false;
  }
}