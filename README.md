# ox.termcolor library

## Description

Ox.termcolor is a `header-only` library
This is a library that supports color output in the terminal.
It supports legacy16 and true-color output.



On windows, [Windows API](https://learn.microsoft.com/en-us/windows/console/setconsoletextattribute) instead of ANSI escape sequences is used for legacy16 colors.

You can use it on windows, almost all unix-like systems, etc.

## Usage

```cpp

#include <ox/termcolor.hpp>
#include <iostream>

using namespace ox::termcolor;

int main() {
    std::cout << red() << "Hello World!" << reset() << std::endl; // 16 color, also legacy16<31>
    // reset() to reset color to default

    return 0;
}
```

Note:
- ox.termcolor ignores any color for non-tty streams
- legacy16 colors are all supported
- true colors are `NOT` support if your windows os doesn't have [virtual terminal processing](https://learn.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences#enable-virtual-terminal-processing)

## Foreground manipulators

### 16 colors manipulators

- ox::termcolor::reset
- ox::termcolor::grey
- ox::termcolor::red
- ox::termcolor::green
- ox::termcolor::yellow
- ox::termcolor::blue
- ox::termcolor::magenta
- ox::termcolor::cyan
- ox::termcolor::white
- ox::termcolor::bright_grey
- ox::termcolor::bright_red
- ox::termcolor::bright_green
- ox::termcolor::bright_yellow
- ox::termcolor::bright_blue
- ox::termcolor::bright_magenta
- ox::termcolor::bright_cyan
- ox::termcolor::bright_white
- ox::termcolor::legacy16<30 - 37, 90 - 97>
- ox::termcolor::legacy16(COLOR_CODE)

### True color manipulators

- ox::termcolor::rgb_reset
- ox::termcolor::rgb<RED, GREEN, BLUE>
- ox::termcolor::rgb(RED, GREEN, BLUE)

## Background manipulators

### 16 colors manipulators

- ox::termcolor::on_reset
- ox::termcolor::on_grey
- ox::termcolor::on_red
- ox::termcolor::on_green
- ox::termcolor::on_yellow
- ox::termcolor::on_blue
- ox::termcolor::on_magenta
- ox::termcolor::on_cyan
- ox::termcolor::on_white
- ox::termcolor::on_bright_grey
- ox::termcolor::on_bright_red
- ox::termcolor::on_bright_green
- ox::termcolor::on_bright_yellow
- ox::termcolor::on_bright_blue
- ox::termcolor::on_bright_magenta
- ox::termcolor::on_bright_cyan
- ox::termcolor::on_bright_white
- ox::termcolor::legacy16<40 - 47, 100 - 107>
- ox::termcolor::legacy16(COLOR_CODE)

### True color manipulators

- ox::termcolor::on_rgb_reset
- ox::termcolor::on_rgb<RED, GREEN, BLUE>
- ox::termcolor::on_rgb(RED, GREEN, BLUE)

## Attribute manipulators

- ox::termcolor::bold
- ox::termcolor::dark
- ox::termcolor::italic
- ox::termcolor::underline
- ox::termcolor::blink
- ox::termcolor::reverse
- ox::termcolor::concealed
- ox::termcolor::crossed

Note:
- Windows API is not supported for these manipulators