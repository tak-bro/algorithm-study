function listSquared(m, n) {
  let rootDivisors = [];
  
  for (let i = m; i <= n; i++) {
    let divisors = [];
    
    for (let j = 1; j <= i; j++) {
      // Push every divisor of numbers...
      if (i % j === 0) divisors.push(j);
    }
    
    let divisorsSquared = divisors.map(x => x * x);
    
    let sumOfDivisorsSquared = divisorsSquared.reduce((a, b) => a + b);
    
    if (Number.isInteger(Math.sqrt(sumOfDivisorsSquared))) {
      rootDivisors.push([i, sumOfDivisorsSquared]);
    }
  }
  
  return rootDivisors;
}