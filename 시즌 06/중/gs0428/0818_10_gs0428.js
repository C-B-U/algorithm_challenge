const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");
let tmp = input[0].split(' ').map((n) => Number(n));
const repeat = tmp[0]
for (let i = 1; i <= repeat; i++) {
    console.log(input[i].split('').reverse().join(''))
}