#include <iostream>

extern "C"
{
    int addNumbers(int a, int b)
    {
        return a + b;
    }
}

int main()
{
    // Call the C++ function from main if desired
    int result = addNumbers(5, 3);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
