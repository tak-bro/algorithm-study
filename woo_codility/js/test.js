/** 
 * Testing operations and validation functions
 * with Mocha and Node.js Assert module.
 *
 */

const assert = require('assert');

/* **********************************************************************************************************************************************************
 * start soluiton
 * **********************************************************************************************************************************************************/

function pad(n, width) {
  n = n + '';
  return n.length >= width ? n : new Array(width - n.length + 1).join(' ') + n;
}

// function getWidth(A) {
//   let width = 0;

//   for (const index in A) {
//     const strElement = A[index] + '';

//     if (width < strElement.length) {
//       width = strElement.length;
//     }
//   }

//   return width;
// }

// function solution(A, K) {
//   const tmpArr = [...A];
//   const width = tmpArr.sort((a, b) => b - a)[0].toString().length;
//   const row = Math.ceil(A.length / K);

//   let curAIndex = 0;
//   let result = '';
//   let minusFence = '';

//   // get minus string
//   for (let i = 0; i < width; i++) {
//     minusFence += '-';
//   }

//   // check length
//   if (A.length < K) {
//     K = A.length;
//   }

//   // draw whole table
//   for (let rowNumber = 0; rowNumber < row; rowNumber++) {
//     let isLast = false;
//     // draw upper fence
//     for (let i = 0; i < K; i++) {
//       result += '+';
//       result += minusFence;
//     }
//     result += '+';
//     result += '\n';

//     for (let j = 0; j < K; j++) {
//       if (j === 0) {
//         result += '|';
//       }

//       if (A[curAIndex]) {
//         result += pad(A[curAIndex], width);
//       } else {
//         result += '';
//         isLast = true;
//       }

//       if (!isLast) {
//         result += '|';
//       }
//       curAIndex += 1;
//     }

//     result += '\n';
//   }

//   // draw lower fence
//   for (let i = 0; i < K; i++) {
//     result += '+';
//     result += minusFence;
//   }
//   result += '+';

//   console.log(result);
// }

// solution([4, 35, 80, 123, 12345, 44, 8, 23, 12321, 12312333, 12321], 4);


function pad(n, width) {
  n = n + '';
  return n.length >= width ? n : new Array(width - n.length + 1).join(' ') + n;
}

function getWidth(A) {
  let width = 0;

  for (const index in A) {
      const strElement = A[index] + '';

      if (width < strElement.length) {
          width = strElement.length;
      }
  }

  return width;
}

function solution(A, K) {
  const width = getWidth(A);
  const row = Math.ceil(A.length / K);

  let result = '';
  let minusFence = ''
  let curAIndex = 0;
  let lowerFenceLength = (A.length < K) ? A.length : K;

  // get minus string
  for (let i = 0; i < width; i++) {
      minusFence += '-';
  }

  // set K for width
  if (A.length < K) {
      K = A.length;
  }

  // draw whole table
  for (let rowNumber = 0; rowNumber < row; rowNumber++) {
      // draw upper fence
      for (let i = 0; i < K; i++) {
          result += '+';
          result += minusFence;
      }
      result += '+';

      result += '\n';

      for (let j = 0; j < K; j++) {
          if (j === 0) {
              result += '|';
          }

          if (A[curAIndex]) {
              result += pad(A[curAIndex], width);

              result += '|';
              curAIndex += 1;
          } else {
              lowerFenceLength = j;
              break;
          }
      }

      result += '\n';
  }

  // draw lower fence
  for (let i = 0; i < lowerFenceLength; i++) {
      result += '+';
      result += minusFence;
  }
  result += '+';

  console.log(result);
}

solution([4, 35, 80, 123, 12345, 44, 8,123,123124,234,3244,543,5123,123,123123,123,123,12,312,312,3,123,123,213,213,12,312,321,3,123,12], 5)