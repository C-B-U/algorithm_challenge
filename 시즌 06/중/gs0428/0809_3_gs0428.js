const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");
const n = input.map((i) => Number(i));
const repeat = n[0];
const num = n.splice(1, repeat).sort(function (a, b) {
    if (a >= b) {
        return 1;
    }
    if (a < b) {
        return -1;
    }
})
let l = repeat - 3, m = repeat - 2, r = repeat - 1;
while(1) {
    if (num[l] + num[m] > num[r]) {
        console.log(num[l] + num[m] + num[r])
        break;
    }
    if(l === 0 && r === 2) {
        console.log(-1);
        break;
    }
    if(num[l] + num[m] <= num[r]) {
        r -= 1;
        m = r - 1;
        l = m - 1;
    }
}