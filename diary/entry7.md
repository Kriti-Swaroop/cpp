# Entry #7 (2021/03/13)

- When individual bits of an object are used as Boolean values, the bits are
  called bit flags.
- In computing, a flag is a value that acts as a signal for some function or
  process. Analogously, in real life, a mailbox flag is used to signal that
  there is something inside the mailbox, so the mailbox doesn’t have to be
  opened to check.
- To define a set of bit flags, we’ll typically use an unsigned integer of the
  appropriate size (8 bits, 16 bits, 32 bits, etc… depending on how many flags
  we have), or std::bitset.

```cpp
#include <bitset>
// 8 bits in size means room for 8 flags
std::bitset<8> my_bit_set {}; 
```

- Bit manipulation is one of the few times when you should unambiguously use
  unsigned integers (or std::bitset).
- std::bitset provides 4 key functions that are useful for doing bit
  manipulation:
  - `test()` allows us to query whether a bit is a 0 or 1
  - `set()` allows us to turn a bit on (this will do nothing if the bit is
    already on)
  - `reset()` allows us to turn a bit off (this will do nothing if the bit is
    already off)
  - `flip()` allows us to flip a bit value from a 0 to a 1 or vice versa

```cpp
#include <bitset>
#include <iostream>
 
int main()
{
    // we need 8 bits, start with bit pattern 0000 0101
    std::bitset<8> bits{ 0b0000'0101 }; 
    bits.set(3);    // set bit position 3 to 1 (now we have 0000 1101)
    bits.flip(4);   // flip bit 4 (now we have 0001 1101)
    bits.reset(4);  // set bit 4 back to 0 (now we have 0000 1101)
 
    std::cout << "All the bits: " << bits << '\n';
    std::cout << "Bit 3 has value: " << bits.test(3) << '\n';
    std::cout << "Bit 4 has value: " << bits.test(4) << '\n';

    // output
    // All the bits: 00001101
    // Bit 3 has value: 1
    // Bit 4 has value: 0
 
    return 0;
}
```

- C++ provides 6 bit manipulation operators, often called bitwise operators:

| Operator    | Symbol | Form     | Operation                                     |
|-------------|--------|----------|-----------------------------------------------|
| left shift  | `<<`   | `x << y` | all bits in `x` are shifted left by `y` bits  |
| right shift | `>>`   | `x >> y` | all bits in `x` are shifted right by `y` bits |
| right NOT   | `~`    | `~x`     | all bits in `x` flipped                       |
| bitwise AND | `&`    | `x & y`  | each bit in `x` AND each bit in `y`           |
| bitwise OR  | `\|`   | `x \| y` | each bit in `x` OR each bit in `y`            |
| bitwise XOR | `^`    | `x ^ y`  | each bit in `x` XOR each bit in `y`           |

- Bitwise left shift (`<<`) and bitwise right shift (`>>`) operators:

```
0011 << 1 is 0110
0011 << 2 is 1100
0011 << 3 is 1000
```

```
1100 >> 1 is 0110
1100 >> 2 is 0011
1100 >> 3 is 0001
```

- Note that in the third case we shifted a bit off the right end of the number,
  so it is lost.
- Similar to the arithmetic assignment operators, C++ provides bitwise assignment
  operators in order to facilitate easy modification of variables.

| Operator               | Symbol | Form      | Operation                   |
|------------------------|--------|-----------|-----------------------------|
| Left shift assignment  | `<<=`  | `x <<= y` | Shift `x` left by `y` bits  |
| Right shift assignment | `>>=`  | `x >>= y` | Shift `x` right by `y` bits |
| Bitwise OR assignment  | `\|=`  | `x \|= y` | Assign `x \| y` to `x`      |
| Bitwise AND assignment | `&=`   | `x &= y`  | Assign `x & y` to `x`       |
| Bitwise XOR operator   | `^=`   | `x ^= y`  | assign `x ^ y` to `x`       |

```cpp
#include <bitset>
#include <iostream>
 
int main()
{
    std::bitset<4> bits { 0b0100 };
    bits >>= 1;
    std::cout << bits;
 
    return 0;
}
```

