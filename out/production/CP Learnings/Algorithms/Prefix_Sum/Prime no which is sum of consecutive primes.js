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
  Given an array of limits. For every limit, find the prime number which can be 
  written as the sum of the most consecutive primes smaller than or equal to limit.
  The maximum possible value of a limit is 10^4.

  Example: 

  Input  : arr[] = {10, 30}
  Output : 5, 17
  Explanation : There are two limit values 10 and 30.
  Below limit 10, 5 is sum of two consecutive primes,
  2 and 3. 5 is the prime number which is sum of largest 
  chain of consecutive below limit 10.

  Below limit 30, 17 is sum of four consecutive primes.
  2 + 3 + 5 + 7 = 17
  */
  // =============== SOLVE ==============
  // =========== My try ============
  let prefixSumArr = [],
    prefixSum = 0
  let arr = readline().split(' ').map(x => {
    x = +x
    prefixSum += x
    prefixSumArr.push(prefixSum)
    return x
  }),
   k = readline().split(' ').map(x => +x)

   if (prefixSum <= k) {
    console.log('size = ', arr.length)
    return
  } else if (Math.max(...arr) > k) {
    console.log('SIZE = ', -1)
    return
  }

  let maxReducibleSize = 1,
    subarraySumFront = prefixSum,
    subarraySumBack,
    i , j

  // reduce from front
  for (i=0; i<arr.length; i++) {
    subarraySumFront -= arr[i]
    if (subarraySumFront <= k) {
      break
    }
    maxReducibleSize++
  }
  // reduce from back
  subarraySumBack = prefixSumArr[arr.length - i - 1]
  for (j=arr.length-1-i; j >= 0 ; j--) {
    subarraySumBack -= arr[j]
    if (subarraySumBack <= k) {
      console.log('size = ', arr.length - maxReducibleSize)
      return
    }
    maxReducibleSize++
  }
  // Time Complexity: O(n)
}
/*
aRR 1 2 3 4  k = 8
PS  1 3 6 10
*/