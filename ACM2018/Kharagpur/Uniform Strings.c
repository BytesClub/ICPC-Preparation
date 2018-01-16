/**
 * Uniform Strings
 *
 * You are given a string s of length 8 consisting solely of '0's and '1's.
 * Assume that the characters of the string are written in a circular fashion.
 * You need to find the number of 0-1 or 1-0 transitions that one has to make
 * while making a single traversal over the string. ie. start from any character
 * and go circularly until you get back to the same character, and find the
 * number of transitions that you made. The string is said to be said to be
 * uniform if there are at most two such transitions. Otherwise, it is called
 * non-uniform.
 */

 #include <stdio.h>

 int main(void)
 {
 	int n;
 	scanf("%d", &n);
 	while (n--) {
 		char C[10];
 		scanf("%s", C);
 		char s = C[0];
 		int sum = 0;
 		for (int j = 0; j < 7; j++) {
 			if (C[j] != C[j + 1]) {
 				sum++;
 			}
 		}
 		if(C[7] != C[0])
 			sum++;
 		if(sum <= 2)
 			printf("uniform\n");
 		else
 			printf("non-uniform\n");
 	}
 	return 0;
 }
