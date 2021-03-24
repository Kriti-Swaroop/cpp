# Entry #9 (2021/03/24)

- Global variables with internal linkage are sometimes called internal variables.
- To make a non-constant global variable internal, we use the `static` keyword.
- `const` and `constexpr` global variables have internal linkage by default

```cpp
#include <iostream>
 
// this separate internal g_x is only
// accessible within main.cpp
static int g_x { 3 };
 
int main()
{
    // uses main.cpp's g_x, prints 3
    std::cout << g_x << '\n'; 
    return 0;
}
```

- The use of `static` above is an example of a storage class specifier, which sets
  both the name's linkage and its storage duration (but not its scope).
- The most commonly used storage class specifiers are `static`, `extern`, and `mutable`.
  The term storage class specifier is mostly used in technical documentations.
- Because linkage is a property of an identifier (not of a variable), function
  identifiers have the same linkage property that variable identifiers do.
- Functions default to external linkage, but can be set to internal linkage via
  the `static` keyword:

```cpp
/* add.cpp */

// This function is declared as static, and can now be 
// used only within this file. Attempts to access it
// from another file via a function forward declaration
// will therefore fail
static int add(int x, int y)
{
    return x + y;
}
```

```cpp
/* main.cpp */
#include <iostream>

// forward declaration for function add
int add(int x, int y);
 
int main()
{
    // This program won't link, because function
    // add is not accessible outside of add.cpp
    std::cout << add(3, 4) << '\n'; 
    return 0;
}
```

## Quick Summary

```cpp
static int g_x;          // defines non-initialized internal global variable (zero initialized by default)
static int g_x{ 1 };     // defines initialized internal global variable
 
const int g_y { 2 };     // defines initialized internal global const variable
constexpr int g_y { 3 }; // defines initialized internal global constexpr variable
 
static int foo() {};     // defines internal function
```

- Functions have external linkage by default
- If a function had internal linkage instead, the linker would not be able to
  connect the function call to the function definition, and a linker error would
  result of this.
- Global variables with external linkage are sometimes called external variables.
  To make a global variable `external` (and thus accessible by other files), we
  can use the extern keyword to do so:

```cpp
/* a.cpp */
int g_x{ 2 };
extern const int g_y{ 3 };
```

- **Warning:** Although `constexpr` variables can be given external linkage via the
  `extern` keyword, they can not be forward declared, so there is no value in
  giving them external linkage.

```cpp
/* main.cpp */
int g_x { 2 };
 
extern const int g_y { 3 };
extern constexpr int g_z { 3 };
 
int main()
{
    return 0;
}
```

- Note that the extern keyword has different meanings in different contexts. In
  some contexts, extern means "give this variable external linkage". In other
  contexts, extern means "this is a forward declaration for an external variable
  that is defined somewhere else".
- To actually use an external global variable that has been defined in another
  file, you also must place a forward declaration for the global variable in any
  other files wishing to use the variable.
- **Warning:** If you want to define an uninitialized non-const global variable,
  do not use the `extern` keyword, otherwise C++ will think you're trying to make
  a forward declaration for the variable.
- Note that function forward declarations don't need the `extern` keyword - the
  compiler is able to tell whether you're defining a new function or making a
  forward declaration based on whether you supply a function body or not. Variables
  forward declarations do need the `extern` keyword to help differentiate variables
  definitions from variable forward declarations (they look otherwise identical)

```cpp
// non-constant 
int g_x;                    // variable definition (can have initializer if desired)
extern int g_x;             // forward declaration (no initializer)
 
// constant
extern const int g_y { 1 }; // variable definition (const requires initializers)
extern const int g_y;       // forward declaration (no initializer)
```

- The terms **file scope** and **global scope** tend to cause confusion, and this
  is partly due to the way they are informally used. Technically, in C++, all global
  variables have "file scope", and the linkage property controls whether they can
  be used in other files or not.
- Initialization of global variables happens as part of program startup, before
  execution of the main function. This proceeds in two phases:

1. In the **static initialization phase**, global variables with `constexpr` initializers
   (including literals) are initialized to those values. Also, global variables
   without initializers are zero-initialized.
2. The **dynamic initialization phase** is more complex and nuanced, but the gist
   of it is that global variables with non-constexpr initializers are initialized.

- **Warning:** Dynamic initialization of global variables causes a lot of problems
  in C++. Avoid it whenever possible.
- While this is simple (and fine for smaller programs), every time `constants.hpp`
  gets included into a different code file, each of these variables is copied into
  the including code file. Therefore, if `constants.hpp` gets included into 20
  different code files, each of these variables is duplicated 20 times. Header
  guards won't stop this from happening, as they only prevent a header from being
  included more than once into a single including file, not from being included
  one time into multiple different code files. This introduces two challenges:

1. Changing a single constant value would require recompiling every file that
   includes the constants header, which can lead to lengthy rebuild times for
   larger projects.
2. If the constants are large in size and can't be optimized away, this can use
   a lot of memory.

- One way to avoid these problems is by turning these constants into external
  variables, since we can then have a single variable (initialized once) that is
  shared across all files.

```cpp
/* constants.cpp */
#include "constants.h"
 
namespace constants
{
    extern const double pi { 3.14159 };
    extern const double avogadro { 6.0221413e23 };
    extern const double my_gravity { 9.2 };
}
```

```cpp
/* constants.hpp */
#pragma once

namespace constants
{
    extern const double pi;
    extern const double avogadro;
    extern const double my_gravity;
}
```

```cpp
/* main.cpp */ 
#include <iostream>
#include "constants.h"

int main()
{
    std::cout << "Enter a radius: ";
    int radius{};
    std::cin >> radius;
 
    std::cout << "The circumference is: " << 2.0 * radius * constants::pi << '\n';
 
    return 0;
}
```

- Because global symbolic constants should be namespaced (to avoid naming conflicts
  with other identifiers in the global namespace), the use of a `g_` naming prefix
  is not necessary.
- However, there are a couple of downsides to this method: First, these constants
  are now considered compile-time constants only within the file they are actually
  defined in (`constants.cpp`), not anywhere else they are used. This means that
  outside of `constants.cpp`, they can’t be used anywhere that requires a compile-time
  constant. Second, the compiler may not be able to optimize these as much.
- C++17 introduced a new concept called inline variables. In C++, the term `inline`
  has evolved to mean "multiple definitions are allowed". Thus, an inline variable
  is one that is allowed to be defined in multiple files without violating ODR.
  Inline global variables have external linkage by default.

```cpp
/* constants.hpp */
namespace constants
{
    inline constexpr double pi { 3.14159 };
    inline constexpr double avogadro { 6.0221413e23 };
    inline constexpr double my_gravity { 9.2 };
}
```

```cpp
/* main.cpp */ 
#include <iostream>
#include "constants.h"
 
int main()
{
    std::cout << "Enter a radius: ";
    int radius{};
    std::cin >> radius;
 
    std::cout << "The circumference is: " << 2.0 * radius * constants::pi << '\n';
 
    return 0;
}
```

- We can include constants.h into as many code files as we want, but these variables
  will only be instantiated once and shared across all code files.
- If you need global constants and your compiler is C++17 capable, prefer defining
  inline constexpr global variables in a header file.
