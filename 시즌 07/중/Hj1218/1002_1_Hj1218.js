const fs = require("fs");  //입력을 받아 처리하는 FileSystem 모듈 불러오기
const input = fs.readFileSync("test.txt").toString().split("\n");
const [n,m] = input[0].split(" "); 
let chessBoard = [];
let whiteBoard = ['WBWBWBWB', 'BWBWBWBW', 'WBWBWBWB', 'BWBWBWBW', 'WBWBWBWB', 'BWBWBWBW', 'WBWBWBWB', 'BWBWBWBW'];
let blackBoard = ['BWBWBWBW', 'WBWBWBWB', 'BWBWBWBW', 'WBWBWBWB', 'BWBWBWBW', 'WBWBWBWB', 'BWBWBWBW', 'WBWBWBWB'];
for(let i=0;i<n;i++){
  chessBoard[i] = input[i+1].split("");
}
let count = 64;
for(let i=0;i<=n-8;i++){
  for(let j=0;j<=m-8;j++){
    let white = 0;
    let black = 0;
    for(let k=i;k<i+8;k++){
      for(let l=j;l<j+8;l++){
        if(chessBoard[k][l]!=whiteBoard[k-i][l-j]){
          white++;
        }
        if(chessBoard[k][l]!=blackBoard[k-i][l-j]){
          black++;
        }
      }
    }
    let min = 64;
    if(black < white){
      min = black;
    }
    else{
      min = white;
    }
    if(min<count){
      count = min;
    }
  }
}
console.log(count);