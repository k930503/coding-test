const fs = require("fs");
const input = (
  process.platform === "linux"
    ? fs.readFileSync("/dev/stdin").toString()
    : `
    2
    6 12 10
    30 50 72
    `
)
  .trim()
  .split('\n');

const count = input.shift();

for(let i = 0; i < count; i++){
    const [ H, W, N ] = input[i].trim().split(' ').map(Number);

    let ho = parseInt(N / H)
    let floor = N % H

    if (floor != 0) {
        ho++
    } else {
        floor = H
    }

    if (parseInt(ho / 10) == 0) {
        console.log(floor.toString().concat("0".concat(ho.toString())))
    } else {
        console.log(floor.toString().concat(ho.toString()))
    }
}