- A bit mask is a predefined set of bits that is used to select which specific
  bits will be modified by subsequent operations.
- Defining bit masks in C++14 (seel code snippet below)
- To determine if a bit is on or off, we use bitwise AND in conjunction with the
  bit mask for the appropriate bit:

```cpp
#include <cstdint>
#include <iostream>

int main()
{
  constexpr std::uint_fast8_t mask0{ 0b0000'0001 }; // represents bit 0
  constexpr std::uint_fast8_t mask1{ 0b0000'0010 }; // represents bit 1
  constexpr std::uint_fast8_t mask2{ 0b0000'0100 }; // represents bit 2 
  constexpr std::uint_fast8_t mask3{ 0b0000'1000 }; // represents bit 3
  constexpr std::uint_fast8_t mask4{ 0b0001'0000 }; // represents bit 4
  constexpr std::uint_fast8_t mask5{ 0b0010'0000 }; // represents bit 5
  constexpr std::uint_fast8_t mask6{ 0b0100'0000 }; // represents bit 6
  constexpr std::uint_fast8_t mask7{ 0b1000'0000 }; // represents bit 7

  // 8 bits in size means room for 8 flags
  std::uint_fast8_t flags{ 0b0000'0101 };

  std::cout << "bit 0 is " << ((flags & mask0) ? "on\n" : "off\n");
  std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");

  // output
  // bit 0 is on
  // bit 1 is off
}
```

- To set (turn on) a bit, we use bitwise OR equals (operator `\|=`) in conjunction
  with the bit mask for the appropriate bit:

```cpp
#include <cstdint>
#include <iostream>

int main()
{
  constexpr std::uint_fast8_t mask0{ 0b0000'0001 }; // represents bit 0
  constexpr std::uint_fast8_t mask1{ 0b0000'0010 }; // represents bit 1
  constexpr std::uint_fast8_t mask2{ 0b0000'0100 }; // represents bit 2 
  constexpr std::uint_fast8_t mask3{ 0b0000'1000 }; // represents bit 3
  constexpr std::uint_fast8_t mask4{ 0b0001'0000 }; // represents bit 4
  constexpr std::uint_fast8_t mask5{ 0b0010'0000 }; // represents bit 5
  constexpr std::uint_fast8_t mask6{ 0b0100'0000 }; // represents bit 6
  constexpr std::uint_fast8_t mask7{ 0b1000'0000 }; // represents bit 7

  // 8 bits in size means room for 8 flags
  std::uint_fast8_t flags{ 0b0000'0101 };

  std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");
  // turn on bit 1
  flags |= mask1;
  std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");

  // output
  // bit 0 is off
  // bit 1 is on
}
```

- We can also turn on multiple bits at the same time using Bitwise OR:

```cpp
flags |= (mask4 | mask5); // turn bits 4 and 5 on at the same time
```

- To clear a bit (turn off), we use Bitwise AND and Bitwise NOT together:

```cpp
#include <cstdint>
#include <iostream>

int main()
{
  constexpr std::uint_fast8_t mask0{ 0b0000'0001 }; // represents bit 0
  constexpr std::uint_fast8_t mask1{ 0b0000'0010 }; // represents bit 1
  constexpr std::uint_fast8_t mask2{ 0b0000'0100 }; // represents bit 2 
  constexpr std::uint_fast8_t mask3{ 0b0000'1000 }; // represents bit 3
  constexpr std::uint_fast8_t mask4{ 0b0001'0000 }; // represents bit 4
  constexpr std::uint_fast8_t mask5{ 0b0010'0000 }; // represents bit 5
  constexpr std::uint_fast8_t mask6{ 0b0100'0000 }; // represents bit 6
  constexpr std::uint_fast8_t mask7{ 0b1000'0000 }; // represents bit 7

  // 8 bits in size means room for 8 flags
  std::uint_fast8_t flags{ 0b0000'0101 };

  std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");
  // turn off bit 2
  flags &= ~mask2;
  std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");

  // output
  // bit 0 is off
  // bit 1 is on
}
```

