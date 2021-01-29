const posts = [
    {
        title: 'Post One',
        body: 'This is post one',
    },
    {
        title: 'Post Two',
        body: 'This is post two',
    }
];

function getPosts() {
    setTimeout(()=> {
        let output = '';
        posts.forEach((post, index)=> {
            output += `${post.title} ${post.body}\n`
        });
        console.log(output);
    }, 1000)
}

// 1 callback
// const createPost = (post, callback)=> {
//     setTimeout(()=> {
//         posts.push(post);
//         callback();
//     }, 2000);
// }
// 
// getPosts();
// createPost({title: 'Post Three', body: 'This is post three'}, getPosts); // primal callback

const createPost = (post) => {
    return new Promise((resolve, reject)=> {
        setTimeout(()=> {
            posts.push(post);
            const error = false;
            if (!error) {
                resolve();
            } else {
                reject('Error: Something went wrong');
            }
        }, 2000);
    });
}

// 2 promise callback
// createPost({title: 'Post Three', body: 'This is post three'})
//     .then(getPosts)
//     .catch(err => console.log(err)); // promise 

// 3 async/await
const init = async ()=> {
    await createPost({title: 'Post Three', body: 'This is post three'});
    getPosts();
}

init();

// Promise.all
// const promise1 = Promise.resolve('Hello World');
// const promise2 = 10;
// const promise3 = new Promise((resolve, reject)=> {
//     setTimeout(resolve, 2000, 'Goodbye');
// });
// const promise4 = fetch('https://jsonplaceholder.typicode.com/users')
//     .then(res=> res.json());
// 
// Promise.all([promise1, promise2, promise3, promise4]).then((values)=> {
//     console.log(values);
// })
