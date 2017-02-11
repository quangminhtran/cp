#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int N;
	int abcde, fghij, k = 0;
	while (scanf("%d", &N), N) {
		if (k > 0) {
			printf("\n");
		}
		int found = 0;
		for (fghij = 1234; fghij <= 98765/N; fghij++) {
			abcde = fghij * N; /* abcde and fghij are at most 5 digits */
			int used = (fghij < 10000);
			int tmp = fghij;
			while (tmp) {
				used |= (1 << (tmp % 10));	 /* Turn on tmp % 10 bit */
				tmp /= 10;		
			}
			tmp = abcde;
			while (tmp) {
				used |= (1 << (tmp % 10));
				tmp /= 10;
			}
			if (used == (1 << 10) - 1) {
				printf("%0.5d / %0.5d = %d\n", abcde, fghij, N);
				found = 1;
			}
						
		}
		if (!found) {
			printf("There are no solutions for %d.\n", N);	
		}
		k++;
	}
	return 0;	
}