- To toggle a bit state, we use Bitwise XOR:

```cpp
#include <cstdint>
#include <iostream>

int main()
{
  constexpr std::uint_fast8_t mask0{ 0b0000'0001 }; // represents bit 0
  constexpr std::uint_fast8_t mask1{ 0b0000'0010 }; // represents bit 1
  constexpr std::uint_fast8_t mask2{ 0b0000'0100 }; // represents bit 2 
  constexpr std::uint_fast8_t mask3{ 0b0000'1000 }; // represents bit 3
  constexpr std::uint_fast8_t mask4{ 0b0001'0000 }; // represents bit 4
  constexpr std::uint_fast8_t mask5{ 0b0010'0000 }; // represents bit 5
  constexpr std::uint_fast8_t mask6{ 0b0100'0000 }; // represents bit 6
  constexpr std::uint_fast8_t mask7{ 0b1000'0000 }; // represents bit 7

  // 8 bits in size means room for 8 flags
  std::uint_fast8_t flags{ 0b0000'0101 };

  std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");
  // flip bit 2
  flags ^= mask2;
  std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");
  // flip bit 2
  flags ^= mask2;
  std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");

  // output
  // bit 2 is on
  // bit 2 is off
  // bit 2 is on
}
```

- We can flip multiple bits simultaneously:

```
flags ^= (mask4 | mask5); // flip bits 4 and 5 at the same time
```

- `std::bitset` supports the full set of bitwise operators. So even though it’s
  easier to use the functions (`test`, `set`, `reset`, and `flip`) to modify
  individual bits, you can use bitwise operators and bit masks if you want.
- Why would you want to? The functions only allow you to modify individual bits.
  The bitwise operators allow you to modify multiple bits at once:

```cpp
#include <cstdint>
#include <iostream>
#include <bitset>

int main()
{
  constexpr std::uint_fast8_t mask0{ 0b0000'0001 }; // represents bit 0
  constexpr std::uint_fast8_t mask1{ 0b0000'0010 }; // represents bit 1
  constexpr std::uint_fast8_t mask2{ 0b0000'0100 }; // represents bit 2 
  constexpr std::uint_fast8_t mask3{ 0b0000'1000 }; // represents bit 3
  constexpr std::uint_fast8_t mask4{ 0b0001'0000 }; // represents bit 4
  constexpr std::uint_fast8_t mask5{ 0b0010'0000 }; // represents bit 5
  constexpr std::uint_fast8_t mask6{ 0b0100'0000 }; // represents bit 6
  constexpr std::uint_fast8_t mask7{ 0b1000'0000 }; // represents bit 7

  // 8 bits in size means room for 8 flags
  std::uint_fast8_t flags{ 0b0000'0101 };

  std::cout << "bit 1 is " << (flags.test(1) ? "on\n" : "off\n");
  std::cout << "bit 2 is " << (flags.test(2) ? "on\n" : "off\n");
  flags ^= (mask1 | mask2); // flip bits 1 and 2
     
  std::cout << "bit 1 is " << (flags.test(1) ? "on\n" : "off\n");
  std::cout << "bit 2 is " << (flags.test(2) ? "on\n" : "off\n");
  flags |= (mask1 | mask2); // turn bits 1 and 2 on
     
  std::cout << "bit 1 is " << (flags.test(1) ? "on\n" : "off\n");
  std::cout << "bit 2 is " << (flags.test(2) ? "on\n" : "off\n");
  flags &= ~(mask1 | mask2); // turn bits 1 and 2 off
     
  std::cout << "bit 1 is " << (flags.test(1) ? "on\n" : "off\n");
  std::cout << "bit 2 is " << (flags.test(2) ? "on\n" : "off\n");

  // output
  // bit 1 is off
  // bit 2 is on
  // bit 1 is on
  // bit 2 is off
  // bit 1 is on
  // bit 2 is on
  // bit 1 is off
  // bit 2 is off
}
```

