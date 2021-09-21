package Algorithms.Prefix_Sum;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Minimum_cost_for_acquiring_all_coins_with_k_extra_coins_allowed_with_every_coin_PrefixSum_Approach {
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
    n--> n = no. of coins
    [C1....Cn] --> array of n coins
    q queries
    (follows q no. of Ks)
    [k0, k1, ....., kq]
    */
    // inputs
    int n = sc.nextInt(),
            k, ans = 0;
    ArrayList<Integer> al = new ArrayList<>();
    for (int i=0; i<n; i++) {
      al.add(sc.nextInt());
    }
    // sort it
    Collections.sort(al);
    /* Approach 3
    We can take at most k+1 elements
    So, the ans would be sum of ceil(n / (k+1)) elements
    maintain a prefixSum of them
    */
    int prefixSum = 0;
    for (int i=0; i < n; i++) {
      prefixSum += al.get(i);
      al.set(i, prefixSum);
    }
    // for q queries
    int q = sc.nextInt();
    while (q > 0) {
      k = sc.nextInt();
      getAns(al, (int)Math.ceil((double)n / (k+1)));
      q--;
    }
  }
  static void getAns(ArrayList<Integer> al, int i) {
    System.out.println("ans = " + al.get(i - 1));
  }
}