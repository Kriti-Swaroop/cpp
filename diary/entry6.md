# Entry #6 (2021/03/12)

- Printing binary:

```cpp
#include <bitset>
#include <iostream>
 
int main()
{
    std::bitset<8> bin1{ 0b1100'0101 };
    std::bitset<8> bin2{ 0xC5 };

    std::cout << bin1 << ' ' << bin2 << '\n';
    std::cout << std::bitset<4>{ 0b1010 } << '\n';
 
    // output
    // 11000101 11000101
    // 1010
    return 0;
}
```

- We can also create a temporary (anonymous) `std::bitset` to print a single value.
  In the above code, this line creates a temporary `std::bitset` object with 4 bits,
  initializes it with `0b1010`, prints the value in binary, and then discards the
  temporary std::bitset.

```cpp
std::cout << std::bitset<4>{ 0b1010 } << '\n';
```

- Runtime vs compile time constants:
  - Runtime constants are those whose initialization values can only be resolved
    at runtime (when your program is running), see example #1
  - Compile-time constants are those whose initialization values can be resolved
    at compile-time (when your program is compiling), see example #2
- Avoid using #define to create symbolic constants macros.

```cpp
// +++ example 1 (runtime constant) +++
// Any variable that should not be modifiable
// after initialization and whose initializer 
// is not known at compile-time should be declared 
// as const.
std::cout << "Enter your age: ";
int age{};
std::cin >> age; 
const int usersAge { age };

// +++ example 2 (compile-time constant) +++
// Any variable that should not be modifiable after 
// initialization and whose initializer is known at 
// compile-time should be declared as constexpr.
constexpr double gravity { 9.8 };
```

- Incrementing (adding 1 to) and decrementing (subtracting 1 from) a variable are both
  so common that they have their own operators.
- Note that there are two versions of each operator - a prefix version (where the
  operator comes before the operand) and a postfix version (where the operator comes
  after the operand).
- The prefix increment/decrement operators are very straightforward. First, the operand
  is incremented or decremented, and then expression evaluates to the value of the
  operand. For example:

```cpp
#include <iostream>
 
int main()
{
    int x { 5 };
    // x is incremented to 6, x is evaluated 
    // to the value 6, and 6 is assigned to y
    int y = ++x; 
    // output 6:6
    std::cout << x << ' ' << y;
    return 0;
}
```

- The postfix increment/decrement operators are trickier. First, a copy of the
  operand is made. Then the operand (not the copy) is incremented or decremented
  Finally, the copy (not the original) is evaluated. For example:

```cpp
#include <iostream>
 
int main()
{
    int x { 5 };
    // x is incremented to 6, copy of original
    // x is evaluated to the value 5, and 5 is
    // assigned to y
    int y = x++;
    // output: 6 5
    std::cout << x << ' ' << y;
    return 0;
}
```

- Let’s examine how this line 6 works in more detail. First, a temporary copy of
  x is made that starts with the same value as x (5). Then the actual x is incremented
  from 5 to 6. Then the copy of x (which still has value 5) is returned and assigned
  to y. Then the temporary copy is discarded.
- Note that the postfix version takes a lot more steps, and thus may not be as
  performant as the prefix version.
- Strongly favor the prefix version of the increment and decrement operators, as
  they are generally more performant, and you’re less likely to run into strange
  issues with them.
- A function or expression is said to have a side effect if it does anything that
  persists beyond the life of the function or expression itself.
- C++ does not define the order of evaluation for function arguments or operator
  operands.
- The comma operator (,) allows you to evaluate multiple expressions wherever a
  single expression is allowed. The comma operator evaluates the left operand,
  then the right operand, and then returns the result of the right operand.
- First the left operand of the comma operator is evaluated, which increments `x`
  from 1 to 2. Next, the right operand is evaluated, which increments `y` from 2
  to 3. The comma operator returns the result of the right operand (3), which is\
  subsequently printed to the console.

```cpp
#include <cmath>
#include <iostream>

int main()
{
    int x{1};
    int y{2};
    // output: 3
    std::cout << (++x,++y);
    return 0;
}

```

- Avoid using the comma operator, except within *for loops*.
- Avoid using operator== and operator!= with floating point operands.

```cpp
#include <cmath>
 
bool is_almost_equal(double a, double b, double epsilon)
{
    // comparison of distance between a and b
    return std::abs(a - b) <= epsilon;
}
```

- Donald Knuth, a famous computer scientist, suggested the following method in
  his book "The Art of Computer Programming, Volume II: Seminumerical Algorithm
  (Addison-Wesley, 1969)":

```cpp
#include <cmath>
#include <algorithm>

bool is_approx_equal(double a, double b, double epsilon)
{
    // true if the difference between a and b is within epsilon
    // percent of the larger of a and b
    return (std::abs(a - b) <= (std::max(std::abs(a), std::abs(b)) * epsilon));
}
```

- In a short circuit evaluation, `&&` will return `false` if the first operand
  evaluates to `false`
- Short circuit evaluation may cause Logical OR and Logical AND to not evaluate
  one operand. Avoid using expressions with side effects in conjunction with
  these operators.
- C++ doesn’t provide a logical XOR operator. However, you can easily mimic
  logical XOR using the inequality operator:

```cpp
if (a != b) { ... } // a XOR b, provided both a and b are booleans
```
