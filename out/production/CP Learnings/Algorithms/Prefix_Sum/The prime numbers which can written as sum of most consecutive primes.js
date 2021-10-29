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
  Given an array of limits. For every limit, find the prime number which can be written as the sum of the most consecutive primes smaller than or equal to limit.
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
  const MAX_LIMIT = 10**4
  let limits = [10, 30, 100, 1000, 10000],
    primes = [],
    prefixSum = 0,
    truePrime = [], // primes which are sum of primes
    truePrimesArr = [], // primes whose sum made truePrime
    ansPrime = 0
  
  // get primes by sieve of Eratosthenes
  primes = sieveOfEratosthenes(MAX_LIMIT)
  console.log('primes:', primes.length)

  // get prefix Sum of primes
  primes.forEach(num => {
    prefixSum += num
    /*
      1. It is to be marked which sum is prime => check directly if it's primes or not
      2. Think of how you will store it => store only the primes
    */
    if(isNumPrime(prefixSum)) {
      // push to truePrimes
      truePrime.push(prefixSum)
    }
  })
  // for each limit
  limits.forEach(limit => {
    // get largest prime under that limit
    ansPrime = binarySearch(limit, truePrime)
    console.log('Limit = ' + limit + ' | ansPrime = ' + ansPrime)
  })
}
function binarySearch (num, arr) {
  let start = 0,
    end = arr.length - 1,
    mid = 0

  while(end - start > 1) {
    mid = start + parseInt((end - start) / 2)
    // console.log('start:', start)
    // console.log('end:', end)
    if (num < arr[mid]) {
      // shift segment left
      end = mid
    } else if (num > arr[mid]) {
      // shift segment right
      start = mid
    } else {
      break
    } 
    // console.log('arr[' + mid + ']:', arr[mid])
  }
  if (arr[mid] > num) mid--
  return arr[mid]
}
function isNumPrime (num) {
  if (num % 2 == 0) {
    return false
  }
  for (let i=3; i < Math.ceil(Math.sqrt(num)); i += 2) {
    if (num % i == 0) {
      return false
    }
  }
  return true
}
function sieveOfEratosthenes (LIMIT) {
  let isPrime = [...Array(LIMIT + 1).keys()].map(x => true),
    primes = []

  // find next index
  for (let i=2; i < LIMIT; i++) {
    if (isPrime[i]) {
      primes.push(i)
    }
    for (let j=0; i * primes[j] < LIMIT && j<primes.length; j++) {
      isPrime[i * primes[j]] = false
    }
  }
  return primes
}
/*

*/