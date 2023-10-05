const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");
const [height, width] = input[0].split(' ').map((Number));
let slash = 0;
let dot = 0;
input.slice(1).map((n) => {
    for (let i = 0; i < n.length; i++) {
        if (n[i] === '\\' || n[i] === '/') {
            slash++;
        }

        if (slash % 2) {
            if (n[i] === '.') {
                dot++;
            }
        }
    }
});

console.log(Math.floor(slash / 2) + dot);