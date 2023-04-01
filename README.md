# 'Implies' Operator For C++

Use the implication (`-->`) operator in your code today!

Simply replace `bool` with `implies::Bool` and benefit from the new operator.

```C++
#include <implies/implies.hpp>

using namespace implies;
static_assert(Bool(false) --> Bool(false));
static_assert(Bool(false) --> Bool(true));
static_assert(!(Bool(true) --> Bool(false)));
static_assert(Bool(true) --> Bool(true));
```

## How to Use

`implies` is a header only library and very lightweight, so you will be able to
drop it into your project structure and use the provided CMakeLists.txt file.

## Running tests

```bash
mkdir build && cd build
cmake ..
make all
ctest
```
