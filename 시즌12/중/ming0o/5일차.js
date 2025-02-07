const fs = require("fs");
const input = fs.readFileSync("/dev/stdin", "utf8").trim().split("\n");

const alphabet = Array.from({ length: 26 }, (_, i) => String.fromCharCode(97 + i));
const T = parseInt(input[0]);

for (let t = 1; t <= T; t++) {
    const pangram = input[t].toLowerCase();
    const check = new Array(26).fill(0);

    for (let char of pangram) {
        const index = char.charCodeAt(0) - 97;
        if (index >= 0 && index < 26) {
            check[index]++;
        }
    }

    const minCount = Math.min(...check);
    let result = "";
    if (minCount === 0) {
        result = `Case ${t}: Not a pangram`;
    } else if (minCount === 1) {
        result = `Case ${t}: Pangram!`;
    } else if (minCount === 2) {
        result = `Case ${t}: Double pangram!!`;
    } else if (minCount === 3) {
        result = `Case ${t}: Triple pangram!!!`;
    }

    console.log(result);
}
