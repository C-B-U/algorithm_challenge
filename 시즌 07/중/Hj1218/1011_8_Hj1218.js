const fs = require("fs");  //입력을 받아 처리하는 FileSystem 모듈 불러오기
const input = fs.readFileSync("test.txt").toString().split("\n");
const [n,m] = input[0].split(" ").map(Number);
const arr = input[1].split(" ").map(Number);
let end = 0;
for(let i=0;i<n;i++){
  end = Math.max(end, arr[i]);
}
let start = 0;
let mid = 0;
while(start<=end){
  let count = 0;
  mid = Math.floor((start+end)/2);
  for(let i=0;i<n;i++){
    if(mid<arr[i]){
      count+=arr[i]-mid;
    }
  }
  if(count<m){
    end = mid -1;
  }
  else{
    start = mid+1;
  }
}
console.log(end);