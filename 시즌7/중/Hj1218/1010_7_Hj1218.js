const fs = require("fs");  //입력을 받아 처리하는 FileSystem 모듈 불러오기
const input = fs.readFileSync("test.txt").toString().split("\n");
const t= Number(input[0]);
let result = [];
for(let i=0;i<t;i++){
  let arr = input[i+1].split(" ").map(Number);
  let x1 = arr[0];
  let y1 = arr[1];
  let r1 = arr[2];
  let x2 = arr[3];
  let y2 = arr[4];
  let r2 = arr[5];
  let a = (x1 - x2)**2+(y1-y2)**2;
  if(a==0&&r1==r2){
    result.push(-1);
  }
  else if(a==(r1+r2)**2||a==(r1-r2)**2){
    result.push(1);
  }
  else if(a<(r1+r2)**2&&a>(r1-r2)**2){
    result.push(2);
  }
  else{
    result.push(0);
  }
}
console.log(result.join("\n"));