- A best practice is to give your bit masks useful names as a way to document
  the meaning of your bit flags. Here’s an example from a game we might write:

```cpp
#include <cstdint>
#include <iostream>
 
int main()
{
  // Define a bunch of physical/emotional states
  constexpr std::uint_fast8_t isHungry{ 1 << 0 };       // 0000 0001
  constexpr std::uint_fast8_t isSad{ 1 << 1 };          // 0000 0010
  constexpr std::uint_fast8_t isMad{ 1 << 2 };          // 0000 0100
  constexpr std::uint_fast8_t isHappy{ 1 << 3 };        // 0000 1000
  constexpr std::uint_fast8_t isLaughing{ 1 << 4 };     // 0001 0000
  constexpr std::uint_fast8_t isAsleep{ 1 << 5 };       // 0010 0000
  constexpr std::uint_fast8_t isDead{ 1 << 6 };         // 0100 0000
  constexpr std::uint_fast8_t isCrying{ 1 << 7 };       // 1000 0000
 
  // all flags/options turned off to start
  std::uint_fast8_t me{};
  // I am happy and laughing
  me |= (isHappy | isLaughing);
  // I am no longer laughing
  me &= ~isLaughing;
 
  // Query a few states
  // (we'll use static_cast<bool> to interpret the results as a boolean value)
  std::cout << "I am happy? " << static_cast<bool>(me & isHappy) << '\n';
  std::cout << "I am laughing? " << static_cast<bool>(me & isLaughing) << '\n';
 
  return 0;
}
```

- Here’s the same example implemented using `std::bitset`:

```cpp
#include <iostream>
#include <bitset>
 
int main()
{
  // Define a bunch of physical/emotional states
  std::bitset<8> isHungry{ 0b0000'0001 };
  std::bitset<8> isSad{ 0b0000'0010 };
  std::bitset<8> isMad{ 0b0000'0100 };
  std::bitset<8> isHappy{ 0b0000'1000 };
  std::bitset<8> isLaughing{ 0b0001'0000 };
  std::bitset<8> isAsleep{ 0b0010'0000 };
  std::bitset<8> isDead{ 0b0100'0000 };
  std::bitset<8> isCrying{ 0b1000'0000 };
 
  // all flags/options turned off to start
  std::bitset<8> me{};
  // I am happy and laughing
  me |= (isHappy | isLaughing);
  // I am no longer laughing
  me &= ~isLaughing;
 
  // Query a few states (we use the any() function to see if any bits remain set)
  std::cout << "I am happy? " << (me & isHappy).any() << '\n';
  std::cout << "I am laughing? " << (me & isLaughing).any() << '\n';
 
  return 0;
}
```

- Bit flags make the most sense when you have many identical flag variables. For
  example, in the example above, imagine that instead of having one person (me),
  you had 100. If you used 8 Booleans per person (one for each possible state),
  you’d use 800 bytes of memory. With bit flags, you’d use 8 bytes for the bit
  masks, and 100 bytes for the bit flag variables, for a total of 108 bytes of
  memory - approximately 8 times less memory.
- There’s another case where bit flags and bit masks can make sense. Imagine you
  had a function that could take any combination of 32 different options.
- This is ridiculously difficult to read [...] Instead, if you defined the function
  using bit flags like this:

```cpp
void someFunction(std::bitset<32> options);
```

- Then you could use bit flags to pass in only the options you wanted:

```cpp
someFunction(option10 | option32);
```

---

- This is one of the reasons OpenGL, a well regarded 3d graphic library, opted
  to use bit flag parameters instead of many consecutive Boolean parameters.
- Here’s a sample function call from OpenGL:

```cpp
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear the color and the depth buffer
```

- `GL_COLOR_BUFFER_BIT` and `GL_DEPTH_BUFFER_BIT` are bit masks defined as
  follows (in `gl2.h`):

```cpp
#define GL_DEPTH_BUFFER_BIT     0x00000100
#define GL_STENCIL_BUFFER_BIT   0x00000400
#define GL_COLOR_BUFFER_BIT     0x00004000
```
