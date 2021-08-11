'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });
    
    main()   
});

function readline() {
    return inputString[currentLine++]
}

// Make a Snippet for the code above this and then write your logic in main();
function main () {
  console.time('Execution Time')
  let testCases = readline()
  while (testCases--) {
    solve()
  }
  console.log('=========')
  console.timeEnd('Execution Time');
}

function solve () {
  /*
  Given two binary arrays, arr1[] and arr2[] of the same size n. 
  Find the length of the longest common span (i, j) where j >= i 
  such that arr1[i] + arr1[i+1] + …. + arr1[j] = arr2[i] + arr2[i+1] + …. + arr2[j].
  The expected time complexity is Θ(n).

  Examples:  

  Input: arr1[] = {0, 1, 0, 0, 0, 0};
        arr2[] = {1, 0, 1, 0, 0, 1};
  Output: 4
  The longest span with same sum is from index 1 to 4.

  Input: arr1[] = {0, 1, 0, 1, 1, 1, 1};
        arr2[] = {1, 1, 1, 1, 1, 0, 1};
  Output: 6
  The longest span with same sum is from index 1 to 6.

  Input: arr1[] = {0, 0, 0};
        arr2[] = {1, 1, 1};
  Output: 0

  Input: arr1[] = {0, 0, 1, 0};
        arr2[] = {1, 1, 1, 1};
  Output: 1 
  */
  // =============== SOLVE ==============
  // =========== My try ============
  let  arr1 = readline().split(' ').map(x => +x),
    arr2 = readline().split(' ').map(x => +x),
    n = arr1.length,
    // create auxiliary (helper) array of size 2n+1
    // because diff in prefixSum can go from -n to n
    diffArray = [...Array(2 * arr1.length + 1).keys()].map(x => -1),
    prefixSum1 = 0, prefixSum2 = 0, curr_diff, maxLen = 0 
    
  // get prefixSum of arrays and
  // keep marking the diff of prefixSums
  for (let i=0; i < arr1.length; i++) {
    prefixSum1 += arr1[i]
    prefixSum2 += arr2[i]
    curr_diff = prefixSum1 - prefixSum2
    // if curr_diff == 0 then
    // the prefixSums till that point are same
    // so maxLen = i + 1
    if (!curr_diff) maxLen = i + 1
    // if curr_diff is found for first time
    else if (diffArray[n + curr_diff] == -1) {
      // mark it in diffArray
      diffArray[n + curr_diff] = i
    } else { // if curr_diff is already present
      // get the sum span
      maxLen = Math.max(maxLen, i - diffArray[n + curr_diff])
    }
  }
  console.log('maxLen = ', maxLen)
}
/*

*/