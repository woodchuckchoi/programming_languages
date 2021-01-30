async function test() {
    const tmp = [1,2,3,4,5,6,7,8,9,10];
    let out = [];
    tmp.forEach(num => {
        out.push(num);
    })
    await new Promise((resolve, reject) => {
        console.log(out);
        resolve();
    });
}

test();
