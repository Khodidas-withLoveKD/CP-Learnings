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


function main() {
    let testCases = readline()
    while(testCases--)
        solve()
}

// function to solve problems
function solve (){
    let arrLength = readline()
    let n = readline().split(' ').map(x => +x)
    // let n = line[0]
    // let k = line[1]
    // let ans = 0
    // ------------------
    // count the most occurrences and it is the answer
    let myMap = new Map()
    for (let i = 0; i < n.length; i++) {
        // if (myMap.has(n[i])){
        if (myMap.has(n[i])) {
            myMap.set(n[i], myMap.get(n[i]) + 1)
            // console.log('IF myMap = ', myMap)
        }
        else {
            myMap.set(n[i], 1)
            // console.log('myMap = ', myMap)
        }
    }
    let max = 0
    // console.log(myMap.keys())
    // console.log('map entries = ', myMap.entries())
    for (const [key, value] of myMap.entries()) {
        max = (value > max) ? +value: max
    }
    console.log(max)
}