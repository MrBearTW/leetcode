// 2700. Differences Between Two Objects

//ref:  https://youtu.be/gH7oZs1WZfg

/**
 * @param {object} obj1
 * @param {object} obj2
 * @return {object}
 */
function objDiff(o1, o2) {
    if (!isObject(o1) && !isObject(o2)) { // both primitive
        return o1 === o2 ? {} : [o1, o2];
    }
    if (!isObject(o1) || !isObject(o2)) { // one primitive
        return [o1, o2];
    }
    if (Array.isArray(o1) !== Array.isArray(o2)) { // one arr, one obj
        return [o1, o2];
    }
    const diff = {};
    for (const key in o1) {
        if (o2.hasOwnProperty(key)) {
            const res = objDiff(o1[key], o2[key]);
            if (Object.keys(res).length > 0) {
                diff[key] = res;
            }
        }
    }
    return diff;

    function isObject(obj) {
        return typeof obj === 'object' && obj !== null;
    }
};