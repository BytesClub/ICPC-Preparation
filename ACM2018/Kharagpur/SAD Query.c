/*
 * SAD Query
 *
 * "The Mean Absolute Difference is a measure of statistical dispersion equal to
 * the average absolute difference of two independent values drawn from a
 * probability distribution." - Wikipedia
 *
 * In this problem we are concerned not with Mean Absolute Difference (MAD) of
 * two distributions but rather with the Summed Absolute Difference (SAD) of two
 * arrays. Given arrays (1-indexed) P and Q of lengths p and q, define
 *      SAD(P, Q) = SUM[i = 0 -> p] SUM[j = 0 -> q] |Pi - Qj|
 * Given a collection of K arrays A1, ..., AK, report SAD(Ai, Aj) for several
 * queries (i, j).
 */

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*((int*)a) > *((int*)b));
}

int lowest_index(int A[], int start, int end, int val) {
    int findex = start, count = end - start, step, i;
    while (count > 0) {
        step = count / 2;
        i = findex + step;
        if (i < end && A[i] < val) {
            findex = ++i;
            count -= step + 1;
        } else {
            count = step;
        }
    }
    return findex;
}

int main(void) {
	int k, m, e = 0;
	scanf("%d", &k);
	int s[k];
	int* A[k];
	int* Pref[k];
	int* Suf[k];
	for (int i = 0; i < k; i++) {
	    scanf("%d", s + i);
	    A[i] = malloc(s[i] * sizeof(int));
	    Pref[i] = malloc(s[i] * sizeof(int));
	    Suf[i] = malloc(s[i] * sizeof(int));
	    for (int j = 0; j < s[i]; j++) {
	        scanf("%d", A[i] + j);
	    }
	    qsort(A[i], s[i], sizeof(int), cmp);
	    Pref[i][0] = 0;
	    for (int j = 1; j < s[i]; j++) {
	        Pref[i][j] = Pref[i][j - 1] + (A[i][j] - A[i][0]);
	    }
	    Suf[s[i] - 1] = 0;
	    for (int j = s[i] - 2; i >= 0; j--) {
	        Suf[i][j] = Suf[i][j + 1] + (A[i][s[i] - 1] - A[i][j]);
	    }
	}
	scanf("%d", &m);
	long long int DP[m][3], result = 0;
	for (int i = 0; i < m; i++) {
	    int x, y, flag = 0, q = 0;
	    scanf("%d %d", &x, &y);
	    --x, --y;
	    if (s[x] > s[y] || (s[x] == s[y] && x > y)) {
	        int temp = x;
	        x = y;
	        y = temp;
	    }
	    for (int j = 0; j < e; j++) {
	        if (DP[j][0] == x && DP[j][1] == y) {
	            printf("%lld\n", DP[j][2]);
	            flag = 1;
	            break;
	        }
	    }
	    if (flag) continue;
	    for (int p = 0; p < s[x]; p++) {
	        q = lowest_index(A[y], q, s[y], A[x][p]);
	        if (q) {
	            result += (A[x][p] - A[y][0]) * q;
	            result -= Pref[y][q - 1];
	        }
	        if (q < s[y]) {
	            result += (A[y][s[y] - 1] - A[x][p]) * 1ll * (s[y] - q);
	            result -= Suf[y][q - 1];
	        }
	    }
	    printf("%lld\n", result);
	    DP[e][0] = x, DP[e][1] = y, DP[e][2] = result;
	    ++e;
	}
	for (int i = 0; i < k; i++) {
	    free(A[i]);
	    free(Pref[i]);
	    free(Suf[i]);
	}
	return 0;
}
