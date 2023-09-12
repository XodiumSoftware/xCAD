#ifndef FUNC_HPP
#define FUNC_HPP

#include <vector>

class ItemPrinter
{
public:
    void custom_print(const int &i, const int &val);
    void print_even(const std::vector<int> &items);
    void print_odd(const std::vector<int> &items);
    void print_all(const std::vector<int> &items);
};

#endif
