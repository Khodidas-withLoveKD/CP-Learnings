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
    Write an efficient program to find the sum of contiguous subarray within 
    a one-dimensional array of numbers that has the largest sum.
    arr = [-2, -3, 4, -1, -2, 1, 5, -3]
                  |_______________|
                          | |
                          ans = 7
  */
  // =============== SOLVE ==============
  // =========== My try ============
  let  prefixSumArr = [0],
    prefixSum = 0,
    arr = readline().split(' ').map(x => {
      x = +x
      prefixSum += x
      prefixSumArr.push(prefixSum)
    }),
    // m = +(readline()), 
    maxSum = 0, modSum
  // make subarrays and check the ans (brute force)
  for (let i=prefixSumArr.length - 1; i >= 0; i-- ) {
    for (let j=0; j < i; j++) {
      // sum = 
      modSum = prefixSumArr[i] - prefixSumArr[j]
      // console.log('j:', j)
      // console.log('i:', i)
      // console.log('modSum:', modSum)
      maxSum = Math.max(modSum, maxSum)
    }
  }
  console.log('maxSum:', maxSum)
  // Time Complexity: O(n^2)
}
/*

*/