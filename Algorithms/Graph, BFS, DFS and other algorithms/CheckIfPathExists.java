package Algorithms.BFS_DFS;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Cell  {
  int i,j;
  Cell (int i, int j) {
    this.i = i;
    this.j = j;
  }
}
public class CheckIfPathExists {
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
      Find if the path Exist --> GFG
    */
    int n = sc.nextInt();
    int[][] grid = new int[n][n];
    boolean[][] visited = new boolean[n][n];
    Queue<Cell> q = new LinkedList<>();

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        grid[i][j] = sc.nextInt();
        if (grid[i][j] == 1) q.add(new Cell(i, j));
      }
    }

    while (!q.isEmpty()) {
      Cell currCell = q.poll();
      if (grid[currCell.i][currCell.j] == 2) {
        System.out.println("EXISTS :)");
        return;
      }
      visited[currCell.i][currCell.j] = true;
      // check for all the adjacent unvisited cells
      if (isSafe(currCell.i + 1, currCell.j, n, grid, visited)) q.add(new Cell(currCell.i + 1, currCell.j));
      if (isSafe(currCell.i - 1, currCell.j, n, grid, visited)) q.add(new Cell(currCell.i - 1, currCell.j));
      if (isSafe(currCell.i, currCell.j + 1, n, grid, visited)) q.add(new Cell(currCell.i, currCell.j + 1));
      if (isSafe(currCell.i, currCell.j - 1, n, grid, visited)) q.add(new Cell(currCell.i, currCell.j - 1));
    }
    System.out.println("DOES NOT EXISTS :(");
  }

  private static boolean isSafe (int i, int j, int n, int[][] grid, boolean[][] visited) {
    return  (i >= 0 && i < n) &&
            (j >= 0 && j < n) &&
            !visited[i][j] &&
            grid[i][j] != 0;
  }
}
