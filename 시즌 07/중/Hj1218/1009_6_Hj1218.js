const fs = require("fs");  //입력을 받아 처리하는 FileSystem 모듈 불러오기
const input = fs.readFileSync("test.txt").toString().split("\n");
const t= Number(input[0]);
let a = 1;
let result=[];
let num = [];
let visit = [];
let m,n,k=0;
for(let i=0;i<t;i++){
  let count =0;
  let arr = input[a].split(" ").map(Number);
  m = arr[0];
  n = arr[1];
  k = arr[2];
  num = [];
  visit = [];
  for(let j=0;j<n;j++){ //이차원배열 생성(모두 0으로 저장)
    let visitt = [];
    let numm = [];
    for(let l=0;l<m;l++){
      numm.push(0);
      visitt.push(0);
    }
    num.push(numm);
    visit.push(visitt);
  }
  for(let j=1;j<=k;j++){
    let arr2 = input[a+j].split(" ").map(Number);
    let x = arr2[0];
    let y = arr2[1];
    num[y][x] = 1;
  }
  for(let j=0;j<n;j++){
    for(let l=0;l<m;l++){
      if(num[j][l]==1&&visit[j][l]==0){
        dfs(j,l);
        count++;
      }
    }
  }
  result.push(count);
  a +=k+1;
}
console.log(result.join("\n"));
function dfs(i, j){
  let dx = [0,1,0,-1];
  let dy = [1,0,-1,0];
  visit[i][j] = 1;
  for(let a=0;a<4;a++){
    let ax = i+dx[a];
    let ay = j+dy[a];
    if(ax>=0&&ay>=0&&ax<n&&ay<m){
      if(visit[ax][ay]==0&&num[ax][ay]==1){
        dfs(ax,ay);
      }
    }
  }
}