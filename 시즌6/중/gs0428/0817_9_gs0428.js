const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");
const num = input[0].split(' ').map((n) => Number(n));
let x = num[0];
let y = num[1];
const divisor = (x, y) => {
    if(y === 0)
        return x;
    else
        return divisor(y, x % y)
}
const div = divisor(x, y);
console.log(x + y - div);