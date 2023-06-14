cdef long factorial_cython(int n):
    """
    Calculate the factorial of a given integer using Cython.
    """
    cdef long result = 1
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
    cdef long result = factorial(n)
    print("The factorial of {} is: {}".format(n, result))

if __name__ == '__main__':
    main()