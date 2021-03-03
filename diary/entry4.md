# Entry #4 (2021/03/03)

- You can use conditional preprocessor directives to debug your code:

```cpp
#include <iostream>
 
#define ENABLE_DEBUG
 
int getUserInput()
{
#ifdef ENABLE_DEBUG
    std::cerr << "getUserInput() called" << '\n';
#endif
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;
    return x;
}
 
int main()
{
#ifdef ENABLE_DEBUG
    std::cerr << "main() called\n";
#endif
    int x{ getUserInput() };
    std::cout << "You entered: " << x;
 
    return 0;
}
```

- The call stack is a list of all the active functions that have been called to
  get to the current point of execution
- In Visual Studio, the call stack window can be found via `Debug menu/Windows/Call Stack`.
  Note that you have to be in a debug session to activate this window.
- Many of the types defined in newer versions of C++ (e.g. std::nullptr_t) use a `_t`
  suffix. This suffix means `type`, and it’s a common nomenclature applied to
  modern types. If you see something with a `_t` suffix, it’s probably a type.
  But many types don’t have a `_t` suffix, so this isn’t consistently applied.
- C++ only guarantees that each fundamental data types will have a minimum size:

| Character      | Type        | Min. Size | Note             |
|----------------|-------------|-----------|------------------|
| boolean        | bool        | 1 byte    |                  |
| character      | char        | 1 byte    | Always exactly 1 |
|                | wchar_t     | 1 byte    |                  |
|                | char16_t    | 2 byte    | C++11 type       |
|                | char32_t    | 4 byte    | C++11 type       |
| integer        | short       | 2 byte    |                  |
|                | int         | 2 byte    |                  |
|                | long        | 4 byte    |                  |
|                | long long   | 8 byte    |                  |
| floating point | float       | 4 byte    | C99/C++11 type   |
|                | double      | 8 byte    |                  |
|                | long double | 8 byte    |                  |

- For maximum compatibility, you shouldn’t assume that variables are larger than
  the specified minimum size.
- You might assume that types that use less memory would be faster than types that
  more memory. This is not always true. CPUs are often optimized to process data
  of a certain size (e.g. 32 bits), and types that match that size may be quicker.
  On such a machine, a 32-bit int could be faster than a 16-bit short or an 8-bit char.
- Signed integer overflow will result in undefined behavior.
- Be careful when using integer division, as you will lose any fractional parts of
  the quotient. However, if it’s what you want, integer division is safe to use,
  as the results are predictable.
- If you need to protect a function against negative inputs, use an assertion or
  exception instead
- New programmers often use unsigned integers to represent non-negative data, or to take advantage of the additional range. Bjarne Stroustrup, the designer of C++, said,
  
> "Using an unsigned instead of an int to gain one more bit to represent positive
> integers is almost never a good idea".

- To help with cross-platform portability, C99 defined a set of fixed-width integers
  (in the stdint.h header) that are guaranteed to have the same size on any architecture.
- The above fixed-width integers should be avoided, as they may not be defined on
  all target architectures.
- Favor the `std::int_fast#_t` and `std::int_least#_t` integers when you need an
  integer guaranteed to be at least a certain minimum size.
- Avoid the 8-bit fixed-width integer types. If you do use them, note that they
  are often treated like chars.
- **Integer best practices:**
  - `int` should be preferred when the size of the integer doesn’t matter (e.g.
  the number will always fit within the range of a 2 byte signed integer). For
  example, if you’re asking the user to enter their age, or counting from 1 to 10,
  it doesn’t matter whether int is 16 or 32 bits (the numbers will fit either way).
  - If you need a variable guaranteed to be a particular size and want to favor
  performance, use `std::int_fast#_t`.
  - If you need a variable guaranteed to be a particular size and want to favor
  memory conservation over performance, use `std::int_least#_t`.
- `std::size_t` is defined as an unsigned integral type, and it is typically used
  to represent the size or length of objects.
- `std::size_t` is guaranteed to be unsigned and at least 16 bits
- Always make sure the type of your literals match the type of the variables they’re
  being assigned to or used to initialize. Otherwise an unnecessary conversion will result, possibly with a loss of precision.
- When outputting floating point numbers, std::cout has a default precision of 6,
  i.e. it assumes all floating point variables are only significant to 6 digits
  (the minimum precision of a float), and hence it will truncate anything after that.
- Also note that std::cout will switch to outputting numbers in scientific notation
  in some cases.
- **Favor double over float unless space is at a premium, as the lack of precision
  in a float will often lead to inaccuracies.**
- Rounding errors make floating point comparisons tricky:

```cpp
#include <iomanip> // for std::setprecision()
#include <iostream>
 
int main()
{
    double d{0.1};
    std::cout << d << '\n'; 
    std::cout << std::setprecision(17);
    std::cout << d << '\n';
    return 0;

    // output:
    // 0.1
    // 0.10000000000000001
}
```

- Rounding errors can have unexpected consequences:

```cpp
#include <iomanip>
#include <iostream>
 
int main()
{
    std::cout << std::setprecision(17);
 
    double d1{ 1.0 };
    std::cout << d1 << '\n';

    // should equal 1.0
    double d2{ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 };
    std::cout << d2 << '\n';

    // output
    // 1
    // 0.99999999999999989

}
```

- **Rounding errors aren’t the exception -- they’re the rule. Never assume your
  floating point numbers are exact.**
- Table of Escape Sequences:

| Name            | Symbol  | Meaning                                          |
|-----------------|---------|--------------------------------------------------|
| Backspace       | `\a`    | Makes an alert, such as a beep                   |
| Formfeed        | `\b`    | Moves the cursor back one space                  |
| Formfeed        | `\f`    | Moves the cursor to the next logical page        |
| Newline         | `\n`    | Moves the cursor to the next line                |
| Carriage Return | `\r`    | Moves the cursor to the beginning of a line      |
| Horizontal Tab  | `\t`    | Prints a horizontal tab                          |
| Vertical Tab    | `\v`    | Prints a vertical tab                            |
| Single Quote    | `\'`    | Prints a single quote                            |
| Double Quote    | `\"`    | Prints a double quote                            |
| Backslash       | `\\`    | Prints a backslash                               |
| Question Mark   | `\?`    | Prints a question mark (No longer relevant)      |
| Hex Number      | `\x(n)` | Translates into char represented by a hex number |

- Always put stand-alone chars in single quotes (e.g. `'t'` or `'\n'`, not `"t"`
  or `"\n")`. This helps the compiler optimize more effectively.
- Use `std::getline()` to input text:

```cpp
#include <string>
#include <iostream>
 
int main()
{
    std::cout << "Enter your full name: ";
    std::string name{};
    std::getline(std::cin, name);
 
    std::cout << "Enter your age: ";
    std::string age{};
    std::getline(std::cin, age);
 
    std::cout << "Your name is " << name << " and your age is " << age << '\n';
 
    return 0;
}
```
