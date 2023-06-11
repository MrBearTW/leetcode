// 2622. Cache With Time Limit

// ref: https://youtu.be/w772gtNK0Gw


class TimeLimitedCache {
    cache = new Map();

    set(key, value, duration) {
        const alreadyExists = this.cache.get(key);
        if (alreadyExists) {
            clearTimeout(alreadyExists.timeoutID);
        }
        const timeoutID = setTimeout(() => {
            this.cache.delete(key);
        }, duration);
        this.cache.set(key, { value, timeoutID });
        return Boolean(alreadyExists)
    };

    get(key) {
        if (this.cache.has(key))
            return this.cache.get(key).value;
        return -1;
    }

    count() {
        return this.cache.size;
    }

}

// var TimeLimitedCache = function() {

// };

/**
 * @param {number} key
 * @param {number} value
 * @param {number} time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
// TimeLimitedCache.prototype.set = function (key, value, duration) {

// };

// /** 
//  * @param {number} key
//  * @return {number} value associated with key
//  */
// TimeLimitedCache.prototype.get = function (key) {

// };

// /** 
//  * @return {number} count of non-expired keys
//  */
// TimeLimitedCache.prototype.count = function () {

// };

/**
 * Your TimeLimitedCache object will be instantiated and called as such:
 * var obj = new TimeLimitedCache()
 * obj.set(1, 42, 1000); // false
 * obj.get(1) // 42
 * obj.count() // 1
 */