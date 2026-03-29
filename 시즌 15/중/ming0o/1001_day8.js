const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : '../input.txt';
const input = fs.readFileSync(filePath).toString().split('\n');

// shift는 처음값을 return 하고 삭제한다.
const N = +input.shift();

// 문자열로 되어있는 배열을 공백 기준으로 잘러서,
// 각각을 숫자로 만들어준다.
let arr = [];
input.map(item => {
  let tmp = item.split(' ').map(item => +item);
  arr.push(tmp);
});

// Floyd-Warshall Algorithm
function solution(N, matrix) {
  // k는 거쳐갈 중간노드를 나타낸다.
  for (let k = 0; k < N; k++) {
    for (let i = 0; i < N; i++) {
      for (let j = 0; j < N; j++) {
        // k를 거쳐서 i부터 j까지 갈 수 있다면,
        if (matrix[i][k] && matrix[k][j]) {
          matrix[i][j] = 1;
        }
      }
    }
  }

  // 출력예시에 맞게 출력
  for (let i = 0; i < N; i++) {
    console.log(matrix[i].join(' '));
  }
}

solution(N, arr);