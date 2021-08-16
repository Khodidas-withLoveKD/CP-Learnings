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
  /*
    There will be 3 cases (types of input):
    1. All positive
    2. Both +ve and -ve
    3. All negative

    #1 is quite straight-forward. The entire array sum is ans
    #2 will use kadane's algorithm (learnt from gfg)
    #3 little complex --> let's see
  */
  // ============ Handling all cases =========
  let arr = readline().split(' ').map(x => +x),
  maxSoFar = Number.MIN_SAFE_INTEGER,currSum = 0

  // traverse the array
  arr.forEach( num => {
    // There are two things that can happen
    // Either it will be an addition to my sum
    // or it will be the starting of the array with max sum if it > the current prefixSum
    // choose the maximum
    currSum = Math.max(currSum + num, num)
    // which is maximum, currSum or max Sum found earlier?
    maxSoFar = Math.max(currSum, maxSoFar)
  })
  console.log('ans = ', maxSoFar)
  /*
  // ======== handling (just) case #3 =========
  let arr = readline().split(' ').map(x => +x),
    maxSoFar = Number.MIN_SAFE_INTEGER, prefixSum = 0
  
  // this is very stupid
  maxSoFar = Math.max(...arr)
  console.log('ans = ', maxSoFar)
  */
  /*
  // ============ Kadane's algorithm =========
  let arr = readline().split(' ').map(x => +x),
    maxSoFar = 0,prefixSum = 0
  
  // traverse the array
  arr.forEach( num => {
    prefixSum += num
    if (prefixSum < 0) {
      prefixSum = 0
    } else if (prefixSum > maxSoFar) {
      maxSoFar = prefixSum
    }
  })
  console.log('ans = ', maxSoFar)
  */
  /*
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
  */
}
/*

*/