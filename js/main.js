// DOM Manipulation

const myForm = document.querySelector('#my-form');
const nameInput = document.querySelector('#name');
const emailInput = document.querySelector('#email');
const msg = document.querySelector('.msg');
const userList = document.querySelector('#users');

myForm.addEventListener('submit', onSubmit);

function onSubmit(e) {
    e.preventDefault();

    if (nameInput.value === '' || emailInput.value === '') {
        msg.classList.add('error');
        msg.innerHTML = 'Please enter all fields';

        setTimeout(() => msg.remove(), 3000);
    } else {
        const li = document.createElement('li');
        li.appendChild(document.createTextNode(`${nameInput.value} : ${emailInput.value}`))
        
        userList.appendChild(li);

        nameInput.value = '';
        emailInput.value = '';
    }
}

// const btn = document.querySelector('.btn');

// btn.addEventListener('click', (e)=>{
//     e.preventDefault();
//     document.querySelector('#my-form').style.background = '#ccc';
//     document.querySelector('body').classList.add('bg-dark');
//     document.querySelector('.items').lastElementChild.innerHTML='<h1>hello</h1>';
//     alert('Submit!');
// });

// Single Element
// const form = document.getElementById('my-form');
// const cont = document.querySelector('.container')

// console.log(form);
// console.log(cont);

// Multiple Element
// const items = document.querySelector('.items'); // === querySelectorAll('.item')
// console.log(items);

// const items = document.querySelectorAll('.item');
// items.forEach((item) => console.log(item));

// const ul = document.querySelector('.items');

// // ul.remove();
// ul.firstElementChild.textContent = 'Hello';
// ul.children[1].innerText = 'Brad';
// ul.lastElementChild.innerHTML = '<h1>Hello</h1>';

// const btn = document.querySelector('.btn');
// btn.style.background = 'red';

/*
// OOP
class Person {

    constructor(firstName, lastName, dob) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.dob = new Date(dob);
    }

    getBirthYear() {
        return this.dob.getFullYear();
    }

    getFullName() {
        return `${this.firstName} ${this.lastName}`;
    }

    addProp(val) {
        if (this.prop == undefined) {
            this.prop = [];
        }
        this.prop.push(val);
    }
}

const person = new Person('Hyuck', 'Choi', '12-06-1991');

console.log(person.getBirthYear());
console.log(person.getFullName());
person.addProp('test');
console.log(person.prop);

*/
/*
function Person(firstName, lastName, dob) {
    this.firstName = firstName;
    this.lastName = lastName;
    this.dob = new Date(dob);
}


Person.prototype.getBirthYear = function() {
    return this.dob.getFullYear();
};

Person.prototype.getFullName = function() {
    return `${this.firstName.toUpperCase()} ${this.lastName.toUpperCase()}`;
}

const person = new Person('Hyuck', 'Choi', '12-06-1991');

console.log(person.dob);
console.log(person.getBirthYear());
console.log(person.getFullName());
*/
/*

function addNums(num1, num2) {
    return Number(num1) + Number(num2);
}

console.log(addNums(12, 42));

const hey = (num1=4, num2=10) => num1**num2;

console.log(hey(2, 10));
*/

/*

// Conditional

const x = 10;
const y = 15;

if (x == '10' && y == '15') {
    console.log('loose condition');
}

if (x === '10') {
    console.log('strict condition');
} else if (x > 10 || y > 13) {
    console.log('Higher than 10 or 13?');
} else {
    console.log('Lower or Equal to ten');
}

console.log(x > 11? 'Yay': 'Damn!');

switch (x) {
    case 9:
        console.log('oiooi');
        break
    case 10:
        console.log('hooray');
        break
    default:
        console.log('aiaiai');
}

*/

/*
// Loops2

const hello = [1,2,3,4,5,66];

// hello.forEach(x=>console.log(x*10));

const ello = hello.map(x=>x>4?x*100:x*10);

console.log(ello);

const yolo = hello.filter(x=>x<5).map(x=>x*x);
console.log(yolo);
*/

/*
// Loops

for (let i = 0; i < 10; i++) {
    console.log(i);
}

let test = 10;

while (test > 0) {
    console.log(test);
    test -= 1;
}

const oi = ['a', 'b', 'c'];

for (let i = 0; i < oi.length; i++) {
    console.log(oi[i]);
}

for (let o of oi) {
    console.log(`hello ${o}`);
}

*/

/*
const todos = [
    {
        id: 1,
        text: 'trash',
        complete: true
    },
    {
        id: 2,
        text: 'meeting',
        complete: false
    }
];

console.log(todos[1].text);

console.log(JSON.stringify(todos));
*/
/*

const person = {
    firstName: 'Hyuck',
    age: 30,
    sex: 'Male',
    hobby: {
        'sports': 'kickboxing',
        'music': 'guitar'
    }
};

console.log(person.hobby.music);

const { firstName, age, hobby: { music }} = person;

console.log(firstName, age, music);

person.email = 'choiggoggi@gmail.com';

console.log(person.email);

*/

/*
// Arrays

const numbers   = new Array(1,2,3,4);
const fruits    = ['apples', true, 4.5];

fruits.push('grapes');
fruits.shift();
fruits.unshift('mango');
const newFruits = fruits.slice(0, 2);

console.log(fruits);
console.log(newFruits);

console.log(Array.isArray(fruits));

console.log(fruits.indexOf('mango'));
*/


/*
// var = global scope, let = local variable, const = constant

const name  = 'John';
const age   = 30;

// Concatenation
console.log('My name is ' + name + ' and I am ' + age);

// Template String
console.log(`My name is ${name} and I am ${age}`);
const hello = `Ich bin ${name} und Ich bin ${age}`;
console.log(hello);
*/
/*
const s = 'Hello World!';

console.log(s.toUpperCase());
console.log(s.toLowerCase());
console.log(s.substring(0, s.length).toUpperCase());
console.log(s.split(''));

const dept = 'technology, computers, it, code';

console.log(dept.split(', '));
*/