const fs = require("fs");  //입력을 받아 처리하는 FileSystem 모듈 불러오기
const input = fs.readFileSync("test.txt").toString().split("\n");
const n = Number(input[0]);
const num = [];
for(let i=1;i<=n;i++){
  num.push(input[i].split(" "));
}
for(let i=0;i<n;i++){
  for(let j=0;j<n;j++){
    for(let k=0;k<n;k++){
      if(Number(num[k][i])==1&&Number(num[i][j])==1){
        num[k][j]=1;
      }
    }
  }
}
for(let i=0;i<n;i++){
  console.log(num[i].join(" "));
}