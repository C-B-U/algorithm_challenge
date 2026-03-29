const fs = require("fs")
let inputs = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [N, newScore, P] = inputs[0].split(" ").map(Number);
const ranking = N > 0 ? inputs[1].split(" ").map(Number) : [];

let rank = 1;
let count = 0;

for (let score of ranking) {
    if (newScore < score) {
        rank++;
    } else if (newScore === score) {
        rank = rank;
    } else {
        break;
    }
    count++;
}

if (N === 0 || count < P) {
    console.log(rank);
} else {
    console.log(-1);
}
