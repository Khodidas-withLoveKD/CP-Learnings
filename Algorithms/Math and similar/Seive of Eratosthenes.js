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
  let limit = 10**4,
    isPrime = [...Array(limit + 1).keys()].map(x => true)
  let primes = []

  /* ===== Method 1 O(n*loglog(n)) ========
  let index = 1
  // find next index
  for (let j = index+1; j < limit; j++) {
    if (isPrime[j]) {
      primes.push(j)
      index = j
      // mark other as non-prime/composite
      for (let i = index * index; i < limit; i += index)
        isPrime[i] = false
    }
  }
  // Time Complexity: O(nloglog(n))
  // Execution Time: 7.193ms
  */
  // ==== Method 2 O(n) ======
  let SPF = [...Array(limit + 1).keys()]

  // 0 and 1 are composite
  isPrime[0] = isPrime[1] = false

  // loop through entire array => O(n)
  for (let i=0; i < isPrime.length; i++) {
    if (isPrime[i]) {
      // push it to primes[]
      primes.push(i)

      SPF[i] = i
    }
    // mark the nums who are = primes[] * SPF[i]
    for (let j=0; i * primes[j] < isPrime.length && j < primes.length; j++) {
      SPF[i * primes[j]] = primes[j]
      isPrime[i * primes[j]] = false
    }
  }
  // Time Complexity: O(n)
  // Execution Time: 11.211ms
  // Suitable method when have to find primes incase of large numbers
  
  // print primes
  console.log('No. of Primes = \n', primes.length)
  console.log('Primes = \n', ...primes)
}
/*

*/