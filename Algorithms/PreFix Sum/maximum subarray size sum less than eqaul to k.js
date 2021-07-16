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
  Given an array of n positive integers and a positive integer k, the task is to find 
  the maximum subarray size such that all subarrays of that size have the sum of 
  elements less than or equals to k.

  Examples : 

  Input :  arr[] = {1, 2, 3, 4} and k = 8.
  Output : 2
  Sum of subarrays of size 1: 1, 2, 3, 4.
  Sum of subarrays of size 2: 3, 5, 7.
  Sum of subarrays of size 3: 6, 9.
  Sum of subarrays of size 4: 10.
  So, maximum subarray size such that all subarrays of that size have the sum of elements less than 8 is 2.

  Input :  arr[] = {1, 2, 10, 4} and k = 8.
  Output : -1
  There is an array element with value greater than k, so subarray sum cannot be less than k.

  Input :  arr[] = {1, 2, 10, 4} and K = 14
  Output : 2
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