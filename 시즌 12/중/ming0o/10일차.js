let input = require('fs').readFileSync('/dev/stdin').toString().trim();

let lines = input.split('\n');
let [N, M] = lines[0].split(' ').map(Number);
let words = lines.slice(1);

let temp = words.reduce((acc, word) => acc + word.length, 0);
let diff = M - temp;
let gap = N - 1;
let quotient = Math.floor(diff / gap);
let remain = diff % gap;

let result = words[0];

for (let i = 1; i < N; i++) {
    if (words[i][0] >= 'a' && words[i][0] <= 'z' && remain > 0) {
        remain--;
        result += "_".repeat(quotient + 1) + words[i];
    } else if (words[i][0] >= 'A' && words[i][0] <= 'Z' && i + remain > gap) {
        remain--;
        result += "_".repeat(quotient + 1) + words[i];
    } else {
        result += "_".repeat(quotient) + words[i];
    }
}

console.log(result);
