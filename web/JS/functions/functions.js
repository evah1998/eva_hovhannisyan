//1
function firstWordToUpperCase(str) {
    const words = str.split(' ');
    const firstWord = words[0].toUpperCase();
    str = firstWord + str.slice(str.indexOf(' '));
    return str;
}

const str = firstWordToUpperCase('Javascript is a programming language');
console.log(str);

//2
function subArray(arr, size) {
    const newArray = [];
    let tempSize = size;
    for (let i = 0; i < arr.length; i += size) {
        newArray.push(arr.slice(i, tempSize));
        tempSize+=size;
    }
    return newArray;
}

console.log(subArray([1, 2, 3, 4,], 2));
console.log(subArray([1, 2, 3, 4, 5], 4));
console.log(subArray([1, 2, 3, 4, 5, 6, 7, 8], 3));

//3
function sumOfNumbersObject(obj) {
    let sum = 0;
    for (const [key, value] of Object.entries(obj)) {
        if(!isNaN(value)){
            sum += value;
        }
    }
    return sum;
}
const object = { a: 10, b: 20, c: 'string', d: 12 }
console.log(sumOfNumbersObject(object));

//4
function vowelsCount(str) {
    const vowels = 'aeiouAEIOU';
    let vowelsCount = 0;

    for (let i = 0; i < str.length; i++) {
        if (vowels.indexOf(str[i]) !== -1) {
            vowelsCount += 1;
        }
    }
    return vowelsCount;
}
console.log(vowelsCount('Today is the best day of my life'));

//5
function sumOfNumbersArray(arr) {
    let sumOfPositiveNum = 0;
    let sumOfNegativeNum = 0;

    for (const num of arr) {
        if (num > 0) {
            sumOfPositiveNum += num;
        }
        else {
            sumOfNegativeNum += num;
        }
    }
    return { positive: sumOfPositiveNum, negative: sumOfNegativeNum }; 
}

console.log(sumOfNumbersArray([10, -12, 30, -1, -8, 0, 14, -33, 20]));

//6
const data = [
    { id: 1, name: 'Name one', city: 'Stepanakert'},
    { id: 2, name: 'Name one', city: 'Yerevan' },
    { id: 3, name: 'Name one', city: 'Moscow' },
    { id: 4, name: 'Name one', city: 'Stepanakert' },
    { id: 5, name: 'Name one', city: 'Yerevan' },
];

const arr = [];
function uniqueCitiesName(data) {
    for (let i = 0; i < data.length; i++) {
        arr.push(data[i].city);
    }
    return [...new Set(arr)];
}
console.log(uniqueCitiesName(data));