let age: number = 19;

let userName: string = 'paul';

let isStudent: boolean = true;

let ages: number[];
ages = [1,2,3];
// OR
let frnds: Array<number> = [2,6,9];
// number[] is just the syntactical sugar for Array<number>

let names: string[] = ['logan','david','floyd'];

// typescript is forgivingin a manner as it has a type any by default
// that allows any value type of value to be stored in variable by default

let person: any = {
    name: 'billie jean',
    age: 45
};

let insan: {
    name: string,
    frnds: number
}

insan = {name: 'harry potter', frnds: 2}

// array or objects
let manyPerson : {
    name: string,
    frnds: number
}[];

// type inference: without explicitly defining it inferes the type based of initial value
let bro = 'pewds';
// bro = 1234 this gives error

// union types allows multiple types
let Bro: string | number = 'pewds';
Bro = 78 // now its allowed

let arrayUnion: number | number[];

// create your own types
type Person = {
    name: string,
    frnds: number
}

let brass: Person[];

// functions and types
// by default the return type is infered y we can set it too
function willyWonk(a: number, b: number): number {
    return a+b;
}

function chocFactoryLatte(value: any) {
    console.log('this function is of type void');
}

// Generics

// in general it would have taken type any and that is not good
// so we added generics <T> it looks at the incoming values type and automatically takes its type
function awesome<T>(array: T[], value: T){
    const newArray = [value, ...array];
    return newArray;
}

const demoArray = [1,2,3];
const updatedArray = awesome(demoArray, -3);
const stringArray = awesome(['a','s','d'], 'y');
// if we do not want the T method we can also do
const newStringArray = awesome<string>(['a','s','d'], 'y');