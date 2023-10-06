const fs = require("fs");  //입력을 받아 처리하는 FileSystem 모듈 불러오기
const input = fs.readFileSync("test.txt").toString().split("\n");
const arr1 = input[0].split(" ").map(Number);
const arr2 = input[1].split(" ").map(Number);
const arr3 = input[2].split(" ").map(Number);
let a = arr1[0]*arr2[1]+arr2[0]*arr3[1]+arr3[0]*arr1[1];
let b = arr1[1]*arr2[0]+arr2[1]*arr3[0]+arr3[1]*arr1[0];
if(a<b){
  console.log(-1);
}
else if(a>b){
  console.log(1);
}
else{
  console.log(0);
}