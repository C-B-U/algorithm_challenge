const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");
const [n, len] = input[0].split(' ').map((n) => Number(n));
const loc = input[1].split(' ').map((n) => Number(n)).sort((a, b) => {
  if(a >= b)
      return 1;
  else
      return -1;
})
let start = loc[0];
let ans = 0;
for (let i = 1; i < n; i++) {
    if (len <= loc[i] - start) {
        ans++;
        start = loc[i];
    }
}
console.log(ans + 1)