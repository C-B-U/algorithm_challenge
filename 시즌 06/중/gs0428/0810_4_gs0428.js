const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");
const repeat = Number(input[0]);
let shortcut = []
for (let i = 1; i <= repeat; i++) {
    let word = input[i].split(' ');
    let exist;
    for (let k = 0; k < word.length; k++) {
        exist = shortcut.some((s) => s === word[k][0]);
        if(!exist) {
            shortcut.push(word[k][0]);
            shortcut.push(word[k][0] >= 'a' && word[k][0] <= 'z' ? word[k][0].toUpperCase() : word[k][0].toLowerCase());
            word[k] = '[' + word[k][0] + ']' + word[k].slice(1, word[k].length)
            break;
        }
    }
    if (!exist) {
        console.log(word.join(' '));
        continue;
    }
    for (let k = 0; k < word.length; k++) {
        for (let j = 1; j < word[k].length; j++) {
            exist = shortcut.some((s) => s === word[k][j]);
            if(!exist) {
                shortcut.push(word[k][j]);
                shortcut.push(word[k][j] >= 'a' && word[k][j] <= 'z' ? word[k][j].toUpperCase() : word[k][j].toLowerCase());
                word[k] = word[k].slice(0, j) + '[' + word[k][j] + ']' + word[k].slice(j + 1, word[k].length);
                break;
            }
        }
        if(!exist)
            break;
    }
    console.log(word.join(' '));
}