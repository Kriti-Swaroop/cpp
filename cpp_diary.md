# CPP Diary

## About

This document present in chronological order interesting things and stuff I learnt
while skimming through the language's core features. I've linked a list of references
I used for you to take a look at if you need more information.

---

## Diary

### Entry #2 (2021/03/01)

For new projects created in Visual Studio, apply the following changes:

- move all source files to the subdirector `src`
- Go to `Project/Properties/All Options` and
  - [x] set `Disable Language Extensions` to `Yes (/Za)`
  - [x] set `C++ Language Standard` to `ISO C++17 Standard (/std:c++17)`
  - [x] set `Warning Level` to `EnableAllWarnings (/Wall)`

Misc key points from todays research:

- In C++, direct memory access is not allowed. Instead, we access memory
  indirectly through an object
- In general programming, the term object typically refers to a variable, data
  structure in memory, or function. In C++, the term object has a narrower
  definition that excludes functions.
- [Different types of initialization](https://www.learncpp.com/cpp-tutorial/variable-assignment-and-initialization/):
  
```cpp
int width = 5;   // copy initialization
int width( 5 );  // direct initialization
int width { 5 }; // list initialization
```

- For simple data types (like integers), copy and direct initialization are
  essentially the same
- **Undefined behavior** occurs when the programmer does something that is
  ill-specified by the C++ language. The consequences could be almost anything,
  from crashing to producing the wrong answer to working correctly anyway.
- Using `std::endl` can be a bit inefficient, as it actually does two jobs: it
  moves the cursor to the next line, and it "flushes" the output (makes sure that
  it shows up on the screen immediately). When writing text to the console using `std::cout`, `std::cout` usually flushes output anyway (and if it doesn’t, it
  usually doesn’t matter), so having `std::endl` flush is rarely important.
- Some compilers, such as Visual Studio, will initialize the contents of memory
  to some preset value when you’re using a debug build configuration. This will
  not happen when using a release build configuration.
- Using the value from an uninitialized variable is our first example of undefined
  behavior.
- **Unary** operators act on one operand, **Binary** operators act on two operands,
  and **Ternary** operators act on three operands
- An **expression** is a combination of literals, variables, operators, and explicit function calls (not shown above) that produce a single output value
- **Statements** are used when we want the program to perform an action, **Expressions**
  are used when we want the program to calculate a value.
- Unlike some other programming languages, in C++, functions cannot be defined
  inside other functions (so-called **nested functions**).
- The C++ standard only defines the meaning of 3 status codes: `0`, `EXIT_SUCCESS`,
  and `EXIT_FAILURE`. `0` and `EXIT_SUCCESS` both mean the program executed
  successfully. `EXIT_FAILURE` means the program did not execute successfully.

```cpp
// for EXIT_SUCCESS and EXIT_FAILURE
#include <cstdlib>
 
int main()
{
    return EXIT_SUCCESS;
}
```

- Note: Failure to return a value from a function with a non-void return type
  (other than main) will result in **undefined behavior**.

```cpp
#include <string>

int get_user_input(std::string msg)
{
  std::cout << msg;
  int input{};
  std::cin >> input; 
  return input;
}
```

Remark: Template implementations always go straight into the header file. Here,
braced init is guaranteed to work, if `T` is default constructible (a non-example
would be a custom class that does not provide the default constructor).

```cpp
#include <string>
#include <type_traits>

template <typename T>
T get_user_input(std::string msg)
{
  std::cout << msg;
  T input;
  std::cin >> input; 
  return input;
}
```

The C++ specification does not define whether arguments are matched with parameters in left to right order or right to left order. When copying values, order is of no consequence. However, if the arguments are function calls, then this can be problematic:

```cpp
some_function(a(), b()); // a() or b() may be called first
```

If it is important that one argument evaluate first, you should explicitly define the order of execution, like so:

```cpp
int a_var{ a() }; // a() will always be called first
int b_var{ b() }; // b() will always be called second

// it doesn't matter whether avar or bvar are copied first because they are just values
some_function(a_var, b_var);
```

### Entry #1 (2021/02/28)

Requiring access to random number generators occurs fairly frequently, but there
are a few pitfalls that one should be wary of. Here are two articles that go a
little more into detail as to what to avoid:

- [Don't use rand(): a guide to random number generators in C++](https://codeforces.com/blog/entry/61587)
- [Generating random numbers using C++ standard library: the problems](https://codingnest.com/generating-random-numbers-using-c-standard-library-the-problems/)

The other day I have been given two code snippets that aim to address these issues:

#### Generate Random Integers

```cpp
#include <random>

int random_range(int min, int max) {
  // randomInteger in [min, max]
  static std::default_random_engine eng{std::random_device{}()};
  std::uniform_int_distribution<int> dist(min, max);
  return dist(eng);
}
```

#### Generate Random Generics

```cpp
#include <random>
#include <type_traits>

template <typename T>
T random_range(T min, T max) {
  // random Number in [min, max]
  static std::default_random_engine eng{std::random_device{}()};
  if constexpr (std::is_integral_v<T>) {
    std::uniform_int_distribution<T> dist(min, max);
    return dist(eng);
  } else {
    std::uniform_real_distribution<T> dist(min, max);
    return dist(eng);
  }
}
```

---

## References

Sources I used to study *modern* CPP:

> ### LearnCPP
>
> [1] beginner-friendly introduction, generally a good starting point\
> <https://www.learncpp.com/>
> a

> ### CPP Core Guidelines
>
> [2] in case of doubt seek help from the core guidelines
> <https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#main>
