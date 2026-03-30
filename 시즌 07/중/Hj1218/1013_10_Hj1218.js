const fs = require("fs");  //입력을 받아 처리하는 FileSystem 모듈 불러오기
const input = fs.readFileSync("test.txt").toString().split("\n");
const n = input[0];
let c = [];
for(let i=0;i<n;i++){
  c.push(input[i+1].split(" ").map(Number));
}
const s = [];
c.forEach(element => {
  s.push({time: element[0], start: 1});
  s.push({time: element[1], start: -1});
});
s.sort((a,b)=>a.time==b.time ? a.start - b.start : a.time - b.time);
let count =0;
let result = 0;
s.forEach(ss => {
  if(ss.start == 1){
    count++;
  }
  else if(ss.start==-1){
    count --;
  }
  result = Math.max(result, count);
})
console.log(result);