/**
 * A Different Problem: https://icpc.kattis.com/problems/different
 *
 * Write a program that computes the difference between non-negative integers.
 *
 * Input
 * Each line of the input consists of a pair of integers. Each integer is
 * between 00 and 10151015 (inclusive). The input is terminated by end of file.
 *
 * Output
 * For each pair of integers in the input, output one line, containing the
 * absolute value of their difference.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    if (argc != 1) {
        return 1;
    }
    long long int a, b;
    while (! feof(stdin)) {
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", llabs(a - b));
    }
    return 0;
}
