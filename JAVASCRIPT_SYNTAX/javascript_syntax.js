Modern JavaScript (ES6+) includes a wide range of syntactic concepts that improve readability, maintainability, and performance. Below is a structured breakdown:


---

1. Declarations

var, let, const (Variable Declarations)

function (Function Declaration)

class (Class Declaration)

import/export (Module Import/Export)



---

2. Data Types & Structures

Primitive types: string, number, bigint, boolean, undefined, null, symbol

Reference types: Object, Array, Function, Date, RegExp, Map, Set, WeakMap, WeakSet



---

3. Operators

Arithmetic Operators

+, -, *, /, %, **

Comparison Operators

==, !=, ===, !==, >, <, >=, <=

Logical Operators

&&, ||, !, ?? (Nullish coalescing)

Bitwise Operators

&, |, ^, ~, <<, >>, >>>

Assignment Operators

=, +=, -=, *=, /=, %=, **=, &=, |=, ^=, <<=, >>=, >>>=

Ternary Operator

condition ? expr1 : expr2

Spread & Rest Operators

... (Spread and Rest)


---

4. Control Flow

Conditionals

if, else, else if

switch, case, default


Loops

for

while

do...while

for...in (Iterates over object properties)

for...of (Iterates over iterable values)


Error Handling

try, catch, finally

throw



---

5. Functions

Function Declarations

function add(a, b) {
  return a + b;
}

Function Expressions

const multiply = function (a, b) {
  return a * b;
};

Arrow Functions

const divide = (a, b) => a / b;

Default Parameters

function greet(name = "Guest") {
  console.log(`Hello, ${name}`);
}

Rest Parameters

function sum(...numbers) {
  return numbers.reduce((acc, num) => acc + num, 0);
}

Immediately Invoked Function Expressions (IIFE)

(function () {
  console.log("Executed immediately");
})();


---

6. Objects

Object Literals

const user = { name: "Alice", age: 30 };

Object Destructuring

const { name, age } = user;

Object Shorthand Property

const name = "Alice";
const user = { name }; // { name: "Alice" }

Object Methods

const person = {
  greet() {
    console.log("Hello!");
  },
};

Optional Chaining (?.)

console.log(user?.address?.city);


---

7. Arrays

Array Destructuring

const [first, second] = [10, 20, 30];

Array Methods

map(), filter(), reduce(), forEach(), find(), some(), every(), includes(), push(), pop(), shift(), unshift(), splice(), slice()


---

8. Classes

Class Declaration

class Animal {
  constructor(name) {
    this.name = name;
  }
  speak() {
    console.log(`${this.name} makes a noise.`);
  }
}

Class Inheritance

class Dog extends Animal {
  speak() {
    console.log(`${this.name} barks.`);
  }
}

Static Methods

class MathUtil {
  static add(a, b) {
    return a + b;
  }
}

Private Fields & Methods

class Person {
  #privateField = 42;
  #privateMethod() {
    console.log("Private method");
  }
}


---

9. Promises & Async Programming

Promises

const fetchData = new Promise((resolve, reject) => {
  setTimeout(() => resolve("Data loaded"), 2000);
});

Async/Await

async function fetchUser() {
  const response = await fetch("https://api.example.com/user");
  const data = await response.json();
  console.log(data);
}


---

10. Modules (ES6)

Exporting Modules

export const PI = 3.1416;
export function add(a, b) {
  return a + b;
}

Importing Modules

import { PI, add } from "./math.js";

Default Export

export default function greet() {
  console.log("Hello!");
}

import greet from "./greet.js";


---

11. Generators

function* generatorFunction() {
  yield 1;
  yield 2;
  yield 3;
}
const gen = generatorFunction();
console.log(gen.next().value); // 1


---

12. Symbols & Iterators

Creating Symbols

const sym = Symbol("unique");

Custom Iterators

const iterable = {
  [Symbol.iterator]() {
    let step = 0;
    return {
      next() {
        step++;
        return step <= 3 ? { value: step, done: false } : { done: true };
      },
    };
  },
};


---

13. Proxy & Reflect API

const handler = {
  get(target, prop) {
    return prop in target ? target[prop] : "Not found";
  },
};
const proxy = new Proxy({ name: "Alice" }, handler);
console.log(proxy.name); // Alice
console.log(proxy.age); // Not found


---

14. Web APIs & Events

fetch()

localStorage, sessionStorage

setTimeout(), setInterval()

addEventListener(), removeEventListener()



---

This covers all key syntactic concepts in modern JavaScript. Let me know if you need more details on any topic!

