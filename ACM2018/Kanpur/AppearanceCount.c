/**
 * Appearance Count
 *
 * You will be given m strings. For each of those strings, you need to count
 * total number of appearance of that string as substring in all possible
 * strings of length n containing only lower case English letters.
 *
 * A substring may appear in a string multipe times. Also, these appearances
 * may overlap. All these must be counted seperately. For example: 'aa' appears
 * thrice in the string aaacaa: 'aa'acaa, a'aa'caa, aaac'aa'.
 */

#include <math.h>
#include <stdio.h>
#include <string.h>
#define SIZE 500000
#define MOD 1000000007

long long int mod_pow(long long int b, long long int e) {
    long long int res = 1;
    b = b % MOD;
    while (e > 0) {
        if (e & 1) {
            res = (res * b) % MOD;
        }
        e = e >> 1;
        b = (b * b) % MOD;
    }
    return res;
}

int main(void) {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
	    int n, m;
	    scanf("%d %d", &n, &m);
	    printf("Case %d:\n", i);
	    char str[SIZE];
	    for (int j = 0; j < m; j++) {
    	    scanf("%s", str);
    	    int k = strlen(str);
    	    if (n < k) {
    	        puts("0");
    	        continue;
    	    }
    	    long long int ans = mod_pow(26, n - k);
	        ans = (ans * ((n - k + 1) % MOD)) % MOD;
	        printf("%lld\n", ans);
	    }
	}
	return 0;
}
