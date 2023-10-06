const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");
const [min, max] = input[0].split(' ').map((n) => Number(n));
const isPrimeNum = [];
isPrimeNum.push(false);
isPrimeNum.push(false);
for (let i = 2; i <= max; i++) {
    isPrimeNum.push(true);
}
for (let i = 2; i <= Math.floor(Math.sqrt(max)); i++) {
    if (!isPrimeNum[i]) {
        continue
    }
    for (let k = 2 * i; k <= max; k += i) {
        isPrimeNum[k] = false;
    }
}
for (let i = min; i <= max; i++) {
    if (isPrimeNum[i]) {
        console.log(i)
    }
}