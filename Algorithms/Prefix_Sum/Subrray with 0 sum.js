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
  Given an array of positive and negative numbers, find if there is a subarray (of size at-least one) with 0 sum.

  Examples :

  Input: {4, 2, -3, 1, 6}
  Output: true 
  Explanation:
  There is a subarray with zero sum from index 1 to 3.

  Input: {4, 2, 0, 1, 6}
  Output: true 
  Explanation:
  There is a subarray with zero sum from index 2 to 2.

  Input: {-3, 2, 3, 1, 6}
  Output: false
  Extend the above program to print starting and ending indexes
  of all subarrays with 0 sum.
  3
  4 2 -3 1 6
  1 -1 1 -1 0 0 0
  4 2 0 1 6
  -3 2 3 1 6
  */
  // =============== SOLVE ==============
  // =========== Method 1 ============
  let prefixSumArr = [],
    prefixSum = 0
  let mp = new Map()
  let arr = readline().split(' ').map(x => {
    x = +x
    prefixSum += x
    prefixSumArr.push(prefixSum)
    return x
  }), 
  flag = false
  mp.set(0, [-1])
  for (let i=0; i<arr.length; i++) {
    if (mp.has(prefixSumArr[i])) {
      if (!flag) {
        flag = true
        console.log(true)
      }
      // return
      // ====== Extension =====
      printIndexes(mp.get(prefixSumArr[i]), i)
      mp.set(prefixSumArr[i], (mp.get(prefixSumArr[i])).concat(i))
    } else {
      mp.set(prefixSumArr[i], [i])
    }
  }
  if (!flag) console.log(false)
}

function printIndexes(arr, index) {
  arr.forEach(num => console.log(num + 1, index))
}