const fs = require("fs");

const n = Number(fs.readFileSync('/dev/stdin').toString().trim());

// t(n)을 계산하는 함수 (BigInt 사용)
function calculateT(n) {
    const t = [BigInt(1)];  // t(0) = 1을 BigInt로 초기화

    // t(1)부터 t(n)까지 계산
    for (let i = 1; i <= n; i++) {
        let sum = BigInt(0);  // sum은 BigInt로 초기화
        for (let j = 0; j < i; j++) {
            sum += t[j] * t[i - 1 - j];  // 점화식에 맞춰 계산
        }
        t.push(sum);  // 계산된 t(i)를 배열에 추가
    }

    return t[n];  // t(n) 반환
}

console.log(calculateT(n).toString());  // BigInt 값을 문자열로 출력
