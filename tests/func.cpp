#include "func.hpp"
#include <iostream>

void ItemPrinter::custom_print(const int &i, const int &val)
{
    std::cout << "Custom Item " << i << ": " << val << std::endl;
}

void ItemPrinter::print_even(const std::vector<int> &items)
{
    std::vector<int>::const_iterator it;

    for (it = items.begin(); it != items.end(); it++)
    {
        if (*it % 2 == 0)
        {
            custom_print(std::distance(items.begin(), it), *it);
        }
    }
}

void ItemPrinter::print_odd(const std::vector<int> &items)
{
    std::vector<int>::const_iterator it;

    for (it = items.begin(); it != items.end(); it++)
    {
        if (*it % 2 != 0)
        {
            custom_print(std::distance(items.begin(), it), *it);
        }
    }
}

void ItemPrinter::print_all(const std::vector<int> &items)
{
    std::vector<int>::const_iterator it;

    for (it = items.begin(); it != items.end(); it++)
    {
        custom_print(std::distance(items.begin(), it), *it);
    }
}
