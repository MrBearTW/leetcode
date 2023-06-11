// 2677. Chunk Array

// ref: https://youtu.be/VUN-O3B9ceY


/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
var chunk = function (arr, size) {
    // code 2
    const res = [];

    for (let i = 0; i < arr.length; i += size) {
        res.push(arr.slice(i, i + size));
    }
    return res;

    // code1
};