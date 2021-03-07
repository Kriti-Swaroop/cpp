# Entry #3 (2021/03/02)

- Local variables are destroyed in the opposite order of creation when their scope
  terminates
- An object’s lifetime is defined to be the time between its creation and destruction
- These rules are guarantees governed by compilers; at times they may be created before
  entering scope or destroyed after going out of scope for optimization purposes
- Despite all that, variables can stil not be used before the point of definition
  (even if the compiler opts to create them before then).
- A forward declaration allows us to tell the compiler about the existence of an
  identifier before actually defining the identifier:

```cpp
#include <iostream>
 
// a declaration is all that is needed to satisfy the compiler
int add(int x, int y);
 
int main()
{
    // this works because of the forward declaration
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n';
    return 0;
}

// the function definition
int add(int x, int y)
{
    return x + y;
}
```

- If a forward declaration is made, but the function is never called, the program will
  compile and run fine. However, if a forward declaration is made and the function is
  called, but the program never defines the function, the program will compile okay, but
  the linker will complain that it can’t resolve the function call.
- The **one definition rule** (or ODR for short) is a well-known rule in C++. The
  DR has three parts:
  
1. Within a given *file*, a function, object, type, or template can only have
   one definition.
2. Within a *given program*, an object or normal function can only have one
   definition. This distinction is made because programs can have more than one
   file
3. Types, templates, inline functions, and variables are allowed to have identical
   definitions in different files.

- Note: Functions that share an identifier but have different parameters are
  considered to be distinct functions (this is called function overloading)
- Most naming collisions occur in two cases:

1. Two (or more) definitions for a function (or global variable) are introduced
   into separate files that are compiled into the same program. *This will result
   in a linker error*.
2. Two (or more) definitions for a function (or global variable) are introduced
   into the same file (often via an #include). *This will result in a compiler error*.

- A **namespace** is a region that allows you to declare names inside of it for
  the purpose of disambiguation
- The namespace provides a scope (called namespace scope) to the names declared
  inside of it.
- In C++, any name that is not defined inside a class, function, or a namespace is
  considered to be part of an implicitly defined namespace called the **global
  namespace**.
- A **using directive** tells the compiler to check a specified namespace when trying
  to resolve an identifier that has no namespace prefix

```cpp
#include <iostream>

// avoid using directives at the top of your program.
// They violate the reason why namespaces were added
// in the first place!
using namespace std;
 
int main()
{
    cout << "Hello world!" << '\n';
    return 0;
}
```

- Prior to compilation, the code file goes through a phase known as **translation**.
- A code file with translations applied to it is called a **translation unit**.
- **Preprocessor directives** are instructions that tell the preprocessor to perform
  specific particular text manipulation tasks
- The `#define` **directive** can be used to create a macro:

```cpp
#include <iostream>
 
#define MY_NAME "ヘンタイちゃん"
 
int main()
{
    std::cout << "My name is: " << MY_NAME << '\n';
    return 0;
}
```

- The preprocessor converts the above into the following:

```cpp
#include <iostream>
 
int main()
{
    std::cout << "My name is: " << "ヘンタイちゃん" << '\n';
    return 0;
}
```

- The **conditional compilation preprocessor directives** allow you to specify under
  what conditions something will or won’t compile:

```cpp
#include <iostream>
 
#define PRINT_FOO
 
int main()
{
#ifdef PRINT_FOO
    std::cout << "FOO\n";
#endif
 
#ifdef PRINT_BAR
    std::cout << "BAR\n";
#endif
 
    return 0;
}
```

- `#ifndef` is the opposite of `#ifdef`
- Directives are resolved before compilation, from top to bottom on a file-by-file
  basis. Therefore, attempts to scope directives don't change the behavior of the
  program. For general readability, you’ll generally want to `#define` identifiers
  outside of functions.
- Header files should generally not contain function and variable definitions, so
  as not to violate the one definition rule. An exception is made for symbolic constants
- Use a `.hpp` suffix when naming your header files.
- When including a header file from the standard library, use the no extension
  version (without the `.h`) if it exists. User-defined headers should still use
  a `.hpp` extension.
- It’s common that a header file will need a declaration or definition that lives
  in a different header file. Because of this, header files will often `#include`
  other header files.
- If your header files are written properly and #include everything they need,
  the order of inclusion shouldn’t matter.
- **Best Practice Tip**: Order your `#includes` as follows:

1. standard library headers
2. third-party library headers
3. your own user-defined headers

- with the headers in each section sorted alphabetically.
- Header guards are conditional compilation directives that take the following form:

```cpp
#ifndef SOME_UNIQUE_NAME_HERE
#define SOME_UNIQUE_NAME_HERE
 
// your declarations (and certain types of definitions) here
 
#endif
```

- Many compilers support a simpler, alternate form of header guards using the
  `#pragma` directive:

```cpp
#pragma once
 
// your code here
```
