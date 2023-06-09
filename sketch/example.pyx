# Import the required Cython modules
from libc.stdlib cimport malloc, free

# Define the factorial function in Cython
cdef long long factorial_cython(int n):
    cdef long long result = 1
    cdef int i
    for i in range(1, n + 1):
        result *= i
    return result

# Define a Python wrapper function for the factorial function
def factorial(n):
    return factorial_cython(n)

# Define a main function to demonstrate the usage
def main():
    cdef int n = 5
    result = factorial(n)
    print(f"The factorial of {n} is: {result}")

# Call the main function
if __name__ == '__main__':
    main()
