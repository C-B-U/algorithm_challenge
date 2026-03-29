const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");
const tmp = input[0].split(' ');
const [x, y, w, s] = tmp.map((t) => Number(t));

const case1 = (x + y) * w;
let case2 = Math.max(x, y) * s;
if ((x + y) % 2 !== 0) {
    case2 = (Math.max(x, y) - 1) * s + w;
}
const case3 = Math.min(x, y) * s + Math.abs(x - y) * w;

console.log(Math.min(Math.min(case1, case2), case3));