/** 
 * Testing operations and validation functions
 * with Mocha and Node.js Assert module.
 *
 */

const assert = require('assert');

/* **********************************************************************************************************************************************************
 * start soluiton
 * **********************************************************************************************************************************************************/

function solution(N) {
    // write your code in JavaScript (Node.js 8.9.4)
    console.log(N);

    return N;
}

it('solution test', () => {
  assert.equal(solution(3), 3);
});