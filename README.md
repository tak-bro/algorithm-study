# CodeWars

### Table of Contents 
- [Alphabet war](#alphabet-war)
- [The takeWhile Function](#the-takewhile-function)
- [Mr. Safety's treasures](#mr-safetys-treasures)
- [A disguised sequence (I)](#a-disguised-sequence-i)
- [Integers: Recreation One](#integers-recreation-one)
- [Unwanted dollars](#unwanted-dollars)
- [Directions Reduction](#directions-reduction)
- [Sort the odd](#sort-the-odd)
- [Sum The Tree](#sum-the-tree)
- [Ball Upwards](#ball-upwards)
- [Complete The Pattern #8 - Number Pyramid](#complete-the-pattern-8---number-pyramid)
- [Count the Digit](#count-the-digit)
- [Help the bookseller](#help-the-bookseller)
- [Don't give me five!](#dont-give-me-five!)
- [Bouncing ball](#bouncing-ball)
- [Parts of a list](#parts-of-a-list)
- [Couting Duplicates](#couting-duplicates)
- [Averages of numbers](#averages-of-numbers)

----
####[Alpabet war](https://www.codewars.com/kata/alphabet-war-airstrike-letters-massacre/cpp)
- [My Solution](https://github.com/njir/Algorithm-study/tree/master/codewars/Alphabet_war.cpp)

----

#### The takeWhile Function
- The first is the sequence of values, and the second is the predicate function. The function does not change the value of the original sequence.
```
std::function<bool (int)> isEven = [](int value)
{
    return abs(value) % 2 == 0;
};

std::vector<int> seq = { 2, 4, 6, 8, 1, 2, 5, 4, 3, 2 };

takeWhile(seq, pred); // -> { 2, 4, 6, 8 }
```
- Your task is to implement the takeWhile function.
- [My Solution](https://github.com/njir/Algorithm-study/tree/master/codewars/TakeWhile.cpp)

----

#### Mr. Safety's treasures
- Can you crack his numeric locks? Mr. Safety's treasures wait for you. Write an algorithm to open his numeric locks. Can you do it without his Nokia 3310?
- Input
  - The str or message (Python) input string consists of lowercase and upercase characters. It's a real object that you want to unlock.
- Output
  - Return a string that only consists of digits.
- Example
```
unlock("Nokia")  // => 66542
unlock("Valut")  // => 82588
unlock("toilet") // => 864538
```
- [My Solution](https://github.com/njir/Algorithm-study/tree/master/codewars/Unlock.cpp)

----

#### A disguised sequence (I)
- Given u0 = 1, u1 = 2 and the relation 6unun+1-5unun+2+un+1un+2 = 0 calculate un for any integer n >= 0.
- Examples
```
fct(n) returns un: fct(17) -> 131072, fct(21) -> 2097152
```
- Remark: You can take two points of view to do this kata:
  - the first one purely algorithmic from the definition of un
  - the second one - not at all mandatory, but as a complement - is to get a bit your head around and find which sequence is hidden behind un.
- [Solution](https://github.com/njir/Algorithm-study/tree/master/codewars/DisguisedSequence.cpp)

----

#### Integers: Recreation One
- Divisors of 42 are : 1, 2, 3, 6, 7, 14, 21, 42. These divisors squared are: 1, 4, 9, 36, 49, 196, 441, 1764. The sum of the squared divisors is 2500 which is 50 * 50, a square!
- Given two integers m, n (1 <= m <= n) we want to find all integers between m and n whose sum of squared divisors is itself a square. 42 is such a number.
- The result will be an array of arrays(in C an array of Pair), each subarray having two elements, first the number whose squared divisors is a square and then the sum of the squared divisors.
- Examples:
```
list_squared(1, 250) --> [[1, 1], [42, 2500], [246, 84100]]
list_squared(42, 250) --> [[42, 2500], [246, 84100]]
```
- [Solution](https://github.com/njir/Algorithm-study/tree/master/codewars/ListSquared.js)
  - not my solution 

----

#### Unwanted dollars
- do you put the $ sign in, or not? Inevitably, some people will type a $ sign and others will leave it out. The instructions could be made clearer - but that won't help those annoying people who never read instructions anyway.
- A better solution is to write code that can handle the input whether it includes a $ sign or not.
- So, we need a simple function that converts a string representing a number (possibly with a $ sign in front of it) into the number itself.
- Remember to consider negative numbers (the - sign may come either before or after the $ sign, if there is one), and any extraneous space characters (leading, trailing, or around the $ sign) that the users might put in. You do not need to handle trailing characters other than spaces (e.g. "1.2 3"). If the given string does not represent a number, (either with or without a $ sign), return 0.0 .
- [My Solution](https://github.com/njir/Algorithm-study/tree/master/codewars/UnwantedDollars.cpp)

----


#### Directions Reduction
- Write a function dirReduc which will take an array of strings and returns an array of strings with the needless directions removed (W<->E or S<->N side by side).
- The Haskell version takes a list of directions with data Direction = North | East | West | South. The Clojure version returns nil when the path is reduced to nothing. The Rust version takes a slice of enum Direction {NORTH, SOUTH, EAST, WEST}.
- Examples: 
```
Examples
dirReduc(["NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"]) => ["WEST"]
dirReduc(["NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH"]) => []
```

- [My Solution](https://github.com/njir/Algorithm-study/tree/master/codewars/DirectionsReduction.cpp)

----

#### Sort the odd
- You have an array of numbers.
- Your task is to sort ascending odd numbers but even numbers must be on their places.
- Zero isn't an odd number and you don't need to move it. If you have an empty array, you need to return it.
- Example:
```
sortArray([5, 3, 2, 8, 1, 4]) == [1, 3, 2, 8, 5, 4]
```

- [My Solution](https://github.com/njir/Algorithm-study/tree/master/codewars/SortOdd.cpp)

----

#### Sum The Tree
- Given a node object representing a binary tree:
```
Node:
  value: <int>,
  left: <Node> or null,
  right: <Node> or null
```

- In C++:
```
struct node
{
  int value;
  node* left;
  node* right;
}
```
- write a function that returns the sum of all values, including the root.
- Examples:
```
10
| \
1  2
=> 13
```
- [My Solution](https://github.com/njir/Algorithm-study/tree/master/codewars/SumOfTrees.cpp)

----


#### Ball Upwards
- You throw a ball vertically upwards with an initial speed v (in km per hour). 
- The height h of the ball at each time t is given by h = v*t - 0.5*g*t*t where g is Earth's gravity (g ~ 9.81 m/s**2). 
- A device is recording at every tenth of second the height of the ball. 
- For example:
```
with v = 15 km/h the device gets something of the following form: (0, 0.0), (1, 0.367...), (2, 0.637...), (3, 0.808...), (4, 0.881..) ... 
where the first number is the time in tenth of second and the second number the height in meter.

max_ball(15) should return 4
max_ball(25) should return 7
```
- [My Solution](https://github.com/njir/Algorithm-study/tree/master/codewars/BallUpwards.cpp)

----

#### Complete The Pattern #8 - Number Pyramid
- You have to write a function pattern which creates the following Pattern(See Examples) upto n(parameter) number of rows.
- If the Argument is 0 or a Negative Integer then it should return "" i.e. empty string.
- All the lines in the pattern have same length i.e equal to the number of characters in the last line. Range of n is (-∞,100]
- Examples: 
```
pattern(5):

    1    
   121   
  12321  
 1234321 
123454321
```
- [Solution](https://github.com/njir/Algorithm-study/tree/master/codewars/CompleteThePattern.cpp)
  - very clever
   
----

#### Count the Digit
- Take an integer n (n >= 0) and a digit d (0 <= d <= 9) as an integer. Square all numbers k (0 <= k <= n) between 0 and n. Count the numbers of digits d used in the writing of all the k**2. Call nb_dig (or nbDig or ...) the function taking n and d as parameters and returning this count.
- Examples:
```
n = 10, d = 1, the k*k are 0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100
We are using the digit 1 in 1, 16, 81, 100. The total count is then 4.

nb_dig(25, 1):
the numbers of interest are
1, 4, 9, 10, 11, 12, 13, 14, 19, 21 which squared are 1, 16, 81, 100, 121, 144, 169, 196, 361, 441
so there are 11 digits `1` for the squares of numbers between 0 and 25.
```
> Note that 121 has twice the digit 1.
- [Solution](https://github.com/njir/Algorithm-study/tree/master/codewars/HelpTheBookseller.cpp)
  - I added someone else's solution instead of my solution since it is clever solution.

----

#### Help the bookseller.
- A bookseller has lots of books classified in 26 categories labeled A, B, ... Z. Each book has a code c of 3, 4, 5 or more capitals letters. The 1st letter of a code is the capital letter of the book category. In the bookseller's stocklist each code c is followed by a space and by a positive integer n (int n >= 0) which indicates the quantity of books of this code in stock.
- In a given stocklist all codes have the same length and all numbers have their own same length (can be different from the code length).
- For example an extract of one of the stocklists could be:
```
L = {"ABART 20", "CDXEF 50", "BKWRK 25", "BTSQZ 89", "DRTYM 60"}.
```
- In this stocklist all codes have a length of five and all numbers have a length of two. You will be given a stocklist (e.g. : L) and a list of categories in capital letters e.g :
```
  M = {"A", "B", "C", "W"}
```
- and your task is to find all the books of L with codes belonging to each category of M and to sum their quantity according to each category. For the lists L and M of example you have to return the string (in Haskell/Clojure a list of pairs):
```
  (A : 20) - (B : 114) - (C : 50) - (W : 0)
```
- where A, B, C, W are the categories, 20 is the sum of the unique book of category A, 114 the sum corresponding to "BKWRK" and "BTSQZ", 50 corresponding to "CDXEF" and 0 to category 'W' since there are no code beginning with W. If L or M are empty return string is "" (Clojure should return an empty array instead).
- [Solution](https://github.com/njir/Algorithm-study/tree/master/codewars/HelpTheBookseller.cpp)

----


#### Don't give me five!
- In this kata you get the start number and the end number of a region and should return the count of all numbers except numbers with a 5 in it. The start and the end number are both inclusive!
- The result may contain fives. ;-)
- The start number will always be smaller than the end number. Both numbers can be also negative!
- Examples:
```
1,9 -> 1,2,3,4,6,7,8,9 -> Result 8
4,17 -> 4,6,7,8,9,10,11,12,13,14,16,17 -> Result 12
```
- [My Solution](https://github.com/njir/Algorithm-study/tree/master/codewars/DontGiveMeFive.cpp)
```
// Best Solution I think
bool containsFive(int num) {
  for (; num > 0; num /= 10) {
    if (num%10 == 5) { return true; }
  }
  return false;
}

int dontGiveMeFive(int start, int end) {
  int count = 0;
  for (int i = start; i <= end; ++i) {
    if (!containsFive(abs(i))) { count++; }
  }
  return count;
}
```

----

#### Bouncing ball
- A child plays with a ball on the nth floor of a big building. The height of this floor is known:
    - (float parameter "h" in meters, h > 0) .
- He lets out the ball. The ball rebounds for example to two-thirds: of its height.
    - (float parameter "bounce", 0 < bounce < 1) 
- His mother looks out of a window that is 1.5 meters from the ground:
    - (float parameters window < h).
- How many times will the mother see the ball either falling or bouncing in front of the window
    - (return a positive integer unless conditions are not fulfilled in which case return -1) ?
- Note: You will admit that the ball can only be seen if the height of the rebouncing ball is stricty greater than the window parameter.
- Example:
```
h = 3, bounce = 0.66, window = 1.5, result is 3
h = 3, bounce = 1, window = 1.5, result is -1
```
- [My Solution](https://github.com/njir/Algorithm-study/tree/master/codewars/BouncingBalls.cpp)

----


#### Parts of a list
- Write a function partlist that gives all the ways to divide a list (an array) of at least two elements into two non-empty parts.
    - Each two non empty parts will be in a pair (or an array for languages without tuples or a structin C - C: see Examples test Cases - )
    - Each part will be in a string
    - Elements of a pair must be in the same order as in the original array.
- Example:
```
a = ["az", "toto", "picaro", "zone", "kiwi"] --> 
answer: [["az", "toto picaro zone kiwi"], ["az toto", "picaro zone kiwi"], ["az toto picaro", "zone kiwi"], ["az toto picaro zone", "kiwi"]]
```
- [My Solution](https://github.com/njir/Algorithm-study/tree/master/codewars/PartOfaList.cpp)


----

#### Couting Duplicates
- Write a function that will return the count of distinct case-insensitive alphabetic characters and numeric digits that occur more than once in the input string. The input string can be assumed to contain only alphanumeric characters, including digits, uppercase and lowercase alphabets.
- Example:
```
"abcde" -> 0 # no characters repeats more than once
"aabbcde" -> 2 # 'a' and 'b'
"aabbcdeB" -> 2 # 'a' and 'b'
"indivisibility" -> 1 # 'i'
"Indivisibilities" -> 2 # 'i' and 's'
"aa11" -> 2 # 'a' and '1'
```
- [My Solution](https://github.com/njir/Algorithm-study/tree/master/codewars/CoutingDuplicates.cpp)

----

#### Averages of numbers
- Write a method, that gets an array of integer-numbers and return an array of the averages of each integer-number and his follower, if there is one.
- Example:
```
Input:  [ 1, 3, 5, 1, -10]
Output:  [ 2, 4, 3, -4.5]
```
- [My Solution](https://github.com/njir/Algorithm-study/tree/master/codewars/AveragesNumbers.cpp)


----

## Codeforces

##### simple c++ code to solve problemset in codeforces.com
- 2015.05.25 solved : 1A, 4A, 71A, 118A, 282A, 158B
- 2015.05.28 solved : 96A, 131A, 266A, 133A, 112A
- 2015.05.29 solved : 339A, 281A
- 2015.06.05 solved : 236A, 110A, 467A
- 2015.10.10 solved : 41A, 61A, 443A
- 2015.10.14 solved : 102B
