#include <iostream>
#include <ox/termcolor/termcolor.hpp>
using namespace ox;

struct range_item {
    int begin;
    int end;
    const char *name;
};

const range_item ranges[5] = {
    {30, 37, "normal"},
    {40, 47, "bg"},
    {90, 97, "bright"},
    {100, 107, "bright bg"},
    {1, 9, "styles"}
};

template <class Color>
void print_group(const range_item &item, const char *group) {
    std::cout << "#group " << item.name << ": " << std::endl;
    for (int i = item.begin; i <= item.end; ++i) {
        std::cout << Color(i) << i << reset() << "\t";
        if (i % 3 == 0 && i != item.begin)
            std::cout << std::endl;
    }
    std::cout << std::endl;
}

void print_legacy() {
    for (int i = 0; i < 5; ++i)
        print_group<legacy16>(ranges[i], "legacy");
}

void print_rgb() {
    std::cout << "#group rgb: " << std::endl;
    for (int i = 10; i < 15; ++i) {
        for (int j = 250; j < 255; ++j) {
            for (int k = 230; k < 235; ++k) {
                std::cout << "(" << i << ", " << j << ", " << k << ")" << "\t";
                std::cout << reset() << rgb(i, j, k) << "(" << i << ", " << j << ", " << k << ")" << reset() << "\t";
                std::cout << reset() << on_rgb(i, j, k) << "(" << i << ", " << j << ", " << k << ")" << reset() << std::endl;
                std::cout << on_rgb_reset();
            }
        }
    }
}

int main() {
    print_legacy();
    print_rgb();
    return 0;
}