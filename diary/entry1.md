# Entry #1 (2021/02/28)

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