#include <iostream>
#include <vector>
#include "func.hpp"

void test_func()
{
    std::vector<int> items = {1, 2, 3, 4, 5};
    for (int i = 0; i < items.size(); i++)
    {
        std::cout << "Item " << i << ": " << items[i] << std::endl;
    }
}
