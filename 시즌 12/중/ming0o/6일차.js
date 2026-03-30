const fs = require("fs");
const X = Number(fs.readFileSync("/dev/stdin").toString().trim());

let limit = 1, n = 1;

while (limit < X) {
    limit += ++n;
}

const a = n - (limit - X);

if (n % 2 === 0) {
    console.log(`${a}/${n - a + 1}`);
} else {
    console.log(`${n - a + 1}/${a}`);
}
