package Algorithms.Prefix_Sum;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Minimum_cost_for_acquiring_all_coins_with_k_extra_coins_allowed_with_every_coin {
  static Scanner sc;
  public static void main(String[] args) throws IOException {
    int caseNo = 1;
    sc = new Scanner(System.in);
    int testCases = sc.nextInt();         // scan first-word
    while (testCases > 0) {
      System.out.println("Testcase: " + caseNo++);
      justDoIt();
      testCases--;
      System.out.println("-------------");
    }
  }

  static void justDoIt() {
     /*
    You are given a list of N coins of different denominations.
    You can pay an amount equivalent to any 1 coin and can acquire that coin.
    In addition, once you have paid for a coin, we can choose at most K more coins and can acquire those for free.
    The task is to find the minimum amount required to acquire all the N coins for a given value of K.

    Examples :

    Input : coin[] = {100, 20, 50, 10, 2, 5},
            k = 3
    Output : 7

    Input : coin[] = {1, 2, 5, 10, 20, 50},
            k = 3
    Output : 3
    Input STYLE
    t testcases
    n k --> n = no. of coins
    [C1....Cn] --> array of n coins
    */
    // inputs
    int n = sc.nextInt(),
            k = sc.nextInt(), ans = 0;
    ArrayList<Integer> al = new ArrayList<>();
    for (int i=0; i<n; i++) {
      al.add(sc.nextInt());
    }
    // sort it
    Collections.sort(al);
    // take the minimum till al is not empty
    while (al.size() > 0) {
      // take out the min most
      ans += al.remove(0);
      // remove last k elements
      for (int i=0; i<k && al.size() > 0; i++) {
        al.remove(al.size() - 1);
      }
    }
    System.out.println("ans = " + ans);
  }
}