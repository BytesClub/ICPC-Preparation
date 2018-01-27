/**
 * Triangle Count
 *
 * You are given an equilateral triangle ΔABC with the side BC being the
 * base. Each side of the triangle is of length L. There are L-1
 * additional points on each of the sides dividing the sides into equal
 * parts of unit lengths. Points on the sides of the triangle are called
 * major points. Joining these points with lines parallel to the sides of
 * ΔABC will produce some more equilateral triangles. The intersection
 * points of these parallel lines are called minor points.
 *
 * You will be given L, the length of the original triangle ΔABC. You need
 * to find out the number of valid equilateral triangles with side length
 * exactly K.
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 int main(void)
 {
 	int test;
 	scanf("%d",&test);
 	for(int q = 1; q <= test; q++ ) {
 		int m,n;
 		scanf("%d %d",&m,&n);
 		if(m < n) {
 			printf("Case %d: 0\n",q);
 			continue;
 		}
 		int t = (m-n)+1;
 		int val = (t * t + t) / 2;
 		printf("Case %d: %d\n",q,val);
 	}
 	return 0;
 }
