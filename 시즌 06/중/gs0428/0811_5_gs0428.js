const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");
const size = Number(input[0]);
const arr = input.slice(1).map((a) => a.split('').map((a) => Number(a)));
let ans = '';

const quadTree = (x, y, size) => {
    if (size === 1) {
        ans += arr[x][y];
        return;
    }

    let isOnlyZero = true, isOnlyOne = true;
    for (let i = x; i < x + size; i++) {
        for (let j = y; j < y + size; j++) {
            if (arr[i][j] === 0) isOnlyOne = false;
            if (arr[i][j] === 1) isOnlyZero = false;
        }
        if (!isOnlyOne && !isOnlyZero) break;
    }

    if (isOnlyOne) {
        ans += '1';
        return;
    }

    if (isOnlyZero) {
        ans += '0';
        return;
    }

    ans += '(';
    const halfSize = size / 2;
    quadTree(x, y, halfSize);
    quadTree(x, y + halfSize, halfSize);
    quadTree(x + halfSize, y, halfSize);
    quadTree(x + halfSize, y + halfSize, halfSize);
    ans += ')';
};

quadTree(0, 0, size);
console.log(ans);
