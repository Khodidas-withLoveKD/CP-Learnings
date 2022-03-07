import java.io.IOException;
import java.util.*;
import java.lang.*;

public class solve {
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
    Given an array that is sorted and then rotated around an unknown point.
    Find if the array has a pair with a given sum x.
    It may be assumed that all elements in the array are distinct.

    Examples :
    Input: arr[] = {11, 15, 6, 8, 9, 10}, x = 16
    Output: true
    There is a pair (6, 10) with sum 16

    Input: arr[] = {11, 15, 26, 38, 9, 10}, x = 35
    Output: true
    There is a pair (26, 9) with sum 35

    Input: arr[] = {11, 15, 26, 38, 9, 10}, x = 45
    Output: false
    There is no pair with sum 45.
    ------------
    Input STYLE
    t testcases
    for each testcase
    n (no. of elements)
    [n0, n1, .... nn-1] elements
    sun
    */
    // inputs
    int n = sc.nextInt();
    List<Integer> list = new ArrayList<>(n);
    for (int i = 0; i < n; i++) {
      list.add(sc.nextInt());
    }
    int sum = sc.nextInt();

    // ===== APPROACH ======
    /*
    - Find Pivot
    - split the list in two halves
    - in one half find the num which is just lower than sum
    - find the diff = sum - num
    - check in which half the sum could lie
   */
    // find pivot
    int pivot = findPivot(list);

    int[] ans;
    ans = findAns(list, sum, pivot);
    if (ans[0] == -1) {
      System.out.println("KEY not found");
    } else {
      System.out.println("Pair found at index: " + ans[0] + " and " + ans[1]);
    }
  }
  private static int[] findAns(List<Integer> list, int sum, int pivot) {
    int[] ans = new int[2];
    ans[0] = -1;
    // It's nums complement must exist in either of the list
    // else no such pair possible
    // split the list from pivot
    // get the bigger list --> Won't work
//    if (pivot < list.size()/2) {
      // take the left list as main list
      for (int i = pivot - 1; i >= 0; i--) {
        if (list.get(i) < sum) {
          int diff = sum - list.get(i);
          int diffIndex = binarySearch(list, pivot, list.size() - 1, diff);
          if (diffIndex == -1) {
            // search in the same half as well
            diffIndex = binarySearch(list, 0, pivot - 1, diff);
          }
          if (diffIndex != -1) {
            // ans found
            ans[0] = i;
            ans[1] = diffIndex;
            break;
//            return ans;
          }
        }
        // else continue on another num
      }
//    } else {
      // take the right list as main list
      for (int i = pivot; i < list.size() - 1; i++) {
        if (list.get(i) < sum) {
          int diff = sum - list.get(i);
          int diffIndex = binarySearch(list, 0, pivot - 1, diff);
          if (diffIndex == -1) {
            // search in the same half as well
            diffIndex = binarySearch(list, pivot, list.size() - 1, diff);
          }
          if (diffIndex != -1) {
            // ans found
            ans[0] = i;
            ans[1] = diffIndex;
            break;
          }
        }
      }
    return ans;
  }
  // passing list everyTime will create a memory overhead. So, passing l and r as instead
  private static int binarySearch(List<Integer> list, int l, int r, int key) {
    while (r >= l) {
      int m = l + (r - l)/2 ;
      if (key == list.get(m)) return m;
      if (key < list.get(m)) {
        // move to left
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return -1;
  }
  private static int findPivot(List<Integer> list) {
    int l = 0,
        r = list.size() - 1,
        m;
    // find the pivot with a binary search approach
    while (r - l > 0) {
      m = l + (r - l)/2;
      // termination
      if (r - l == 1) return r;

      int left = list.get(l),
          right = list.get(r),
          mid = list.get(m);
      // else
      // move to the half which is not sorted
      if (left > mid) {
        r = m;
      } else if (mid > right){
        l = m;
      }
    }
    return -1;
  }
}