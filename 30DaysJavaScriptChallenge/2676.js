// 2676. Throttle

// ref: https://youtu.be/zyGZV_fIQWk

/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var throttle = function (fn, t) {
    let isThrottled = false;
    let nextArgs = null;

    return function (...args) {
        if (isThrottled) {
            nextArgs = args;
        } else {
            fn(...args);
            isThrottled = true;
            setTimeout(helper, t);
        }

        function helper() {
            if (nextArgs) {
                fn(...nextArgs);
                isThrottled = true;
                nextArgs = null;
                setTimeout(helper, t);
            } else {
                isThrottled = false;
            }
        }
    }
};

/**
 * const throttled = throttle(console.log, 100);
 * throttled("log"); // logged immediately.
 * throttled("log"); // logged at t=100ms.
 */