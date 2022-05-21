package Algorithms.Data_Structures.Array;

import javafx.util.Pair;

import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Scanner;

public class MergeKSortedArraysShorterBetterApproch {
  static Scanner sc;
  public static void main (String[] args) {
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
  // ==== SOLVE ==============
  static void justDoIt () {
    int k = sc.nextInt();
    int[][] arr = new int[k][k];

    for (int i = 0; i < k; i++)
      for (int j = 0; j < k; j++)
        arr[i][j] = sc.nextInt();

    System.out.println(mergeKArrays(arr, k));
  }
  //Function to merge k sorted arrays.
  public static ArrayList<Integer> mergeKArrays(int[][] arr,int K)
  {
    // Write your code here.
    ArrayList<Integer> ans = new ArrayList<>();

    // keep pointers to k list
    // a DS to store one elems from each of the list
    PriorityQueue<Pair<Integer, Pair<Integer, Integer>>> pq =
            new PriorityQueue<>(
                    (pair1, pair2) ->
                      pair1.getKey() - pair2.getKey());

    // start --> init
    for (int i = 0; i < K; i++) {
      pq.add(new Pair<>(arr[i][0], new Pair<>(i, 0)));
    }

    // keep on going till pq is empty
    while (!pq.isEmpty()) {
      Pair<Integer, Pair<Integer, Integer>> topNum = pq.poll();
      ans.add(topNum.getKey());

      int i = topNum.getValue().getKey();
      int j = topNum.getValue().getValue();

      // if the next num of that array exist
      if (++j < arr[i].length) {
        pq.add(new Pair<>(arr[i][j], new Pair<>(i, j)));
      }
    }
    return ans;
  }
}