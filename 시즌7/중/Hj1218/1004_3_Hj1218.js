const fs = require("fs");  //입력을 받아 처리하는 FileSystem 모듈 불러오기
const input = fs.readFileSync("test.txt").toString().split("\n");
const [h,w] = input[0].split(" ");
let sum = 0;
for(let i=1;i<=h;i++){
  let arr = input[i];
  let flag = false;
  for(let j=0;j<w;j++){
    if(flag && arr[j]=="."){
      sum += 1;
    }
    if(arr[j]=="/"||arr[j]=="\\"){
      sum+=0.5;
      if(flag){
        flag = false;
      }
      else{
        flag = true;
      }
    }
  }
}
console.log(sum);