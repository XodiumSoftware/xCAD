#include "func.hpp"

int main()
{
    ItemPrinter printer;
    std::vector<int> items = {1, 2, 3, 4, 5};
    printer.print_even(items);
    printer.print_odd(items);
    printer.print_all(items);
    return 0;
}
