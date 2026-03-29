const fs = require("fs");  //입력을 받아 처리하는 FileSystem 모듈 불러오기
const input = fs.readFileSync("test.txt").toString();
let a = input.split(" ");
const m = Number(a[0]);
const n = Number(a[1]);
const prime = [];
let arr = [];
for(let i=0;i<=n;i++){
  arr.push(true);
}
arr[0] = false;
arr[1] = false;
for(let i=2; i<=n;i++){
  if(arr[i]){
    for(let j=2;i*j<=n;j++){
      arr[i*j] = false;
    }
  }
}
for(let i=m;i<=n;i++){
  if(arr[i]){
    prime.push(i);
  }
}
console.log(prime.join("\n"));