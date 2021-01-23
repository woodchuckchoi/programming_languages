var num = 0.222, hex = 0xbeef, bin = 2;
var str = 'Hello', multiStr = "This variable\ncan be stretched over multiple lines", strExpr = "num is " + num;
console.log(num, hex, bin);
console.log(str, multiStr, strExpr);
// 
var boolFalse = false, boolTrue = true;
var multipleVar = 'String';
multipleVar = 42;
if (typeof str === 'string') {
    console.log('str is string');
}
else {
    console.log('str is not string');
}
var Human = /** @class */ (function () {
    function Human(data) {
        this.name = data;
    }
    return Human;
}());
// instanceof can check custom objects' types as well
var human = new Human('Hyuck');
if (human instanceof Human) {
    console.log(human.name + " is a human");
}
// type assertion
var anything = 'A string variable';
var strLength = anything.length;
// let strLength = (<string>anything).length
// Array is a collection of the same objects in TS
var string = ['Hello', 'Hi', 'Bonjour'];
// when in need of a multi-type array
var stringsAndNumbers = ['String', 42];
var multiDimensional = [[1, 2, 3, 4, 5], [6, 7, 8, 9, 10]];
// Tuple is a collection with a limited length with the types declared
var exampleTuple = [42, 'answer'];
var State;
(function (State) {
    State[State["Normal"] = 0] = "Normal";
    State[State["Abnormal"] = 1] = "Abnormal";
})(State || (State = {}));
var Something;
(function (Something) {
    Something[Something["SomePerson"] = 1] = "SomePerson";
    Something[Something["SomeAnimal"] = 2] = "SomeAnimal";
    Something[Something["SomeFood"] = 3] = "SomeFood";
})(Something || (Something = {}));
console.log(Something.SomePerson, Something.SomeAnimal, Something.SomeFood);
// Object
var hyuck = {
    fistName: 'Hyuck',
    lastName: 'Choi'
};
var cheetah = { name: 'Spotty', species: 'Big Cat' };
var optionalFunction = function (num1, num2) {
    if (num2) {
        return num1 + num2;
    }
    else {
        return num1;
    }
};
var defaultFunction = function (num1, num2) {
    if (num2 === void 0) { num2 = 10; }
    return num1 + num2;
};
var theThing = cheetah; // cheetah has a name, not status though.
var readOnlyThing = { name: 'Something', id: 42 };
readOnlyThing.id = 41; // doesn't work
// Any
function dumberDummyFunc(arg) {
    return arg;
}
// Generic
function dummyFunc(arg) {
    return arg;
}
var dumber = dumberDummyFunc(str);
var dumb = dummyFunc(str);
function someFunc(arg) {
    console.log(arg + " is string");
}
someFunc(dumber);
someFunc(dumb);
