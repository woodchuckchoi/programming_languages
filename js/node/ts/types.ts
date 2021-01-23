let num: number = 0.222,
    hex: number = 0xbeef,
    bin: number = 0b0010;

let str: string = 'Hello',
    multiStr: string = `This variable
can be stretched over multiple lines`,
    strExpr: string = `num is ${num}`;    

console.log(num, hex, bin);
console.log(str, multiStr, strExpr);

// 

let boolFalse: boolean = false,
    boolTrue: boolean = true;

let multipleVar: string | number = 'String'
multipleVar = 42;

if (typeof str === 'string') {
    console.log('str is string');
} else {
    console.log('str is not string');
}

class Human {
    name: string;

    constructor(data: string) {
        this.name = data;
    }
}

// instanceof can check custom objects' types as well

let human = new Human('Hyuck');
if (human instanceof Human) {
    console.log(`${human.name} is a human`);
}

// type assertion

let anything: any = 'A string variable';
let strLength = (anything as string).length 
// let strLength = (<string>anything).length

// Array is a collection of the same objects in TS
let string: string[] = ['Hello', 'Hi', 'Bonjour'];

// when in need of a multi-type array
let stringsAndNumbers: (string | number) [] = ['String', 42];

let multiDimensional: number[][] = [[1,2,3,4,5], [6,7,8,9,10]];

// Tuple is a collection with a limited length with the types declared
let exampleTuple: [number, string] = [42, 'answer'];

enum State {
    Normal,
    Abnormal
}

enum Something {
    SomePerson = 1,
    SomeAnimal,
    SomeFood
}

console.log(Something.SomePerson, Something.SomeAnimal, Something.SomeFood);

// Object
const hyuck = {
    fistName : 'Hyuck',
    lastName : 'Choi'
}

// custom types
type Animal = {name: string, species: string};
const cheetah : Animal = {name: 'Spotty', species: 'Big Cat'};

const optionalFunction = (num1 : number, num2? : number) : number => {
    if (num2) {
        return num1 + num2;
    } else {
        return num1;
    }
}

const defaultFunction = (num1 : number, num2 : number = 10) : number => {
    return num1 + num2;
}

interface Thing {
    name: string
    status?: State
}

const theThing = cheetah; // cheetah has a name, not status though.

interface ReadOnly {
    name: string
    readonly id: number
}

const readOnlyThing = {name: 'Something', id: 42};
readOnlyThing.id = 41; // doesn't work

// Any
function dumberDummyFunc(arg: any) : any {
    return arg;
}

// Generic
 function dummyFunc<T>(arg: T): T { // knows the return type
    return arg;
}

let dumber = dumberDummyFunc(str);
let dumb = dummyFunc(str);

function someFunc(arg: string) {
    console.log(`${arg} is string`);
}

someFunc(dumber); // dumber is type of any
someFunc(dumb);

// AccessModifiers
// Private can only be accessed in the class they are defined
// Protected can only be accessed in the class they are defined and its sub/child classes