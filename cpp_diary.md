# CPP Diary

## About

This document present in chronological order interesting things and stuff I learnt
while skimming through the language's core features. I've linked a list of references
I used for you to take a look at if you need more information.

---

## Diary

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
