const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];

rl.on('line', function (line) {
    input = [line];
}).on('close',function(){
    str = input[0];
    
//     let answer = "";
//     for (let i = 0; i < str.length; i++) {
//         answer += str[i] + '\n';
//     }
    
//     console.log(answer.trim());
    
    let answer = str.split('').join('\n');
    console.log(answer);
});