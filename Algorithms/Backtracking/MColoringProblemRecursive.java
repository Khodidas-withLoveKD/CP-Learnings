package Algorithms.Backtracking;

import java.util.Arrays;
import java.util.Scanner;

public class MColoringProblemRecursive {
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
    Bipartite Graph - recursive
    */

    // Approach
    // assign color to a node and move further
    // if it works fine go ahead
    // else backtrack and try another color

        /* Create following graph and
           test whether it is
           3 colorable
          (3)---(2)
           |   / |
           |  /  |
           | /   |
          (0)---(1)
        */
    int graph[][] = {
            { 0, 1, 1, 1 },
            { 1, 0, 1, 0 },
            { 1, 1, 0, 1 },
            { 1, 0, 1, 0 },
    };
    int m = 3; // Number of colors

    bipartiteIt(graph, m, 4);
  }

  private static void bipartiteIt (int[][] graph, int m, int n) {
    // start from zero
    int[] color = new int[n];
//    color[0] = 1;
    if (!graphColorUtil(0, graph, color, m, n)) {
      System.out.println("Solution does not exist");
    } else {
      System.out.println("Solution exists :)");
      System.out.println(Arrays.toString(color));
    }
  }

  private static boolean graphColorUtil (int v, int[][] graph, int[] color, int m, int n) {
    if (v == n) return true;

    for (int c = 1; c <= m; c++) {
      color[v] = c;

      if (isSafe(v, graph, color, n)) {
        graphColorUtil(v + 1, graph, color, m, n);
        return true;
      }

      // revert the change
      color[v] = 0;
    }
    return false;
  }

  private static boolean isSafe (int v, int[][] graph, int[] color, int n) {
    for (int i = 0; i < n; i++) {
      // if the adj vertex is traversed has the same color then return false
      if (graph[v][i] > 0 && color[v] == color[i]) {
        return false;
      }
    }
    return true;
  }
}
