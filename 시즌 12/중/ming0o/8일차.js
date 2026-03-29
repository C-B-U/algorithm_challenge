let input = require('fs').readFileSync('/dev/stdin').toString().trim();

let n = parseInt(input);
const dp = new Array(n + 1).fill(0);
for (let i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + 1;
    if (i % 2 === 0) dp[i] = Math.min(dp[i], dp[i / 2] + 1);
    if (i % 3 === 0) dp[i] = Math.min(dp[i], dp[i / 3] + 1);
}
console.log(dp[n]);