/**
 * Extreme Encoding: https://www.codechef.com/ACM16KOL/problems/KOL16B
 *
 * Lajuk is a little girl who loves playing with array. In her 10th birthday,
 * she got two arrays as presents. Let’s call them A and B. Both arrays have the
 * same size n and contains integers between 0 to 30000.
 *
 * Lajuk’s hard-drive is almost full of presents and she barely has any space to
 * keep the arrays. She discovered a brilliant function to merge the array into
 * one:
 *
     int encodeInteger(int x, int n){
     	n = n<<(1<<(1<<(1<<1)));
     	x = x | n;
    	return x;
    }
    void encodeArray(int *A, int *B, int n){
    	for(int i=0;i<n;i++) {
        	    A[i] = encodeInteger(A[i], B[i]);
    	}
    }
 * Lajuk passed A and B into the encodeArray function. After that she discarded
 * array B and saved the modified version of array A in the hard-drive.

 * Now in her 15th birthday Lajuk wants to play with those arrays again. She
 * found the modified version of array A in the hard-drive but she forgot how to
 * recover the original arrays from it. Being upset, she asked for your help.
 * Can you help her to recover the original arrays?
 *
 * Input
 * The first line contains T (1 ≤ T ≤ 100), the number of test cases. The first
 * line of each test cases contains n (1 ≤ n ≤ 104), the size of the array. Next
 * n line contains n integers denoting the modified array A.
 *
 * Output
 * For each case print the case number in the first line. In the second line,
 * print n integers denoting the original array A. In the third line print n
 * integers denoting the array B. Two consecutive integers should be separated
 * by a single space.
 */

#include <stdio.h>

int main(int argc, char const *argv[]) {
    if (argc != 1) {
        return 1;
    }
    int t, n, k;
    scanf("%d", &t);
    for (int j = 1; j <= t; j++) {
        scanf("%d", &n);
        int A[n], B[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &k);
            A[i] = k & 65535;
            B[i] = k >> 16;
        }
        printf("Case %d:\n", j);
        for (int i = 0; i < n || ! putchar('\n'); i++) {
            printf("%d ", A[i]);
        }
        for (int i = 0; i < n || ! putchar('\n'); i++) {
            printf("%d ", B[i]);
        }
    }
    return 0;
}
