// 2636. Promise Pool

// ref: https://youtu.be/DB8pAAg-9xw

/**
 * @param {Function[]} functions
 * @param {number} n
 * @return {Function}
 */

// method 1
var promisePool = async function(functions, n){
    return new Promise((resolve, reject)=>{
        let i = 0;
        let inProgress = 0;

        function callback(){
            if(i === functions.length && inProgress ===0){
                resolve();
            }
            while (i < functions.length && inProgress < n){
                functions[i++]()
                .then(() => {
                    inProgress--;
                    callback();
                });
                inProgress++;
            }
        }
        callback();
    })
}


// method 2
/*
var promisePool = async function (functions, n) {
    let i = 0;

    async function callback() {
        if (i === functions.length) {
            return;
        }
        await functions[i++]();
        await callback();
    }
    const nPromises = Array(n).fill().map(callback);
    await Promise.all(nPromises);
};
*/

/**
 * const sleep = (t) => new Promise(res => setTimeout(res, t));
 * promisePool([() => sleep(500), () => sleep(400)], 1)
 *   .then(console.log) // After 900ms
 */