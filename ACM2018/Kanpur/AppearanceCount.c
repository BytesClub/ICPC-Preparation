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
#define SIZE 500001

int main(int argc, char const *argv[]) {
    if (argc != 1) {
        return 1;
    }
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int n, m;
        char str[SIZE];
        printf("Case-%d:\n", t);
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++) {
            scanf("%s", str);
            int len = strlen(str);
            int rem = n - len;
            long long int count = pow(26, rem) * (rem + 1);
            printf("%lld\n", count);
        }
    }
    return 0;
}
