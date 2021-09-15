import javafx.util.Pair;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.lang.*;

public class solve {
  static BufferedReader br;

  public static void main(String[] args) throws IOException {
    int caseNo = 1;
    br = new BufferedReader(new InputStreamReader(System.in));
    int testCases = Integer.parseInt(br.readLine());         // scan first-word
    while (testCases > 0) {
      System.out.println("Testcase: " + caseNo++);
      justDoIt();
      testCases--;
      System.out.println("-------------");
    }
  }

  static void justDoIt() throws IOException {
     /*
    Trying to store Pair<Integer, Integer> as key in Hashset/Treeset
    */
    // =============== SOLVE ==============
    // =========== My try ============
//    int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer :: parseInt).toArray();
    int ans = 0;
    /*
    */
    // HashMap
    HashMap <Integer, HashMap <Integer, Integer>> hm = new HashMap<>();

    // check the reference thing
    createMap (hm, 3, 1, 32);
    createMap (hm, 5, 4, 54);
    createMap (hm, 3, 2, 360);
    createMap (hm, 4, 2, 33);
    createMap (hm, 5, 2, 40);
    System.out.println("hm = " + hm);
    int max = 2, min = 3;
    System.out.println("total  = " + hm.get(3).get(1));
//    System.out.println("Max sum is " + ans);
  }
  static void createMap( HashMap <Integer, HashMap <Integer, Integer>> hm, Integer max, Integer min, Integer total) {
    HashMap <Integer, Integer> in = new HashMap<>();
    // min, total
    in.put(min, total);
    hm.put(max, in);
  }
}