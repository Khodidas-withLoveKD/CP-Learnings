import javafx.util.Pair;

import java.util.*;
import java.lang.*;

public class solve {
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
    PriorityQueue<Integer> pq = new PriorityQueue<>();

    // keep track of the list from which the num is poped
    // 2 -> [1, 0]
    Map<Integer, List<Pair<Integer, Integer>>> indexMapper =
            new HashMap<>();

    // list index, num index of that list
    List<Pair<Integer, Integer>> tempList;
    // start --> init
    for (int i = 0; i < K; i++) {
      tempList = indexMapper.getOrDefault(arr[i][0],
              new ArrayList<>());

      tempList.add(new Pair<>(i, 0));
      indexMapper.put(arr[i][0], tempList);
      pq.add(arr[i][0]);
    }

    // keep on going till pq is empty
    while (!pq.isEmpty()) {
      int numToBeAdded = pq.poll();
      ans.add(numToBeAdded);
      // get that num from iM and add proper nums
      // get the list of that index
      tempList = indexMapper.get(numToBeAdded);
      // 2 -> [<1,0>]
      Pair<Integer, Integer> pair = tempList.remove(0);
      int listIndex = pair.getKey(); // 1
      int numIndexInList = pair.getValue(); // 0

      // update the old list
      if (tempList.size() > 0) {
        indexMapper.put(numToBeAdded, tempList);
      } else {
        indexMapper.remove(numToBeAdded);
      }

      // add the next num in list
      if (++numIndexInList < K) { // 1
        int newNumToBeAdded = arr[listIndex][numIndexInList];
        // add that num in list
        tempList = indexMapper.getOrDefault(newNumToBeAdded,
                new ArrayList<>());
        tempList.add(new Pair<>(listIndex, numIndexInList)); // <1, 1>
        // add the list to indexMapper
        indexMapper.put(newNumToBeAdded, tempList); // 2 -> [<1,1>]
        // add that num in pq
        pq.add(newNumToBeAdded); //arr[1][1] = 2
      }
    }
    return ans;
  }

}