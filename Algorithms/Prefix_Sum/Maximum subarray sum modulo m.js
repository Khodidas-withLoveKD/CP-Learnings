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
  Given an array of n elements and an integer m. The task is to find the maximum 
  value of the sum of its subarray modulo m i.e find the sum of each 
  subarray mod m and print the maximum value of this modulo operation.
  Examples: 
  
  Input : arr[] = { 3, 3, 9, 9, 5 }
          m = 7
  Output : 6
  All sub-arrays and their value:
  { 9 } => 9%7 = 2
  { 3 } => 3%7 = 3
  { 5 } => 5%7 = 5
  { 9, 5 } => 14%7 = 2
  { 9, 9 } => 18%7 = 4
  { 3, 9 } => 12%7 = 5
  { 3, 3 } => 6%7 = 6
  { 3, 9, 9 } => 21%7 = 0
  { 3, 3, 9 } => 15%7 = 1
  { 9, 9, 5 } => 23%7 = 2
  { 3, 3, 9, 9 } => 24%7 = 3
  { 3, 9, 9, 5 } => 26%7 = 5
  { 3, 3, 9, 9, 5 } => 29%7 = 1

  Input : arr[] = {10, 7, 18}
          m = 13
  Output : 12
  The subarray {7, 18} has maximum sub-array
  sum modulo 13.
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
    m = +(readline()), maxSum = 0, modSum

  // make subarrays and check the ans (brute force)
  for (let i=prefixSumArr.length - 1; i >= 0; i-- ) {
    for (let j=0; j < i; j++) {
      // sum = 
      modSum = (prefixSumArr[i] - prefixSumArr[j]) % m
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