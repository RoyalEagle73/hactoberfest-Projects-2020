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
    
    main();    
});

function readLine() {
    return inputString[currentLine++];
}

/*
 * Complete the vowelsAndConsonants function.
 * Print your output using 'console.log()'.
 */
function vowelsAndConsonants(s) {
    var vowels =['a','e','i','o','u'];
        
    for( let i=0;i<s.length;i++){
         for( let j=0;j<5;j++){
      
            if (s[i] == vowels[j]){
           console.log(s[i]);
           break;
       }
      
       }
      
    }
var consonants =['b','c' ,'d','f','g','h','j','k','l','m','n','p','q','r','s','t','w','v','x','y','z'];
        
    for( let i=0;i<s.length;i++){
         for( let j=0;j<21;j++){
      
            if (s[i] ==consonants[j]){
           console.log(s[i]);
           break;
       }
      
       }
      
    }
    
}
