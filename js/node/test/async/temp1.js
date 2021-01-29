//let p = new Promise((resolve, reject) => {
//    const tmp = 1 + 1;
//    if (tmp === 2) {
//        resolve('Success');
//    } else {
//        reject('Fail');
//    }
//});

//p.then(val => {
//    console.log(val);
//}).catch(val => {
//    console.log(`failed! ${val}`);
//})

//const p = new Promise((resolve, reject) => {
//    console.log('promise start');
//    setTimeout(() => {
//        console.log('inside timeout');
//    }, 500);
//    console.log('promise end');
//    setTimeout(() => {
//        resolve('promise resolved');
//    }, 500);
//    // resolve('promise resolve');
//})
//
//function timedLog(message) {
//    return setTimeout(() => {
//        console.log(message);
//    }, 500);
//}
//
//async function wrap(promise) {
//    const val = await promise;
//    console.log(`wrapper received promise value ${val}`);
//    console.log('wrap end');
//}
//
//wrap(p);

const p1 = new Promise((resolve, reject) => {
    setTimeout(() => {
        resolve('promise1 resolved');
    }, 500);
})
const p2 = new Promise((resolve, reject) => {
    setTimeout(() => {
        resolve('promise2 resolved');
    }, 1000);
})
const p3 = new Promise((resolve, reject) => {
    setTimeout(() => {
        resolve('promise3 resolved');
    }, 1500);
})

async function wrap() {
    // const vals = await Promise.all([p1, p2, p3]);
    // console.log(`wrapper received resolved values ${vals}`); // everything logs at the same time
    await Promise.all([
        (async () => {console.log(await p1)})(),
        (async () => {console.log(await p2)})(),
        (async () => {console.log(await p3)})(),
    ]);
}

wrap();
