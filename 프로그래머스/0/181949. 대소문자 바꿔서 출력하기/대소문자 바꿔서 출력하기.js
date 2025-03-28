const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];

rl.on('line', function (line) {
    input = [line];
}).on('close',function(){
    let result = "";
    
    for (let i = 0; i < input[0].length; i++) {
        const ch = input[0][i];
        
        if (ch === ch.toUpperCase())
            result += ch.toLowerCase();
        else 
            result += ch.toUpperCase();
    }
    
    console.log(result);
});