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
  Sieve of Eratosthenes
  */
  // =============== SOLVE ==============
  // =========== My try ============
  let limit = 10**3,
    primes = [...Array(limit + 1).keys()].map(x => true)
  let index = 1,
    ans = []

  // find next index
  for (let j = index+1; j < limit; j++) {
    if (primes[j]) {
      ans.push(j)
      index = j
      // mark other as non-prime/composite
      for (let i = index * index; i < limit; i += index)
        primes[i] = false
    }
  }
  // print primes
  console.log('No. of Primes = \n', ans.length)
  console.log(' Primes = \n', ...ans)
  // Time Complexity: O(nloglog(n))
}
/*

*/