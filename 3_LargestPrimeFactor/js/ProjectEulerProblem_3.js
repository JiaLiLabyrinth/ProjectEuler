function largestPrimeFactor(number) {
  var largestPrimeFac = 0;
  // Edge case 1: number is less than 2
  if( number < 2 )
  {
    return largestPrimeFac;
  }

  // Find the prime numbers less than "number"
  var primeNum = [2]; // List of known primary number less than "number"
  for( var i = 3; i <= number; i++ )
  {
    var isDividible = false;
    // Test if i is a prime number
    for( var j = 0; isDividible == false && j < primeNum.length; j++ )
    {
      if( i % primeNum[j] == 0 )
      {
        isDividible = true;
      }
    }
    // If the i is not dividible by any of the known prime number, it's a prime number as well
    if( !isDividible )
    {
      primeNum.push( i );
    }
  }

  // Finding the largest prime number whick is also a factor of "number"
  for( var i = primeNum.length; i >= 0; i-- )
  {
    if( number % primeNum[i] == 0 )
    {
      largestPrimeFac = primeNum[i];
      break;
    }
  }

  return largestPrimeFac;
}

largestPrimeFactor(13195);