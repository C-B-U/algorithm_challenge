const fs = require("fs");

// 입력 처리
let inputs = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

// 첫 줄: 사진 크기(R x C) 및 질의 개수(Q)
let [R, C, Q] = inputs[0].split(" ").map(Number);

// R x C 크기의 사진 밝기 정보
let board = inputs.slice(1, R + 1).map(line => line.split(" ").map(Number));

// Q개의 질의 정보
let queries = inputs.slice(R + 1).map(line => line.split(" ").map(Number));

// 누적 합을 저장할 dp 배열 (1-based index 사용)
let dp = Array.from(Array(R + 1), () => Array(C + 1).fill(0));

// 누적 합 계산 (Prefix Sum)
for (let i = 1; i <= R; i++) {
    for (let j = 1; j <= C; j++) {
        dp[i][j] = board[i - 1][j - 1]
            + dp[i - 1][j]
            + dp[i][j - 1]
            - dp[i - 1][j - 1];
    }
}

// 결과 저장 배열
let results = [];

// 질의 처리
for (let [r1, c1, r2, c2] of queries) {
    let sum = dp[r2][c2]
        - dp[r1 - 1][c2]
        - dp[r2][c1 - 1]
        + dp[r1 - 1][c1 - 1];

    let count = (r2 - r1 + 1) * (c2 - c1 + 1);
    results.push(Math.floor(sum / count));
}

// 결과 한 번에 출력
console.log(results.join("\n"));
