const fs = require('fs');
const path = require('path');

// mkdir
fs.mkdir(path.join(__dirname, 'test'), {}, err=> {
    if (err) throw err;
    console.log('Folder created');
});

// touch
fs.writeFile(path.join(__dirname, 'test', 'hello.txt'), 'Hello World!', err=> {
    if (err) throw err;
    console.log('File created');
});
