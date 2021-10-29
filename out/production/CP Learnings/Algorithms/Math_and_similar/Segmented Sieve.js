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
  Segmented Sieve
  */
  // =============== SOLVE ==============
  // =========== My try ============
  let limit = 10**4,
    primes = [],
    size = Math.ceil(Math.sqrt(limit)),
    isPrime = [...Array(size).keys()].map(x => true),
    low = 0,
    high = size - 1

  // get initial primes
  primes = simpleSieve (isPrime, primes, high)
  console.log('primes:', primes)
  low = size
  high = low + size - 1
  // make segments in sqrt(n) size
  while (low < limit) {
    // check the limit of high
    if (high >= limit) {
      high = limit - 1
    }
    // fill the array/ Map
    isPrime = new Map()
    for (let i=low; high - i >= 0; i++) {
      isPrime.set(i, true)
    }
    primes = getPrimes(isPrime, primes, low, high)
    low += size
    high += size
  }
  
  // print primes
  console.log('No. of Primes = \n', primes.length)
  console.log('Primes = \n', ...primes)

  // Time Complexity: O(n)
  // Space Complexity: O(sqrt(n))
  // Execution Time: 13.881ms
  // Suitable method when have to find primes incase of large numbers
}

function getPrimes(isPrime, primes, low, high) {
  let j
  for (let i = low; i <= high; i++) {
    // check if num is divisible by any prime
    j = 0
    if (isPrime.get(i)) {
      for (; j < primes.length; j++) {
        // if given num prime
        if (i % primes[j] == 0) {
          break
        }
      }
    }
    if (j == primes.length) {
      // push it to prime
      primes.push(i);
    }
    // make it's other multiple false
    for (let k = 0; primes[k] * i <= high && k < primes.length; k++) {
      isPrime.set(primes[k] * i, false);
    }
  }
  return primes
}

function simpleSieve(isPrime, primes, high) {
  for (let i=2; i <= high; i++) {
    // if given num prime
    if (isPrime[i]) {
      // push it to prime
      primes.push(i)
    }
    // make it's other multiple false
    for (let j=0; primes[j]*i <= high && j<primes.length; j++) {
      isPrime[primes[j] * i] = false
    }
  }
  return primes
}
/*

*/