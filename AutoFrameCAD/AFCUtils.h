#ifndef AFCUTILS_H
#define AFCUTILS_H

#ifdef __cplusplus
extern "C"
{
#endif

    int factorial(int n);
    int sumArray(int arr[], int size);
    int isPalindrome(char str[]);
    int isPrime(int n);
    int maxArray(int arr[], int size);
    int minArray(int arr[], int size);
    void reverseString(char str[]);
    void swap(int *a, int *b);

#ifdef __cplusplus
}
#endif

#endif
