const fs = require("fs");  //입력을 받아 처리하는 FileSystem 모듈 불러오기
const input = fs.readFileSync("test.txt").toString().split("\n");
const [n,k] = input[0].split(" ").map(Number);
const visit = Array.from({length: 100001},()=>0);
function bfs(n){
  const q = [];
  q.push([n,0]);
  visit[n]=1;
  while(q.length){
    const [num, time] = q.shift();
    if(num==k){
      return time;
    }
    for(let numm of [num-1,num+1,num*2]){
      if(visit[numm]==0&&numm>=0&&numm<=100000){
        visit[numm]=1;
        q.push([numm, time+1]);
      }
    }
  }
}
console.log(bfs(n));