const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");
const disabled = Number(input[0]);
const chance = Number(input[1]);
if (disabled === 1) {
    console.log(chance * 8);
}
if(disabled === 2) {
    console.log(1 + 6 * Math.floor((chance + 1) / 2) + 2 * Math.floor(chance / 2)) ;
}
if(disabled === 3) {
    console.log(2 + 4 * chance);
}
if(disabled === 4) {
    console.log(3 + 2 * Math.floor((chance + 1) / 2) + 6 * Math.floor(chance / 2));
}
if(disabled === 5) {
    console.log(4 + chance * 8);
}