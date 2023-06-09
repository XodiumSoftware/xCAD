cdef long long factorial_cython(int n):
    """
    Calculate the factorial of a given integer using Cython.
    """
    cdef long long result = 1
    cdef int i
    for i in range(1, n + 1):
        result *= i
    return result

def factorial(n):
    """
    Calculate the factorial of a given integer.
    """
    return factorial_cython(n)

def main():
    """
    Demonstrate the usage of the factorial function.
    """
    cdef int n = 5
    cdef long long result = factorial(n)
    print(f"The factorial of {n} is: {result}")

if __name__ == '__main__':
    main()
