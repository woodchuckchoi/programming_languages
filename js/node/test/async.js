function promiseGenerator(time) {
    return new Promise((res) => {
        setTimeout(() => {
            res("message");
        }, time);
    });
}

async function runner(promise) {
    let ret = await promise;
    console.log("Promise fulfilled!");
    console.log(ret);
}

function wrapper(time) {
    runner(promiseGenerator(time));
    console.log("something");
}

wrapper(10000);
// something
// Promise fulfilled!
// message

// async only needs to be declared outside the inner-most await call
