const fs = require('fs');
const fallocate = require('.');

let fd = fs.openSync('test.txt', 'a+');
console.log('ret =', fallocate(fd, 0, 0, 100));
fs.closeSync(fd);
