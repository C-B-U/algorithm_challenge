const fs = require("fs");

let input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
let T = Number(input[0]);
let cases = input.slice(1).map(Number);

const MAX = 50000;
let isPrime = new Array(MAX + 1).fill(true);
isPrime[0] = isPrime[1] = false;

// 에라토스테네스의 체로 소수 찾기
for (let i = 2; i * i <= MAX; i++) {
    if (isPrime[i]) {
        for (let j = i * i; j <= MAX; j += i) {
            isPrime[j] = false;
        }
    }
}

// 소수 배열 생성
let primes = [];
for (let i = 2; i <= MAX; i++) {
    if (isPrime[i]) primes.push(i);
}

// 소수의 곱을 저장할 배열
let primeProducts = [];
for (let i = 0; i < primes.length; i++) {
    for (let j = i + 1; j < primes.length; j++) {  // 중복 방지 (i != j)
        let product = primes[i] * primes[j];
        if (product > 100001) break; // 100001을 넘어가면 중단
        primeProducts.push(product);
    }
}

// 소수의 곱 정렬
primeProducts.sort((a, b) => a - b);

// 이진 탐색으로 K 이상의 가장 작은 수 찾기
function lowerBound(arr, target) {
    let left = 0, right = arr.length;
    while (left < right) {
        let mid = Math.floor((left + right) / 2);
        if (arr[mid] >= target) right = mid;
        else left = mid + 1;
    }
    return arr[left];
}

// 결과 계산 및 출력
let result = cases.map((K) => lowerBound(primeProducts, K));
console.log(result.join("\n"));
