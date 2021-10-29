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
  let testCases = readline(),
    caseNo = 1
  while (testCases--) {
    console.log('Test Case:', caseNo++)
    solve()
    console.log('-------------')
  }
  console.log('=========')
  console.timeEnd('Execution Time');
}

function solve () {
  /*
    Write an efficient program to find the product of contiguous subarray within 
    a one-dimensional array of numbers that has the largest product.
    arr = [-2, -3, 4, -1, -2, 1, 2, -3]
            |_____________________|
                          | |
                          ans = 96
  */
  // =============== SOLVE ==============
  /*
    There will be 3 cases (types of input):
    1. All positive
    2. All negative
    3. Both +ve and -ve

    #1 is quite straight-forward. The entire array sum is ans
    #2 if num of elements even --> all else eleminate the least of first or last
    #3 let's see

    Additional: Printing indexes as well

    ====== Input =====
    10
    0 0 0 -1 2 1 -2
    -1 2 1 2
    -1 -2 1 -2 -1
    -1 2 0 1 -2
    0 -1
    0 -1 -2
    -1 2
    -1
    0
    0 0 0
  */
  // ============ Handling all cases + Printing indexes as well =========
  let arr = readline().split(' ').map(x => +x),
  maxSoFar = 1,
  currProduct = 1,
  start = 0, end = 0, maxStart = 0, allow = true
  
  if (arr.length === 1) {
    console.log('maxProduct = ', arr[0])
    console.log('start = ' + 0 + ' | end = ' + 0)
    return
  }
  // Similar DP approach as done in sum
  // Here currProduct will be product of the all the nums
  // while maxSoFar will be the product of nums which will make the entire product positive
  for (let i = 0; i < arr.length; i++) {
    // one time thing
    // mark the beginning of maxSoFar
    if (allow && arr[i] > 0) {
      allow = false
      maxStart = i
    }
    // currProduct can become -ve many times
    currProduct *= arr[i]
    // consider a num in MaxSoFar if it increases its value
    if (maxSoFar * arr[i] > maxSoFar) {
      maxSoFar *= arr[i]
      end = i
    }
    // but if earlier it was negative so now it becomes positive
    // obviously currProduct > maxSoFar
    if (currProduct > maxSoFar) {
      maxSoFar = currProduct
      end = i
      maxStart = start
    }
    if (currProduct == 0) {
      // reset
      currProduct = 1
      // next index will be the start of the new group
      start = i + 1
    }
  }
  if (allow && maxSoFar === 1) maxSoFar = 0
  console.log('maxProduct = ', maxSoFar)
  console.log('start = ' + maxStart + ' | end = ' + end)
  // Hence, wrote a code that covers all cases (smile with tears in eyes)s
}
/*

*/