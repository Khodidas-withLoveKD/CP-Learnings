package Algorithms.Data_Structures.Map;

import java.io.IOException;
import java.util.*;

public class Sort_Map_by_key_and_value {
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
    Sorting Map by value
    ------------
    Input STYLE
    t testcases
    for each testcase
    n (no. of elements)
    [n0, n1, .... nn-1] elements
    */
    // inputs
    int n = sc.nextInt();
    Map<Integer, Integer> map = new HashMap<>();
    for (int i = 0; i < n; i++) {
      map.put(sc.nextInt(), sc.nextInt());
    }

    System.out.println("Map without sorting:\n" + map);
    sortMapByKey(map);
    System.out.println("\n==============\nMap without sorting:\n" + map);
    sortMapByValue(map);
  }

  private static void sortMapByKey(Map<Integer, Integer> map){
    // make it list
    List<Map.Entry<Integer, Integer>> list = new ArrayList<>(map.entrySet());
    System.out.println("BEFORE SORT LIST: \n" + list);
    // sort list using Collections.sort and lambda functions
    Collections.sort(list,
            (entry1, entry2) ->
                (entry1.getKey().compareTo(entry2.getKey())
            ));
    Map<Integer, Integer> sortedMap = new LinkedHashMap<>();
    System.out.println("AFTER SORT LIST: \n" + list);
    for (Map.Entry<Integer, Integer> entry: list) {
      sortedMap.put(entry.getKey(), entry.getValue());
    }
    System.out.println("Ascending sortedMap: \n" + sortedMap);

    // sort in descending
    /* Reverse the list
      OR
      Do -1 * (entry1.getKey().compareTo(entry2.getKey())
     */
    Map<Integer, Integer> descendingSortedMap = new LinkedHashMap<>();
    Collections.reverse(list);
    for (Map.Entry<Integer, Integer> entry: list) {
      descendingSortedMap.put(entry.getKey(), entry.getValue());
    }
    System.out.println("descendingSortedMap: \n" + descendingSortedMap);
  }
  private static void sortMapByValue(Map<Integer, Integer> map) {
    List<Map.Entry<Integer, Integer>> list = new ArrayList<>(map.entrySet());
    Collections.sort(list,
            (entry1, entry2) ->
              -1 * entry1.getValue().compareTo(entry2.getValue())   // Note the change here
            );
    Map<Integer, Integer> ascendingSortedMap = new LinkedHashMap<>();
    Map<Integer, Integer> descendingSortedMap = new LinkedHashMap<>();
    for (Map.Entry<Integer, Integer> entry: list) {
      descendingSortedMap.put(entry.getKey(), entry.getValue());
    }
    System.out.println("descendingSortedMap:\n " + descendingSortedMap);

    Collections.reverse(list);
    for (Map.Entry<Integer, Integer> entry: list) {
      ascendingSortedMap.put(entry.getKey(), entry.getValue());
    }
    System.out.println("ascendingSortedMap:\n " + ascendingSortedMap);
  }
}