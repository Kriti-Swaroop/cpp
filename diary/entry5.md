# Entry #5 (2021/03/04)

- C++ has two kinds of constants: literal constants, and symbolic constants.
- Literal constants (usually just called literals) are values inserted directly
  into the code. For example:

```cpp
return 5;                   // 5 is an integer literal
bool myNameIsAlex { true }; // true is a boolean literal
std::cout << 3.4;           // 3.4 is a double literal
```

- If the default type of a literal is not as desired, you can change the type of
  a literal by adding a suffix:

| Data Type | Suffix                                                    | Meaning            |
|-----------|-----------------------------------------------------------|--------------------|
| int       | `u` or `U`                                                | unsigned int       |
| int       | `I` or `L`                                                | long               |
| int       | `ul`, `uL`, `Ul`, `UL`, `lu`, `lU`, `Lu`, or `LU`         | unsigned long      |
| int       | `ll` or `LL`                                              | long long          |
| int       | `ull`, `uLL`, `Ull`, `ULL`, `llu`, `llU`, `LLu`, or `LLU` | unsigned long long |
| double    | `f` or `F`                                                | float              |
| double    | `l` or `L`                                                |  long double       |

- You generally won’t need to use suffixes for integer types, but here are examples:

```cpp
unsigned int value1 { 5u }; // 5 has type unsigned int
long value2 { 6L };         // 6 has type long
```

- There are two different ways to declare floating-point literals:

```cpp
double pi { 3.14159 };       // 3.14159 is a double literal in standard notation
double avogadro { 6.02e23 }; // 6.02 x 10^23 is a double literal in scientific notation
```

- Writing octal and hexadecimal numbers:

```cpp
#include <iostream>
 
int main()
{
    // 0b before the number means this is hexadecimal (C++14)
    int bin{ 0b1 };
    std::cout << bin << '\n';
    // 0 before the number means this is octal
    int oct{ 012 };
    std::cout << oct << '\n';
    // 0x before the number means this is hexadecimal
    int hex{ 0xF };
    std::cout << bin << '\n';
    
    return 0;
}
```

- By default, C++ prints values in decimal. However, you can tell it to print in
  other formats. Printing in decimal, octal, or hex is easy via use of `std::dec`,
  `std::oct`, and `std::hex`:

```cpp
#include <iostream>
 
int main()
{
    int x { 12 };
    // decimal (by default)
    std::cout << x << '\n';
    // hexadecimal
    std::cout << std::hex << x << '\n'; 
    // now hexadecimal
    std::cout << x << '\n';
    // octal
    std::cout << std::oct << x << '\n';
    // return to decimal
    std::cout << std::dec << x << '\n';
    // decimal
    std::cout << x << '\n';
 
    return 0;
}
```
