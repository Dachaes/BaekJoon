const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];

rl.on('line', function (line) {
    input = line.split(' ');
}).on('close', function () {
    let str = "";
    while (Number(input[1])) {
        str += input[0];
        input[1]--;
    }
    console.log(str);
});