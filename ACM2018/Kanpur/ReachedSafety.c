/**
 * Reached Safely or Not
 *
 * The city can be considered as a grid. Rakesh starts his journey from
 * (0, 0) position of the grid. His relative's house is situated at (Rx,
 * Ry). Rakesh can move in four directions: up, down, right, or left
 * indicated by U, D, R, and L respectively.
 *
 * Any position of the city with x ordinate negative or greater than M is
 * considered as dangerous. Also, any position of the city with y ordinate
 * negative or greater than N is considered as dangerous. You will be
 * given the total sequence of Rakesh's movement. You need to determine if
 * Rakesh ended up being at his relative's house, at a dangerous place, or
 * at a random place in the city.
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 int main()
 {
 	int test;
 	scanf("%d",&test);
 	for(int q = 1; q <= test; q++ ) {
 		int m,n;
 		scanf("%d %d",&m,&n);
 		int Rx,Ry;
 		scanf("%d %d",&Rx,&Ry);
 		int len;
 		scanf("%d",&len);
 		char C[len+10];
 		scanf("%s",C);
 		int x=0,y=0;
 		for(int i = 0; i < len; i++) {
 			if(C[i] == 'U') {
 				y++;
 				continue;
 			}
 			if(C[i] == 'D') {
 				y--;
 				continue;
 			}
 			if(C[i] == 'R' ) {
 				x++;
 				continue;
 			}
 			if(C[i] == 'L') {
 				x--;
 				continue;
 			}
 		}
 		if(x == Rx && y == Ry) {
 			printf("Case %d: REACHED\n",q);
 		} else if(x < 0 || x > m || y < 0 || y > n) {
 			printf("Case %d: DANGER\n",q);
 		} else {
 			printf("Case %d: SOMEWHERE\n",q);
 		}
 	}
 	return 0;
 }
