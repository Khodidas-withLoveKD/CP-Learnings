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
  let index = 2,
    factor = index,
    stop = false,
    ans = []

  while (!stop) {
    stop = true
    factor = index
    for (let i = index * index; i<limit; i += factor) {
      primes[i] = false
    }
    // find next index
    for (let i = index+1; i<limit; i++) {
      if (primes[i]) {
        ans.push(i)
        index = i
        stop = false
        break
      }
    }
  }
  // print primes
  console.log(' Primes = \n', ...ans)
  // Time Complexity: O()
}
/*
aRR 1 2 3 4  k = 8
PS  1 3 6 10
*/