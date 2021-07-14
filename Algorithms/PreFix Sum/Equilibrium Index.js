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
  let testCases = readline()
  while (testCases--) {
    solve()
  }
}
function solve () {
  /*
  Equilibrium index of an array is an index such that the sum of elements at lower indexes is equal to the sum of elements at higher indexes.
  Input: A[] = {-7, 1, 5, 2, -4, 3, 0} 
  Output: 3 
  3 is an equilibrium index, because: 
  A[0] + A[1] + A[2] = A[4] + A[5] + A[6]

  Input: A[] = {1, 2, 3} 
  Output: -1
  */
  // =============== SOLVE ==============
  let prefixSumArr = [],
    prefixSum = 0
  let arr = readline().split(' ').map(x => {
    x = +x
    prefixSum += x
    prefixSumArr.push(prefixSum)
    return x
  })
  let leftSum = 0
  for (let i=0; i<arr.length; i++) {
    // console.log('arr[i]:', arr[i])
    leftSum += arr[i]
    // console.log('leftSum:', leftSum)
    if (leftSum == prefixSum) {
      console.log('Equi Index = ', i)
      return
    }
    prefixSum -= arr[i]
    // console.log('prefixSum:', prefixSum)
  }
  console.log('Equi Index = ', -1)
}
/*
lS -7 -6 -1 1
RS 7 6 1 -1
*/